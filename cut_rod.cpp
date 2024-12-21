#include <iostream>
#include <climits>
using namespace std;

int cutRod(int p[], int n){
    if (n == 0){
        return 0;
    }
    int q = INT_MIN;
    for (int i = 1; i <= n; i++){
        q = max(q, p[i] + cutRod(p, n - i));
    }
    return q;
}

int bottomUpCutRod(int p[], int n, int*& s) {
    int* r = new int[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            if (q < p[i] + r[j - i]) {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return r[n];
}

void printCutRodSolution(int p[], int n) {
    int* s = new int[n + 1]; // Initialize s array
    int maxRevenue = bottomUpCutRod(p, n, s);
    cout << maxRevenue << endl;

    while (n > 0) {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << "-1" << endl;
    delete[] s;
}

int main() {
    int n;
    cin >> n;
    int p[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    printCutRodSolution(p, n);
    return 0;
}

