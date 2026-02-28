#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int n, m, v1[300001], v2[300001], ctr1=0, ctr2 = 1;

    fin>>n;
    for (int i=1; i<=n; i++)
        fin>>v1[i];
    fin>>m;
    for (int i=1; i<=m; i++)
        fin>>v2[i];
    fin.close();

    /* we go in parallel with ctr1 and ctr2 for each array */
    for (int i=1; i<=n; i++) {
        if (v1[i]==v2[ctr2]) {
            ctr1++;
            ctr2++;
        } else if (v1[i] > v2[ctr2]) {
            v1[i] -= v2[ctr2];
            ctr2++;
            i--;
        } else {
            v2[ctr2] -= v1[i];
        }
    }

    if (v1[n] != v2[m])
        fout<<-1<<endl;
    else
        fout<<ctr1<<endl;

    fout.close();

    return 0;
}
