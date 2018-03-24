#include <iostream>

using namespace std;

class A {
	public:
		A(string nm) {name = nm;} 
	protected:
		string name;
};

class B : public A {
	public:
		B(string nm) : A(nm) {};
};

class C : public B {
	public:
		C(string nm, string milik) : B(nm) {pemilik = milik;}
		void print() {cout << name << " " << pemilik << endl;}
	private:
		string pemilik;
};