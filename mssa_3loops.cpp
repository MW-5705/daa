#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    vector <int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};
    int max = arr[0];
    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            int temp = 0;
            for (int k = j; k < j + i; k++)
            {
                if (k < arr.size())
                {
                    temp += arr[k];
                }
            }
            if (temp > max)
            {
                max = temp;
            }
        }
    }
    cout << "Max sub array sum: " << max << endl;
}