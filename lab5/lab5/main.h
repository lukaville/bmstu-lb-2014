#ifndef MAIN_H
#define MAIN_H

int q = 0;

int maximum(int a = q, int b = 0, int c = 0) {
    return ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
}

int maximum1(int a, int b, int c) {
    return ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
}

int maximum1(int a, int b) {
    int c = 0;
    return ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
}

int maximum1(int a) {
    int b = 0;
    int c = 0;
    return ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
}

int maximum1() {
    int a = 0;
    int b = 0;
    int c = 0;
    return ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
}

int test(int b = 11) {
    b = 99;
    return b;
}

int multiply(int a, int b, int c) {
    return a * b * c;
}

double multiply(double a, double b, double c) {
    return a * b * c;
}

char multiply(char a, char b, char c) {
    return a * b * c;
}

int multiply(int a, int b) {
    return a * b;
}

char multiply(char a, char b) {
    return a * b;
}

double multiply(double a, double b) {
    return a * b;
}

double multiply(double a, double b, double c = 1.3) {
    return a * b * c;
}


#endif // MAIN_H
