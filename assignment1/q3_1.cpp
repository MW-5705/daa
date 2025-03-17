#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int sum = INT_MIN;
    int a[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    for (int i = 0; i < 8; i++)
    {
        int temp = 0;
        for (int j = i; j < 8; j++)
        {
            temp+=a[j];
            if (temp > sum)
            {
                sum = temp;
            }
        }
    }
    cout << "Final sum of max sub array: " << sum << endl;
}