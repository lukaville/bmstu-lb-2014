#include <iostream>
#define STUDENT_NUMBER 23

using namespace std;

int main()
{
    /* Variable initialization */
    int int_var = 0;
    long long_var = 0;
    char char_var = 'a';
    float float_var = 0.1;
    double double_var = 0.1;
    bool bool_var = false;

    /* Array initialization */
    int int_arr[25] = {int_arr[STUDENT_NUMBER - 1] = 1};
    long long_arr[25] = {int_arr[STUDENT_NUMBER - 1] = 1};
    char char_arr[25] = {int_arr[STUDENT_NUMBER - 1] = 'a'};
    float float_arr[25] = {int_arr[STUDENT_NUMBER - 1] = 0.1};
    double double_arr[25] = {int_arr[STUDENT_NUMBER - 1] = 0.1};
    bool bool_arr[25] = {int_arr[STUDENT_NUMBER - 1] = false};

    /* Print array element */
    cout << int_arr[STUDENT_NUMBER - 1] << endl;

    /* Pointers */
    int* int_pointer = nullptr;
    int a = 5;
    int_pointer = &a;
    int &b = a;
    cout << a << " " << b << " " << int_pointer;

    return 0;
}
