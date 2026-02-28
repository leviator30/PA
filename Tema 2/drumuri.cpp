#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max();

/* Dijkstra Algorithm to find the shortest paths to every node in a graph */
vector<long long> Dijkstra(int n, int source,
vector<vector<pair<int, long long>>>& graph) {
    vector<long long> distances(n+1, INF);

    distances[source] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (d > distances[u])
            continue;

        for (const auto& neigh : graph[u]) {
            int v = neigh.first;
            long long w = neigh.second;

            /* Update distances */
            if (distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                pq.push({distances[v], v});
            }
        }
    }

    return distances;
}


int main() {
    ifstream fin("drumuri.in");
    ofstream fout("drumuri.out");

    int n, m;
    fin>>n>>m;

    vector<vector<pair<int, long long>>> graph(n+1);
    vector<vector<pair<int, long long>>> inversed_graph(n+1);

    for (int i=0; i<m; i++) {
        int u, v;
        long long c;
        fin>>u>>v>>c;
        graph[u].push_back({v, c});
        inversed_graph[v].push_back({u, c});
    }

    int start1, start2, finish;
    fin >> start1 >> start2 >> finish;

    fin.close();

    /* Find distances with Dijkstra from the given 3 points */
    vector<long long> dijkstra1 = Dijkstra(n, start1, graph);
    vector<long long> dijkstra2 = Dijkstra(n, start2, graph);
    vector<long long> dijkstra_finish = Dijkstra(n, finish, inversed_graph);

    unsigned long long min_sum = dijkstra_finish[start1] +
        dijkstra_finish[start2];

    /* We find the sum from start1, start2 and final to every node in the
    graph, and select the minimum */
    for (int i=1; i<=n; i++) {
        if (min_sum > dijkstra1[i] + dijkstra2[i] + dijkstra_finish[i] &&
            dijkstra1[i]!=INF && dijkstra2[i]!=INF && dijkstra_finish[i]!=INF)
            min_sum = dijkstra1[i] + dijkstra2[i] + dijkstra_finish[i];
    }

    fout<<min_sum;
    fout.close();

    return 0;
}
