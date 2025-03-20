#include <iostream>
#include <vector>
using namespace std;

bool func(vector<int> nums, int i, int j)
{
    return nums[i] == nums[j];
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int i;
    vector <int> nums;
    for (i = 0; i < n; i++)
    {
        int ele;
        cout << "Enter element: ";
        cin >> ele;
        nums.push_back(ele);
    }
    int res = 0;
    int count = 1;
    for (i = 1; i < n; i++)
    {
        if (func(nums, res, i))
        {
            count ++;
        }
        else
        {
            if (count)
            {
                count --;
            }
            else
            {
                res = i;
                count  = 1;
            }
        }
    }
    cout << "Majority element: " << nums[res] << endl;
}