#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 1e6;
    vector<int> facs(n+1, 0);
    for (int i = 2; i <= n; ++i) {
        if (facs[i] != 0) continue;
        for (int j = i; j <= n; j += i) ++facs[j];
    }
    vector<vector<int>> cum(11, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        if (facs[i] <= 10) cum[facs[i]][i] = 1;
        for (int j = 0; j <= 10; ++j) {
            cum[j][i] += cum[j][i-1];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b, n; cin >> a >> b >> n;
        cout << cum[n][b] - cum[n][a-1] << endl;
    }
    return 0;
}


