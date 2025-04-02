// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

vector < vector <int>> a = {{0,1,1,1}, {1,0,1,0}, {1,1,0,1}, {1,0,1,0}};
vector <int> x(4, 0);

bool nextValue(int k)
{
    while (true)
    {
        x[k] = (x[k]+1)%(3+1);
        if (x[k] == 0)
        {
            return false;
        }
        int flag = 1;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[k][i] && x[i] == x[k])
            {
                flag == 0;
            }
        }
        if (flag)
        {
            return true;
        }
    }
}

void mcoloring(int k)
{
    if (nextValue(k))
    {
        if (k == a.size()-1)
        {
            for (int i = 0; i < x.size(); i++)
            {
                if (x[i] == 0)
                {
                    cout << "No solution possible\n";
                    return;
                }
            }
            cout << "solution found: ";
            for (int i : x)
            {
                cout << i << "  ";
            }
            cout << endl;
            return;
        }
        mcoloring(k+1);
    }
}

int main() {
    mcoloring(0);
}
