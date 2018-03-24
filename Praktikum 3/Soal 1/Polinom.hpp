// Polinom.hpp
#ifndef POLINOM_HPP
#define POLINOM_HPP

class Polinom {
  public:
    // ctor, cctor, dtor, op=
    // untuk konstruktor, inisialisasi seluruh nilai koefisien dengan 0.
    Polinom();    // ctor Polinom dengan orde = 0
    Polinom(int); // ctor Polinom dengan orde = n (sesuai parameter)
    Polinom(const Polinom&);
    ~Polinom();
    Polinom& operator=(const Polinom&);

    // getter, setter
    int getKoefAt(int idx) const;
    int getDerajat() const;
    void setKoefAt(int idx, int val);
    void setDerajat(int);
    
    // operator overloading
    // Untuk setiap operator, **tidak perlu mengubah nilai derajat tertinggi**
    // Orde Polinom hasil operasi adalah MAX(orde Polinom 1, orde Polinom 2)
    friend Polinom operator+(const Polinom&, const Polinom&); // Penjumlahan 2 buah Polinom.
    friend Polinom operator-(const Polinom&, const Polinom&); // Pengurangan 2 buah Polinom.
    friend Polinom operator*(const Polinom&, const int); // Perkalian Polinom dengan konstanta
    friend Polinom operator*(const int, const Polinom&); // Perkalian Polinom dengan konstanta (sifat komutatif)
    friend Polinom operator/(const Polinom&, const int); // Pembagian bilangan bulat. Tidak perlu menangani apabila kasus pembagi = 0.

    // member function
    // Melakukan pembacaan koefisien sejumlah derajat Polinom, dimulai dari x^0 (konstanta)
    void input();

    // Mencetak seluruh koefisien polinom. Untuk setiap koefisien akhiri dengan end-of-line
    // Cetaklah apa adanya dari koefisien ke-0 hingga derajat tertinggi (termasuk apabila koefisien = 0)
    void printKoef();

    // Menghitung hasil substitusi x dengan sebuah bilangan ke dalam polinom
    int substitute(int);

    // Melakukan aksi derivasi terhadap Polinom.
    // Lakukan pengurangan pada derajat tertinggi Polinom. 
    // Apabila derajat tertinggi = 0, hasil derivasi = 0 (dengan derajat tertinggi = 0)
    Polinom derive();

    // ** METHOD BONUS (TC 12,13,14) ** (Tidak wajib dikerjakan)
    // Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst (diakhiri dengan end-of-line)
    // Apabila suatu koefisien bernilai < 0, gunakan tanda "-" untuk menggantikan tanda "+"
    // Apabila suatu koefisien bernilai 0, lewati koefisien tersebut dan lanjutkan ke koefisien selanjutnya
    // Jika seluruh koefisien bernilai 0, keluarkan "0"
    void print();

  private:
    const static int MAX_LENGTH = 20;
    int koef[MAX_LENGTH];
    int derajat; // derajat tertinggi
};

#endif