#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int row = 5;
    int col = 4;
    int matrix[row][col] = {
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0}
    };
    int dp[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int  j = 0; j < col; j++)
        {
            if (j == 0)
            {
                dp[i][j] = matrix[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = matrix[i][j];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    int max = 0;
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j])
            {
                dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // cout << dp[i][j] << "   ";
            if (max < dp[i][j])
            {
                max = dp[i][j];
            }
        }
        // cout << endl;
    }
    cout << "Length of max square is " << max << endl;
}