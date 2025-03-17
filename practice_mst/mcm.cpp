#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void paren(vector <vector<int>> &s, int i, int j)
{
    if (i == j)
    {
        cout << "A"<<i;
    }
    else
    {
        cout << "(";
        paren(s, i, s[i][j]);
        paren(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    int size = 5;
    int p[] = {4,10,3,12,20,7};
    int m[size+1][size+1];
    vector <vector <int>> s(size+1, vector <int>(size+1,0));
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <=size ;j++)
        {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }
    for (int l = 2; l <= size; l++)
    {
        for (int i = 1, n = size-l+1; i <= n; i++)
        {
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << m[i][j] << "    ";
        }
        cout << endl;
    }
    paren(s, 1, size);
    // for (int i = 1; i <= size; i++)
    // {
    //     for (int j = 1; j <= size; j++)
    //     {
    //         cout << s[i][j] << "    ";
    //     }
    //     cout << endl;
    // }
}