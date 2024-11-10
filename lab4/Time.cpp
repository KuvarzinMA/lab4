#include "Time.h"
#include <iomanip>
#include <limits>

using namespace std;

// Конструкторы
Time::Time() : hours(0), minutes(0) {}

Time::Time(short int h, short int m) {
    setTime(h, m);
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// Сеттер
void Time::setTime(short int h, short int m) {
    hours = h;
    minutes = m;
}


// Геттеры
short int Time::getHours() const { return hours; }
short int Time::getMinutes() const { return minutes; }

// Перегрузка оператора вывода
ostream& operator<<(ostream& os, const Time& time) {
    os << setw(2) << setfill('0') << time.hours << ":"
        << setw(2) << setfill('0') << time.minutes;
    return os;
}

// Метод для вычитания времени
Time Time::subtract(const Time& other) const {
    int totalMinutes1 = hours * 60 + minutes;
    int totalMinutes2 = other.hours * 60 + other.minutes;
    int resultMinutes = totalMinutes1 - totalMinutes2;

    if (resultMinutes < 0) {
        resultMinutes += 24 * 60;
    }

    Time result;
    result.hours = (resultMinutes / 60) % 24;
    result.minutes = resultMinutes % 60;
    return result;
}

// Метод для ввода времени
void Time::inputTime() {
    short int h, m;
    bool isValid = false;

    while (!isValid) {
        std::cout << "Введите часы (0-23): ";
        std::cin >> h;

        // Проверка на корректность числового ввода
        if (std::cin.fail()) {
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число." << std::endl;
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
            continue;
        }

        std::cout << "Введите минуты (0-59): ";
        std::cin >> m;

        // Проверка на корректность числового ввода
        if (std::cin.fail()) {
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Проверка корректности диапазона значений
        if (h >= 0 && h < 24 && m >= 0 && m < 60) {
            setTime(h, m);
            isValid = true; // Выход из цикла при корректном вводе
        }
        else {
            std::cout << "Некорректное значение времени! Пожалуйста, повторите ввод." << std::endl;
        }
    }
}


// Унарные операторы
Time& Time::operator++() {
    ++minutes;
    if (minutes >= 60) {
        minutes = 0;
        ++hours;
    }
    if (hours >= 24) {
        hours = 0;
    }
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    ++(*this);
    return temp;
}

Time& Time::operator--() {
    --minutes;
    if (minutes < 0) {
        minutes = 59;
        --hours;
    }
    if (hours < 0) {
        hours = 23;
    }
    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;
    --(*this);
    return temp;
}

// Преобразование в int
Time::operator int() const {
    return hours * 60 + minutes;
}

// Преобразование в bool
Time::operator bool() const {
    return hours != 0 || minutes != 0;
}

// Операторы сравнения
bool Time::operator<(const Time& other) const {
    return (hours * 60 + minutes) < (other.hours * 60 + other.minutes);
}

bool Time::operator>(const Time& other) const {
    return (hours * 60 + minutes) > (other.hours * 60 + other.minutes);
}
