#ifndef TASK_H
#define TASK_H

#include <string>

// Класс Task представляет одну задачу с названием, описанием и статусом выполнения
class Task {
private:
    std::string name;          // Название задачи
    std::string description;    // Описание задачи
    bool completed;             // Статус выполнения (true - выполнена, false - в ожидании)

public:
    // Конструктор для задания начальных значений
    Task(std::string name, std::string description);

    // Метод для пометки задачи как выполненной
    void markAsCompleted();

    // Метод для проверки, выполнена ли задача
    bool isCompleted() const;

    // Метод для отображения задачи в консоли
    void display() const;

    // Получить название задачи
    std::string getName() const;

    // Получить описание задачи
    std::string getDescription() const; // Метод для получения описания задачи
};

#endif
