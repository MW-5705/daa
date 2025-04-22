#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}};

vector<int> x(graph.size(), 0);

void nextValue(int k)
{
    while (true)
    {
        x[k] = (x[k] + 1) % graph.size();
        if (x[k] == 0)
        {
            return;
        }
        if (graph[x[k - 1]][x[k]])
        {
            int i;
            for (i = 1; i < k; i++)
            {
                if (x[i] == x[k])
                {
                    break;
                }
            }
            if (i == k)
            {
                if (k < graph.size() or graph[x[k]][x[0]])
                {
                    return;
                }
            }
        }
    }
}

void hamiltonian(int k)
{
    while (true)
    {

        // cout << k << endl;
        nextValue(k);
        if (x[k] == 0)
        {
            return;
        }
        if (k == graph.size() - 1)
        {
            cout << "Hamiltonian Cycle: ";
            for (int i = 0; i < x.size(); i++)
            {
                cout << x[i] << "   ";
            }
            cout << x[0];
            cout << endl;
            return;
        }
        else
        {
            hamiltonian(k + 1);
        }
    }
}

int main()
{
    hamiltonian(1);
}