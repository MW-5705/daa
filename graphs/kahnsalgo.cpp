// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

vector <int> indeg(vector <vector <int>> graph)
{
    vector <int> indegree;
    for (int col = 0; col < graph.size(); col++)
    {
        int in = 0;
        for (int row = 0; row < graph.size(); row++)
        {
            in += graph[row][col];    
        }
        indegree.push_back(in);
    }
    return indegree;
}

vector<int> zero_indegree(vector<int> indegree)
{
    vector <int> ans;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

void kahns_algo(vector <vector <int>> graph)
{
    int n = graph.size();
    vector<int> indegree = indeg(graph);
    vector <int> l;
    vector <int> s;
    vector<int> temp = zero_indegree(indegree);
    s = temp;
    
   while (!s.empty())
   {
       int node = s[0];
       l.push_back(s[0]);
       s.erase(s.begin());
       for (int i = 0; i < n; i++)
       {
           if (graph[node][i])
           {
               indegree[i]--;
               if (indegree[i] == 0)
               {
                   s.push_back(i);
               }
           }
       }
   }
   vector<int> comparator(n, 0);
   if (indegree == comparator)
   {
       cout << "Found Order: ";
       for (int i : l)
       {
           cout << i << "   ";
       }
       cout << endl;
   }
   
    
}

int main() {
    // Write C++ code here
    
    vector <vector <int>> graph = {
        {0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
    };
    kahns_algo(graph);

    return 0;
}
