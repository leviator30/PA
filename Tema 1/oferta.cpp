#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/* Function to calculate min for 2 values */
double min2(double a, double b) {
    if (a<b)
        return a;
    else
        return b;
}

/* Function to calculate min for 3 values */
double min3(double a, double b, double c) {
    if (a<=b && a<=c)
        return a;
    else if (b<=a && b<=c)
        return b;
    else
        return c;
}

int main() {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");

    int n, k;
    double v[100001];
    double dp[100001];

    fin>>n>>k;
    for (int i=1; i<=n; i++)
        fin>>v[i];
    fin.close();

    /* Calculate base case for 1, 2 and 3 elements*/
    dp[1] = v[1];
    dp[2] = v[1] + v[2] - (double)(min2(v[1], v[2])/2.0);

    if (min3(v[1], v[2], v[3]) > min2(v[1], v[2])/2 &&
        min3(v[1], v[2], v[3]) > min2(v[2], v[3])/2) {
            dp[3] = v[1] + v[2] + v[3] - min3(v[1], v[2], v[3]);
    } else if (min2(v[1], v[2])/2 > min3(v[1], v[2], v[3]) &&
        min2(v[1], v[2])/2 > min2(v[2], v[3])/2) {
            dp[3] = v[1] + v[2] + v[3] - (min2(v[1], v[2])/2.0);
    } else {
        dp[3] = v[1] + v[2] + v[3] - (min2(v[2], v[3])/2.0);
    }

    /* Dynamic programming, we add elements in the sum, based on previous
    results.We choose the best option to continue (best offer or no offer) */
    for (int i=4; i<=n; i++) {
        double nooffer = dp[i-1] + v[i];
        double offer2 = dp[i-2] + (v[i-1] + v[i]) -
            min2(v[i-1], v[i])/2.0;
        double offer3 = dp[i-3] + (v[i-2] + v[i-1] + v[i]) -
                min3(v[i-2], v[i-1], v[i]);

        dp[i] = min3(nooffer, offer2, offer3);
        }

    fout << fixed << setprecision(1) << dp[n];
    fout.close();
    return 0;
}
