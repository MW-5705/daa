// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

bool is_safe(vector <vector <int>> &a, int row, int col, int n)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[row][i] == n)
        {
            return false;
        }
        if (a[i][col] == n)
        {
            return false;
        }
    }
    
    int row_s = row-row%3;
    int col_s = col-col%3;
    for (int i = row_s; i < row_s+3; i++)
    {
        for (int j = col_s; j < col_s+3; j++)
        {
            if (a[i][j] == n)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>> &a, int row, int col)
{
    if (row == a.size()-1 && col == a.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << a[i][j] << "    ";
            }
            cout << endl;
        }
        cout<<"Hello" << endl;
        return true;
    }
    
    if (col == a.size())
    {
        row ++;
        col = 0;
    }
    if (a[row][col] != 0)
    {
        return solveSudoku(a, row, col+1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (is_safe(a,row, col, i))
            {
                a[row][col] = i;
                if (solveSudoku(a, row, col))
                {
                    return true;
                }
                a[row][col] = 0;
            }
        }
    }
    return false;
    
}


int main() {
    vector < vector <int>> a = {{5,0,4,0,0,0,0,6,0}, {0,6,0,3,0,0,1,0,0}, {0,9,2,5,4,0,0,0,0}, {6,0,8,0,0,1,0,0,0}, {0,0,0,8,0,4,0,0,0}, {0,0,0,2,0,0,6,0,1}, {0,0,0,0,9,5,8,1,0}, {0,0,1,0,0,2,0,3,0}, {0,8,0,0,0,0,2,0,0}};
    solveSudoku(a, 0, 0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << a[i][j] << "    ";
        }
        cout << endl;
    }
}
    

