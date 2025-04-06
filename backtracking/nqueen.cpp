#include <iostream>
#include <vector>
using namespace std;

vector<int> x(4, 0);

bool place(int k, int i)
{
    for (int j = 0; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }
    }
    return true;
}

void nqueen(int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n - 1)
            {
                cout << "Possible solution(column number at which the queen should be placed): " << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << x[i]+1 << "      ";
                }
                cout << endl;
            }
            else
            {
                nqueen(k + 1, n);
            }
        }
    }
}

int main()
{
    nqueen(0, 4);
}
