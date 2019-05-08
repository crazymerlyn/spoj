#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n = 10, m = 2000;
    vector<vector<long long>> dp(n+1, vector<long long>(m+1));
    for (int i = 1; i <= m; ++i) dp[1][i] = i;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j/2];
        }
    }
    for (int t1 = 1; t1 <= t; ++t1) {
        int n, m; cin >> n >> m;

        cout << "Data set " << t1 << ": " << n << " " << m << " " << dp[n][m] << endl; 
    }
    return 0;
}


