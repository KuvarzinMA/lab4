#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time { // Объявление класса Time
private:
    short int hours;   // Приватное поле для хранения количества часов
    short int minutes; // Приватное поле для хранения количества минут

public:
    // Конструкторы (Фигурные скобки позволяют задать начальные значения полям класса)
    Time(); // Конструктор по умолчанию, инициализирующий объект Time
    Time(short int h, short int m); // Конструктор, принимающий часы и минуты в качестве параметров
    Time(const Time& other); // Конструктор копирования, создающий новый объект на основе существующего

    // Сеттер - это метод, который устанавливает значение для приватного поля
    void setTime(short int h, short int m); // Метод для установки значений часов и минут

    // Геттеры - это методы, которые возвращают значение приватного поля
    short int getHours() const; // Метод для получения значения часов
    short int getMinutes() const; // Метод для получения значения минут

    // Методы
    Time subtract(const Time& other) const; // Метод для вычитания времени другого объекта Time
    void inputTime(); // Метод для ввода времени от пользователя

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Time& time); // Дружеская функция для перегрузки оператора вывода

    // Перегрузка унарных операторов
    Time& operator++();    // Префиксный инкремент (увеличивает время на 1 минуту)
    Time operator++(int);  // Постфиксный инкремент (увеличивает время на 1 минуту, возвращая старое значение)
    Time& operator--();    // Префиксный декремент (уменьшает время на 1 минуту)
    Time operator--(int);  // Постфиксный декремент (уменьшает время на 1 минуту, возвращая старое значение)

    // Перегрузка операций приведения типа
    operator int() const;    // Преобразование объекта Time в int (общее количество минут)
    explicit operator bool() const; // Преобразование объекта Time в bool (проверка на ноль, если время равно 0), explicit используется для предотвращения ошибки при преобразовании 

    // Перегрузка бинарных операторов сравнения
    bool operator<(const Time& other) const; // Сравнение времени: меньше ли текущее время, чем другое
    bool operator>(const Time& other) const; // Сравнение времени: больше ли текущее время, чем другое
};


#endif // TIME_H
