#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l; cin >> n >> l;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) cin >> s[i];
        sort(s.begin(), s.end());
        int limit = s[n-1] + l + 2;
        long long mod = 1e9 + 7;
        vector<long long> dp(limit);
        for (auto v: s) dp[v] += 1;
        for (int i = s[n-1] + 1; i < limit; ++i) dp[i] = 1;
        for (int i = s[n-1]; i >= 0; --i) dp[i] = (dp[i+1] + dp[i] * dp[i + l]) % mod;

        cout << (dp[0] + mod - 1) % mod << endl;
    }
    return 0;
}


