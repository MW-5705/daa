#include <iostream>
using namespace std;

int main()
{
    int max = 0;
    int a[] = {0, 10, 5, 2};
    int size = 4;
    for (int i = 1; i < size; i++)
    {
        if (a[i] > a[max])
        {
            max = i;
        }
    }
    if (max == 0 || max == size-1)
    {
        cout << "Doesn't exist\n";
        return 0;
    }
    cout << "Peak index element is " << a[max] << " at index "<< max << endl;
}