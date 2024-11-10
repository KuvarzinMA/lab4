#include "Time.h"
#include <iomanip>
#include <limits>

using namespace std;

// ������������
Time::Time() : hours(0), minutes(0) {}

Time::Time(short int h, short int m) {
    setTime(h, m);
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// ������
void Time::setTime(short int h, short int m) {
    hours = h;
    minutes = m;
}


// �������
short int Time::getHours() const { return hours; }
short int Time::getMinutes() const { return minutes; }

// ���������� ��������� ������
ostream& operator<<(ostream& os, const Time& time) {
    os << setw(2) << setfill('0') << time.hours << ":"
        << setw(2) << setfill('0') << time.minutes;
    return os;
}

// ����� ��� ��������� �������
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

// ����� ��� ����� �������
void Time::inputTime() {
    short int h, m;
    bool isValid = false;

    while (!isValid) {
        std::cout << "������� ���� (0-23): ";
        std::cin >> h;

        // �������� �� ������������ ��������� �����
        if (std::cin.fail()) {
            std::cout << "������ �����! ����������, ������� ����� �����." << std::endl;
            std::cin.clear(); // ���������� ���� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����� �����
            continue;
        }

        std::cout << "������� ������ (0-59): ";
        std::cin >> m;

        // �������� �� ������������ ��������� �����
        if (std::cin.fail()) {
            std::cout << "������ �����! ����������, ������� ����� �����." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // �������� ������������ ��������� ��������
        if (h >= 0 && h < 24 && m >= 0 && m < 60) {
            setTime(h, m);
            isValid = true; // ����� �� ����� ��� ���������� �����
        }
        else {
            std::cout << "������������ �������� �������! ����������, ��������� ����." << std::endl;
        }
    }
}


// ������� ���������
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

// �������������� � int
Time::operator int() const {
    return hours * 60 + minutes;
}

// �������������� � bool
Time::operator bool() const {
    return hours != 0 || minutes != 0;
}

// ��������� ���������
bool Time::operator<(const Time& other) const {
    return (hours * 60 + minutes) < (other.hours * 60 + other.minutes);
}

bool Time::operator>(const Time& other) const {
    return (hours * 60 + minutes) > (other.hours * 60 + other.minutes);
}
