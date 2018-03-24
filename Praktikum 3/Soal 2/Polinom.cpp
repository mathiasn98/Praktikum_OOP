#include "Polinom.hpp"
#include <iostream>
#include <math.h>
using namespace std;

// ctor, cctor, dtor, op=
// untuk konstruktor, inisialisasi seluruh nilai koefisien dengan 0.
Polinom::Polinom(){
    koef = new int[20];
    for(int i =0;i<20;i++){
        koef[i] = 0;
    }
    derajat = 0;
}    // ctor Polinom dengan orde = 0
Polinom::Polinom(int _derajat){
    koef = new int[_derajat+1];
    for(int i=0;i<=_derajat;i++){
        koef[i] = 0;
    }
    derajat = _derajat;
    } // ctor Polinom dengan orde = n (sesuai parameter)
Polinom::Polinom(const Polinom& P){
    koef = new int[P.derajat+1];
    for(int i = 0; i <= P.derajat; i++){
        koef[i] = P.koef[i];
    }
    derajat = P.derajat;
}
Polinom::~Polinom(){
    delete koef;
}
Polinom& Polinom::operator=(const Polinom& P){
    if(P.derajat > derajat){
        koef = new int[P.derajat+1];
        derajat = P.derajat;
    }
    for(int i = 0;i<=derajat;i++){
        koef[i] = P.koef[i];
    }
    return *this;
}

// getter, setter
int Polinom::getKoefAt(int idx) const{return koef[idx];}
int Polinom::getDerajat() const{return derajat;}
void Polinom::setKoefAt(int idx, int val){koef[idx] = val;}
void Polinom::setDerajat(int _derajat){derajat = _derajat;}

// member function
// Melakukan pembacaan koefisien sejumlah derajat Polinom, dimulai dari x^0 (konstanta)
void Polinom::input(){
    for(int i = 0;i<=derajat;i++){
        cin>>koef[i];
    }
}

// Mencetak seluruh koefisien polinom. Untuk setiap koefisien akhiri dengan end-of-line
// Cetaklah apa adanya dari koefisien ke-0 hingga derajat tertinggi (termasuk apabila koefisien = 0)
void Polinom::printKoef(){
    for(int i = 0 ;i<=derajat;i++){
        cout<<koef[i];
        cout<<endl;
    }
}

// Menghitung hasil substitusi x dengan sebuah bilangan ke dalam polinom
int Polinom::substitute(int x){
    int sum = 0;
    for(int i = 0;i<=derajat;i++){
        sum += koef[i]*pow(x,i);
    }
    return sum;
}

// ** METHOD BONUS (TC 8,9,10) ** (Tidak wajib dikerjakan)
// Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst (diakhiri dengan end-of-line)
// Apabila suatu koefisien bernilai < 0, gunakan tanda "-" untuk menggantikan tanda "+"
// Apabila suatu koefisien bernilai 0, lewati koefisien tersebut dan lanjutkan ke koefisien selanjutnya
// Jika seluruh koefisien bernilai 0, keluarkan "0"
void Polinom::print(){
    bool allZero = true;
    for(int i = 0;i<=derajat;i++){
        if(koef[i]!=0){
            allZero = false;
            break;
        }
    }
    if(allZero){
        cout<<"0"<<endl;
    }
    else{
        cout<<koef[0];
        for(int i = 1;i<=derajat;i++){
            if(koef[i]>0){
                cout<<'+';
            }
            if(koef[i]!=0){
                cout<<koef[i];
                cout<<"x^";
                cout<<i;
            }
        }
        cout<<endl;
    }
}
