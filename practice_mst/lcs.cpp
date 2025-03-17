#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    string a = "aggtab";
    string b = "gxtxayb";
    int m = a.size();
    int n = b.size();
    int c[m+1][n+1];
    for (int i = 0; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i-1] == b[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else
            {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << c[i][j] << "    ";
        }
        cout << endl;
    }
}