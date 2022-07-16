#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> Transportasi;

string find(string x)
{

    if (Transportasi[x] == x)
    {
        return x;
    }

    return find(Transportasi[x]);
}

void merge(string x, string y)
{

    string transportasiX = find(x);
    string transportasiY = find(y);

    Transportasi[x] = transportasiY;
}

int main()
{

    Transportasi["PESAWAT"] = "PESAWAT"; // Parents untuk rute yg bisa dilalui dg pesawat saja
    Transportasi["PBKAKF"] = "PBKAKF";   // Parents untuk rute yang bisa dilalui dg Pesawat, Bus, Kereta Api, dan Kapal Ferry
    Transportasi["PBKA"] = "PBKA";       // Parents untuk group rute yang bisa dilalui dengan Pesawat, Bus, dan Kereta Api
    Transportasi["PKF"] = "PKF";         // Parents untuk group rute yang bisa dilalui dengan Pesawat dan Kapal Ferry

    // Rute untuk PBKA
    Transportasi["JKT-BDG"] = "JKT-BDG";
    Transportasi["BDG-JKT"] = "BDG-JKT";

    Transportasi["SBY-BDG"] = "SBY-BDG";
    Transportasi["BDG-SBY"] = "BDG-SBY";

    // Rute untuk PBKAKF
    Transportasi["JKT-SBY"] = "JKT-SBY";
    Transportasi["SBY-JKT"] = "SBY-JKT";

    // Rute untuk PKF
    Transportasi["JKT-JYPR"] = "JKT-JYPR";
    Transportasi["JYPR-JKT"] = "JYPR-JKT";

    Transportasi["SBY-JYPR"] = "SBY-JYPR";
    Transportasi["JYPR-SBY"] = "JYPR-SBY";

    // Rute untuk Pesawat saja
    Transportasi["JYPR-MDN"] = "JYPR-MDN";
    Transportasi["MDN-JYPR"] = "MDN-JYPR";

    Transportasi["JYPR-BDG"] = "JYPR-BDG";
    Transportasi["BDG-JYPR"] = "BDG-JYPR";

    Transportasi["MDN-JKT"] = "MDN-JKT";
    Transportasi["JKT-MDN"] = "JKT-MDN";

    Transportasi["MDN-BDG"] = "MDN-BDG";
    Transportasi["BDG-MDN"] = "BDG-MDN";

    // merge untuk rute PBKAKF
    merge("PBKAKF", "JKT-SBY");
    merge("JKT-SBY", "SBY-JKT");

    // merge untuk rute PBKA
    merge("PBKA", "JKT-BDG");
    merge("JKT-BDG", "BDG-JKT");
    merge("BDG-JKT", "SBY-BDG");
    merge("SBY-BDG", "BDG-SBY");

    // merge untuk rute PKF
    merge("PKF", "JKT-JYPR");
    merge("JKT-JYPR", "JYPR-JKT");
    merge("JYPR-JKT", "SBY-JYPR");
    merge("SBY-JYPR", "JYPR-SBY");
    merge("JYPR-SBY", "JYPR-JKT");
    merge("JYPR-JKT", "JKT-JYPR");
    merge("JKT-JYPR", "JYPR-SBY");
    merge("JYPR-SBY", "SBY-JYPR");

    // merge untuk rute pesawat saja
    merge("PESAWAT", "JYPR-MDN");
    merge("JYPR-MDN", "MDN-JYPR");
    merge("MDN-JYPR", "JYPR-BDG");
    merge("JYPR-BDG", "BDG-JYPR");
    merge("BDG-JYPR", "MDN-JKT");
    merge("MDN-JKT", "JKT-MDN");
    merge("JKT-MDN", "MDN-BDG");
    merge("MDN-BDG", "BDG-MDN");

    while (1)
    {

        string tujuan;

        cout << "===========================================================" << endl;
        cout << "=                                                         =" << endl;
        cout << "=              MODA TRANSPORTASI ANTAR-KOTA               =" << endl;
        cout << "=                                                         =" << endl;
        cout << "===========================================================\n"
             << endl;
        cout << "Kota Asal - Kota Tujuan" << endl;
        cout << "1) JKT-BDG" << endl;
        cout << "2) SBY-BDG" << endl;
        cout << "3) JKT-SBY" << endl;
        cout << "4) SBY-JYPR" << endl;
        cout << "5) JYPR-JKT" << endl;
        cout << "6) JYPR-MDN" << endl;
        cout << "7) JYPR-BDG" << endl;
        cout << "8) MDN-BDG" << endl;
        cout << "9) MDN-JKT" << endl;
        cout << ">> Rute di atas berlaku sebaliknya <<" << endl;
        cout << "Format Input = KOTAASAL-KOTATUJUAN" << endl;
        cout << "\nMasukkan Kota Asal dan Kota Tujuan : " << endl;
        cin >> tujuan;

        if (find(tujuan) == find("PBKAKF"))
        {
            cout << "\nRute dari " << tujuan << " yang tersedia sebagai berikut : " << endl;
            cout << "1) Pesawat" << endl;
            cout << "2) Bus" << endl;
            cout << "3) Kereta Api" << endl;
            cout << "4) Kapal Ferry\n\n";
        }

        else if (find(tujuan) == find("PBKA"))
        {
            cout << "\nRute dari " << tujuan << " yang tersedia sebagai berikut : " << endl;
            cout << "1) Pesawat" << endl;
            cout << "2) Bus" << endl;
            cout << "3) Kereta Api\n\n";
        }

        else if (find(tujuan) == find("PKF"))
        {
            cout << "\nRute dari " << tujuan << " yang tersedia sebagai berikut : " << endl;
            cout << "1) Pesawat" << endl;
            cout << "2) Kapal Ferry\n\n";
        }

        else if (find(tujuan) == find("PESAWAT"))
        {
            cout << "\nMohon maaf untuk rute " << tujuan << " saat ini hanya tersedia Pesawat saja\n\n";
        }

        else
        {
            cout << "\n!! MOHON MAAF INPUT YANG ANDA MASUKKAN SALAH !!" << endl;
            cout << "!! SILAKAN COBA LAGI !!\n\n";
        }

        char cek_lagi;
        cout << "Ingin Mengecek Moda Transportasi lagi? (Y/N) : ";
        cin >> cek_lagi;

        if (cek_lagi == 'n' || cek_lagi == 'N')
        {
            break;
        }
    }

    return 0;
}
