#include <iostream>

using namespace std;

int power(int base, int p)
{
    int ans = 1;

    while (p)
    {
        if (p & 1)
        {
            ans *= base;
        }
        base *= base;
        p >>= 1;
    }

    return ans;
}

int main()
{
    string binStr;
    int ans = 0;
    cout << "\nEnter binary number : ";
    cin >> binStr;
    for (int i = 0; i < binStr.size(); i++)
    {
        if (binStr[i] == '1')
        {
            ans += power(2, (binStr.size() - i) - 1);
        }
    }
    cout << "\nDecimal of that number : " << ans << endl;

    return 0;
}