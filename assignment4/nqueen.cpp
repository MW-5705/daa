// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

vector <int> ans(4, 0);

bool place(int k, int i)
{
    for (int j = 0; j < k; j++)
    {
        if ((ans[j] == i) || (abs(j-k) == abs(ans[j]-i)))
        {
            return 0;
        }
    }
    return 1;
    
}

void nqueen(int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (place(k, i))
        {
            ans[k] = i;
            if (k == n-1)
            {
                cout << "Answer: \n";
                for (int i = 0; i < n; i++)
                {
                    cout << ans[i] << " ";
                }
                cout << endl;
            }
            else
                nqueen(k+1, n);
        }
    }
}

int main() {
    nqueen(0,4);
}
