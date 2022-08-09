#include <iostream>

using namespace std;

const int n = 1e3;

// if weighted graph then change type to int or whatever
bool graph[n][n];

void drawGraph(int numOfVertex)
{
    for (int i = 1; i <= numOfVertex; i++)
    {
        for (int j = 1; j <= numOfVertex; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void connectVertex(int row, int col)
{
    // for weighted graph value should be assigned here
    graph[row][col] = 1;
    // for directed graph comment out below line
    graph[col][row] = 1;
}

int main()
{
    int numOfvertex, edges;
    cin >> numOfvertex >> edges;

    for (int i = 0; i < edges; i++)
    {
        int row, col;
        cin >> row >> col;
        connectVertex(row, col);
    }

    drawGraph(numOfvertex);
    return 0;
}