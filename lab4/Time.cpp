#include "Time.h"
#include <iomanip>
#include <limits>

using namespace std;

// Конструкторы (Фигурные скобки позволяют задать начальные значения полям класса)
Time::Time() : hours(0), minutes(0) {} // Конструктор по умолчанию: инициализирует часы и минуты нулем

Time::Time(short int h, short int m) { // Конструктор, принимающий часы и минуты
    setTime(h, m); // Устанавливает время с помощью метода setTime
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {} // Конструктор копирования: копирует часы и минуты из другого объекта


// Сеттер - это метод, который устанавливает значение для приватного поля
void Time::setTime(short int h, short int m) { // Метод для установки значений часов и минут
    hours = h; // Присваивает значение часов
    minutes = m; // Присваивает значение минут
}


// Геттеры - это методы, которые возвращают значение приватного поля
short int Time::getHours() const { return hours; } // Возвращает значение часов
short int Time::getMinutes() const { return minutes; } // Возвращает значение минут


// Перегрузка оператора вывода
ostream& operator<<(ostream& os, const Time& time) { // Дружеская функция для перегрузки оператора вывода
    os << setw(2) << setfill('0') << time.hours << ":" // Форматирует часы с ведущим нулем
        << setw(2) << setfill('0') << time.minutes; // Форматирует минуты с ведущим нулем
    return os; // Возвращает поток для дальнейшего использования
}

// Метод для вычитания времени
Time Time::subtract(const Time& other) const { // Метод для вычитания времени другого объекта Time
    int totalMinutes1 = hours * 60 + minutes; // Преобразует текущее время в общее количество минут
    int totalMinutes2 = other.hours * 60 + other.minutes; // Преобразует другое время в общее количество минут
    int resultMinutes = totalMinutes1 - totalMinutes2; // Вычисляет разницу в минутах

    if (resultMinutes < 0) { // Если результат отрицательный (т.е. время меньше)
        resultMinutes += 24 * 60; // Добавляет 24 часа в минутах для корректировки
    }

    Time result; // Создает новый объект Time для хранения результата
    result.hours = (resultMinutes / 60) % 24; // Вычисляет часы из общего количества минут
    result.minutes = resultMinutes % 60; // Вычисляет минуты из общего количества минут
    return result; // Возвращает объект результата
}

// Метод для ввода времени
void Time::inputTime() { // Метод для ввода времени от пользователя
    short int h, m; // Переменные для хранения введенных часов и минут
    bool isValid = false; // Флаг для проверки корректности ввода

    while (!isValid) { // Цикл до тех пор, пока ввод не будет корректным
        std::cout << "Введите часы (0-23): "; // Запрашивает ввод часов
        std::cin >> h; // Читает значение часов

        // Проверка на корректность числового ввода
        if (std::cin.fail()) { // Если ввод некорректен
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число." << std::endl; // Сообщение об ошибке
            std::cin.clear(); // Сбрасывает флаг ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n'); // Очищает буфер ввода
            continue; // Переходит к следующей итерации цикла
        }

        std::cout << "Введите минуты (0-59): "; // Запрашивает ввод минут
        std::cin >> m; // Читает значение минут

        // Проверка на корректность числового ввода
        if (std::cin.fail()) { // Если ввод некорректен
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число." << std::endl; // Сообщение об ошибке
            std::cin.clear(); // Сбрасывает флаг ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n'); // Очищает буфер ввода
            continue; // Переходит к следующей итерации цикла
        }

        // Проверка корректности диапазона значений
        if (h >= 0 && h < 24 && m >= 0 && m < 60) { // Если введенные часы и минуты находятся в допустимом диапазоне
            setTime(h, m); // Устанавливает введенное время с помощью метода setTime

                        isValid = true; // Устанавливает флаг корректности ввода в true для выхода из цикла
        }
        else {
            std::cout << "Некорректное значение времени! Пожалуйста, повторите ввод." << std::endl; // Сообщение о некорректном вводе
        }
    }
}


// Унарные операторы
Time& Time::operator++() { // Префиксный инкремент: увеличивает время на 1 минуту
    ++minutes; // Увеличивает минуты на 1
    if (minutes >= 60) { // Если минуты достигают 60
        minutes = 0; // Сбрасывает минуты на 0
        ++hours; // Увеличивает часы на 1
    }
    if (hours >= 24) { // Если часы достигают 24
        hours = 0; // Сбрасывает часы на 0
    }
    return *this; // Возвращает текущий объект для цепочки вызовов
}

Time Time::operator++(int) { // Постфиксный инкремент: увеличивает время на 1 минуту, возвращая старое значение
    Time temp = *this; // Сохраняет текущее значение в временной переменной
    ++(*this); // Вызывает префиксный инкремент для увеличения времени на 1 минуту
    return temp; // Возвращает старое значение времени
}

Time& Time::operator--() { // Префиксный декремент: уменьшает время на 1 минуту
    --minutes; // Уменьшает минуты на 1
    if (minutes < 0) { // Если минуты меньше 0
        minutes = 59; // Устанавливает минуты на 59
        --hours; // Уменьшает часы на 1
    }
    if (hours < 0) { // Если часы меньше 0
        hours = 23; // Устанавливает часы на 23 (предыдущий день)
    }
    return *this; // Возвращает текущий объект для цепочки вызовов
}

Time Time::operator--(int) { // Постфиксный декремент: уменьшает время на 1 минуту, возвращая старое значение
    Time temp = *this; // Сохраняет текущее значение в временной переменной
    --(*this); // Вызывает префиксный декремент для уменьшения времени на 1 минуту
    return temp; // Возвращает старое значение времени
}

// Преобразование в int: возвращает общее количество минут
Time::operator int() const {
    return hours * 60 + minutes; // Преобразует время в общее количество минут с учетом часов и минут
}

// Преобразование в bool: проверяет, является ли время ненулевым (не равно нулю)
Time::operator bool() const {
    return hours != 0 || minutes != 0; // Возвращает true, если хотя бы одна из величин не равна нулю (время не равно нулю)
}

// Операторы сравнения: сравнивают два объекта Time по времени в минутах
bool Time::operator<(const Time& other) const {
    return (hours * 60 + minutes) < (other.hours * 60 + other.minutes); // Возвращает true, если текущее время меньше другого времени
}

bool Time::operator>(const Time& other) const {
    return (hours * 60 + minutes) > (other.hours * 60 + other.minutes); // Возвращает true, если текущее время больше другого времени
}
