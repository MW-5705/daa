#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ans = 0;
    int n, k;
    cin >> n;
    cin >> k;
    vector <int> a;
    int e;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        a.push_back(e); 
    }
    // int i = 0;
    // while (k <= n-i)
    // {
    //     int j = i+1;
    //     int count = 0;
    //     while (j < n)
    //     {
    //         if (a[j] > a[i])
    //         {
    //             count ++;
    //         }
    //         j++;
    //     }
    //     if (count == k)
    //     {
    //         ans += a[i];
    //     }
    //     i++;
    // }
    sort(a.begin(), a.end());
    for (int i = 0; i < n-k ; i++)
    {
        ans+=a[i];
    }
    cout << ans;

}