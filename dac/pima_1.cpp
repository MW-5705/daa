#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int a[]= {10, 20, 30, 40, 35, 25, 15, 5};
    int s = 0;
    int e = 4;
    while (s <= e)
    {
        int mid = (s+e)/2;
        if (a[mid] > a[mid-1] && a[mid] > a[mid+1])
        {
            cout << "Peak element " << a[mid] << " at index " << mid << endl;
            return 0;
        }
        if (a[mid] > a[mid-1])
        {
            s = mid+1;
        }
        if (a[mid] > a[mid+1])
        {
            e = mid-1;
        }
    }
    cout << "Not found!!\n";
}