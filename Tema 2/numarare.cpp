#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

typedef struct egde {
    int start;
    int finish;
} TEdge;

/* Comparator to sort edges */
bool comparator(TEdge elem1, TEdge elem2) {
    if (elem1.start != elem2.start)
        return elem1.start < elem2.start;
    return elem1.finish < elem2.finish;
}

int main() {
    ifstream fin("numarare.in");
    ofstream fout("numarare.out");

    int n, m;

    fin>>n>>m;

    vector<TEdge> arr;

    /* Read all the edges */
    for (int i=0; i<2*m; i++) {
        int x, y;
        fin>>x>>y;
        TEdge node;
        node.start = x;
        node.finish = y;
        arr.push_back(node);
    }

    fin.close();

    /* Sort edges */
    sort(arr.begin(), arr.end(), comparator);

    vector<vector<int>> commonGraph(n + 1);

    /* If there are 2 identical consecutive edges, we put the edge in the
        common graph */
    for (int i=0; i<arr.size()-1; i++) {
        if (arr[i].start==arr[i+1].start && arr[i].finish==arr[i+1].finish) {
            commonGraph[arr[i].start].push_back(arr[i].finish);
            i++;
            }
    }

    /* We use dinamic programming, our solution is based on previous solutions.
        Number of roads to a node is based on the sum of number of roads to 
        previous nodes */
    vector<int> dp(n+1, 0);
    dp[1] = 1;

    for (int i=1; i<commonGraph.size(); i++) {
        for (int j=0; j<commonGraph[i].size(); j++)
            dp[commonGraph[i][j]] = (dp[commonGraph[i][j]] + dp[i]) % MOD;
        }

    fout << dp[n] % MOD << endl;
    fout.close();

    return 0;
}
