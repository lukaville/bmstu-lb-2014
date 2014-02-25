#include <iostream>
#include <fstream>
#include <string>

#include "main.h"
#include "additional.cpp"

#define STUDENT_ID 23

#define avr(a,b,c) ((a)+(b)+(c))/3

using namespace std;

typedef int* int_ptr;

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
    int int_arr[25] = {int_arr[STUDENT_ID - 1] = 1};
    long long_arr[25] = {int_arr[STUDENT_ID - 1] = 1};
    char char_arr[25] = {int_arr[STUDENT_ID - 1] = 'a'};
    float float_arr[25] = {int_arr[STUDENT_ID - 1] = 0.1};
    double double_arr[25] = {int_arr[STUDENT_ID - 1] = 0.1};
    bool bool_arr[25] = {int_arr[STUDENT_ID - 1] = false};

    /* Print array element */
    cout << int_arr[STUDENT_ID - 1] << endl;

    /* Pointers */
    int* int_pointer = nullptr;
    int a = 5;
    int_pointer = &a;
    int &b = a;
    cout << a << " " << b << " " << int_pointer << endl;

    /* Structures */
    Street tmp_street = {"Ленинский проспект", "Москва", "Измайлово", "Россия"};
    cout << "Steet: " << tmp_street.name  << ", city: " << tmp_street.city << ", district:" << tmp_street.district << "\ncountry: " << tmp_street.country << endl;

    Street streets[] = {tmp_street, tmp_street, tmp_street};

    /* If else statement */
    if (bool_var) {
        cout << "True!";
    } else {
        cout << "False!";
    }

    cout << endl;

    /* Functions */
    vector<int> arr = {2, 1, 3};
    cout << get_min(arr) << endl;
    
    /* Files */
    ofstream text_file;
    text_file.open("chameyev.txt");
    text_file << "Chameyev Nickolay Leonidovich, group IU5-24, variant 23";
    text_file.close();

    string line;
    ifstream read_text_file;
    read_text_file.open("chameyev.txt");
    getline(read_text_file, line);
    cout << line << endl;
    read_text_file.close();

    /* typedef */
    int_ptr ptr = &int_var;

    /* switch */
    switch(3) {
        case 1: cout << "one";
        case 2: cout << "two";
        case 3: cout << "three";
    }

    cout << endl;

    /* macros */
    cout << avr(1,2,3) << endl;

    return 0;
}
