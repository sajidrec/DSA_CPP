#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lld;

int main()
{
    lld num;
    string str = "";
    cout << "\nEnter the number in base 10 : ";
    cin >> num;

    while (num)
    {
        if (num % 2)
        {
            str.push_back('1');
        }
        else
        {
            str.push_back('0');
        }
        num /= 2;
    }

    reverse(str.begin(), str.end());

    cout << "\nBinary representation of the number : " << str << endl;

    return 0;
}