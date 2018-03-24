public class Time {
    private int hour;
    private int minute;
    private int second;

    public Time() {
        hour = 0;
        minute = 0;
        second = 0;
        // Set seluruh atribut dengan nilai 0
    }

    public Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public Time(Time t) {
        this.hour = t.hour;
        this.minute = t.minute;
        this.second = t.second;
        // Set atribut dengan atribut milik t
    }

    public int getHour() {
        return hour;

    }

    public void setHour(int hour) {
        this.hour = hour;
    }

    public int getMinute() {
        return minute;
    }

    public void setMinute(int minute) {
        this.minute = minute;
    }

    public int getSecond() {   
        return second;
    }

    public void setSecond(int second) {
        this.second = second;
    }

    public int convertToSecond() {
        return hour*3600+minute*60+second;
    }

    public Time add(Time t) {
        Time tTemp = new Time();
        int hasilSmt;
        hasilSmt = (this.convertToSecond() + t.convertToSecond())%86400;
        tTemp.hour = hasilSmt/3600;
        hasilSmt = hasilSmt % 3600;
        tTemp.minute = hasilSmt/60;
        tTemp.second = hasilSmt%60;
        return tTemp;
        // Return penjumlahan dua objek jam, yaitu *this* dan t.
        // Apabila hasil penjumlahan melebihi 23:59:59, maka Anda harus mengonversinya seperti tampilan jam digital asli.
        // Contoh : 24:00:00 dituliskan 00:00:00, 25:00:00 dituliskan 01:00:00, dst.
    }

    public Time minus(Time t) {
        Time tTemp = new Time();
        int hasilSmt;
        if(this.convertToSecond() >= t.convertToSecond()){
            hasilSmt = this.convertToSecond()-t.convertToSecond();
        }
        else{
            return (new Time(this));
        }
        tTemp.hour = hasilSmt/3600;
        hasilSmt = hasilSmt % 3600;
        tTemp.minute = hasilSmt/60;
        tTemp.second = hasilSmt%60;
        return tTemp;
        // Return selisih antara dua objek jam, yaitu *this* dan t.
        // Perhitungan selisih hanya dapat dilakukan jika objek ruas kiri lebih akhir dari atau sama dengan objek ruas kanan.
        // Jika objek ruas kiri lebih awal, maka kembalikan nilai objek ruas kiri.
        // Contoh: 00:00:01 - 00:00:02 = 00:00:01
    }

    public boolean lessThan(Time t) {
        if(this.convertToSecond() < t.convertToSecond()){
            return true;
        }
        else{
            return false;
        }
        // Returns true jika *this* < t menurut definisi waktu
    }

    public boolean greaterThan(Time t) {
         if(this.convertToSecond() > t.convertToSecond()){
            return true;
        }
        else{
            return false;
        }
        // Returns true jika *this* > t menurut definisi waktu
    }

    public void printTime() {
        if(hour<10){
            System.out.print(0);
        }
        System.out.print(hour+":");
        if(minute<10){
            System.out.print(0);
        }
        System.out.print(minute+":");
        if(second<10){
            System.out.print(0);
        }
        System.out.println(second);
        
        // Menuliskan jam dalam format hh:mm:ss diakhiri dengan newline. Perhatikan bahwa setiap parameter harus dituliskan 2 digit.
    }
}
