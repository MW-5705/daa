// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

vector < vector <int>> a = {{0,1,1,1}, {1,0,1,0}, {1,1,0,1}, {1,0,1,0}};
vector <int> x(4, 0);
int n = x.size();
int m = 3;

int found = 0;

void nextValue(int k)
{
    while (true) 
    {
        x[k] = (x[k]+1)%(m+1);
        if (x[k] == 0)
        {
            return;
        }
        int i;
        for (i = 0; i < n; i++)
        {
            if (a[i][k] && x[k] == x[i])
            {
                break;
            }
        }
        if (i == n)
        {
            return;
        }

    }
}

void mcoloring(int k)
{
    while (true)
    {
        nextValue(k);
        if (x[k] == 0)
        {
            return;
        }
        if (k == n-1)
        {
            found ++;
            cout << "Solution Exists: " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << x[i] << "   ";
            }
            cout << endl;
            return;
            
        }
        else
        {
            mcoloring(k+1);
        }
    }
}

int main()
{
    mcoloring(0);
    if (found == 0)
    {
        cout << "No solution Exists";
    }
}

