#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int s, int mid, int e)
{
    vector<int> ans;
    int i = s, j = mid+1;
    while (i <= mid && j <= e)
    {
        if (a[i]<a[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else
        {
            ans.push_back(a[j]);
            j++;
        }
    }
    while (i < mid+1)
    {
        ans.push_back(a[i]);
        i++;
    }
    while (j < e+1)
    {
        ans.push_back(a[j]);
        j++;
    }
    for (i = s; i <= e; i++)
    {
        a[i] = ans[i-s];
    }
}

void merge_sort(vector <int> &a, int s, int e)
{
    if (s == e)
    {
        return;
    }
    cout << "Hello";
    int mid = (s+e)/2;
    merge_sort(a, s, mid);
    merge_sort(a, mid+1, e);
    merge(a, s, mid, e);
}

int main()
{
    vector<int> a = {9,8,7,6,5,4,3,2,1};
    merge_sort(a, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl;
    return 0;
}