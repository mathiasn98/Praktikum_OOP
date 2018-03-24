#include "Bike.h"
#include "Car.h"
#include "Vehicle.h"
using namespace std;

int main(){
    Vehicle V1(3,2);
    Vehicle V2(V1);
    Vehicle V3(6,50);
    Car C1(8);
    Car C2(C1);
    Car C3(6);
    Bike B1;
    C3.drive();
    B1.show();
    B1.ride();
}