
#include "Car.h"
using namespace std;
// Ctor
// Menginisiasi jenis fuel dengan t_fuel, gear = 0, ac_power = 0 dan on = false.
Car::Car(Fuel t_fuel){
	fuel = t_fuel;
	gear = 0;
	ac_power = 0;
	on = false;
}

// Getter
Fuel Car::getFuel(){
	return fuel;
}
int Car::getGear(){
	return gear;
}
int Car::getAcPower(){
	return ac_power;
}
bool Car::getOn(){
	return on;
}

/* 
	Melakukan isi bensin terhadap mobil
	Melakukan pengecekan jenis bensin masukan apakah sesuai dengan jenis bensin mobil.
	Bila tidak sesuai lakukan throw jenis bensin masukan (t_fuel)
	Bila sesuai, akan menghasilkan keluaran "Berhasil isi bensin sebanyak (nilai amount_in_liter) liter" diakhiri newline dan abaikan tanda '()'
*/
void Car::fillingFuel(Fuel t_fuel, int amount_in_liter){
	if(t_fuel==fuel){
		cout<<"Berhasil isi bensin sebanyak "<<amount_in_liter<<" liter"<<endl;
	}
	else{
		throw t_fuel;
	}
}

/* 
	Melakukan pergantian gigi mobil
	Melakukan pengecekan t_gear sebagai masukan gigi apakah berada pada range MIN_GEAR<=X<=MAX_GEAR.
	Bila tidak sesuai range lakukan throw gigi masukan (t_gear).
	Bila sesuai, akan merubah nilai gear si mobil dan
	menghasilkan keluaran "Berhasil mengubah gigi menjadi gigi (nilai t_gear)" diakhiri newline dan abaikan tanda '()'.
*/
void Car::changeGear(int t_gear){
	if(t_gear<MIN_GEAR || t_gear>MAX_GEAR){
		throw t_gear;
	}
	else{
		gear = t_gear;
		cout<<"Berhasil mengubah gigi menjadi gigi "<<gear<<endl;
	}
}

/* 
	Melakukan pergantian power ac pada mobil
	Melakukan pengecekan t_ac_power sebagai masukan power ac apakah berada pada range MIN_AC<=X<=MAX_AC.
	Bila tidak sesuai range lakukan throw power ac masukan (t_ac_power).
	Bila sesuai, akan merubah nilai ac_power si mobil dan
	menghasilkan keluaran "Berhasil mengubah power ac menjadi (nilai t_ac_power)" diakhiri newline dan abaikan tanda '()'.
*/
void Car::changeAcPower(int t_ac_power){
	if(t_ac_power<MIN_AC || t_ac_power>MAX_AC){
		throw t_ac_power;
	}
	else{
		cout<<"Berhasil mengubah power ac menjadi "<<t_ac_power<<endl;
	}
}

/* 
	Melakukan starter/ menyalakan mobil
	Melakukan pengecekan apakah mobil sudah dalam kondisi menyala atau belum ketika fungsi start dipanggil.
	Bila mobil sudah menyala lakukan throw nilai on mobil.
	Bila mobil belum menyala akan merubah nilai on mobil menjadi true dan
	menghasilkan keluaran "Berhasil melakukan starter mobil" diakhiri newline.
*/
void Car::start(){
	if(on){
		throw on;
	}
	else{
		on = true;
		cout<<"Berhasil melakukan starter mobil"<<endl;
	}
}

/* 
	Melakukan pergantian pengecekan seluruh fitur pada mobil
	Pengecekan fitur dilakukan dengan cara pemanggilan fungsi dengan urutan
	start -> fillingFuel dengan menggunakan parameter masukan pertama dan kedua 
	-> changeGear dengan menggunakan parameter masukan ketiga
	-> changeAcPower dengan menggunakan parameter masukan keempat.
	Implementasikan prosedur ini menggunakan try catch, dengan multiple catch, total tiga jenis catch.
	Catch tipe boolean, akan menghasilkan keluaran "Mobil sudah menyala" diakhiri newline
	Catch tipe integer, akan menghasilkan keluaran "Input angka diluar range" diakhiri newline
	Catch tipe Fuel, akan menghasilkan keluaran "Bensin tidak sesuai" diakhiri newline
*/
void Car::service(Fuel t_fuel, int amount_in_liter, int t_gear, int t_ac_power){
	try{
		start();
		fillingFuel(t_fuel,amount_in_liter);
		changeGear(t_gear);
		changeAcPower(t_ac_power);
	}
	catch(bool b){
		cout<<"Mobil sudah menyala"<<endl;
	}
	catch(int x){
		cout<<"Input angka diluar range"<<endl;
	}
	catch(Fuel F){
		cout<<"Bensin tidak sesuai"<<endl;
	}
}

