#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include <vector>
#include <string>

// Класс TaskList управляет списком задач, предоставляя функционал добавления, удаления и отображения
class TaskList {
private:
    std::vector<Task> tasks; // Список задач

public:
    // Добавить новую задачу в список
    void addTask(const Task& task);

    // Удалить задачу по названию
    void removeTask(const std::string& name);

    // Отобразить список задач, с опцией показа только выполненных
    void displayTasks(bool completedOnly = false) const;

    // Отметить задачу как выполненную
    void markTaskAsCompleted(const std::string& name);

    // Сохранить задачи в файл
    void saveToFile(const std::string& filename) const;

    // Загрузить задачи из файла
    void loadFromFile(const std::string& filename);
};

#endif
