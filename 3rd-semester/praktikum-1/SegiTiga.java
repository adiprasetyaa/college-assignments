public class SegiTiga {
    int alas = 3;
    int tinggi = 4;
    int sisiMiring = 5;

    public Double hitungLuas() {
        double luas = 0.5 * this.alas * this.tinggi;
        return luas;
    }

    public Double hitungKeliling() {
        double keliling = this.alas + this.tinggi + this.sisiMiring;
        return keliling;
    }

    /**
     * main method
     */
    public static void main(String[] args) {
        SegiTiga segiTiga = new SegiTiga();
        System.out.println("alas : " + segiTiga.alas);
        System.out.println("tinggi : " + segiTiga.tinggi);
        System.out.println("sisi miring : " + segiTiga.sisiMiring);
        System.out.println("Luas segitiga : " + segiTiga.hitungLuas());
        // tambahkan code untuk menampilkan keliling segitiga
        System.out.println("Keliling segitiga : " + segiTiga.hitungKeliling());
    }
}
