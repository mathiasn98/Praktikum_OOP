public class Time {
    private int hour;
    private int minute;
    private int second;

    public Time() {
        // Set seluruh atribut dengan nilai 0
    }

    public Time(int hour, int minute, int second) {

    }

    public Time(Time t) {
        // Set atribut dengan atribut milik t
    }

    public int getHour() {

    }

    public void setHour(int hour) {

    }

    public int getMinute() {

    }

    public void setMinute(int minute) {

    }

    public int getSecond() {

    }

    public void setSecond(int second) {

    }

    public int convertToSecond() {

    }

    public Time add(Time t) {
        // Return penjumlahan dua objek jam, yaitu *this* dan t.
        // Apabila hasil penjumlahan melebihi 23:59:59, maka Anda harus mengonversinya seperti tampilan jam digital asli.
        // Contoh : 24:00:00 dituliskan 00:00:00, 25:00:00 dituliskan 01:00:00, dst.
    }

    public Time minus(Time t) {
        // Return selisih antara dua objek jam, yaitu *this* dan t.
        // Perhitungan selisih hanya dapat dilakukan jika objek ruas kiri lebih akhir dari atau sama dengan objek ruas kanan.
        // Jika objek ruas kiri lebih awal, maka kembalikan nilai objek ruas kiri.
        // Contoh: 00:00:01 - 00:00:02 = 00:00:01
    }

    public boolean lessThan(Time t) {
        // Returns true jika *this* < t menurut definisi waktu
    }

    public boolean greaterThan(Time t) {
        // Returns true jika *this* > t menurut definisi waktu
    }

    public void printTime() {
        // Menuliskan jam dalam format hh:mm:ss diakhiri dengan newline. Perhatikan bahwa setiap parameter harus dituliskan 2 digit.
    }
}