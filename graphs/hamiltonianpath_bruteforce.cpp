#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void hamiltonian_path(vector<vector<int>> path, int &count)
{

    vector <int> p;
    for (int i = 0; i < path.size(); i++)
    {
        p.push_back(i);
    }
    
    while (true)
    {
        bool valid = true;
        for (int i = 0; i < path.size()-1; i++)
        {
            if (!path[p[i]][p[i+1]])
            {
                valid = false;
            }
        }
        if (valid)
        {
            cout << "Hamiltonian path: ";
            for (int i : p)
            {
    
                cout<< i << " ";
            }
            cout << endl;
            count ++;
        }
        if (!next_permutation(p.begin(), p.end()))
        {
            break;
        }
        // cout << endl;
    }
}

int main()
{
    vector<vector <int>> path = {{0,1,0,0}, {1,0,1,1}, {0,1,0,1}, {0,1,1,0}};
    int count = 0;
    hamiltonian_path(path, count);
    if (count)
    {
        cout << "Above are the hamiltonian paths found for given graph \n";
    }
    else
    {
        cout << "no hamiltonian path found\n";
    }
}