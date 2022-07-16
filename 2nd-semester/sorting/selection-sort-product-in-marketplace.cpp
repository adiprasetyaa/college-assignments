#include <iostream>

using namespace std;

void ListProduk();
void SortPilihan();

// Struct untuk menyimpan data dari produk
struct data_produk
{

    string NamaProduk;
    long int HargaProduk;
    long int TotalPenjualan;
    long int TanggalRilis;
};

typedef struct data_produk Data;

int main()
{

    // Struct of array untuk menyimpan data
    Data DataProduk[10];

    // Memasukkan Data Produk ke dalam struct of array
    DataProduk[0] = {"Oxford Shirt", 250000, 59, 20220317};
    DataProduk[1] = {"Flannel Shirt", 225000, 123, 20220129};
    DataProduk[2] = {"Corduroy Shirt", 299000, 43, 20220511};
    DataProduk[3] = {"Black Jeans", 349000, 142, 20220101};
    DataProduk[4] = {"Black Chino", 399000, 82, 20220407};
    DataProduk[5] = {"Daily Blazer", 429000, 89, 20220615};
    DataProduk[6] = {"Tartan Pants", 449000, 23, 20220929};
    DataProduk[7] = {"Ankle Pants", 279000, 193, 20221004};
    DataProduk[8] = {"Knit T-shirt", 159000, 265, 20220721};
    DataProduk[9] = {"Polo T-shirt", 189000, 89, 29221218};

    // Pemanggilan fungsi ListProduk() untuk menampilkan produk yang tersedia secara acak
    ListProduk();

    while (1)
    {
        int userchoice;
        char stop_loop;

        // Pemanggilan fungsi SortPilihan() untuk menampilkan berbagai variasi sorting yang tersedia
        SortPilihan();

        cout << "Masukkan Pilihan anda : ";
        cin >> userchoice;

        if (userchoice == 1)
        {
            cout << "\n\n               >> SORT BY HARGA TERMURAH <<                " << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << "|No.|\tNama Produk\t\t|\tHarga Produk\t|" << endl;
            cout << "--------------------------------------------------------" << endl;

            for (int i = 0; i < 10 - 1; i++)
            {

                int nilai_terkecil = i;

                for (int j = i + 1; j < 10; j++)
                {

                    if (DataProduk[j].HargaProduk < DataProduk[nilai_terkecil].HargaProduk)
                    {
                        nilai_terkecil = j;
                    }
                }

                int temp1 = DataProduk[i].HargaProduk;
                DataProduk[i].HargaProduk = DataProduk[nilai_terkecil].HargaProduk;
                DataProduk[nilai_terkecil].HargaProduk = temp1;

                string temp2 = DataProduk[i].NamaProduk;
                DataProduk[i].NamaProduk = DataProduk[nilai_terkecil].NamaProduk;
                DataProduk[nilai_terkecil].NamaProduk = temp2;

                cout << "| " << i + 1 << " |\t" << DataProduk[i].NamaProduk << "\t\t|\t" << DataProduk[i].HargaProduk << "\t\t|" << endl;
            }
            cout << "--------------------------------------------------------" << endl;
            cout << endl;
        }

        else if (userchoice == 2)
        {

            cout << "\n\n               >> SORT BY HARGA TERMAHAL <<                " << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << "|No.|\tNama Produk\t\t|\tHarga Produk\t|" << endl;
            cout << "--------------------------------------------------------" << endl;

            for (int i = 0; i < 10 - 1; i++)
            {

                int nilai_terkecil = i;

                for (int j = i + 1; j < 10; j++)
                {

                    if (DataProduk[j].HargaProduk > DataProduk[nilai_terkecil].HargaProduk)
                    {
                        nilai_terkecil = j;
                    }
                }

                int temp = DataProduk[i].HargaProduk;
                DataProduk[i].HargaProduk = DataProduk[nilai_terkecil].HargaProduk;
                DataProduk[nilai_terkecil].HargaProduk = temp;

                string temp2 = DataProduk[i].NamaProduk;
                DataProduk[i].NamaProduk = DataProduk[nilai_terkecil].NamaProduk;
                DataProduk[nilai_terkecil].NamaProduk = temp2;

                cout << "| " << i + 1 << " |\t" << DataProduk[i].NamaProduk << "\t\t|\t" << DataProduk[i].HargaProduk << "\t\t|" << endl;
            }

            cout << "--------------------------------------------------------" << endl;
            cout << endl;
        }

        else if (userchoice == 3)
        {

            cout << "\n\n               >> SORT BY PRODUK TERLARIS <<                " << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "|No.|\tNama Produk\t\t|\tProduk Terjual \t  |" << endl;
            cout << "-----------------------------------------------------------" << endl;

            for (int i = 0; i < 10 - 1; i++)
            {

                int nilai_terkecil = i;

                for (int j = i + 1; j < 10; j++)
                {

                    if (DataProduk[j].TotalPenjualan > DataProduk[nilai_terkecil].TotalPenjualan)
                    {
                        nilai_terkecil = j;
                    }
                }

                int temp = DataProduk[i].TotalPenjualan;
                DataProduk[i].TotalPenjualan = DataProduk[nilai_terkecil].TotalPenjualan;
                DataProduk[nilai_terkecil].TotalPenjualan = temp;

                string temp2 = DataProduk[i].NamaProduk;
                DataProduk[i].NamaProduk = DataProduk[nilai_terkecil].NamaProduk;
                DataProduk[nilai_terkecil].NamaProduk = temp2;

                cout << "| " << i + 1 << " |\t" << DataProduk[i].NamaProduk << "\t\t|\t  " << DataProduk[i].TotalPenjualan << "\t\t  |" << endl;
            }

            cout << "-----------------------------------------------------------" << endl;
            cout << endl;
        }

        else if (userchoice == 4)
        {
            cout << "\n\n                        >> SORT BY PRODUK TERBARU <<                   " << endl;
            cout << "------------------------------------------------------------------------" << endl;
            cout << "|No.|\tNama Produk\t\t|\tTanggal Rilis (yyyymmdd)\t|" << endl;
            cout << "------------------------------------------------------------------------" << endl;

            for (int i = 0; i < 10 - 1; i++)
            {

                int nilai_terkecil = i;

                for (int j = i + 1; j < 10; j++)
                {

                    if (DataProduk[j].TanggalRilis < DataProduk[nilai_terkecil].TanggalRilis)
                    {
                        nilai_terkecil = j;
                    }
                }

                int temp = DataProduk[i].TanggalRilis;
                DataProduk[i].TanggalRilis = DataProduk[nilai_terkecil].TanggalRilis;
                DataProduk[nilai_terkecil].TanggalRilis = temp;

                string temp2 = DataProduk[i].NamaProduk;
                DataProduk[i].NamaProduk = DataProduk[nilai_terkecil].NamaProduk;
                DataProduk[nilai_terkecil].NamaProduk = temp2;

                cout << "| " << i + 1 << " |\t" << DataProduk[i].NamaProduk << "\t\t|\t\t" << DataProduk[i].TanggalRilis << "\t\t|" << endl;
            }

            cout << "------------------------------------------------------------------------" << endl;
            cout << endl;
        }

        else
        {
            cout << "\n!! MOHON MAAF, PILIHAN YANG ANDA MASUKKAN SALAH !!" << endl;
            cout << "!!               SILAKAN COBA LAGI !!             \n\n";
        }

        cout << "Apakah Anda ingin pilihan sorting lainnya? (Y/N) : ";
        cin >> stop_loop;

        if (stop_loop == 'N' || stop_loop == 'n')
        {
            break;
        }

        else if (stop_loop == 'Y' || stop_loop == 'y')
        {
            continue;
        }

        else
        {
            cout << "\n!! INPUT YANG ANDA MASUKKAN SALAH !!\n\n";
            cout << "Apakah Anda ingin pilihan sorting lainnya? (Y/N) : ";
            cin >> stop_loop;

            if (stop_loop == 'N' || stop_loop == 'n')
            {
                break;
            }
        }
    }

    return 0;
}

void ListProduk()
{

    cout << "===========================================================" << endl;
    cout << "=                                                         =" << endl;
    cout << "=                       LEVYX STORE                       =" << endl;
    cout << "=                                                         =" << endl;
    cout << "===========================================================" << endl;

    cout << "\n>> Produk Pilihan <<" << endl;
    cout << "1. Oxford Shirt " << endl;
    cout << "2. Flannel Shirt" << endl;
    cout << "3. Corduroy Shirt" << endl;
    cout << "4. Black Jeans" << endl;
    cout << "5. Black Chino" << endl;
    cout << "6. Light Grey Chino" << endl;
    cout << "7. Tartan Pants" << endl;
    cout << "8. Mockneck T-shirt" << endl;
    cout << "9. Knit T-Shirt" << endl;
    cout << "10. Polo T-shirt\n\n";
}

void SortPilihan()
{
    cout << "\nUrutkan Berdasarkan : " << endl;
    cout << "1. Harga Termurah" << endl;
    cout << "2. Harga Termahal" << endl;
    cout << "3. Terlaris" << endl;
    cout << "4. Terbaru\n\n";
}