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

    return 0;
}

