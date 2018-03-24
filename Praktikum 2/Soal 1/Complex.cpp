#include "Complex.h"
Complex::Complex(){
    real = 0;
    imaginer = 0;
}
Complex::Complex(int re, int im){
    real = re;
    imaginer = im;
}
Complex::Complex(const Complex &comp){
    real = comp.real;
    imaginer = comp.imaginer;
}
Complex::~Complex(){

}
/*void Complex::printStatus(){
    cout<<"Real = "<<real<<" Imaginary = "<<imaginer<<endl;
}*/
int Complex::getReal(){
    return real;
}
int Complex::getImaginer(){
    return imaginer;
}
void Complex::setReal(int re){
    real = re;
}
void Complex::setImaginer(int im){
    imaginer = im;
}

Complex Complex::operator + (Complex const &comp){
    int re,im;
    re = real+comp.real;
    im = imaginer + comp.imaginer;
    return Complex(re,im);
}
Complex Complex::operator - (Complex const &comp){
    int re,im;
    re = real-comp.real;
    im = imaginer - comp.imaginer;
    return Complex(re,im);

}
Complex Complex::operator * (Complex const &comp){
    int re,im;
    re = real*comp.real-imaginer*comp.imaginer;
    im = real*comp.imaginer + imaginer * comp.real;
    return Complex(re,im);

}

