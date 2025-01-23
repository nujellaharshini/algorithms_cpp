#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Global Variables
vector<vector<int>> m;
vector<vector<int>> s;
int size;

// Function Declaration
pair<vector<vector<int>>, vector<vector<int>>> MatrixChainOrder(int *);
void PrintOptimalParens(vector<vector<int>>&, int, int);

int main() {
    int *p = NULL;

    cin >> size;
    p = new int[size + 1];
    for (int i = 0; i < size + 1; i++) {
        cin >> p[i];
    }

    auto result = MatrixChainOrder(p);
    cout << result.first[1][size] << endl;
    PrintOptimalParens(result.second, 1, size);
    cout << endl;

    delete [] p;
    return 0;
}
/** matrix-chain-order pseudo: 
    n = p.length - 1
    let m[1...n, 1...n] and s[1...n-1, 2...n] be new tables
    for i = 1 to n
        m[i,j] = 0
    for l = 2 to n
        for i = 1 to n - l + 1
            j = i + l - 1
            m[i,j] = inf
            for k = i to j - 1
                q = m[i,k] + m[k + 1,j] + p(i-1)*p(k)*p(j)
                if q < m[i,j]
                    m[i,j] = q
                    s[i,j] = k
    return m and s
**/

pair<vector<vector<int>>, vector<vector<int>>> MatrixChainOrder(int *p) {
// compute m[i][j] and s[i][j] using DP
    int n = p[0];
    m.resize(n + 1, vector<int>(n + 1));
    s.resize(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return make_pair(m, s);
}

void PrintOptimalParens(vector<vector<int>>& s, int i, int j) {
    if(i == j) {
        cout << "A" << i - 1;  //key
    } else {
        cout << "(";
        PrintOptimalParens(s, i, s[i][j]);
        PrintOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

