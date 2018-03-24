#include "Box.h"
using namespace std;

int main(){
    Box* b1 = new Box(2);
    b1->set(0, 99);
    b1->show();
    Box* b2 = new Box(*b1);
    Box* b3 = new Box(2);
    *b3 = *b1;
    b1->set(0,299);
    b1->show();
    b2->show();
    b3->show();
    delete b1;
    delete b3;
    return 0;

}