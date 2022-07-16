#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main()
{

    queue<int> number;

    for (int i = 0; i < 8; i++)
    {

        string input;
        getline(cin, input);

        if (input == "PUSH 0")
        {
            number.push(0);
        }

        else if (input == "PUSH 1")
        {
            number.push(1);
        }

        else if (input == "TOP")
        {
            int belakang = number.back();
            cout << belakang << endl;
        }

        else if (input == "POP")
        {
            number.pop();
        }
    }

    return 0;
}