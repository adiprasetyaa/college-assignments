public class Mahasiswa {
    String nim, nama, alamat;
    char jenisKelamin;

    // buatlah constructor untuk menginisiasi nilai dari variabel
    // nim, nama, jenisKelamin, alamat
    
    //Ini adalah constructor (selalu dieksekusi pertama kali saat program berjalan)
    Mahasiswa(String nim, String nama, char jenisKelamin, String alamat) {
        this.nim = nim;
        this.nama = nama;
        this.alamat = alamat;
        this.jenisKelamin = jenisKelamin;
    }

   //Method untuk menampilkan data
    public void displayData() {
        System.out.println("[MENAMPILKAN DATA MAHASISWA]");
        System.out.println("NIM              : " + this.nim);
        System.out.println("Nama             : " + this.nama);
        System.out.println("Jenis Kelamin    : " + this.jenisKelamin);
        System.out.println("Alamat           : " + this.alamat);
    }

    public static void main(String[] args) {
        
      //Membuat objek
        Mahasiswa mhs = new Mahasiswa("M0501001", "Patrick Star", 'L', "Bikini Bottom");

       //memanggil method untuk menampilkan data
        mhs.displayData();
    }
}
