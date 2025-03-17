
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int partition(vector <int> &arr, int start, int end)
{
    int pivot = arr[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= end)
        {
            i++;
        }
        while (arr[j] > pivot && j >= start)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

        arr[start] = arr[j];
        arr[j] = pivot;
        return j;
}

void qs(vector <int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int part_ind = partition(arr, start, end);
    qs(arr, start, part_ind-1);
    qs(arr, part_ind+1, end);
}

int main() {
    vector <int> arr = {4, 9, 6, 7, 2, 3, 1, 5, 8};
    qs(arr, 0, arr.size()-1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}