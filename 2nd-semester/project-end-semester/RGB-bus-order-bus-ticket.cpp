#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

map<string, string> Armada;

void MenuUtama();          // Fungsi untuk menampilkan menu utama
void ListTerminal();       // Function untuk menampilkan List Kota dari Terminal yang tersedia
void KetersediaanArmada(); // Function untuk mengecek ketersediaan armada berdasarkan rute
void EstimasiWaktu();      // Function untuk menghitung estimasi waktu perjalanan
int CariKota();            // Function untuk mencari kota dari terminal berdasarkan keyword
void BeliTiket();          // Function untuk membeli tiket bus
string find(string);
void merge(string, string);
void garistipis(); // function untuk mencetak garis [------]
void garistebal(); // function untuk mencetak garis [======]
int find_kota(const vector<string> &array, string, int, int);

// struct untuk menyimpan variabel dan data dari Tiket Bus
struct TiketBus
{
    string rute_perjalanan;
    string armada;
    int harga_tiket;
};

// Enumerasi untuk menginisialiasasi Nama Kota sebagai integer
enum terminal
{
    Serang,
    Jakarta,
    Bandung,
    Semarang,
    Solo,
    Yogyakarta,
    Malang,
    Surabaya,
    Jumlah_terminal
};

int main()
{
    MenuUtama(); // Memanggil Menu Utama

    return 0;
}

// Function MenuUtama() yang berfungsi untuk menampilkan pilihan-pilihan pada menu utama
void MenuUtama()
{

    cout << "===========================================================" << endl;
    cout << "|                                                         |" << endl;
    cout << "|                                                         |" << endl;
    cout << "|                           RGB BUS                       |" << endl;
    cout << "|                  APLIKASI PESAN TIKET BUS               |" << endl;
    cout << "|                                                         |" << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
    cout << "|                       [MENU UTAMA]                      |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "| 1) Ketersediaan Kota Awal dan Kota Tujuan               |" << endl;
    cout << "| 2) Estimasi Waktu Tempuh                                |" << endl;
    cout << "| 3) Ketersediaan Armada Transportasi Berdasarkan Rute    |" << endl;
    cout << "| 4) Beli Tiket dan Layanan Tambahan                      |" << endl;
    cout << "| 5) Exit                                                 |" << endl;
    cout << "===========================================================" << endl;

    int input_user;
    cout << ">> Masukkan Pilihan Anda : ";
    cin >> input_user;

    while (1) // Infinite Loop dan memanggil function berdasarkan input dari user
    {
        if (input_user == 1)
        {
            CariKota();
            break;
        }
        else if (input_user == 2)
        {
            system("cls");
            EstimasiWaktu();
            break;
        }
        else if (input_user == 3)
        {
            system("cls");
            KetersediaanArmada();
            break;
        }
        else if (input_user == 4)
        {
            system("cls");
            BeliTiket();
            break;
        }
        else if (input_user == 5)
        {
            exit(0);
        }
    }
}

// Function yang berisi List Kota dari Terminal-Terminal yang rutenya tersedia
void ListTerminal()
{

    cout << "===========================================================" << endl;
    cout << "|                   ESTIMASI WAKTU TEMPUH                 |" << endl;
    cout << "===========================================================" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "|            TERMINAL TUJUAN SEBAGAI BERIKUT             |" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "| 0. | Serang" << endl;
    cout << "| 1. | Jakarta" << endl;
    cout << "| 2. | Bandung" << endl;
    cout << "| 3. | Semarang" << endl;
    cout << "| 4. | Solo" << endl;
    cout << "| 5. | Yogyakarta" << endl;
    cout << "| 6. | Malang" << endl;
    cout << "| 7. | Surabaya" << endl;
    cout << "===========================================================" << endl;
}

