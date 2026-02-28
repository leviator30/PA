#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/* Data structures for an alphabet with our letters */
typedef struct alphabet {
    char character;
    int nrApparitions;
}TAlphabet;

vector<TAlphabet> alphabet;
char refLetter;

/* Function to add a letter in the alphabet if it didn't exist already */
void alphabetContains(char c) {
    for (int i=0; i<alphabet.size(); i++)
        if (alphabet[i].character == c) {
            alphabet[i].nrApparitions++;
            return;
            }

    TAlphabet elem;
    elem.character = c;
    elem.nrApparitions = 1;
    alphabet.push_back(elem);
}

/* Function to add a whole string in alphabet */
void addToAlphabet(string str) {
    for (int i=0; i<str.length(); i++)
        alphabetContains(str[i]);
}

/* Data structure that contains for each letter, the number of appearances and
total number of letters, we reinitialisate the array for each letter in
alphabet */
typedef struct Strings {
    string str;
    int app;
    int tot;
}TStrings;

vector<TStrings> strings;

/* Function to add a string in the array of TStrings type*/
void addString(string str) {
    int counter = 0;

    for (int i=0; i<str.size(); i++)
        if (str[i] == refLetter)
            counter++;

    TStrings elem;
    elem.app = counter;
    elem.str = str;
    elem.tot = str.size();

    strings.push_back(elem);
}

/* Compare function for sort */
bool comparator(TStrings elem1, TStrings elem2) {
    return (double)(elem1.app)/(double)(elem1.tot) >
        (double)(elem2.app)/(double)(elem2.tot);
}

int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    int n, res = 0;
    string arr[1001];

    /* Form our alphabet */
    fin>>n;
    for (int i=1; i<=n; i++) {
        fin>>arr[i];
        addToAlphabet(arr[i]);
        }
    fin.close();

    /* For each letter in alphaebet, we for an array of TStrings type that
    contains total number of letters and number of appearances for refLetter */
    for (int i=0; i<alphabet.size(); i++) {
        refLetter = alphabet[i].character;

        strings.clear();
        for (int i=1; i<=n; i++)
            addString(arr[i]);

        /* Sort by comparator */
        sort(strings.begin(), strings.end(), comparator);

        int sumTotal = 0;
        int sumApp = 0;

        vector<int> dp1(1001, 0);
        vector<int> dp2(1001, 0);

        /* DP of SCMAX type, like in Lab3 */
        for (int i=0; i<strings.size(); i++) {
            dp1[i] = strings[i].tot;
            dp2[i] = strings[i].app;
        }

        for (int i=1; i<strings.size(); i++)
            for (int j=0; j<i; j++)
                if ((double)((dp1[j] + strings[i].tot)/2.0) <
                    (double)(dp2[j] + strings[i].app)) {
                    if (dp1[j] + strings[i].tot > dp1[i]) {
                        dp1[i] = dp1[j] + strings[i].tot;
                        dp2[i] = dp2[j] + strings[i].app;
                    }
                }

        /* We select the biggest result in whole alphabet, that respect the
        restriction for dominant word */
        for (int i=0; i<strings.size(); i++)
            if (res < dp1[i] && dp1[i]/2 < dp2[i])
                res = dp1[i];
    }

    fout<<res;
    fout.close();

    return 0;
}
