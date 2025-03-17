#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    vector <int> a = {-2,-5,6,-2,-3,1,5,-6};
    int max = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        int temp = 0;
        for (int j = i; j < a.size(); j++)
        {
            temp += a[j];
            if (temp > max)
            {
                max = temp;
            }
        }
    }
    cout << "Max sub array sum : " << max << endl;
}