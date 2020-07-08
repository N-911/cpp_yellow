#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    TeamTasks()= default;
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return task_base.at(person);
    }

    int get_number_tasks(const string& person) {
        int res = 0;

        for (const auto [key, value] : task_base.at(person)) {
            res += value;
        }
        return res;
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        ++task_base[person][TaskStatus ::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count) {
        TasksInfo untouched_tasks, updated_tasks, temp;

        if(task_base.count(person) == 0) {
            return tie(updated_tasks, untouched_tasks);
        }
        temp = GetPersonTasksInfo(person);
        untouched_tasks = GetPersonTasksInfo(person);
        int sum = get_number_tasks(person);
        if (task_count < sum)
            sum = task_count;
        for (int i = 0; i < sum; ++i) {
            if (temp.count(TaskStatus ::NEW) > 0) {
                --temp[TaskStatus::NEW];
                ++updated_tasks[TaskStatus::IN_PROGRESS];
                ++temp[TaskStatus::IN_PROGRESS];
                --untouched_tasks[TaskStatus::NEW];
                if (temp[TaskStatus::NEW] == 0) {
                    temp.erase(TaskStatus ::NEW);
                    untouched_tasks.erase(TaskStatus::NEW);
                }
            }
            else if (temp.count(TaskStatus ::IN_PROGRESS) > 0 ) {
                --temp[TaskStatus ::IN_PROGRESS];
                ++temp[TaskStatus ::TESTING];
                ++updated_tasks[TaskStatus::TESTING];
//                untouched_tasks[TaskStatus::IN_PROGRESS]= temp[TaskStatus::IN_PROGRESS];
                --untouched_tasks[TaskStatus::IN_PROGRESS];
                if (temp[TaskStatus::IN_PROGRESS] == 0) {
                    temp.erase(TaskStatus ::IN_PROGRESS);
                    untouched_tasks.erase(TaskStatus::IN_PROGRESS);
                }
            }
            else if (temp.count(TaskStatus ::TESTING) > 0) {
                --temp[TaskStatus ::TESTING];
                ++temp[TaskStatus ::DONE];
                ++updated_tasks[TaskStatus::DONE];
//                untouched_tasks[TaskStatus::TESTING]= temp[TaskStatus::TESTING];
                --untouched_tasks[TaskStatus::TESTING];
                if (temp[TaskStatus::TESTING] == 0) {
                    temp.erase(TaskStatus ::TESTING);
                    untouched_tasks.erase(TaskStatus::TESTING);
                }
            }
            else if (temp.count(TaskStatus ::DONE) > 0) {
                --temp[TaskStatus ::DONE];
//                untouched_tasks[TaskStatus::DONE]= temp[TaskStatus::DONE];
                if (temp[TaskStatus::DONE] == 0) {
                    temp.erase(TaskStatus ::DONE);
                    untouched_tasks.erase(TaskStatus::DONE);
                }
            }
            else {
                break;
            }
        }
        untouched_tasks.erase(TaskStatus::DONE);
//        task_base.erase(person);
        task_base[person]=temp;
        return {updated_tasks, untouched_tasks};
    }

private:
    map<string, TasksInfo> task_base;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}


int main() {
    TeamTasks tasks;
    TasksInfo updated_tasks, untouched_tasks;

    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 1);
    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 10);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 4);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

    return 0;
}

