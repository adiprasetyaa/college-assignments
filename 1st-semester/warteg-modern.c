#include <stdio.h>

int BiayaLauk();
int BiayaSayur();
int BiayaMinum();

int main()
{

    printf("====================================================\n");
    printf("=                                                  =\n");
    printf("=              WELCOME TO WARTEG MODERN            =\n");
    printf("=                                                  =\n");
    printf("====================================================\n");

    // initialization of side dishes menu
    char Lauk[5][15] = {"Ayam goreng", "Ayam Bakar", "Lele Goreng", "Telur Dadar", "Rendang"};

    printf("---- PILIHAN LAUK ----\n");

    for (int i = 0; i < 5; i++)
    {
        // print menu of side dishes
        printf("[%2d] : %s\n", i + 1, Lauk[i]);
    }

    printf("\n");

    // initialization of vegetables menu
    char Sayur[5][15] = {"Sayur Bayam", "Sayur Sop", "Sayur Lodeh", "Sayur Labu", "Sayur Kangkung"};

    printf("----  PILIHAN SAYUR ----\n");

    for (int i = 0; i < 5; i++)
    {
        // print menu of vegetables
        printf("[%2d] : %s\n", i + 1, Sayur[i]);
    }

    puts("");

    // initialization of drinks menu
    char Minum[3][15] = {"Es Teh", "Es Jeruk", "Air mineral"};

    printf("---- PILIHAN MINUMAN ----\n");

    for (int i = 0; i < 3; i++)
    {
        // print menu of drinks
        printf("[%2d] : %s\n", i + 1, Minum[i]);
    }

    printf("\nINTRUKSI USER\n[kode] : pilihan\n\n");

    unsigned int TotalPembayaran = BiayaLauk() + BiayaSayur() + BiayaMinum(); // calculate total payment

    printf("\n\nTOTAL PEMBAYARAN : %d\n\n", TotalPembayaran);

    unsigned int bayar;
    printf("TOTAL UANG YANG DIBAYARKAN : ");
    scanf("%d", &bayar); // input total money paid

    unsigned int kembalian = bayar - TotalPembayaran; // calculate money changes

    printf("\nTOTAL SISA UANG DARI PEMBAYARAN : %d\n\n", kembalian);

    printf("====================================================\n");
    printf("=                                                  =\n");
    printf("=        TERIMA KASIH DAN SELAMAT MENIKMATI        =\n");
    printf("=                                                  =\n");
    printf("====================================================\n");

    return 0;
}

int BiayaLauk()
{

    char AmbilLauk;
    int sum = 0;

    char belilauk;
    printf("Apakah anda ingin membeli lauk?(y/n) : ");
    scanf(" %c", &belilauk);

    if (belilauk == 'y')
    {

        while (1)
        {

            int BiayaLauk[5] = {8000, 12000, 6000, 3000, 15000};

            unsigned int kodelauk, jumlah;
            char answer;

            printf("\nMasukkan kode lauk yang anda pilih : ");
            scanf("%d", &kodelauk);

            printf("Masukkan jumlah lauk yang dipilih : ");
            scanf("%d", &jumlah);

            printf("Harga Lauk = %d\n", BiayaLauk[kodelauk - 1] * jumlah);

            sum += BiayaLauk[kodelauk - 1] * jumlah;

            printf("apakah anda ingin menambah lauk lagi? (y/n) : ");
            scanf(" %c", &answer);

            if (answer == 'y')
            {
                continue;
            }

            else if (answer == 'n')
            {
                break;
            }

            else
            {
                printf("kode yang anda masukkan tidak valid!");
            }
        }
    }

    printf("TOTAL BIAYA LAUK : %d\n", sum);

    return sum;
}

int BiayaSayur()
{

    char AmbilSayur;
    int sum = 0;

    char belisayur;
    printf("\nApakah anda ingin membeli sayur?(y/n) : ");
    scanf(" %c", &belisayur);

    if (belisayur == 'y')
    {

        while (1)
        {

            int BiayaSayur[5] = {3000, 5000, 3000, 4000, 3000};

            unsigned int kodesayur, jumlah;
            char answer;

            printf("\nMasukkan kode sayur yang anda pilih : ");
            scanf("%d", &kodesayur);

            printf("Masukkan jumlah porsi sayur yang dipilih : ");
            scanf("%d", &jumlah);

            printf("Harga Sayur = %d\n", BiayaSayur[kodesayur - 1] * jumlah);

            sum += BiayaSayur[kodesayur - 1] * jumlah;

            printf("apakah anda ingin menambah sayur lagi? (y/n) : ");
            scanf(" %c", &answer);

            if (answer == 'y')
            {
                continue;
            }

            else if (answer == 'n')
            {
                break;
            }

            else
            {
                printf("kode yang anda masukkan tidak valid!");
            }
        }
    }

    printf("TOTAL BIAYA SAYUR : %d\n", sum);

    return sum;
}

int BiayaMinum()
{

    char AmbilMinum;
    int sum = 0;

    char beliminum;
    printf("\nApakah anda ingin membeli minum?(y/n) : ");
    scanf(" %c", &beliminum);

    if (beliminum == 'y')
    {

        while (1)
        {

            int BiayaMinum[3] = {4000, 5000, 3000};

            int kodeminuman, jumlah;
            char answer;

            printf("\nMasukkan kode minuman yang anda pilih : ");
            scanf("%d", &kodeminuman);

            printf("Masukkan jumlah minuman yang dipilih : ");
            scanf("%d", &jumlah);

            printf("Harga Minuman = %d\n", BiayaMinum[kodeminuman - 1] * jumlah);

            sum += BiayaMinum[kodeminuman - 1] * jumlah;

            printf("apakah anda ingin menambah minuman lagi? (y/n) : ");
            scanf(" %c", &answer);

            if (answer == 'y')
            {
                continue;
            }

            else if (answer == 'n')
            {
                break;
            }

            else
            {
                printf("kode yang anda masukkan tidak valid!");
            }
        }
    }

    printf("TOTAL BIAYA MINUMAN : %d\n", sum);

    return sum;
}
