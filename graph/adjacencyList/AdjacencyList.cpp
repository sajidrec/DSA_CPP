#include <iostream>
#include <vector>

using namespace std;

typedef long long int lld;

class Graph
{
public:
    lld vertices = 0;
    vector<lld> *g;
    vector<bool> visitedG;

    Graph(lld vertices)
    {
        this->vertices = vertices;
        visitedG.assign(vertices, false);
        g = new vector<lld>[vertices + 1];
    }

    void addEdge(lld vertex, lld edge)
    {
        g[vertex].push_back(edge);
        g[edge].push_back(vertex);
    }

    void display()
    {
        for (lld i = 1; i <= vertices; i++)
        {
            cout << i << " : ";
            for (auto val : g[i])
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void dfs(lld vertex)
    {
        cout << vertex << " ";
        visitedG[vertex] = true;
        for (auto v : g[vertex])
        {
            if (!visitedG[v])
            {
                dfs(v);
            }
        }
    }
};

int main()
{
    // sample input
    // Graph g(7);
    // g.addEdge(1, 2);
    // g.addEdge(1, 3);
    // g.addEdge(1, 4);
    // g.addEdge(3, 5);
    // g.addEdge(4, 6);
    // g.addEdge(4, 5);
    // g.addEdge(6, 7);
    // g.addEdge(7, 5);
    // g.display();
    // cout << endl;
    // g.dfs(3);
    // cout << endl;
    return 0;
}
