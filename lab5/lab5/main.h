#ifndef MAIN_H
#define MAIN_H

int maximum(int a = 0, int b = 0, int c = 0) {
    return ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
}

#endif // MAIN_H
