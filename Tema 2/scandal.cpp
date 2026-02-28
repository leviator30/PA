#include <bits/stdc++.h>

using namespace std;

/* Function to perform DFS for finding strongly connected components (SCCs) */
void dfs(int u, const vector<vector<int>>& graph, vector<int>& low,
        vector<int>& disc, stack<int>& st, vector<bool>& onStack,
        vector<vector<int>>& sccs, int& time) {
    disc[u] = low[u] = time++;
    st.push(u);
    onStack[u] = true;

    /* Explore neighbors of node 'u' */
    for (int v : graph[u]) {
        if (disc[v] == -1) {
            /* Recursively call DFS if 'v' is not visited */
            dfs(v, graph, low, disc, st, onStack, sccs, time);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    /* If 'u' is the start of a SCC, pop the stack to construct SCC */
    if (low[u] == disc[u]) {
        vector<int> scc;
        while (true) {
            int v = st.top();
            st.pop();
            onStack[v] = false;
            scc.push_back(v);
            if (u == v) break;
        }
        sccs.push_back(scc);
    }
}

/* Tarjan's algorithm for finding SCCs in a graph */
vector<vector<int>> tarjanSCC(int n, const vector<vector<int>>& graph) {
    vector<int> disc(n + 1, -1);    // Discovery time
    vector<int> low(n + 1, -1);     // Low value
    vector<bool> onStack(n + 1, false);
    stack<int> st;                  // Stack for DFS
    vector<vector<int>> sccs;       // Strongly connected components
    int time = 0;

    /* Perform DFS from each unvisited node to find SCCs */
    for (int i = 1; i <= n; i++) {
        if (disc[i] == -1) {
            dfs(i, graph, low, disc, st, onStack, sccs, time);
        }
    }

    return sccs;
}

/* DFS function for topological sorting */
void DFS(int u, vector<vector<int>>& graph, vector<bool>& visited, stack<int>&
            finished) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            DFS(v, graph, visited, finished);
        }
    }
    finished.push(u);
}

/* Function for topological sorting using DFS */
vector<int> topologicalSort(int n, vector<vector<int>>& graph) {
    vector<bool> visited(n + 1, false);
    stack<int> finished;

    /* Perform DFS from each unvisited node */
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, graph, visited, finished);
        }
    }

    /* Build the result from the stack (nodes are in reverse order of finish
    time) */
    vector<int> result;
    while (!finished.empty()) {
        result.push_back(finished.top());
        finished.pop();
    }

    return result;
}

int main() {
    ifstream fin("scandal.in");
    ofstream fout("scandal.out");

    int n, m;
    fin>>n>>m;

    vector<vector<int>> graph(2*n+1);

    /* Read graph edges and construct the adjacency list */
    for (int i=0; i<m; i++) {
        int u, v, c;
        fin>>u>>v>>c;

        if (c==0) {
            graph[n+u].push_back(v);
            graph[n+v].push_back(u);
        } else if (c==1) {
            graph[n+u].push_back(n+v);
            graph[v].push_back(n+u);
        } else if (c==2) {
            graph[n+v].push_back(n+u);
            graph[u].push_back(v);
        } else {
            graph[u].push_back(n+v);
            graph[v].push_back(n+u);
        }
    }

    /* Find Strongly Connected Components (SCCs) using Tarjan's algorithm */
    vector<vector<int>> sccs = tarjanSCC(2*n, graph);

    /* Mapping nodes to their SCC id */
    vector<int> sccId(2 * n + 1, -1);
    int sccIndex = 0;
    for (const auto& scc : sccs) {
        for (int node : scc) {
            sccId[node] = sccIndex;
        }
        sccIndex++;
    }

    /* Building the SCC graph */
    vector<vector<int>> sccGraph(sccIndex);
    for (int u = 1; u <= 2 * n; u++)
        for (int v : graph[u])
            if (sccId[u] != sccId[v])
                sccGraph[sccId[u]].push_back(sccId[v]);


    /* Topological sort on the SCC graph */
    vector<int> topoOrder = topologicalSort(sccIndex, sccGraph);

    /* Determine the solution */
    vector<int> solution(n + 1, -1);
    for (int u : topoOrder) {
        for (int node : sccs[u]) {
            int actualNode;
            if (node > n) {
                actualNode = node - n;
            } else {
                actualNode = node;
            }

            /* Assign values based on SCC membership */
            if (solution[actualNode] == -1) {
                if (node > n) {
                    solution[actualNode] = 1;
                } else {
                    solution[actualNode] = 0;
                }
            }
        }
    }

    /* Count and output the result */
    int S = 0;
    for (int i = 1; i <= n; i++) {
        if (solution[i] == 1) {
            S++;
        }
    }

    fout<<S<<endl;
    for (int i = 1; i <= n; i++) {
        if (solution[i] == 1) {
            fout<<i<<endl;
        }
    }

    return 0;
}
