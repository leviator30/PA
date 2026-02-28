#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> myMap;

typedef struct edge {
    string start;
    string finish;
} TEdge;

/* Edge structure and function to add in the vector of edges */
vector<TEdge> edges;

void addEdge(string x, string y) {
    edge node;
    node.start = x;
    node.finish = y;
    edges.push_back(node);
}

/* Topological sort function*/
void topSort(int u, vector<vector<int>>& graph, vector<bool>& visited,
stack<int>& topOrder) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            topSort(v, graph, visited, topOrder);
        }
    }

    topOrder.push(u);
}

/* Function to find the longest possible road in a graph */
int longestPath(vector<vector<int>>& graph, int start, int end) {
    vector<int> dist(graph.size(), -1);
    dist[start] = 1;

    /* Sort the cities topological */
    stack<int> topOrder;
    vector<bool> visited(graph.size(), false);
    for (int i = 0; i < myMap.size(); i++) {
        if (!visited[i]) {
            topSort(i, graph, visited, topOrder);
        }
    }

    /* We traverse the top sorted vector and for every city, we check if there
        is a better variant for connected cities from current city */
    while (!topOrder.empty()) {
        int u = topOrder.top();
        topOrder.pop();

        if (dist[u] == -1) {
            continue;
        }

        for (int v : graph[u])
            if (dist[u] + 1 > dist[v])
                dist[v] = dist[u] + 1;
    }

    return dist[end];
}

int main() {
    ifstream fin("trenuri.in");
    ofstream fout("trenuri.out");

    string start, finish;
    int n;
    int idx = 1;

    fin >> start >> finish;

    /* Read datas and create an entry in the HashMap for every city */
    fin >> n;
    for (int i = 0; i < n; i++) {
        string x, y;
        fin >> x >> y;
        if (myMap.find(x) == myMap.end()) {
            myMap[x] = idx;
            idx++;
            }

        if (myMap.find(y) == myMap.end()) {
            myMap[y] = idx;
            idx++;
            }

        addEdge(x, y);
    }

    fin.close();

    vector<vector<int>> graph(myMap.size()+1);

    /* Add edges in the graph as numbers */
    for (int i = 0; i < edges.size(); i++) {
        graph[myMap[edges[i].start]].push_back(myMap[edges[i].finish]);
    }

    fout << longestPath(graph, myMap[start], myMap[finish]);
    fout.close();

    return 0;
}
