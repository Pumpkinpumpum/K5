#include "TaskList.h"
#include <fstream>
#include <iostream>
#include <algorithm> // Необходимо для std::remove_if

// Добавить задачу в список
void TaskList::addTask(const Task& task) {
    tasks.push_back(task);
}

// Удалить задачу по названию
void TaskList::removeTask(const std::string& name) {
    // Используем remove_if для удаления задачи с указанным именем
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
        [&name](const Task& task) { return task.getName() == name; }), tasks.end());
}

// Отобразить задачи. Если completedOnly = true, показываются только выполненные
void TaskList::displayTasks(bool completedOnly) const {
    for (const auto& task : tasks) {
        if (!completedOnly || task.isCompleted()) {
            task.display();
        }
    }
}

// Отметить задачу как выполненную по названию
void TaskList::markTaskAsCompleted(const std::string& name) {
    for (auto& task : tasks) {
        if (task.getName() == name) {
            task.markAsCompleted();
            break;
        }
    }
}

// Сохранить задачи в файл
void TaskList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task.getName() << '\n'
                 << task.isCompleted() << '\n'
                 << task.getDescription() << '\n';
        }
        file.close();
    } else {
        std::cerr << "Ne udalos' otkryt' fail dlya sohraneniya zadach." << std::endl;
    }
}

// Загрузить задачи из файла
void TaskList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string name, description;
        bool completed;
        while (std::getline(file, name)) {
            file >> completed;
            file.ignore(); // Пропустить символ новой строки после статуса
            std::getline(file, description);
            Task task(name, description);
            if (completed) {
                task.markAsCompleted();
            }
            addTask(task);
        }
        file.close();
    } else {
        std::cerr << "Ne udalos' otkryt' fail dlya zagruzki zadach." << std::endl;
    }
}
