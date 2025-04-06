#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> a = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

int n = a.size();
vector <int>x(n, 0);
int found = 0;


void nextValue(int k, int m)
{
    while (true)
    {
        x[k] = (x[k] + 1)%(m+1);
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

void mcoloring(int k, int m)
{
    nextValue(k, m);
    if (x[k] == 0)
    {
        return;
    }
    if (k == n-1)
    {
        found ++;
        return;
    }
    else
    {
        mcoloring(k+1, m);
    }
}

int moptimization()
{
    int m = 1;
    while (m <= n)
    {
        found = 0;
        mcoloring(0, m);
        if (found)
        {
            return m;
        }
        m++;
    }
    return 0;


}

int main()
{
    int ans = moptimization();
    if (ans)
    {
        cout << "Minimum colors required: " << ans << endl;
    }
    else
    {
        cout << "No solution Exists\n";
    }
}
