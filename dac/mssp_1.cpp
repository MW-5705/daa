#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max_cross(vector <int> a, int s, int mid, int e)
{
    int left = INT_MAX;
    for (int i = s; i < mid+1; i++)
    {
        if (a[i] < left)
        {
            left = a[i];
        }
    }
    int right = INT_MIN;
    for (int i = mid+1; i < e+1; i++)
    {
        if (a[i] > right)
        {
            right = a[i];
        }
    }
    return (right-left>=0)? right-left:0;
}

int max_profit(vector <int> a, int s, int e)
{
    if (s==e)
    {
        return 0;
    }
    int mid = (s+e)/2;
    int lp = max_profit(a, s, mid);
    int rp = max_profit(a, mid+1, e);
    int cp = max_cross(a, s, mid, e);
    return max({lp, rp, cp});
}

int main()
{
    vector <int> a = {1, 5, 3, 2};
    cout << "Max Profit: " << max_profit(a, 0, 3) << endl;
}