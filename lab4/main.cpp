#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    Time t1;
    cout << "���� ������� �������:\n";
    t1.inputTime();

    Time t2;
    cout << "���� ������� �������:\n";
    t2.inputTime();

    cout << "\n����� t1: " << t1 << endl;
    cout << "����� t2: " << t2 << endl;

    // ������������ ������� ����������
    cout << "\n��������� ������� t1: " << ++t1 << endl;
    cout << "��������� ������� t1: " << --t1 << endl;

    // ������������ ���������� ����������
    int minutesT1 = t1;
    cout << "\n����� t1 � �������: " << minutesT1 << endl;
    cout << "����� t1 �� ����� ����: " << (bool(t1) ? "true" : "false") << endl;

    // ������������ ���������� ���������
    cout << "\n��������� ������� t1 � t2:" << endl;
    cout << "t1 < t2: " << (t1 < t2 ? "true" : "false") << endl;
    cout << "t1 > t2: " << (t1 > t2 ? "true" : "false") << endl;

    // ������������ ������ ���������
    Time result = t1.subtract(t2);
    cout << "\n��������� ��������� t2 �� t1: " << result << endl;

    return 0;
}
