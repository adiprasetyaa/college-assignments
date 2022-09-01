public class Kubus {
    int sisiKubus = 5;

    public double hitungVolume() {
        double volume = 0.0;
        // code untuk menghitung volume kubus
        volume = this.sisiKubus * this.sisiKubus * this.sisiKubus;
        return volume;
    }

    public int hitungLuasPermukaan() {
        int luasPermukaan = 0;
        // code untuk menghitung luas permukaan kubus
        luasPermukaan = (6) * (this.sisiKubus * this.sisiKubus);
        return luasPermukaan;
    }

    /**
     * buat main method
     * buat objek dari class Kubus
     * tampilkan hasil perhitungan volume kubus
     * tampilkan hasil perhitungan luas permukaan kubus
     */
    public static void main(String[] args) {

        Kubus kubus = new Kubus(); // objek dari class kubus

        System.out.println("===========================================");
        System.out.println("          HASIL PERHITUNGAN KUBUS         ");
        System.out.println("-------------------------------------------");
        System.out.printf("Volume Kubus           : %.2f\n", kubus.hitungVolume()); // menampilkan volume
        System.out.printf("Luas Permukaan Kubus   : %d\n", kubus.hitungLuasPermukaan()); // menampilkan luas permukaan
        System.out.println("===========================================");

    }
}
