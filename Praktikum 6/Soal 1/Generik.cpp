#include <iostream>

using namespace std;
template <class Type>
void print(Type t1){
	if(sizeof(t1)==1){
		cout<<"Masukan SPECIAL anda : "<<t1<<endl;
	}
	else{
		cout<<"Masukan anda : "<<t1<<endl;
	}
	
} 

template <class Type1, int t2>
void print(Type1 t1){
	for(int i=0;i<t2;i++){
		cout<<"Masukan anda : "<<t1<<endl;
	}
}

template <class Type1, class Type2>
void print(Type1 t1, Type2 t2){
	cout<<"Masukan anda : "<<t1<<" dan "<<t2<<endl;
}

