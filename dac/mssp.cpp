#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 5, 3, 2};
    int max = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            if (a[j]-a[i] > max)
            {
                max = a[j]-a[i];
            }
        }
    }
    cout << "Max profit: " << max << endl;
}