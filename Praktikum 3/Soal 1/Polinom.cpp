// Polinom.hpp
#include "Polinom.hpp"
#include <iostream>
#include <math.h>
using namespace std;
#define MAX_L 20
// ctor, cctor, dtor, op=
// untuk konstruktor, inisialisasi seluruh nilai koefisien dengan 0.
Polinom::Polinom(){
    derajat = 0;
    for(int i=0;i<MAX_L;i++){
        koef[i] = 0;
    }
}    // ctor Polinom dengan orde = 0
Polinom::Polinom(int _derajat){
    derajat = _derajat;
    for(int i=0;i<MAX_L;i++){
        koef[i] = 0;
    }
} // ctor Polinom dengan orde = n (sesuai parameter)
Polinom::Polinom(const Polinom& P){
    derajat = P.derajat;
    for(int i = 0;i<=MAX_LENGTH;i++){
        koef[i] = P.koef[i];
    }
}
Polinom::~Polinom(){}
Polinom& Polinom::operator=(const Polinom& P){
    derajat = P.derajat;
    for(int i = 0;i<=MAX_LENGTH;i++){
        koef[i] = P.koef[i];
    }
    return *this;
}

// getter, setter
int Polinom::getKoefAt(int idx) const{return koef[idx];}
int Polinom::getDerajat() const{return derajat;}
void Polinom::setKoefAt(int idx, int val){koef[idx]=val;}
void Polinom::setDerajat(int _derajat){derajat = _derajat;}

// operator overloading
// Untuk setiap operator, **tidak perlu mengubah nilai derajat tertinggi**
// Orde Polinom hasil operasi adalah MAX(orde Polinom 1, orde Polinom 2)
Polinom operator+(const Polinom& P1, const Polinom& P2){
    Polinom P;
    if(P1.derajat>P2.derajat){
        P.derajat = P1.derajat;
    }
    else{
        P.derajat = P2.derajat;
    }
    for(int i = 0; i<MAX_L;i++){
        P.koef[i] = P1.koef[i] + P2.koef[i];
    }
    return P;
} // Penjumlahan 2 buah Polinom.
Polinom operator-(const Polinom& P1, const Polinom& P2){
    Polinom P;
    if(P1.derajat>P2.derajat){
        P.derajat = P1.derajat;
    }
    else{
        P.derajat = P2.derajat;
    }
    for(int i = 0; i<MAX_L;i++){
        P.koef[i] = P1.koef[i] - P2.koef[i];
    }
    return P;
} // Pengurangan 2 buah Polinom.
Polinom operator*(const Polinom& P1, const int k){
    Polinom P(P1);
    for(int i=0;i<MAX_L;i++){
        P.koef[i] *= k;
    }
    return P;
} // Perkalian Polinom dengan konstanta
Polinom operator*(const int k, const Polinom& P1){
    Polinom P(P1);
    for(int i=0;i<MAX_L;i++){
        P.koef[i] *= k;
    }
    return P;
} // Perkalian Polinom dengan konstanta (sifat komutatif)
Polinom operator/(const Polinom& P1, const int k){
    Polinom P(P1);
    for(int i=0;i<MAX_L;i++){
        P.koef[i] /= k;
    }
    return P;
} // Pembagian bilangan bulat. Tidak perlu menangani apabila kasus pembagi = 0.

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
    for(int i=0;i<=derajat;i++){
        cout<<koef[i]<<endl;
    }
}

// Menghitung hasil substitusi x dengan sebuah bilangan ke dalam polinom
int Polinom::substitute(int x){
    int sum = 0;
    for(int i=0;i<=derajat;i++){
        sum += koef[i]*pow(x,i);
    }
    return sum;
}

// Melakukan aksi derivasi terhadap Polinom.
// Lakukan pengurangan pada derajat tertinggi Polinom. 
// Apabila derajat tertinggi = 0, hasil derivasi = 0 (dengan derajat tertinggi = 0)
Polinom Polinom::derive(){
    Polinom P(*this);
    for(int i=0;i<MAX_L;i++){
        P.koef[i] = P.koef[i+1]*(i+1);
    }
    return P;
}

// ** METHOD BONUS (TC 12,13,14) ** (Tidak wajib dikerjakan)
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

