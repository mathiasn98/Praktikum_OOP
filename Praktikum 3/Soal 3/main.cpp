#include "Box.h"
using namespace std;

int main(){
    Box b1(2);
    b1.set(0, 99);
    b1.show();
    Box b2(b1);
    Box b3(2);
    b3 = b1;
    b1.set(0,299);
    b1.show();
    b2.show();
    b3.show();
    return 0;

}