#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int size = 10;
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int start = 0; int end = size-1;
    int target = 23;
    while (start <= end)
    {
        int mid = (start+end)/2;
        if (arr[mid] == target)
        {
            cout << "Found at index: " << mid;
            return 0;
        }
        else if (arr[mid] > target)
        {
            end = mid-1;
        }
        else
        {
            start = mid +1;
        }
    }
    cout << "Not found";
    return 1;
}