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
    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        ++task_base[person][TaskStatus ::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count) {
        TasksInfo t_old, t_new;

        if(task_base.count(person) == 0) {
            return {t_new, t_old};
        }

        t_old = GetPersonTasksInfo(person);
        for (int i = 0; i < task_count; ++i) {
            if (task_base[person][TaskStatus ::NEW] >= 0) {
                if (task_base[person][TaskStatus ::NEW] > 0) {
                    --task_base[person][TaskStatus::NEW];
                    ++task_base[person][TaskStatus::IN_PROGRESS];
                }
                else {
                    task_base[person].erase(TaskStatus ::NEW);
                }
            }
            else if (task_base[person][TaskStatus ::IN_PROGRESS] > 0) {
                --task_base[person][TaskStatus ::IN_PROGRESS];
                ++task_base[person][TaskStatus ::TESTING];
            }
            else if (task_base[person][TaskStatus ::TESTING] > 0) {
                --task_base[person][TaskStatus ::TESTING];
                ++task_base[person][TaskStatus ::DONE];
            }
            else if (task_base[person][TaskStatus ::DONE] > 0) {
                --task_base[person][TaskStatus ::DONE];
            }
            else {
                break;
            }
        }
        t_new = GetPersonTasksInfo(person);
        return {t_new, t_old};
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
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}
