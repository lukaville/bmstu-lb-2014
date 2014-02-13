#include <iostream>

using namespace std;

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

    return 0;
}
