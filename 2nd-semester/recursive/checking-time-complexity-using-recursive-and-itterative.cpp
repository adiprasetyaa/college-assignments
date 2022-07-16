#include <iostream>
#include <chrono>
#include <ratio>
#include <thread>

using namespace std;
using namespace std::chrono;

// recursive function of factorial number
int faktorial_r(int fact)
{

    if (fact == 1)
    {

        return 1;
    }

    else
    {

        return (fact * faktorial_r(fact - 1));
    }
}

// itterative function of factorial number
int faktorial_i(int fact)
{

    unsigned long long int sum = 1;
    for (int i = 2; i <= fact; i++)
    {
        sum = sum * i;
    }

    return sum;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\n=================== BILANGAN FAKTORIAL ===================\n";
        unsigned long long int fact;
        cout << "Masukkan bilangan faktorial \t\t\t: "; // user input factorial number
        cin >> fact;

        auto begin_itterative = high_resolution_clock::now();                            // timer start
        unsigned long long int fact_i = faktorial_i(fact);                               // calling itterative function
        auto end_itterative = high_resolution_clock::now();                              // timer stop
        auto itDuration = duration_cast<nanoseconds>(end_itterative - begin_itterative); // calculating time

        auto begin_recursive = high_resolution_clock::now();                            // timer start
        unsigned long long int fact_r = faktorial_r(fact);                              // calling recursive function
        auto end_recursive = high_resolution_clock::now();                              // timer stop
        auto RecDuration = duration_cast<nanoseconds>(end_recursive - begin_recursive); // calculating time

        cout << "\n=================== MENGGUNAKAN REKURSIF ===================\n";
        cout << "Hasil dari bilangan faktorial tersebut adalah \t: " << fact_i << "\n";
        cout << "Total waktu yang diperlukan \t\t\t: " << RecDuration.count() << " nanosecond" << endl;

        cout << "\n=================== MENGGUNAKAN ITTERATIVE ===================\n";
        cout << "Hasil dari bilangan faktorial tersebut adalah \t: " << fact_r << "\n";
        cout << "Total waktu yang diperlukan \t\t\t: " << itDuration.count() << " nanosecond" << endl;

        cout << "===============================================================";
    }

    return 0;
}