#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    vector <int> a = {-2,-5,6,-2,-3,1,5,-6};
    int max = INT_MIN;
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (i + j > a.size())
            {
                break;
            }
            int temp = 0;
            for (int k = 0; k < i; k++)
            {
                temp += a[j+k];
            } 
            if (temp > max)
            {
                max = temp;
            }
        }
    }
    cout << "Max sub array sum: " << max << endl;

}