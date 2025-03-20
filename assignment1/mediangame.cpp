#include <climits>
#include <iostream>
using namespace std;

int main()
{
    int t, n;
    // cout << "Enter Number of testcases: ";
    cin >> t;
    
    while (t){
        int min = INT_MAX;
        int max = INT_MIN;
        // cout << "Enter Number of elements: ";
        cin >> n;
        int e;
        for (int i = 0; i < n; i++)
        {
            // cout << "Enter element: ";
            cin >> e;
            if (e < min)
            {
                min = e; 
            }
            if (e > max)
            {
                max = e;
            }
        }
        cout << max + min << endl;
        t--; 
    }
}