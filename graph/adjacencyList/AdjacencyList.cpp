#include <bits/stdc++.h>

using namespace std;

int main()
{

    int numOfVertex, numOfEdges;
    cin >> numOfVertex >> numOfEdges;

    // space complexity O(numOfVertex + numOfEdges);
    vector<vector<int>> vec;
    vec.assign(numOfVertex + 1, {});

    for (int i = 0; i < numOfEdges; i++)
    {
        int pointOne, pointTwo;
        cin >> pointOne >> pointTwo;
        vec[pointOne].push_back(pointTwo);
        vec[pointTwo].push_back(pointOne);
    }

    // draw the graph
    int edgeTrack = 0;
    for (auto x : vec)
    {
        if (!edgeTrack)
        {
            edgeTrack++;
            continue;
        }
        cout << edgeTrack << " : ";
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
        edgeTrack++;
    }

    return 0;
}