#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int crossp(vector <int> &arr, int start, int mid, int end)
{
    int left = INT_MAX;
    for (int i = start; i <= mid ; i++)
    {
        if (arr[i] < left)
        {
            left = arr[i];
        }
    }
    int right = INT_MIN;
    for (int i = mid+1; i <= end ; i++)
    {
        if (arr[i] > right)
        {
            right = arr[i];
        }
    }
    if (right <= left)
    {
        return 0;
    }
    return right - left;
    
}

int mssp(vector <int> &arr, int start, int end)
{
    if (start == end)
    {
        return 0;
    }
    int mid = (start+end)/2;
    int left = mssp(arr, start, mid);
    int right = mssp(arr, mid+1, end);
    int cross = crossp(arr, start, mid, end);
    return max({left, right, cross});
}

int  main()
{
    vector <int> arr = {1,5,3,2};
    int max = mssp(arr, 0, arr.size()-1);
    cout << "Max profit: " << max << endl;
}