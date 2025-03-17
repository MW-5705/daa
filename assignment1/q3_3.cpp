#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int crosssum(vector<int> &a, int s, int mid, int e)
{
    int left = INT_MIN;
    int temp = 0;
    for (int i = mid; i >=s; i--)
    {
        temp += a[i];
        if (temp > left)
        {
            left = temp;
        }
    }
    int right = INT_MIN;
    temp = 0;
    for (int i = mid+1; i <= e; i++)
    {
        temp += a[i];
        if (temp > right)
        {
            right = temp;
        }
    }
    return left + right;
}

int mssa(vector <int>& a, int s, int e)
{
    if (s == e)
    {
        return a[s];
    }
    int mid = (s+e)/2;
    int l = mssa(a, s, mid);
    int r = mssa(a, mid+1, e);
    int cross = crosssum(a, s, mid, e);
    // cout << l << r << cross << endl;
    return max({l, r, cross});
}

int main()
{
    vector <int> a = {-6, -2, 8, 3, 4, -2};
    cout << "Max sum of sub array: " << mssa(a, 0, 5);
}