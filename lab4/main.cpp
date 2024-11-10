#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    Time t1;
    cout << "Ввод первого времени:\n";
    t1.inputTime();

    Time t2;
    cout << "Ввод второго времени:\n";
    t2.inputTime();

    cout << "\nВремя t1: " << t1 << endl;
    cout << "Время t2: " << t2 << endl;

    // Тестирование унарных операторов
    cout << "\nИнкремент времени t1: " << ++t1 << endl;
    cout << "Декремент времени t1: " << --t1 << endl;

    // Тестирование операторов приведения
    int minutesT1 = t1;
    cout << "\nВремя t1 в минутах: " << minutesT1 << endl;
    cout << "Время t1 не равно нулю: " << (bool(t1) ? "true" : "false") << endl;

    // Тестирование операторов сравнения
    cout << "\nСравнение времени t1 и t2:" << endl;
    cout << "t1 < t2: " << (t1 < t2 ? "true" : "false") << endl;
    cout << "t1 > t2: " << (t1 > t2 ? "true" : "false") << endl;

    // Тестирование метода вычитания
    Time result = t1.subtract(t2);
    cout << "\nРезультат вычитания t2 из t1: " << result << endl;

    return 0;
}
