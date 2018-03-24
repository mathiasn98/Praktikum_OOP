#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

class Complex {
	public:
		Complex();
		Complex(int re, int im);
		Complex(const Complex &comp);
		~Complex();
		
		int getReal();
		int getImaginer();
		void setReal(int re);
		void setImaginer(int im);

		Complex operator + (Complex const &comp);
		Complex operator - (Complex const &comp);
		Complex operator * (Complex const &comp);

	private: 
		int real, imaginer;
};

#endif