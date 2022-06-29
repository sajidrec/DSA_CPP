#include <iostream>
#include <vector>

using namespace std;

typedef long long int lld;

// return 1 based indexing if element found or else will return -1
lld findElement(vector<lld> &vec, lld left, lld right, lld element)
{
    if (left > right)
    {
        return -1;
    }
    lld mid = (left + right) / 2;

    if (vec[mid] == element)
    {
        return mid + 1;
    }
    if (vec[mid] > element)
    {
        return findElement(vec, left, mid - 1, element);
    }
    else
    {
        return findElement(vec, mid + 1, right, element);
    }
}

int main()
{
    vector<lld> vec = {2, 4, 5, 77, 754, 945, 994};
    // need to pass size-1 for zero based indexing     
    cout << findElement(vec, 0, vec.size()-1, 2) << endl;

    return 0;
}
