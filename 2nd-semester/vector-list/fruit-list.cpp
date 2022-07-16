#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<string> fruit_list;
    // insert fruit to fruit list
    fruit_list.push_back("Apple");
    fruit_list.push_back("Orange");
    fruit_list.push_back("Banana");
    fruit_list.push_back("Orange");
    fruit_list.push_back("Banana");
    fruit_list.push_back("Mango");

    cout << "\nList Awal" << endl;

    /// print list before deletion
    for (int i = 0; i < fruit_list.size(); i++)
    {

        cout << "Fruit List [" << i << "] : " << fruit_list[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < fruit_list.size(); i++)
    {
        if (fruit_list[i] == "Orange")
        {
            cout << "List fruit pada indeks ke-" << i << " yang berisi " << fruit_list[i] << " Berhasil dihapus!" << endl;
            fruit_list.erase(fruit_list.begin() + i); // delete list
        }
    }

    cout << "\nList Akhir" << endl;

    // print list after deletion
    for (int i = 0; i < fruit_list.size(); i++)
    {

        cout << "Fruit List [" << i << "] : " << fruit_list[i] << endl;
    }

    cout << endl;

    return 0;
}