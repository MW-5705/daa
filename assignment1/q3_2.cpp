#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int max = INT_MIN;
    for (int i = 2; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int temp = 0;
            for (int k = 0; k < i; k++)
            {
                if (j+k < 9)
                    temp+=a[j+k];
            }
            if (temp > max)
            {
                max = temp;
            }

        }
    }
    cout << "Max sub array sum: " << max << endl; 
}