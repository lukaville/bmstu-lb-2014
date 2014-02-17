#include <iostream>
#include <iomanip>
#include "circle.h"

using namespace std;

char* get_info(void);

extern int integer_additional_var;

double get_random_double();

int main()
{
    /* Input and output standart types */
    int int_var;
    cout << "Введите int_var: ";
    cin >> int_var;
    cout << "Введено int_var = " << int_var << endl << endl;

    double double_var;
    cout << "Введите double_var: ";
    cin >> double_var;
    cout << "Введено double_var = " << double_var << endl << endl;

    char chars_var[100];
    cout << "Введите chars_var: ";
    cin >> chars_var;
    cout << "Введено chars_var = " << chars_var << endl << endl;

    /* Stream formatting */
    cout.width(20);
    cout << chars_var << " - width(20)" << endl;

    cout.width(20);
    cout.fill('*');
    cout << chars_var << " - fill('*')" << endl;

    cout.width(30);
    cout.fill('!');
    cout << chars_var << " - width(30), fill('!')" << endl;

    cout << "До precision double_var = " << double_var << endl;
    cout.precision(2);
    cout << "После  cout.precision(2) double_var = " << double_var << endl;

    /* Manipulators */
    cout << "hex int_val = " << hex << int_var << endl;
    cout << "dec int_val = " << dec << int_var << endl;
    cout << "oct int_val = " << oct << int_var << endl;

    cout.setf(ios_base::hex);
    cout << "Повторно после вызова cout.setf(ios_base::hex) int_val = " << int_var << endl;
    cout.unsetf(ios_base::hex);
    cout << "Повторно после вызова cout.unsetf(ios_base::hex) int_val = " << int_var << endl << endl;

    cout << "setbase(16) для 16 = " << setbase(16) << 16 << endl;
    cout << "setbase(10) для 16 = " << setbase(10) << 16 << endl;
    cout << "setbase(8) для 16 = " << setbase(8) << 16 << endl << endl;

    cout << "f = " << 5.2111 << " = " << scientific << 5.2111 << fixed << endl << endl;

    cout << "Для 12 hex - " << hex << showbase << 12 << endl;
    cout << "Для 12 oct - " << oct << showbase << 12 << endl;
    cout << "Для 12 dec - " << dec << showbase << 12 << endl << endl;

    cout << "До setprecision(8) - " << 5.21110010 << endl;
    cout << "После setprecision(8) - " << setprecision(8) << 5.21110010 << endl << endl;

    cout.width(80); cout << left << chars_var << left << endl;
    cout.width(80); cout << right << chars_var << right << endl << endl;

    cout << get_info() << endl << endl;

    cout << "integer_additional_var = " << integer_additional_var << endl << endl;

    cout << "get_random_double() = " << get_random_double() << endl << endl;

    Circle c1(1,2,3);
    cout << c1;

    return 0;
}
