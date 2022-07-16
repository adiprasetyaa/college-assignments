#include <iostream>
#include <set>
#include <cmath>

// mengecek apakah `n` adalah bilangan prima
// return: `true` jika bilangan prima, `false` jika tidak

bool is_prime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::set<int> prime_numbers;

    // generate bilangan prima dari 1 sampai 100
    // dan masukkan ke dalam himpunan `prime_numbers`
    // tulis code anda di sini
    for (int j = 2; j <= 100; j++)
    {

        for (int i = 2; i <= j; i++)
        {

            if (j % i != 0)
            {
                prime_numbers.insert(j);
            }
        }
    }

    // cek bilangan prima
    std::cout << "Send Ctrl+C to exit" << std::endl;
    while (true)
    {
        int num;
        std::cout << "Enter a number: ";
        std::cin >> num;

        // cek apakah `num` adalah bilangan prima dari 1 dan 100
        // fungsi is_prime() memiliki kompleksitas O(N), adakah versi yang lebih baik? Ya, ada.
        // jika ada, perbaiki kondisi dalam if di bawah
        if (is_prime(num) && (num != 1))
        {
            std::cout << num << " is a prime number between 1 and 100" << std::endl;
        }
        else
        {
            std::cout << num << " is not a prime number between 1 and 100" << std::endl;
        }
    }

    return 0;
}