// Function untuk menghitung estimasi waktu ketika perjalanan,
// contohnya dari kota A ke kota B, lalu dari kota B ke kota C dan seterusnya
void EstimasiWaktu()
{
    int waktu_tempuh[Jumlah_terminal][Jumlah_terminal];

    // Semua diinisialisasi dengan value (-1) secara default
    // Value (-1) menunjukan sebagai berikut :
    // 1) Tidak ada jalur langsung di antara kedua terminal
    // 2) Kedua terminal tidak terhubung

    for (int i = 0; i < Jumlah_terminal; i++)
    {
        for (int j = 0; j < Jumlah_terminal; j++)
        {

            waktu_tempuh[i][j] = -1;
        }
    }

    // Pemberian value 0 karena merupakan jarak ke dirinya sendiri
    for (int i = 0; i < Jumlah_terminal; i++)
    {
        for (int j = 0; j < Jumlah_terminal; j++)
        {

            if (i == j)
            {
                waktu_tempuh[i][j] = 0;
            }
        }
    }

    cout << "\n\n\n";

    // adjacency matrix
    // Memberikan nilai yang diambil dari jarak di antara kedua terminal [kota]
    waktu_tempuh[Serang][Jakarta] = 2;
    waktu_tempuh[Jakarta][Serang] = 2;

    waktu_tempuh[Serang][Bandung] = 4;
    waktu_tempuh[Bandung][Serang] = 4;

    waktu_tempuh[Jakarta][Bandung] = 2;
    waktu_tempuh[Bandung][Jakarta] = 2;

    waktu_tempuh[Jakarta][Semarang] = 5;
    waktu_tempuh[Semarang][Bandung] = 5;

    waktu_tempuh[Bandung][Solo] = 7;
    waktu_tempuh[Solo][Bandung] = 7;

    waktu_tempuh[Bandung][Yogyakarta] = 8;
    waktu_tempuh[Yogyakarta][Bandung] = 8;

    waktu_tempuh[Solo][Semarang] = 1;
    waktu_tempuh[Semarang][Solo] = 1;

    waktu_tempuh[Solo][Yogyakarta] = 2;
    waktu_tempuh[Yogyakarta][Solo] = 2;

    waktu_tempuh[Solo][Malang] = 4;
    waktu_tempuh[Malang][Solo] = 4;

    waktu_tempuh[Yogyakarta][Malang] = 6;
    waktu_tempuh[Malang][Yogyakarta] = 6;

    waktu_tempuh[Malang][Semarang] = 5;
    waktu_tempuh[Semarang][Malang] = 5;

    waktu_tempuh[Semarang][Surabaya] = 4;
    waktu_tempuh[Surabaya][Semarang] = 4;

    waktu_tempuh[Malang][Surabaya] = 2;
    waktu_tempuh[Surabaya][Malang] = 2;

    int total_waktu = 0;
    int titik_awal = -1;

    while (1)
    {
        int terminal_awal, terminal_selanjutnya;
        int tambah_tujuan;

        ListTerminal(); // Memanggil function ListTerminal() untuk menampilkan List Kota dari Terminal

        if (titik_awal == -1)
        {
            // Jika terminal awal belum tersedia, maka user memasukkan input terminal awal
            cout << "[History terminal awal tidak ada!]" << endl;
            cout << ">> Terminal Awal atau Sebelumnya\t: ";
            cin >> titik_awal;
            terminal_awal = titik_awal;
        }
        else
        {
            // Jika terminal awal sudah tersedia, maka langsung digunakan untuk terminal awal - terminal selanjutnya
            cout << ">> Terminal Sebelumnya \t\t\t: " << terminal_awal << endl;
        }

        cout << ">> Terminal selanjutnya\t\t\t: ";
        cin >> terminal_selanjutnya;

        // Memasukkan terminal selanjutnya yang valid
        if (waktu_tempuh[terminal_awal][terminal_selanjutnya] != -1 && waktu_tempuh[terminal_awal][terminal_selanjutnya] != 0)
        {
            total_waktu = total_waktu + waktu_tempuh[terminal_awal][terminal_selanjutnya];
            terminal_awal = terminal_selanjutnya;
        }

        // Jika terminal awal dan selanjutnya berjarak (-1) atau (0) maka invalid
        else if (waktu_tempuh[terminal_awal][terminal_selanjutnya] == -1 || waktu_tempuh[terminal_awal][terminal_selanjutnya] == 0)
        {
            cout << "!! Jalur tidak tersedia, silakan pilih jalur lainnya!\n\n";
        }

        // Memberikan option lanjut ke kota berikutnya atau tidak
        // jika lanjut, maka user akan menginputkan kota tujuan lagi
        // jika berhenti, maka akan keluar dari looping
        cout << "-----------------------------------------------------------" << endl;
        cout << "| 1) Lanjut ke Kota Berikutnya | 2) Berhenti              |" << endl;
        cin >> tambah_tujuan;

        if (tambah_tujuan == 2)
        {
            break;
        }

        else
        {
            system("cls");
        }
    }

    // Mencetak estimasi waktu tempuh berdasarkan perjalanan user
    if (total_waktu != 0)
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << ">> Total Estimasi Waktu (jam)\t: " << total_waktu << " jam perjalanan\t" << endl;
        cout << "-----------------------------------------------------------" << endl;
    }
    else
    {
        cout << "          !! Kota yang anda masukkan invalid !!            " << endl;
    }

    // Memberikan beberapa pilihan opsi
    // jika [1], maka user akan diminta memasukkan input kota awal dan kota tujuan lagi dan memanggil function EstimasiWaktu()
    // jika [2], maka akan kembali ke menu utama dan memanggil function MenuUtama()
    // jika [3] atau random angka, maka program akan berhenti (exit)
    cout << "1) Cek Estimasi Waktu | 2) Kembali Ke Menu | 3) Exit Program |" << endl;
    int input;
    cout << ">> ";
    cin >> input;

    if (input == 1)
    {
        system("cls");
        EstimasiWaktu(); // memanggil function EstimasiWaktu() & Memasukkan input kota awal dan tujuan lagi
    }
    else if (input == 2)
    {
        system("cls");
        MenuUtama(); // Memanggil function MenuUtama() & Kembali ke Menu Awal
    }

    else if (input == 3)
    {
        exit(0); // Memberhentikan program
    }

    else
    {
        exit(0); // memberhentikan program
    }
}

