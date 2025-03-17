
// Online C++ compiler to run C++ program online
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int sum(vector <int> a)
{
    int ans = 0;
    for (int i : a)
    {
        ans+=i;
    }
    return ans;
}

vector <int> crosssum(vector <int> &arr, int start, int mid, int end)
{
    int li = mid;
    int left = INT_MIN;
    int temp = 0;
    for (int i = mid; i >= start; i--)
    {
        temp += arr[i];
        if (temp > left)
        {
            left = temp;
            li = i;
        }
    }
    int ri = mid+1;
    int right = INT_MIN;
    temp = 0;
    for (int i = mid+1; i <= end; i++)
    {
        temp += arr[i];
        if (temp > right)
        {
            right = temp;
            ri = i;
        }
    }
    vector <int> ans;
    for (int i = li; i <= ri; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}
vector <int> mssa(vector <int> &arr, int start, int end)
{
    if (start == end)
    {
        vector<int> ans = {arr[start]};
        return ans;
    }
    int mid = (start+end)/2;
    vector <int> left = mssa(arr, start, mid);
    vector <int> right = mssa(arr, mid+1, end);
    vector <int> cross = crosssum(arr, start, mid, end);
    // cout << sum(left) << endl;
    // cout << sum(right) << endl;
    // cout << sum(cross) << endl;
    if (sum(left) >= sum(right) && sum (left) >= sum(cross))
    {
        return left;
    }
    else if (sum(right) >= sum(left) && sum (right) >= sum(cross))
    {
        return right;
    }
    else
    {
        return cross;
    }
    
    
}

int main()
{
    vector <int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};
    vector <int> ans = mssa(arr, 0, arr.size()-1);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}