#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    vector <int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};
    int max = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = 0;
        for (int j = i; j < arr.size(); j++)
        {
            temp += arr[j];
            if (temp > max)
            {
                max = temp;
            }
        }
    }
    cout << "Max Sub Array sum for given array: " << max;
}