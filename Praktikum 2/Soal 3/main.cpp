#include "A.hpp"
int main() {
    A x('1');
    A y('2');
    A z = x;
    //x = y;
    z = y;
    y.show();
    return 0;
}