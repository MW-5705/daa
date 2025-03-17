// Online C++ compiler to run C++ program online
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int crossSum(vector <int> a, int s, int mid, int e)
{
    int left = 0;
    int temp = 0;
    for (int i = mid; i >= s; i--)
    {
        temp+=a[i];
        if (temp > left)
        {
            left = temp;
        }
    }
    int right = 0;
    temp = 0;
    for (int i = mid+1; i <= e; i++)
    {
        temp += a[i];
        if (temp > right)
        {
            right = temp;
        }
    }
    // cout << left << "   " << right << endl;
    right += left;
    return right;
}

int divide(vector <int> a, int s, int e)
{
    if (s==e)
    {
        return a[s];
    }
    int mid = (s+e)/2;
    // cout << mid << endl;
    int left = divide(a, s, mid);
    int right = divide(a, mid+1, e);
    int cross = crossSum(a, s, mid, e);
    // cout << left << "   " << right << "     "<< cross << max({left, right, cross}) << endl;
    // cout << ;
    return max({left, right, cross});
}

int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    vector <int> a = {5, 6, 7, 8, 9, 10};
    cout << divide(a, 0,5);

    return 0;
}