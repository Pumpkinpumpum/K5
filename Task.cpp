#include "Task.h"
#include <iostream>

// Конструктор инициализирует задачу названием, описанием и статусом "в ожидании"
Task::Task(std::string name, std::string description)
    : name(name), description(description), completed(false) {}

// Пометить задачу как выполненную
void Task::markAsCompleted() {
    completed = true;
}

// Проверить, выполнена ли задача
bool Task::isCompleted() const {
    return completed;
}

// Отобразить задачу в консоли, показывая статус
void Task::display() const {
    std::cout << (completed ? "[Vypolneno] " : "[V ozhidanii] ") << name << ": " << description << std::endl;
}

// Получить название задачи
std::string Task::getName() const {
    return name;
}

// Получить описание задачи
std::string Task::getDescription() const {
    return description;
}
