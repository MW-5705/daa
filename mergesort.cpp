#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    int l = start;
    int r = mid+1;
    vector <int> merged;
    while (l < mid+1 && r < end+1)
    {
        if (arr[l] > arr[r])
        {
            merged.push_back(arr[r]);
            r++;
        }
        else
        {
            merged.push_back(arr[l]);
            l++;
        }
    }
    while (l < mid+1)
    {
        merged.push_back(arr[l]);
        l++;
    }
    while (r < end+1)
    {
        merged.push_back(arr[r]);
        r++;
    }
    for (int i = start; i < end+1; i++)
    {
        arr[i] = merged[i-start];
    }
}

void mergesort(vector <int> &arr, int start, int end)
{
    if (start == end)
    {
        return;
    }
    int mid = (start+end)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main()
{
    vector <int> arr = { 12, 11, 13, 5, 6, 7 };
    mergesort(arr, 0, arr.size()-1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}