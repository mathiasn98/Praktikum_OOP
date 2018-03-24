#include <iostream>
using namespace std;

class Hewan{
    public:
        Hewan(string _nama){
            nama = _nama;
        }
        ~Hewan(){
            cout<<"Hewan mati "<<nama<<endl;
        }
        virtual void print(){
            cout<<"Hewan ini namanya "<<nama<<endl;
        }
    protected:
        string nama;

};

class Anjing : public Hewan{
    public:
        Anjing(string _nama): Hewan::Hewan(_nama){}
        ~Anjing(){
            cout<<"Anjing mati "<<nama<<endl;
        }
        void print(){
            cout<<"Anjing ini namanya "<<nama<<endl;
        }
    private:

};

class Kucing : public Hewan{
    public:
        Kucing(string _nama): Hewan::Hewan(_nama){}
        virtual ~Kucing(){
            cout<<"Kucing mati "<<nama<<endl;
        }
        /*void print(){
            cout<<"Kucing ini namanya "<<nama<<endl;
        }*/
    private:

};

class AnjingBulldog : public Anjing{
    public:
        AnjingBulldog(string _nama, string _pemilik): Anjing::Anjing(_nama)
        {
            pemilik = _pemilik;
        }
        virtual ~AnjingBulldog(){
            cout<<"Anjing bulldog mati "<<nama<<endl;
        }
        void print(){
            cout<<"Anjing bulldog ini namanya "<<nama<<". "<<"Pemiliknya adalah "<<pemilik<<endl;
        }
        
    protected:
        string pemilik;
};

class KucingAnggora:public Kucing{
    public:
        KucingAnggora(string _nama, string _pemilik):Kucing::Kucing(_nama){
            pemilik = _pemilik;
        }
        ~KucingAnggora(){
            cout<<"Kucing anggora mati "<<nama<<endl;
        }
        void print(){
            cout<<"Kucing anggora ini namanya "<<nama<<". "<<"Pemiliknya adalah "<<pemilik<<endl;
        }
    protected:
        string pemilik;
};