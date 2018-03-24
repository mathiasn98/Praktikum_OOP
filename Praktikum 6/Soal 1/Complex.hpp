#ifndef COMPLEX_HPP
#define COMPLEX_HPP

using namespace std;
template <class Type>
class Complex {
	public:
		// ctor
		// inisialisasi real dan imaginer dengan 0
		Complex(){
			real = 0;
			imaginer = 0;
		}
		// inisialisasi real dengan paramater pertama dan imaginer dengan parameter kedua
		Complex(Type t1, Type t2){
			real = t1;
			imaginer = t2;
		}
		
		// Getter, Setter
		Type getReal() const{
			return real;
		}
		Type getImaginer() const{
			return imaginer;
		}
		void setReal(Type t1){
			real = t1;
		}
		void setImaginer(Type t1){
			imaginer = t1;
		}

		Complex operator +(Complex const &comp) const{
			Type re,im;
			re = real+comp.real;
			im = imaginer + comp.imaginer;
			return Complex(re,im);
		}
		Complex operator -(Complex const &comp) const{
			Type re,im;
			re = real-comp.real;
			im = imaginer - comp.imaginer;
			return Complex(re,im);
		}
		Complex operator *(Complex const &comp) const{
			Type re,im;
			re = real*comp.real-imaginer*comp.imaginer;
			im = real*comp.imaginer + imaginer * comp.real;
			return Complex(re,im);
		}
		Complex& operator +=(const Complex& comp){
			real = real+comp.real;
			imaginer = imaginer + comp.imaginer;
			return *this;
		}
		Complex& operator -=(const Complex& comp){
			real = real-comp.real;
			imaginer = imaginer - comp.imaginer;
			return *this;
		}
		Complex& operator *=(const Complex& comp){
			real = real*comp.real-imaginer*comp.imaginer;
			imaginer = real*comp.imaginer + imaginer * comp.real;
			return *this;
		}

	private: 
		Type real, imaginer;
};

#endif
