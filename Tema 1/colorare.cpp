#include <iostream>
#include <fstream>
#include <iomanip>

const int MOD = 1000000007;

using namespace std;

/* POW efficient function */
long pow(long base, long exponent) {
    long res = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }

    return res;
}

int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    int k, x[300001];
    char t[300001];
    long prod = 1;

    fin>>k;
    for (int i=1; i<=k; i++)
        fin>>x[i]>>t[i];
    fin.close();

    /* Posibilities to fill for the first block */
    if (t[1] == 'H') {
        prod *= 6;
        prod *= pow(3, x[1]-1);
        prod %= MOD;
    } else {
        prod *= 3;
        prod *= pow(2, x[1]-1);
        prod %= MOD;
        }

    /* Calculate posibilities to fill for each block in the array(explained in
    README) */
    for (int i=2; i<=k; i++) {
        if (t[i] == 'H') {
            if (t[i-1] == 'V') {
                prod *= 2*pow(3, x[i]-1);
                prod %= MOD;
            } else {
                prod *= pow(3, x[i]);
                prod %= MOD;
            }
        } else {
            if (t[i-1] == 'V') {
                prod *= pow(2, x[i]);
                prod %= MOD;
            } else {
                prod *= pow(2, x[i]-1);
                prod %= MOD;
            }
        }
    }

    fout<<prod;
    fout.close();

    return 0;
}
