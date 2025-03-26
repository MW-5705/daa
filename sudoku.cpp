// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;


bool place(int k, int i, int j)
{
    for (int a = 0; a <= k; a++)
    {
        for (int b = 0; b <= i; b++)
        {
            if (ans[a][b] == j)
            {
                return 0;
            }
        }
    }
    return 1;
    
}

void sudoku(int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ans[k][i] == 0)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (place(k, i, j))
                {
                    ans[k][i] = j;
                    if ()
                }
            }
        }
    }
}

int main() {
    
    vector <vector<int>> ans = {{3,0,6,5,7,8,4,0,0},{5,2,0,0,0,0,0,0,0},{0,8,7,0,0,0,0,3,1}, {2,6,3,4,1,5,9,8,7},{9,7,4,8,6,3,1,2,5}, {8,5,1,7,9,2,6,4,3}, {1,3,8,9,4,7,2,5,6}, {6,9,2,3,5,1,8,7,4}, {7,4,5,2,8,6,3,1,9}};
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         cout << "Enter value of " << i+1 << " and " << j+1 << " place of sudoku:"
    //         cin >> ans[i][j];
    //     }
    // }
    
}
