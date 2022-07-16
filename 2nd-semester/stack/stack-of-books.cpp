#include <iostream>
#include <stack>

using namespace std;

int main()
{

    stack<string> tumpukan_buku;
    // push or insert book into stack
    tumpukan_buku.push("Numerical Analysis");
    tumpukan_buku.push("Discrete Mathematics and Its Applications");
    tumpukan_buku.push("Computer Networking: A Top Down Approach");
    tumpukan_buku.push("Introduction to Machine Learning");
    tumpukan_buku.push("Linear Algebra and Its Applications");
    tumpukan_buku.push("Fundamentals of Computer Graphics");

    cout << "\n\nKondisi susunan buku awal (dari yang paling atas) :" << endl;
    while (!tumpukan_buku.empty()) // print stack of books from top
    {
        int i;
        cout << tumpukan_buku.top() << endl;
        tumpukan_buku.pop();
    }

    cout << endl;
    cout << endl;

    // push or insert books into stack again
    tumpukan_buku.push("Numerical Analysis");
    tumpukan_buku.push("Discrete Mathematics and Its Applications");
    tumpukan_buku.push("Computer Networking: A Top Down Approach");
    tumpukan_buku.push("Introduction to Machine Learning");
    tumpukan_buku.push("Linear Algebra and Its Applications");
    tumpukan_buku.push("Fundamentals of Computer Graphics");

    while (true)
    {

        int i;
        string ambil = tumpukan_buku.top();

        // try to find books that will be taken out
        if (ambil != "Introduction to Machine Learning")
        {
            cout << "Buku yang berjudul " << ambil << " berhasil dikeluarkan!" << endl;
            tumpukan_buku.pop();
        }

        // searched book has been found
        else if (ambil == "Introduction to Machine Learning")
        {
            cout << "Buku Introduction to Machine Learning berhasil diambil!\n";
            tumpukan_buku.pop(); // searched book has been taken out
            tumpukan_buku.push("Linear Algebra and Its Applications");
            string letak1 = tumpukan_buku.top(); // insert book again
            cout << "Buku yang berjudul " << letak1 << " berhasil diletakkan kembali" << endl;
            tumpukan_buku.push("Fundamentals of Computer Graphics");
            string letak2 = tumpukan_buku.top(); // insert book again
            cout << "Buku yang berjudul " << letak2 << " berhasil diletakkan kembali" << endl;
            break;
        }
    }

    // print book of stack to check stack
    cout << "\n\nKondisi susunan buku akhir (dari yang paling atas) :" << endl;
    while (!tumpukan_buku.empty())
    {
        cout << tumpukan_buku.top() << endl;
        tumpukan_buku.pop();
    }

    cout << "\n\ncatatan : buku yang paling atas pada list merupakan buku yang berada di posisi paling atas pada tumpukkan buku.";

    return 0;
}