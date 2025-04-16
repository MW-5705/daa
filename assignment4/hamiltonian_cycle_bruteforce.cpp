// Online C++ compiler to run C++ program online
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector <int>> graph = {{0,1,0,1,0}, {1,0,1,1,1}, {0,1,0,0,1}, {1,1,0,0,1}, {0,1,1,1,0}};
    vector <int> path = {0,1,2,3,4};
    int n = graph.size();
    while (true)
    {
        bool  valid = true;
        for (int i = 0; i < n-1; i++)
        {
            if (!graph[path[i]][path[i+1]])
            {
                break;
                valid = false;
            }
        }
        if (valid)
        {
            if (graph[path[n-1]][path[0]])
            {
                cout << "Possible Solution: ";
                for (int i : path)
                {
                    cout << i << "  ";
                }
                    cout << path[0] << "  ";
                cout << endl;
                break;
            }
        }
        if (!next_permutation(path.begin(), path.end()))
        {
            break;
        }
    }


    return 0;
}
