#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1;
        cin >> s2;
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for (int i = 1; i <= n; ++i) dp[i][0] = i;
        for (int i = 1; i <= m; ++i) dp[0][i] = i;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
                if (s1[i-1] == s2[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}


