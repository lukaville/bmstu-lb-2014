#ifndef MAIN_H
#define MAIN_H

int maximum(int a = 0, int b = 0, int c = 0) {
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


#endif // MAIN_H