// Menggunakan Algoritma Binary Search Tree
// Digunakakan untuk mencari kota yang termasuk dalam rute bus
// Misalnya mengecek apakah ada rute yang melewati kota SOLO
int CariKota()
{

    std::vector<std::string> keyword_kota;

    // Memasukkan Kota-kota yang dilewati oleh RUte BUs
    // semua nama harus sudah terurut
    keyword_kota.push_back("BANDUNG");
    keyword_kota.push_back("JAKARTA");
    keyword_kota.push_back("MALANG");
    keyword_kota.push_back("SEMARANG");
    keyword_kota.push_back("SERANG");
    keyword_kota.push_back("SOLO");
    keyword_kota.push_back("SURABAYA");

    string cari;
    cout << "-----------------------------------------------------------\n";
    cout << "!! Masukkan Nama Kota dari Terminal Tujuan [CAPSLOCK] !!" << endl;
    while (1)
    {

        cout << ">> Kota dari Terminal Awal/Tujuan : ";
        cin >> cari; // Memasukkan input berupa nama Kota dengan CAPSLOCK

        int indeks = find_kota(keyword_kota, cari, 0, keyword_kota.size() - 1); // memanggil function find_kota()

        if (indeks != -1)
        {
            // Rute tersedia atau dilewati oleh Bus
            cout << "  [" << cari << " Tersedia dalam Rute Perjalanan Kami]" << std::endl;
        }
        else
        {
            // Rute tidak tersedia atau tidak dilewati oleh Bus
            cout << "  [" << cari << " Tidak Tersedia dalam Rute Perjalanan Kami]" << std::endl;
        }

        garistipis();                                                               // print garis
        cout << "1) Cek Kembali | 2) Kembali Ke Menu | 3) Exit Program  |" << endl; // memberikan pilihan untuk user
        garistipis();                                                               // print garis

        int input;
        cout << ">> ";
        cin >> input;

        if (input == 1) // Jika input 1, maka memanggil function CariKota() dan mencari kota lagi
        {
            system("cls");
            CariKota();
        }

        else if (input == 2) // JIka input 2, maka kembali ke menu utama dengan memanggil function MenuUtama()
        {

            system("cls");
            MenuUtama();
        }

        else if (input == 3)
        {

            exit(0); // Keluar dari program
        }

        else
        {
            exit(0); // Keluar dari Program
        }
    }

    system("cls");

    return 0;
}

