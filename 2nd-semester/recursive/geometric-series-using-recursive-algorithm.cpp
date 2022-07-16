#include <iostream>
#include <cmath>

using namespace std;

/*

Berikut ini adalah implementasi dari Deret Geometri yang memiliki rumus awal :

                        ====================
                        =    Un = ar^n-1   =
                        ====================

a = suku pertama; r = rasio; n = banyaknya suku

Deret geometri di bawah ini memiliki a = 15; r = 3, sehingga jika dituliskan deretnya sebagai berikut.
15, 45, 135, 405, ...

Maka,
U1 = 15
U2 = 45
Un = Un-1 * 3

Base case = Un-1 * 3

*/

unsigned long long int deretgeometri(int n)
{

    if (n == 1)
    {
        return 15 * pow(3, n - 1);
    }

    else
    {
        return (deretgeometri(n - 1) * 3);
    }
}

/*

    Misalnya n = 4,

    deretgeometri(4) = deretgeometri(3)*3
            deretgeometri(3) = deretgeometri(2)*3
                            deretgeometri(2) = deretgeometri(1)*3
                                    >> karena n == 1, maka return 15*(3^n-1) yang mana merupakan nilai dari U1 atau suku pertama <<
                            deretgeometri(2) = deretgeometri(1)*3
                            deretgeometri(2) = 15*3 = 45
            deretgeometri(3) = deretgeometri(2)*3
            deretgeometri(3) = 45 * 3 = 135
    deretgeometri(4) = deretgeometri(3)*3
    deretgeometri(4) = 135 * 3 = 405

    Kemudian, dikembalikan ke fungsi main
*/

unsigned long long int jumlahderet(int n)
{

    if (n == 1)
    {
        return 15 * pow(3, n - 1);
    }

    else
    {
        return (15 * pow(3, n - 1) + jumlahderet(n - 1));
    }
}

/*

    Misalnya n = 4,

    jumlahderet(4) = 15*3^3 + jumlahderet(3)
            jumlahderet(3) = 15*3^2 + jumlahderet(2)
                            jumlahderet(2) = 15*3^1 + jumlahderet(1)
                                    >> karena n == 1, maka return 15*(3^n-1) yang mana merupakan nilai dari U1 atau suku pertama <<
                            jumlahderet(2) = 15*3^1 + jumlahderet(1)
                            jumlahderet(2) = 15*3^1 + 15 = 60
            jumlahderet(3) = 15*3^2 + jumlahderet(2)
            jumlahderet(3) = 135 + 60 = 195
    jumlahderet(4) = 15*3^3 + jumlahderet(3)
    jumlahderet(4) = 405 + 195 = 600

    Kemudian, nilainya dikembalikan ke fungsi main

    notes : nilai dari jumlah deret akan 0 jika terdiri  atas lebih dari 38 suku.

*/

int main()
{

    cout << "\n============= DERET GEOMETRI DENGAN =============";
    cout << "\n                ALGORITMA REKURSIF               \n";

    unsigned long long int n;
    cout << "\nMasukkan suku ke-n : ";
    cin >> n;

    cout << "\nSuku ke-n bernilai : ";
    cout << deretgeometri(n) << "\n\n";
    // Memanggil fungsi Deret Geometri

    cout << "Jumlah suku ke-n bernilai : ";
    cout << jumlahderet(n) << "\n\n";

    cout << "====================================================\n";
    return 0;
}