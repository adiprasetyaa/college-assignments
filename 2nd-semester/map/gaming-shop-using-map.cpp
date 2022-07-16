#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

// tester git remote

struct OurShop // struct for data product variable
{

    string nama;  // name of product
    int stok;     // product stocks
    double harga; // price
};

int main()
{

    map<string, OurShop> data_produk; // declare

    cout << "===============================================================================";
    cout << "\n=                                                                             =";
    cout << "\n=                                WELCOME TO LEVYX                             =";
    cout << "\n=                               GAMING GEAR STORE                             =";
    cout << "\n=                                                                             =";
    cout << "\n===============================================================================\n\n";
    cout << "======= LEVYX STORE PRODUCTS =======" << endl;
    cout << "[001] Keyboard Mechanical (IDR 500k) " << endl;
    cout << "[002] Keyboard Membrane (IDR 200k)" << endl;
    cout << "[003] Headset (IDR 450k)" << endl;
    cout << "[004] Controller Rexus (IDR 150k)" << endl;
    cout << "[004] Mouse Wireless (IDR 125k)" << endl;
    cout << "[006] TWS (IDR 250k)\n\n";

    OurShop produk;
    string kodeproduk; // product code
    double TotalPayment = 0;

    double SaldoEwallet;

    // user input e-wallet's balance
    cout << "Masukkan Jumlah Saldo E-Wallet anda!" << endl;
    cin >> SaldoEwallet;

    // products for sale
    produk.nama = "Keyboard Mechanical";
    produk.stok = 15;
    produk.harga = 500000;
    data_produk["001"] = produk;

    produk.nama = "Keyboard Membrane";
    produk.stok = 100;
    produk.harga = 200000;
    data_produk["002"] = produk;

    produk.nama = "Headset";
    produk.stok = 50;
    produk.harga = 450000;
    data_produk["003"] = produk;

    produk.nama = "Controller Rexus";
    produk.stok = 150;
    produk.harga = 150000;
    data_produk["004"] = produk;

    produk.nama = "Mouse Wireless";
    produk.stok = 75;
    produk.harga = 125000;
    data_produk["005"] = produk;

    produk.nama = "TWS";
    produk.stok = 25;
    produk.harga = 250000;
    data_produk["006"] = produk;

    while (true)
    {
        string kodeproduk; // product code
        char buy_again;    // buy again?
        int jumlahbarang;  // stock of product

        cout << "\nMasukkan kode dari barang yg akan dibeli\t : ";
        cin >> kodeproduk; // user input code product that will be buy
        cout << "Jumlah barang yang akan dibeli\t\t\t : ";
        cin >> jumlahbarang; // number of product that will be buy
        if (jumlahbarang > produk.stok)
        {
            cout << "Maaf, stok barang yang anda pilih tidak tersedia!" << endl;
        }

        // for conditional
        int stok_sisa = data_produk[kodeproduk].stok - jumlahbarang;
        float TPsementara = (TotalPayment + (data_produk[kodeproduk].harga * jumlahbarang));

        if ((SaldoEwallet > TPsementara) && (jumlahbarang < produk.stok))
        {
            cout << "Barang berhasil dimasukkan ke dalam keranjang!" << endl;
            data_produk[kodeproduk].stok = data_produk[kodeproduk].stok - jumlahbarang;
            TotalPayment = (TotalPayment + (data_produk[kodeproduk].harga * jumlahbarang));
        }

        else
        {
            cout << "Maaf, saldo anda tidak mencukupi untuk melakukan pembelian ini!" << endl;
        }

        cout << "Menambah barang lagi? Y/N" << endl;
        cin >> buy_again;

        if (buy_again == 'N')
        {
            break; // out of loop
        }
    }

    while (true)
    {

        int pilihan;
        cout << "\n=========================== MENU ===========================" << endl;
        cout << "1) Melakukan Transaksi" << endl;
        cout << "2) Mengecek ketersediaan stok saat ini" << endl;
        cout << "3) Keluar" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            cout << "\n========================================================" << endl;
            cout << fixed << showpoint;
            cout << "Saldo Awal \t\t : " << setprecision(2) << SaldoEwallet << endl;
            cout << "Total Pembayaran \t : " << setprecision(2) << TotalPayment << endl;
            cout << "Saldo Akhir \t\t : " << setprecision(2) << SaldoEwallet - TotalPayment << endl;
            cout << "\n========================================================" << endl;
        }

        else if (pilihan == 2)
        {

            for (
                map<std::string, OurShop>::iterator it = data_produk.begin();
                it != data_produk.end();
                ++it)
            {
                cout << "===================================================\n";
                cout << "Kode barang\t : " << it->first << endl;
                cout << "Nama produk\t : " << it->second.nama << endl;
                cout << "Stok produk\t : " << it->second.stok << endl;
                cout << "Harga produk\t : " << it->second.harga << endl;
            }
        }

        else if (pilihan == 3)
        {
            break;
        }

        else
        {
            cout << "Masukkan kode pilihan yang tepat!\n";
        }
    }

    return 0;
}