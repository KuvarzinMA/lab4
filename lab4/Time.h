#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    short int hours;
    short int minutes;

public:
    // ������������
    Time();
    Time(short int h, short int m);
    Time(const Time& other);

    // ������
    void setTime(short int h, short int m);

    // �������
    short int getHours() const;
    short int getMinutes() const;

    // ������
    Time subtract(const Time& other) const;
    void inputTime();

    // ���������� ��������� ������
    friend std::ostream& operator<<(std::ostream& os, const Time& time);

    // ���������� ������� ����������
    Time& operator++();    // ���������� ���������
    Time operator++(int);  // ����������� ���������
    Time& operator--();    // ���������� ���������
    Time operator--(int);  // ����������� ���������

    // ���������� �������� ���������� ����
    operator int() const;    // �������������� � int (����� ���������� �����)
    explicit operator bool() const; // �������������� � bool (�������� �� ����)

    // ���������� �������� ���������� ���������
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
};

#endif // TIME_H