// Function untuk melakukan searching dengan cari membandingkan
int find_kota(const vector<std::string> &array, string target, int batas_kiri, int batas_kanan)
{
    if (batas_kiri > batas_kanan)
    {
        return -1;
    }

    int tengah = (batas_kiri + batas_kanan) / 2;
    string pembanding = array[tengah];

    if (target < pembanding)
    {
        return find_kota(array, target, batas_kiri, tengah - 1);
    }
    if (target > pembanding)
    {
        return find_kota(array, target, tengah + 1, batas_kanan);
    }

    return tengah;
}

// Function untuk melakukan rekursif
// Function yang berguna untuk menemukan perwakilan armada dari rute tertentu
// Merupakan bagian "find" dalam algoritma "union-find"
string find(string x)
{

    if (Armada[x] == x)
    {
        return x;
    }

    return find(Armada[x]);
}

// Function untuk melakukan merge pada disjoint set
// Digunakan untuk menjalin hubungan antara rute A dan rute B
// merupakan bagian "union" dalam algoritma "union-find"
void merge(string x, string y)
{

    string ArmadaX = find(x);
    string ArmadaY = find(y);

    Armada[x] = ArmadaY;
}

// Function untuk mengecek ketersediaan armada berdasarkan rute yang dipilih
// Setiap rute diwakili oleh satu armada Bus dan dilakukan dengan data struktur berupa disjoint set
void KetersediaanArmada()
{

    Armada["RI"] = "RI";               // Parents untuk rute yg dilalui Armada Rosalia Indah (RI)
    Armada["PRIMADONA"] = "PRIMADONA"; // Parents untuk rute yang dilalui oleh Armada Primadona(PRIMADONA)
    Armada["BORLINDO"] = "BORLINDO";   // Parents untuk group rute yang dilalui oleh Armada Bus Borlindo(BORLINDO)
    Armada["HARYANTO"] = "HARYANTO";   // Parents untuk group rute yang dilalui oleh Armada Haryanto (HARYANTO)

    // Rute untuk rute yg dilalui Armada Bus Primadona (PRIMADONA)
    Armada["SRG-BDG"] = "SRG-BDG";
    Armada["BDG-SRG"] = "BDG-SRG";

    Armada["BDG-DIY"] = "BDG-DIY";
    Armada["DIY-BDG"] = "DIY-BDG";

    // Rute untuk rute yg dilalui Armada Bus Borlindo (BORLINDO)
    Armada["MLG-SMG"] = "MLG-SMG";
    Armada["SMG-MLG"] = "SMG-MLG";

    Armada["MLG-SBY"] = "MLG-SBY";
    Armada["SBY-MLG"] = "SBY-MLG";

    Armada["DIY-MLG"] = "DIY-MLG";
    Armada["MLG-DIY"] = "MLG-DIY";

    // Rute untuk rute yg dilalui Armada Bus Haryanto (HARYANTO)
    Armada["SRG-JKT"] = "SRG-JKT";
    Armada["JKT-SRG"] = "JKT-SRG";

    Armada["JKT-SMG"] = "JKT-SMG";
    Armada["SMG-JKT"] = "SMG-JKT";

    Armada["SMG-SBY"] = "SMG-SBY";
    Armada["SBY-SMG"] = "SBY-SMG";

    // Rute untuk rute yg dilalui Armada Bus Rosalia Indah (RI)
    Armada["JKT-BDG"] = "JKT-BDG";
    Armada["BDG-JKT"] = "BDG-JKT";

    Armada["BDG-SOLO"] = "BDG-SOLO";
    Armada["SOLO-BDG"] = "SOLO-BDG";

    Armada["SOLO-SMG"] = "SOLO-SMG";
    Armada["SMG-SOLO"] = "SMG-SOLO";

    Armada["SOLO-MLG"] = "SOLO-MLG";
    Armada["MLG-SOLO"] = "MLG-SOLO";

    Armada["SOLO-DIY"] = "SOLO-DIY";
    Armada["DIY-SOLO"] = "DIY-SOLO";

    // merge untuk rute yg dilalui Armada Bus Primadona (PRIMADONA)
    // Rute-rute diwakili oleh oleh Armada dengan disjoint set
    merge("PRIMADONA", "SRG-BDG"); // Rute SRG-BDG diwakili oleh ARMADA PRIMADONA
    merge("SRG-BDG", "BDG-SRG");   // Rute BDG-SRG diwakili oleh rute SRG-BDG
    merge("BDG-SRG", "BDG-DIY");   // Rute BDG-DIY diwakili oleh rute BDG-SRG
    merge("BDG-DIY", "DIY-BDG");   // Rute DIY-BDG diwakili oleh rute BDG-DIY
    // Cara ini juga berlaku untuk merge-merge selanjutnya

    // merge untuk rute yg dilalui Armada Bus Borlindo (BORLINDO)
    merge("BORLINDO", "DIY-MLG");
    merge("DIY-MLG", "MLG-DIY");
    merge("MLG-DIY", "MLG-SBY");
    merge("MLG-SBY", "SBY-MLG");
    merge("SBY-MLG", "MLG-SMG");
    merge("MLG-SMG", "SMG-MLG");

    // merge untuk rute yg dilalui Armada Bus Haryanto (HARYANTO)
    merge("HARYANTO", "SRG-JKT");
    merge("SRG-JKT", "JKT-SRG");
    merge("JKT-SRG", "JKT-SMG");
    merge("JKT-SMG", "SMG-JKT");
    merge("SMG-JKT", "SMG-SBY");
    merge("SMG-SBY", "SBY-SMG");

    // merge untuk rute yg dilalui Armada Bus Rosalia Indah (RI)
    merge("RI", "JKT-BDG");
    merge("JKT-BDG", "BDG-JKT");
    merge("BDG-JKT", "BDG-SOLO");
    merge("BDG-SOLO", "SOLO-BDG");
    merge("SOLO-BDG", "SOLO-SMG");
    merge("SOLO-SMG", "SMG-SOLO");
    merge("SMG-SOLO", "SOLO-DIY");
    merge("SOLO-DIY", "DIY-SOLO");
    merge("DIY-SOLO", "SOLO-MLG");
    merge("SOLO-MLG", "MLG-SOLO");

    while (1)
    {

        string tujuan;

        cout << "===========================================================" << endl;
        cout << "|                                                         |" << endl;
        cout << "|                   KETERSEDIAAN ARMADA BUS               |" << endl;
        cout << "|                                                         |" << endl;
        cout << "===========================================================\n";
        cout << "|                   Kota Asal - Kota Tujuan               |" << endl;
        cout << "-----------------------------------------------------------\n";
        cout << "1) SRG-JKT" << endl;  // Serang-Jakarta
        cout << "2) SRG-BDG" << endl;  // Serang-Bandung
        cout << "3) BDG-JKT" << endl;  // Bandung-Jakarta
        cout << "4) BDG-DIY" << endl;  // Bandung-Yogyakarta
        cout << "5) BDG-SOLO" << endl; // Bandung-Solo
        cout << "6) JKT-SMG" << endl;  // Jakarta-Semarang
        cout << "7) SOLO-SMG" << endl; // Solo-Semarang
        cout << "8) SOLO-MLG" << endl; // Solo-Malang
        cout << "9) SOLO-DIY" << endl; // Solo-Yogyakarta
        cout << "10) DIY-MLG" << endl; // Yogyakarta-Malang
        cout << "11) MLG-SBY" << endl; // Malang-Surabaya
        cout << "12) MLG-SMG" << endl; // Malang-Semarang
        cout << "13) SMG-SBY" << endl; // Semarang - Surabaya
        cout << "-----------------------------------------------------------" << endl;
        cout << "|             >> Rute di atas berlaku sebaliknya <<       |" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "                      [!! Keterangan !!]                   " << endl;
        cout << "1) SRG  = Serang\n2) JKT  = Jakarta\n3) BDG  = Bandung\n4) DIY  = Yogayakarta\n5) SOLO = Surakarta\n6) SMG  = Semarang\n7) SBY  = Surabaya" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "|            Format Input = KOTAASAL-KOTATUJUAN           |" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << ">> Masukkan Kota Asal dan Kota Tujuan : " << endl; // User memasukkan kota asal dan tujuan sesuai dengan format pada List di atas
        cout << ">> ";
        cin >> tujuan;
        cout << "-----------------------------------------------------------" << endl;

        if (find(tujuan) == find("RI")) // melakukan pengecekan hingga ke parents dengan fungsi rekursif dari find()
        {
            cout << ">> Rute dari " << tujuan << " yang tersedia : [ROSALIA INDAH]" << endl;
        }

        else if (find(tujuan) == find("PRIMADONA")) // melakukan pengecekan hingga ke parents dengan fungsi rekursif dari find()
        {
            cout << ">> Rute dari " << tujuan << " yang tersedia : [PRIMADONA]" << endl;
        }

        else if (find(tujuan) == find("BORLINDO")) // melakukan pengecekan hingga ke parents dengan fungsi rekursif dari find()
        {
            cout << ">> Rute dari " << tujuan << " yang tersedia : [BORLINDO]" << endl;
        }

        else if (find(tujuan) == find("HARYANTO")) // melakukan pengecekan hingga ke parents dengan fungsi rekursif dari find()
        {
            cout << ">> Rute " << tujuan << " yang tersedia : [HARYANTO]" << endl;
        }

        else
        { // Jika user salah memasukkan input, maka diintruksikan untuk mencoba lagi
            cout << "|    !! MOHON MAAF INPUT YANG ANDA MASUKKAN SALAH !!      |" << endl;
            cout << "|                  !! SILAKAN COBA LAGI !!                |\n";
        }

        garistipis(); // cetak garis ---
        cout << "1) Cek Armada  | 2) Kembali Ke Menu  | 3) Exit Program    |" << endl;
        garistipis(); // cetak garis ---
        int input;
        cout << ">> ";
        cin >> input;

        if (input == 1) // Melakukan clearscreen dan memanggil function KetersediaanArmada()
        {
            system("cls");
            KetersediaanArmada();
        }
        else if (input == 2) // Melakukan clearscreen dan memanggil function MenuUtama()
        {
            system("cls");
            MenuUtama();
        }

        else if (input == 3)
        {
            exit(0); // Memberhentikan Program
        }

        else
        {
            exit(0); // memberhentikan program
        }
    }
}

