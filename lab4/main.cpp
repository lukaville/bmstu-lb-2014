#include <iostream>

#define max_of_three(a, b, c) (( a > b)?(( a > c)? a : c):((b >  c) ? b : c))

using namespace std;

template<typename T>
void swap(T* p1, T* p2)
{
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

template<typename T, int size>
T multiplyArray(T* array) {
    T result = 1;

    for(int i = 0; i < size; ++i) {
        result *= array[i];
    }

    return result;
}

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
    cout << "Произведение float_arr = " << multiplyArray<float, 4>(float_arr) << endl;

    // Class template with one argument


    return 0;
}

