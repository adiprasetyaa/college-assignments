// M0521003 ADI PRASETYA
// Program Memperbesar dan Memperkecil Luas Segitiga dengan pointer di C
// Program to Increase and Decrease the area of the triangle using pointer in C

#include <stdio.h>
#include <string.h>

float PerkecilSegitiga(float *alas, float *tinggi);
float PerbesarSegitiga(float *alas, float *tinggi);

int main()
{
    // declare the variable that will use
    float alas, tinggi, result;

    printf("==========================================\n");
    printf("=                                        =\n");
    printf("=      PROGRAM PERBESAR DAN PERKECIL     =\n");
    printf("=           LUAS DARI SEGITIGA           =\n");
    printf("=                                        =\n");
    printf("==========================================\n");

    printf("Masukkan alas segitiga : "); // input base of the triangle
    scanf("%f", &alas);

    printf("masukkan tinggi segitiga : "); // input height of the triangle
    scanf("%f", &tinggi);

    puts("");

    printf("Luas segitiga asli : %0.2f \n\n", alas * tinggi / 2); // the real area of triangle

    // calling function to increase the area of triangle
    PerbesarSegitiga(&alas, &tinggi);

    printf("Segitiga yang diperbesar dengan alas %0.2f dan tinggi %0.2f memiliki Luas sebesar %0.2f\n\n", alas, tinggi, alas * tinggi / 2);

    // calling function to decrease the area of triangle
    PerkecilSegitiga(&alas, &tinggi);

    printf("Segitiga yang diperkecil dengan alas %0.2f dan tinggi %0.2f memiliki Luas sebesar %0.2f\n\n", alas, tinggi, alas * tinggi / 2);

    return 0;
}

// passing by reference
float PerkecilSegitiga(float *alas, float *tinggi)
{

    *alas = *alas / 4;
    *tinggi = *tinggi / 4;
}

// passing by reference
float PerbesarSegitiga(float *alas, float *tinggi)
{

    *alas = *alas * 2;
    *tinggi = *tinggi * 2;
}
