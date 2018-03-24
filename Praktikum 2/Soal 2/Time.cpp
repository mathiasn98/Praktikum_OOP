#include "Time.h"

//ctor tanpa parameter
Time::Time(){
    hour = 0;
    minute = 0;
    second = 0;
}

//ctor dengan parameter
Time::Time(int h, int m, int s){
    hour = h;
    minute = m;
    second = s;
}

//cctor
Time::Time(const Time& t){
    hour = t.hour;
    minute = t.minute;
    second = t.second;
}

//dtor
Time::~Time(){

}

//Setter & Getter
void Time::setHour(int h){
    hour = h;
}
void Time::setMinute(int m){
    minute = m;
}
void Time::setSecond(int s){
    second = s;
}
int Time::getHour() const{
    return hour;
}
int Time::getMinute() const{
    return minute;
}
int Time::getSecond() const{
    return second;
}

//Konversi ke detik
int Time::convertToSecond(){
    return hour*3600+minute*60+second;
}

//Menuliskan waktu ke layar (format: hh:mm:ss)
void Time::printTime(){
    printf("%.2d:%.2d:%.2d\n",hour,minute,second);
}

//Operator Overloading
Time Time::operator+(const Time& t1){
    int totalSecond;
    Time t = t1;
    totalSecond = (this->convertToSecond() + t.convertToSecond()) % 86400;
    return Time(totalSecond/3600,(totalSecond%3600)/60,totalSecond%60);
}
Time Time::operator-(const Time& t1){
    int totalSecond;
    Time t = t1;
    if(t.convertToSecond() > this->convertToSecond()){
        return Time(hour,minute,second);
    }
    else{
        totalSecond = (this->convertToSecond() - t.convertToSecond()) % 86400;
        return Time(totalSecond/3600,(totalSecond%3600)/60,totalSecond%60);
    }
    
}
Time& Time::operator=(const Time& t){
    hour = t.hour;
    minute = t.minute;
    second = t.second;
    return *this;
}
bool Time::operator<(const Time& t1){
    Time t = t1;
    return (this->convertToSecond() < t.convertToSecond());
}
bool Time::operator>(const Time& t1){
    Time t = t1;
    return (this->convertToSecond() > t.convertToSecond());
}
