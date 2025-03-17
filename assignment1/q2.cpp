#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> a = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int start = 0, end = a.size()-1, target = 23;
    while (start <= end)
    {
        int mid = (start+end)/2;
        if (a[mid] == target)
        {
            cout << "Found \n";
            return 0;
        }
        if (target > a[mid])
        {
            start = mid+1;
        }
        if (target < a[mid])
        {
            end = mid-1;
        }
    }
    cout << "Not found\n";

}