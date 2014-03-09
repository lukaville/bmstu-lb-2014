#include <iostream>
#include "cpoint.h"
#include "line.h"
#include "longline.h"

#include <vector>

#define max_of_three(a, b, c) (( a > b)?(( a > c)? a : c):((b >  c) ? b : c))

using namespace std;

template<typename T>
void swap(T* p1, T* p2)
{
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

template<typename T>
void foo() {
    cout << "foo()" << endl;
}

template<>
void foo<int>() {
    cout << "foo<int>()" << endl;
}

template<typename T, int size>
T multiplyArray(T* array) {
    T result = 1;

    for(int i = 0; i < size; ++i) {
        result *= array[i];
    }

    return result;
}

typedef Line<int> IntLine;

int main()
{
    // Using macros max of three
    int v0 = 0;
    int v1 = 1;
    double v2 = 1.1;
    double v3 = 3.6;
    const int v4 = 5.1;
    const double v5 = 6.9;

    cout << max_of_three(v1, v2, v3) << endl;
    cout << max_of_three(v2, v3, v4) << endl;
    cout << max_of_three(v3, v4, v5) << endl;

    // Swap
    int* x = &v0;
    int* y = &v1;

    double* d1 = &v2;
    double* d2 = &v3;

    cout << "Целый тип:" << endl;
    cout << "До Swap: x = " << *x << " y = " << *y << endl;
    swap<int>(x, y);
    cout << "После Swap:  x = " << *x << " y = " << *y << endl;
    cout << "Вещественный тип:" << endl;
    cout << "До Swap: d1 = " << *d1 << " d2 = " << *d2 << endl;
    swap<double>(d1, d2);
    cout << "После Swap:  d1 = " << *d1 << " d2 = " << *d2 << endl;

    // Array multiplication
    int* int_arr = new int[10];
    double* double_arr = new double[10];
    float* float_arr = new float[10];

    for(int i = 0; i < 4; ++i) {
        int_arr[i] = 2 * (i + 1);
        double_arr[i] = 2.1 * (i + 1);
        float_arr[i] = 2.4 * (i + 1);
    }

    cout << "Произведение int_arr = " << multiplyArray<int, 4>(int_arr) << endl;
    cout << "Произведение double_arr = " << multiplyArray<double, 4>(double_arr) << endl;
    cout << "Произведение float_arr = " << multiplyArray<float, 4>(float_arr) << endl << endl;

    // Class template with one argument
    Line<int> line1(CPoint<int>(1,2), CPoint<int>(3,4));
    cout << "Линия int:" << endl;
    line1.print(); cout << endl;

    Line<float> line2(CPoint<float>(6.2,1.2), CPoint<float>(9.1,42.3));
    cout << "Линия float:" << endl;
    line2.print(); cout << endl;

    Line<double> line3(CPoint<double>(5.5,9.1), CPoint<double>(8.1,2.2));
    cout << "Линия double:" << endl;
    line3.print(); cout << endl << endl;

    // Class template with three arguments
    Line<int, 3> line4(CPoint<int>(1,2), CPoint<int>(3,4));
    cout << "Линия int с начальной закраской:" << endl;
    line4.print(); cout << endl;

    Line<float, 8> line5(CPoint<float>(6.2,1.2), CPoint<float>(9.1,42.3));
    cout << "Линия float с начальной закраской:" << endl;
    line5.print(); cout << endl;

    Line<double, 2> line6(CPoint<double>(5.5,9.1), CPoint<double>(8.1,2.2));
    cout << "Линия double с начальной закраской:" << endl;
    line6.print(); cout << endl << endl;

    // Declaration of move method outside class
    Line<long, 8> line7(CPoint<long>(65,2), CPoint<long>(4,42));
    line7.move(3, 3);
    cout << "Линия long с начальной закраской:" << endl;
    line7.print(); cout << endl << endl;

    // Inheritance
    LongLine line8(CPoint<long>(65,2), CPoint<long>(4,42), 3, 4, 5);
    cout << "Линия LongLine с начальной закраской:" << endl;
    line8.print(); cout << endl << endl;

    // Typedef demo
    IntLine line9(CPoint<int>(65,2), CPoint<int>(4,42));
    line9.move(3, 3);
    cout << "Линия на основе typedef (int):" << endl;
    line9.print(); cout << endl << endl;

    // STL demo
    vector<Line<int>> vectorOfLines;
    vectorOfLines.push_back(line1);
    vectorOfLines.push_back(line1);
    vectorOfLines.push_back(line1);

    for(auto line : vectorOfLines) {
        line.print();
    }

    // Function template specification
    cout << endl;
    foo<double>();
    foo<float>();
    foo<int>();

    return 0;
}

