#include "BunchOfKeys.hpp"
#include <iostream>

BunchOfKeys::BunchOfKeys(){}
void BunchOfKeys::add(){
	n_keys++;
}
void BunchOfKeys::shake(){
	if(n_keys<=1){
		std::cout<<"Tidak terjadi apa-apa"<<std::endl;
	}
	else{
		for(int i=0;i<n_keys;i++){
			std::cout<<"krincing"<<std::endl;
		}
	}
	
}
