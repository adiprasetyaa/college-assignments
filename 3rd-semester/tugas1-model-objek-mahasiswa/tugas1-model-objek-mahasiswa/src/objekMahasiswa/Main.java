package objekMahasiswa;
import java.lang.String;
import java.util.*;

class Mahasiswa{
    //atribut dari class mahasiswa
    public String NIM;
    public String namaLengkap;
    public String jenisKelamin;
    public String alamat;

    //method untuk pengisian data
    void IsiData(){
        Scanner inputUser = new Scanner(System.in);
        System.out.print("\n[Data Mahasiswa]\n");
        System.out.print("Nama\t\t\t: ");
        this.namaLengkap = inputUser.nextLine();
        System.out.print("NIM\t\t\t\t: ");
        this.NIM = inputUser.nextLine();
        System.out.print("Jenis Kelamin\t: ");
        this.jenisKelamin = inputUser.nextLine();
        System.out.print("Alamat\t\t\t: ");
        this.alamat = inputUser.nextLine();
    }

    //method untuk menampilkan data yang sudah diisi
    void PrintData() {
        System.out.println("\n[Data Mahasiswa]");
        System.out.printf("Nama\t\t\t\t: %s\n", this.namaLengkap);
        System.out.printf("NIM\t\t\t\t\t: %s\n", this.NIM);
        System.out.printf("Jenis Kelamin\t\t: %s\n", this.jenisKelamin);
        System.out.printf("Alamat\t\t\t\t: %s\n", this.alamat);

    }
}

public class Main {

    public static void main(String[] args){

        Mahasiswa mahasiswa = new Mahasiswa();

        mahasiswa.IsiData();
        mahasiswa.PrintData();

    }
}