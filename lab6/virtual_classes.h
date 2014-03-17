#ifndef VIRTUAL_CLASSES_H
#define VIRTUAL_CLASSES_H

class I {
public:
        I(){ a = 0; }
        I(float x){ a = x; }
        float a;
};

class J : virtual public I {
public:
        J(){ b = 0; }
        J(float x, float y) : I(y) { b = x; }
        float b;
};

class K : virtual public I {
public:
        K(){ c = 0; }
        K(float x, float y) : I(y) { c = x; }
        float c;
};

class L : public J, public K {
public:
        L(){ d = 0; }
        L(float x, float y, float z, float w) : I(w), J(y, w), K(z, w) { d = x; }
        float d;
};

#endif // VIRTUAL_CLASSES_H