void BeliTiket()
{

    map<string, TiketBus> data_Tiket; // Mendeklarasikan string ke struct TiketBus
    TiketBus Tiket;

    string kode_tiket;
    int total_payment = 0;

    // Mencetak Kode, Rute, Armada, dan Harga agar bisa dilihat oleh user
    cout << "===========================================================" << endl;
    cout << "|                                                         |" << endl;
    cout << "|                      RGB BUS : TICKET SHOP              |" << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "|                      TICKET BUS                         |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "| KODE  |  RUTE PERJALANAN  |       ARMADA      |  HARGA  |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "| [001] | Serang-Jakarta    |      Haryanto     |  75000  |" << endl;
    cout << "| [002] | Serang-Bandung    |     Primadona     | 100000  |" << endl;
    cout << "| [003] | Bandung-Jakarta   |   Rosalia Indah   |  80000  |" << endl;
    cout << "| [004] | Bandung-Jogja     |     Primadona     | 250000  |" << endl;
    cout << "| [005] | Bandung-Solo      |   Rosalia Indah   | 225000  |" << endl;
    cout << "| [006] | Jakarta-Semarang  |      Haryanto     | 150000  |" << endl;
    cout << "| [007] | Solo-Semarang     |   Rosalia Indah   |  60000  |" << endl;
    cout << "| [008] | Solo-Malang       |   Rosalia Indah   | 275000  |" << endl;
    cout << "| [009] | Solo-Jogja        |   Rosalia Indah   |  50000  |" << endl;
    cout << "| [010] | Jogja-Malang      |     Borlindo      | 300000  |" << endl;
    cout << "| [011] | Malang-Surabaya   |     Borlindo      | 125000  |" << endl;
    cout << "| [012] | Malang-Semarang   |     Borlindo      | 175000  |" << endl;
    cout << "| [013] | Semarang-Surabaya |     Haryanto      | 150000  |" << endl;
    cout << "-----------------------------------------------------------" << endl;

    // Mengaitkan TiketBus dengan indeks berdasarkan data di atas
    // Dengan Obyek Struct pada map data_tiket
    Tiket.rute_perjalanan = "[Serang - Jakarta]|[Jakarta - Serang]";
    Tiket.armada = "HARYANTO";
    Tiket.harga_tiket = 75000;
    data_Tiket["001"] = Tiket;

    Tiket.rute_perjalanan = "[Serang - Bandung]|[Bandung - Serang]";
    Tiket.armada = "PRIMADONA";
    Tiket.harga_tiket = 100000;
    data_Tiket["002"] = Tiket;

    Tiket.rute_perjalanan = "[Jakarta - Bandung]|[Bandung - Jakarta]";
    Tiket.armada = "ROSALIA INDAH";
    Tiket.harga_tiket = 80000;
    data_Tiket["003"] = Tiket;

    Tiket.rute_perjalanan = "[Bandung - Jogja]|[Jogja - Bandung]";
    Tiket.armada = "PRIMADONA";
    Tiket.harga_tiket = 250000;
    data_Tiket["004"] = Tiket;

    Tiket.rute_perjalanan = "[Bandung - Solo]|[Solo - Bandung]";
    Tiket.armada = "ROSALIA INDAH";
    Tiket.harga_tiket = 225000;
    data_Tiket["005"] = Tiket;

    Tiket.rute_perjalanan = "[Jakarta-Semarang]|[Semarang-Jakarta]";
    Tiket.armada = "HARYANTO";
    Tiket.harga_tiket = 150000;
    data_Tiket["006"] = Tiket;

    Tiket.rute_perjalanan = "[Solo-Semarang]|[Semarang-Solo]";
    Tiket.armada = "ROSALIA INDAH";
    Tiket.harga_tiket = 60000;
    data_Tiket["007"] = Tiket;

    Tiket.rute_perjalanan = "[Solo-Malang]|[Malang - Solo]";
    Tiket.armada = "ROSALIA INDAH";
    Tiket.harga_tiket = 275000;
    data_Tiket["008"] = Tiket;

    Tiket.rute_perjalanan = "[Solo - Jogja]|[Jogja - Solo]";
    Tiket.armada = "ROSALIA INDAH";
    Tiket.harga_tiket = 50000;
    data_Tiket["009"] = Tiket;

    Tiket.rute_perjalanan = "[Jogja-Malang]|[Malang-Jogja]";
    Tiket.armada = "BORLINDO";
    Tiket.harga_tiket = 300000;
    data_Tiket["010"] = Tiket;

    Tiket.rute_perjalanan = "[Malang-Surabaya]|[Surabaya-Malang]";
    Tiket.armada = "BORLINDO";
    Tiket.harga_tiket = 125000;
    data_Tiket["011"] = Tiket;

    Tiket.rute_perjalanan = "[Malang - Semarang]|[Semarang - Malang]";
    Tiket.armada = "BORLINDO";
    Tiket.harga_tiket = 175000;
    data_Tiket["012"] = Tiket;

    Tiket.rute_perjalanan = "[Semarang - Surabaya]|[Surabaya - Semarang]";
    Tiket.armada = "HARYANTO";
    Tiket.harga_tiket = 150000;
    data_Tiket["013"] = Tiket;

    int jumlah_tiket;
    string nama_pembeli;

    cout << "-----------------------------------------------------------" << endl;
    cout << "|                     PEMBELIAN TIKET                      |" << endl;
    cout << "-----------------------------------------------------------" << endl;

    cout << ">> Nama Pembeli : ";
    cin.ignore();
    getline(cin, nama_pembeli); // user diminta memasukkan nama pembeli
    cout << ">> Kode Ticket  : ";
    cin >> kode_tiket; // User diminta memasukkan kode tiket

    cout << ">> Jumlah Tiket : ";
    cin >> jumlah_tiket; // User diminta memasukkan jumlah tiket yang ingin dibeli

    cout << "-----------------------------------------------------------" << endl;
    cout << " 1) Pembayaran  | 2) Batalkan  |   3) Exit Program |" << endl;
    cout << "-----------------------------------------------------------" << endl;

    int user_input;
    cout << ">> masukkan pilihan : ";
    cin >> user_input;

    if (user_input == 1)
    {
        // Melakukan Pentotalan berdasarkan kode tiket dan jumlah tiket yang dibeli
        total_payment = (total_payment + (data_Tiket[kode_tiket].harga_tiket * jumlah_tiket));
        // Mendapatkan obyek TiketBus dengan indeks yang dimasukan oleh user dari map data_tiket
        TiketBus Tiket = data_Tiket[kode_tiket];

        // MENCETAK TIKET BERDASARKAN DATA YANG TERSEDIA DAN YANG DIINPUTKAN OLEH USER
        cout << "========================================================" << endl;
        cout << "|                       TIKET BUS                      |" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << ">> NAMA         : " << nama_pembeli << endl;
        cout << ">> KODE TIKET   : " << kode_tiket << endl;
        cout << ">> RUTE         : " << Tiket.rute_perjalanan << endl;
        cout << ">> NAMA ARMADA  : " << Tiket.armada << endl;
        cout << ">> HARGA TIKET  : IDR " << Tiket.harga_tiket << endl;
        cout << ">> JUMLAH TIKET : " << jumlah_tiket << " tiket" << endl;

        cout << "\n>> TOTAL PEMBAYARAN : IDR " << total_payment << endl;
        cout << "=======================================================" << endl;
    }

    else if (user_input == 2) // Memanggil Function Beli Tiket Kembali
    {
        system("cls");
        BeliTiket();
    }
    else if (user_input == 3) // Memberhentikan Program
    {
        exit(0);
    }
    else
    {
        exit(0); // Memberhentikan Program
    }
}

// function yang berisi garis
void garistipis()
{
    cout << "-----------------------------------------------------------" << endl;
}

void garistebal()
{
    cout << "===========================================================" << endl;
}
