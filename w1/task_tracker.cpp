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


    TaskStatus next_status(TaskStatus tS) {
       TaskStatus res;
        if (tS == TaskStatus::NEW) {
            res = TaskStatus::IN_PROGRESS;
        }
        else if (tS == TaskStatus::IN_PROGRESS) {
            res = TaskStatus::TESTING;
        }
        else if (tS == TaskStatus::TESTING) {
            res = TaskStatus::DONE;
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
//        untouched_tasks = GetPersonTasksInfo(person);

        for (const auto [key, value] : task_base[person]) {
            if (key != TaskStatus::DONE && value > 0) {
                for (int j = 0; j < value; ++j) {
                    if (task_count > 0) {

                        --temp[key];
                        ++updated_tasks[next_status(key)];
                        ++temp[next_status(key)];
//                        --untouched_tasks[key];
                        if (temp[key] == 0) {
                            temp.erase(key);
//                            untouched_tasks.erase(key);
                        }
                        --task_count;
                    }
                    else {

                        untouched_tasks[key]++;
                    }
                }
            }
        }
        untouched_tasks.erase(TaskStatus::DONE);
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
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 11);
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 10);
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 10);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

    return 0;
}


