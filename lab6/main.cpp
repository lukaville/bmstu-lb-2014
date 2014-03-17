#include <iostream>
#include "coblist.h"
#include "main.h"
#include "virtual_classes.h"

using namespace std;

int main()
{
    Abstr *pAbs;
    Deriv1 d1(11);
    Deriv2 d2(22);
    Deriv3 d3(33);

    cout << endl;

    d1.print();
    d2.print();
    d3.print();

    cout << endl;

    Deriv1* pd1 = &d1;
    Deriv2* pd2 = &d2;
    Deriv3* pd3 = &d3;

    pd1->print();
    pd2->print();
    pd3->print();

    cout << endl;

    pAbs = pd1;
    pAbs->print();

    pAbs = pd2;
    pAbs->print();

    pAbs = pd3;
    pAbs->print();

    cout << endl;

    CObList ListDer;
    for(int i = 0; i < 2; ++i) {
        ListDer.AddTail(new Deriv1(i));
    }

    for(int i = 0; i < 2; ++i) {
        ListDer.AddTail(new Deriv2(i));
    }

    for(int i = 0; i < 2; ++i) {
        ListDer.AddTail(new Deriv3(i));
    }

    cout << "CObList demo:" << endl;
    for(POSITION pos = ListDer.GetHeadPosition(); pos != NULL;) {
        Abstr* a = ((Abstr*) ListDer.GetNext(pos));

        if (a != NULL) {
            a->print();
        }

        cout << endl;
    }

    // Removing second element
    POSITION pos1 = ListDer.GetHeadPosition();
    const int removePosition = 2;
    for(int i = 0; i < removePosition - 1; ++i) {
        ListDer.GetNext(pos1);
    }
    ListDer.RemoveAt(pos1);

    // Print
    cout << "List with one removed element:" << endl;
    for(POSITION pos = ListDer.GetHeadPosition(); pos != NULL;) {
        ((Abstr*) ListDer.GetNext(pos))->print();
        cout << endl;
    }


    // Clear
    for(POSITION pos = ListDer.GetHeadPosition(); pos != NULL;) {
        delete ListDer.GetNext(pos);
    }
    ListDer.RemoveAll();

    // Print
    cout << "Cleared list:" << endl;
    for(POSITION pos = ListDer.GetHeadPosition(); pos != NULL;) {
        Abstr *p = ((Abstr*) ListDer.GetNext(pos));
        p->print();

        cout << endl;
    }

    cout << endl;

    // Virtual classes demo
    L testL(1, 1.234, 2.345, 3.456);
    cout << testL.a << endl;
    cout << testL.b << endl;
    cout << testL.c << endl;
    cout << testL.d << endl;



    return 0;
}
