#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int crosssum(vector <int> &arr, int start, int mid, int end)
{
    int left = INT_MIN;
    int temp = 0;
    for (int i = mid ; i >= start ; i--)
    {
        temp += arr[i];
        if (temp > left)
        {
            left = temp;
        }
    }
    int right = INT_MIN;
    temp = 0;
    for (int i = mid+1 ; i <= end ; i++)
    {
        temp += arr[i];
        if (temp > right)
        {
            right = temp;
        }
    }
    return left+right;
    
}

int msas(vector <int> &arr, int start, int end)
{
    if (start == end)
    {
        return arr[start];
    }
    int mid = (start+end)/2;
    int left = msas(arr, start, mid);
    int right = msas(arr, mid+1, end);
    int cross = crosssum(arr, start, mid, end);
    return max({left, right, cross});
}

int  main()
{
    vector <int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};
    int max = msas(arr, 0, arr.size()-1);
    cout << "Max sub array sum: " << max << endl;
}