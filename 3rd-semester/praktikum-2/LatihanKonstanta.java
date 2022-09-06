public class LatihanKonstanta {
    public static final int KURS_DOLLAR = 15000;
    public static final double PI = 3.14;
    public static final String NAMA = "Squidward";

    public static void main(String args[]) {
        // KURS_DOLLAR = 13500;
        System.out.println(KURS_DOLLAR);
        System.out.println(PI);
        System.out.println(NAMA);
    }
}

/*
 * [] Apa yang salah dengan source code tersebut?
 * => karena terjadi penginisialisasian ulang (mengubah value) pada variabel
 * KURS_DOLLAR dalam main function,sedangkan variabel KURS_DOLLAR pada class
 * LatihanKonstanta sudah berupa final sehingga tidak diperkenankan untuk
 * melakukan perubahan value dari variabel KURS_DOLLAR di function main maupun
 * di function lainnya.
 * [] Apa maksud penggunaan keyword static sebelum keyword final pada deklarasi
 * variabel tersebut?
 * => Saat sebuah variabel dideklarasikan sebagai static variable, maka satu
 * salinan variabel dibuat dan dibagikan di antara semua objek di dalam class.
 * Variabel statis pada dasarnya adalah variabel global. Variabel static
 * disimpan dalam static memory.
 */
