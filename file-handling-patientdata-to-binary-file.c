#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct datapasien
{

    unsigned int NomorPasien;
    char NamaDepan[10];
    char NamaBelakang[10];
    char TempatLahir[15];
    char TanggalLahir[12];
    char JenisKelamin;
};

typedef struct datapasien Data;

Data DataPasien[100];

void TampilkanArray(Data DataPasien[], int);

enum menu
{
    menampilkan = 1,
    write,
    read,
    update,
    keluar
};

int main()
{

    Data DataPasien[100];
    int jumlahdata, i;

    FILE *datapasien;

    printf("\nMasukkan jumlah data pasien yang ingin disimpan : ");
    scanf("%d", &jumlahdata);

    printf("\n\n");

    for (i = 0; i < jumlahdata; i++)
    {

        printf("Masukkan Nomor Pasien : ");
        scanf("%d", &DataPasien[i].NomorPasien);
        printf("Masukkan Nama Depan Pasien : ");
        scanf("%s", DataPasien[i].NamaDepan);
        printf("Masukkan Nama Belakang Pasien : ");
        scanf("%s", DataPasien[i].NamaBelakang);
        printf("Masukkan Tempat Lahir : ");
        scanf("%s", DataPasien[i].TempatLahir);
        printf("Masukkan Tanggal Lahir (dd-mm-yyyy) : ");
        scanf("%s", DataPasien[i].TanggalLahir);
        printf("Masukkan Jenis Kelamin (L/P) : ");
        scanf(" %c", &DataPasien[i].JenisKelamin);
        puts(" ");
    }

    printf("====================================================\n");
    printf("=                                                  =\n");
    printf("=                                                  =\n");
    printf("=                                                  =\n");
    printf("=               DATA PASIEN RAWAT INAP             =\n");
    printf("=               RUMAH SAKIT KERE HORE              =\n");
    printf("=                                                  =\n");
    printf("=                                                  =\n");
    printf("=                                                  =\n");
    printf("====================================================\n\n");

    printf("--------  Pilihan Menu  ----------\n");
    printf("1. Menampilkan Data Pasien\n");
    printf("2. Write Data Pasien ke Binary File\n");
    printf("3. Read Data Pasien dari Binary FIle\n");
    printf("4. Update Data Pasien\n");
    printf("5. Keluar Program\n\n");

    while (1)
    {

        int userinput, jumlahupdate;
        printf("\nPilihan User : ");
        scanf("%d", &userinput);

        puts("");

        if (userinput == menampilkan)
        {
            TampilkanArray(DataPasien, jumlahdata);
        }

        else if (userinput == write)
        {
            datapasien = fopen("DataPasien.dat", "wb");

            if (datapasien == NULL)
            {
                printf("Data tidak tersedia!\n");
                exit(1);
            }

            fwrite(DataPasien, sizeof(Data) * jumlahdata, 1, datapasien);
            fclose(datapasien);
        }

        else if (userinput == read)
        {
            datapasien = fopen("DataPasien.dat", "rb");

            int jumlah;
            printf("Masukkan jumlah data yang ingin ditampilkan : ");
            scanf("%d", &jumlah);

            if (datapasien == NULL)
            {
                printf("Data tidak tersedia!\n");
                exit(1);
            }

            fread(&DataPasien, sizeof(Data) * jumlah, 1, datapasien);
            printf("%-5s%-20s%-23s%-15s%-15s%15s\n", "No.", "Nama Depan Pasien", "Nama Belakang Pasien", "Tempat Lahir", "Tanggal Lahir", "Jenis Kelamin");
            for (int i = 0; i < jumlah; i++)
            {
                printf("%-5d%-20s%-23s%-15s%-15s%8c\n", DataPasien[i].NomorPasien, DataPasien[i].NamaDepan, DataPasien[i].NamaBelakang, DataPasien[i].TempatLahir, DataPasien[i].TanggalLahir, DataPasien[i].JenisKelamin);
            }
            fclose(datapasien);
        }

        else if (userinput == update)
        {
            datapasien = fopen("DataPasien.dat", "ab");

            printf("\nMasukkan jumlah data pasien yang ingin diupdate : ");
            scanf("%d", &jumlahupdate);

            printf("\n\n");

            for (i = 0; i < jumlahupdate; i++)
            {

                printf("Masukkan Nomor Pasien : ");
                scanf("%d", &DataPasien[i].NomorPasien);
                printf("Masukkan Nama Depan Pasien : ");
                scanf("%s", DataPasien[i].NamaDepan);
                printf("Masukkan Nama Belakang Pasien : ");
                scanf("%s", DataPasien[i].NamaBelakang);
                printf("Masukkan Tempat Lahir : ");
                scanf("%s", DataPasien[i].TempatLahir);
                printf("Masukkan Tanggal Lahir (dd-mm-yyyy) : ");
                scanf("%s", DataPasien[i].TanggalLahir);
                printf("Masukkan Jenis Kelamin (L/P) : ");
                scanf(" %c", &DataPasien[i].JenisKelamin);
                puts(" ");
            }

            if (datapasien == NULL)
            {
                printf("Data tidak tersedia!\n");
                exit(1);
            }

            fwrite(DataPasien, sizeof(Data) * jumlahupdate, 1, datapasien);
            fclose(datapasien);
        }

        else if (userinput == keluar)
        {
            break;
        }

        else
        {
            printf("Pilihan yang anda masukkan salah!\n");
            printf("Silakan masukkan pilihan 1- 5\n");
        }
    }

    return 0;
}

void TampilkanArray(Data DataPasien[], int jumlah)
{

    printf("%-5s%-20s%-23s%-15s%-15s%15s\n", "No.", "Nama Depan Pasien", "Nama Belakang Pasien", "Tempat Lahir", "Tanggal Lahir", "Jenis Kelamin");

    for (int i = 0; i < jumlah; i++)
    {

        printf("%-5d%-20s%-23s%-15s%-15s%8c\n", DataPasien[i].NomorPasien, DataPasien[i].NamaDepan, DataPasien[i].NamaBelakang, DataPasien[i].TempatLahir, DataPasien[i].TanggalLahir, DataPasien[i].JenisKelamin);
    }
}
