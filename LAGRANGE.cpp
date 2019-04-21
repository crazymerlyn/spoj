#include <bits/stdc++.h>

using namespace std;

int main() {
    int limit = 1 << 15;
    int sqlimit = sqrt(limit);
    vector<vector<vector<int>>> dp(5, vector<vector<int>>(sqlimit + 1, vector<int>(limit + 1)));
    for (int i = 0; i * i <= limit; ++i) {
        for (int j = i; j <= sqlimit; ++j) {
            dp[1][j][i * i] = 1;
        }
    }
    for (int i = 0; i <= limit; ++i) {
        dp[2][0][i] = i == 0;
        for (int j = 1; j <= sqlimit; ++j) {
            dp[2][j][i] += dp[2][j-1][i];
            if (i >= j * j) dp[2][j][i] += dp[1][j][i - j * j];
        }
    }
    for (int i = 0; i <= limit; ++i) {
        dp[3][0][i] = i == 0;
        for (int j = 1; j <= sqlimit; ++j) {
            dp[3][j][i] += dp[3][j-1][i];
            if (i >= j * j) dp[3][j][i] += dp[2][j][i - j * j];
        }
    }
    for (int i = 0; i <= limit; ++i) {
        dp[4][0][i] = i == 0;
        for (int j = 1; j <= sqlimit; ++j) {
            dp[4][j][i] += dp[4][j-1][i];
            if (i >= j * j) dp[4][j][i] += dp[3][j][i - j * j];
        }
    }
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        cout << dp[4][sqlimit][n] << endl;
    }
    return 0;
}


