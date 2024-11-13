#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    short int hours;
    short int minutes;

public:
    // Конструкторы (Фигурные скобки позволяют задать начальные значения полям класса)
    Time();
    Time(short int h, short int m);
    Time(const Time& other);

    // Сеттер - это метод, который устанавливает значение для приватного поля
    void setTime(short int h, short int m);

    // Геттеры - это метод который возвращает значение приватного поля
    short int getHours() const;
    short int getMinutes() const;

    // Методы
    Time subtract(const Time& other) const;
    void inputTime();

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Time& time);

    // Перегрузка унарных операторов
    Time& operator++();    // Префиксный инкремент
    Time operator++(int);  // Постфиксный инкремент
    Time& operator--();    // Префиксный декремент
    Time operator--(int);  // Постфиксный декремент

    // Перегрузка операций приведения типа
    operator int() const;    // Преобразование в int (общее количество минут)
    explicit operator bool() const; // Преобразование в bool (проверка на ноль)

    // Перегрузка бинарных операторов сравнения
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
};

#endif // TIME_H
