#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    long long n, c[100001], p[100001];
    double minus, plus;

    fin>>n;
    for (int i=1; i<=n; i++)
        fin>>p[i];
    for (int i=1; i<=n; i++)
        fin>>c[i];
    fin.close();

    /* Search for the minimum of p[i] - c[i] and p[i] + c[i] */
    minus = p[1] - c[1];
    plus = p[1] + c[1];

    for (int i=2; i<=n; i++) {
        if (p[i] - c[i] < minus)
            minus = p[i] - c[i];
        if (p[i] + c[i] < plus)
            plus = p[i] + c[i];
        }

    double prag = (plus - minus)/2;
    fout<<fixed<<setprecision(1)<<plus - prag<<endl;
    fout.close();

    return 0;
}
