#ifndef MAIN_H
#define MAIN_H

#include "cobject.h"

class Abstr : public CObject
{
public:
    Abstr() {}
    Abstr(float fPar) {
        std::cout << "Calling constructor abstr..." << std::endl;
        this->fPar = fPar;
    }
    virtual ~Abstr() {
        cout << "~Abstr()" << endl;
    }
    float fPar;
    virtual void print() = 0;
};

class Deriv1 : public Abstr
{
public:
    Deriv1() {}
    Deriv1(float fdPar) {
        this->fDPar = fdPar;
    }
    virtual ~Deriv1() {
        cout << "~Deriv1()" << endl;
    }
    float fDPar;
    virtual void print() {
        std::cout << "fPar = " << fPar << std::endl;
        std::cout << "fDPar = " << fDPar << std::endl;
    }
};

class Deriv2 : public Deriv1
{
public:
    Deriv2() {}
    Deriv2(float fdPar) {
        this->fDPar = fdPar;
    }
    virtual ~Deriv2() {
        cout << "~Deriv2()" << endl;
    }
    float fDPar;
    virtual void print() {
        std::cout << "fPar = " << fPar << std::endl;
        std::cout << "fDPar = " << fDPar << std::endl;
    }
};

class Deriv3 : public Deriv1
{
public:
    Deriv3() {}
    Deriv3(float fdPar) {
        this->fDPar = fdPar;
    }
    virtual ~Deriv3() {
        cout << "~Deriv3()" << endl;
    }
    float fDPar;
    virtual void print() {
        std::cout << "fPar = " << fPar << std::endl;
        std::cout << "fDPar = " << fDPar << std::endl;
    }
};


#endif // MAIN_H
