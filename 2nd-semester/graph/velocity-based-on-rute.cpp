#include <iostream>

using namespace std;

enum lokasi
{
    RUMAH,
    UNS,
    RS_DR_Moewardi,
    SMPN_8_Surakarta,
    Pecel_Madiun_Pucangsawit,
    SMPN_4_Surakarta,
    SMAN_3_Surakarta,
    Jumlah_Lokasi
};

int main()
{
    double distance[Jumlah_Lokasi][Jumlah_Lokasi];

    // Semua diinisialisasi dengan value (-1) secara default
    // Value (-1) menunjukan sebagai berikut :
    // 1) Tidak ada jalur langsung di antara kedua lokasi
    // 2) Kedua lokasi tidak terhubung

    for (int i = 0; i < Jumlah_Lokasi; i++)
    {
        for (int j = 0; j < Jumlah_Lokasi; j++)
        {

            distance[i][j] = -1.0;
        }
    }

    // Pemberian value 0.0 karena merupakan jarak ke dirinya sendiri
    for (int i = 0; i < Jumlah_Lokasi; i++)
    {
        for (int j = 0; j < Jumlah_Lokasi; j++)
        {

            if (i == j)
            {
                distance[i][j] = 0.0;
            }
        }
    }

    // adjacency matrix
    distance[RUMAH][UNS] = 2.97;
    distance[UNS][RUMAH] = 2.97;

    distance[RUMAH][Pecel_Madiun_Pucangsawit] = 2.54;
    distance[Pecel_Madiun_Pucangsawit][RUMAH] = 2.54;

    distance[UNS][SMPN_8_Surakarta] = 1.61;
    distance[SMPN_8_Surakarta][UNS] = 1.61;

    distance[UNS][RS_DR_Moewardi] = 2.86;
    distance[RS_DR_Moewardi][UNS] = 2.86;

    distance[RS_DR_Moewardi][SMPN_4_Surakarta] = 1.43;
    distance[SMPN_4_Surakarta][RS_DR_Moewardi] = 1.43;

    distance[SMPN_8_Surakarta][SMPN_4_Surakarta] = 2.99;
    distance[SMPN_4_Surakarta][SMPN_8_Surakarta] = 2.99;

    distance[SMPN_8_Surakarta][SMAN_3_Surakarta] = 1.25;
    distance[SMAN_3_Surakarta][SMPN_8_Surakarta] = 1.25;

    distance[Pecel_Madiun_Pucangsawit][SMPN_4_Surakarta] = 4.00;
    distance[SMPN_4_Surakarta][Pecel_Madiun_Pucangsawit] = 4.00;

    distance[Pecel_Madiun_Pucangsawit][SMAN_3_Surakarta] = 2.28;
    distance[SMAN_3_Surakarta][Pecel_Madiun_Pucangsawit] = 2.28;

    cout << "===========================================================" << endl;
    cout << "=                                                         =" << endl;
    cout << "=             ESTIMASI KECEPATAN RATA-RATA                =" << endl;
    cout << "=                                                         =" << endl;
    cout << "===========================================================" << endl;
    double kecepatan_rata2, total_jarak = 0;
    int menit, titik_awal = -1;

    while (1)
    {
        int lokasi_awal, lokasi_selanjutnya;
        char tambah_tujuan;

        cout << "\n>> LOKASI TUJUAN SEBAGAI BERIKUT <<" << endl;
        cout << "0. Rumah " << endl;
        cout << "1. UNS" << endl;
        cout << "2. RS Dr Moewardi" << endl;
        cout << "3. SMPN 8 Surakarta" << endl;
        cout << "4. Pecel MAdiun Surakarta" << endl;
        cout << "S. SMPN 4 Surakarta" << endl;
        cout << "6. SMAN 3 Surakarta" << endl;
        if (titik_awal == -1)
        {
            // Jika lokasi awal belum tersedia, maka user memasukkan input lokasi awal
            cout << "\nHistory lokasi awal tidak ada!" << endl;
            cout << "Lokasi Awal atau Sebelumnya\t: ";
            cin >> titik_awal;
        }
        else
        {
            // Jika lokasi awal sudah tersedia, maka langsung digunakan untuk lokasi awal - lokasi selanjutnya
            cout << "Lokasi awal \t\t\t: " << lokasi_awal << endl;
        }
        cout << "Lokasi selanjutnya\t\t: ";
        cin >> lokasi_selanjutnya;

        // Memasukkan lokasi selanjutnya yang valid
        if (distance[lokasi_awal][lokasi_selanjutnya] != -1.0 && distance[lokasi_awal][lokasi_selanjutnya] != 0.0)
        {
            total_jarak = total_jarak + distance[lokasi_awal][lokasi_selanjutnya];
            lokasi_awal = lokasi_selanjutnya;
        }

        // JIka lokasi awal dan selanjutnya berjarak (-1) atau (0) maka invalid
        else if (distance[lokasi_awal][lokasi_selanjutnya] == -1.0 || distance[lokasi_awal][lokasi_selanjutnya] == 0.0)
        {
            cout << "Jalur tidak tersedia, silakan pilih jalur lainnya!\n\n";
        }

        cout << "Apakah anda ingin melakukan perjalanan lagi? (Y/N)" << endl;
        cin >> tambah_tujuan;

        if (tambah_tujuan == 'N' || tambah_tujuan == 'n')
        {
            break;
        }
    }

    cout << "\nTotal Jarak (km)\t\t\t\t: " << total_jarak << endl;

    // Convert dari menit ke detik, kemudian dari km/s diubah menjadai km/jam
    if (total_jarak != 0)
    {

        cout << "Estimasi waktu yang diinginkan (dalam menit)\t: ";
        cin >> menit;

        kecepatan_rata2 = total_jarak / (menit * 60); // convert menjadi km/s
        kecepatan_rata2 = kecepatan_rata2 * 3600;     // dari km/s menjadi km/jam

        cout << "\n\nKecepatan rata-rata yang diperlukan\t\t: " << kecepatan_rata2 << " km/jam" << endl;
    }

    else
    {
        cout << "Lokasi yang anda masukkan invalid!\n";
    }

    return 0;
}
