#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time {
    public:
        //ctor tanpa parameter
        Time();

        //ctor dengan parameter
        Time(int, int, int);

        //cctor
        Time(const Time&);

        //dtor
        ~Time();

        //Setter & Getter
        void setHour(int);
        void setMinute(int);
        void setSecond(int);
        int getHour() const;
        int getMinute() const;
        int getSecond() const;

        //Konversi ke detik
        int convertToSecond();

        //Menuliskan waktu ke layar (format: hh:mm:ss)
        void printTime();

        //Operator Overloading
        Time operator+(const Time&);
        Time operator-(const Time&);
        Time& operator=(const Time&);
        bool operator<(const Time&);
        bool operator>(const Time&);

    private:
        int hour;
        int minute;
        int second;
};

#endif //TIME_H