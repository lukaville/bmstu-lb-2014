#include <iostream>

#define max_of_three(a, b, c) (( a > b)?(( a > c)? a : c):((b >  c) ? b : c))

using namespace std;

int main()
{
    // Using macros max of three
    int v1 = 1;
    double v2 = 1.1;
    double v3 = 3.6;
    const int v4 = 5.1;
    const double v5 = 6.9;

    cout << max_of_three(v1, v2, v3) << endl;
    cout << max_of_three(v2, v3, v4) << endl;
    cout << max_of_three(v3, v4, v5) << endl;

    return 0;
}

