public class LatihanLong {
    public static void main(String args[]) {
        long p = 2147483648L;
        System.out.println(p);
    }
}

/*
 * [] Apa maksud dari pesan error yang muncul?
 * => Pesan error yang muncul adalah sebagai berikut
 * (The literal 2147483648 of type int is out of range)
 * Arti dari pesan error sebagai berikut :
 * "type is out of range" berarti bahwa value tersebut dianggap sebagai integer
 * dimana bukan merupakan tipe data yg diinginkan dan nilai dari value berada di
 * luar batas (di luar batas di sini mungkin diasumsikan sebagai integer)
 * "The literal (value)" berarti bahwa literal adalah tempat di mana terdapat
 * beberapa nilai dalam source code. Setiap kali memberi value secara eksplisit
 * maka itu akan disebut sebagai literal.
 * Jadi, permasalahannya bukan pada deklarasi variabelnya tetapi pada value
 * yg diberikan di mana tidak diberikan akhiran L
 * 
 * [] Bagaimana memperbaiki source code tersebut?
 * => Dengan menambahkan akhiran L pada value tersebut, akhiran L tersebut
 * akan memberi tahu compiler bahwa kita memiliki angka literal dengan tipe
 * data berupa long
 */
