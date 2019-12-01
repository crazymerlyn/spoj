#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<float> ps(n);
        for (int i = 0; i < n; ++i) cin >> ps[i];
        vector<vector<double>> dp(n, vector<double>(k+1));
        dp[0][0] = 1-ps[0];
        if (k >= 1) dp[0][1] = ps[0];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i-1][0] * (1 - ps[i]);
        }

        for (int k1 = 1; k1 <= k; ++k1) {
            for (int i = max(1,k1-1); i < n; ++i) {
                dp[i][k1] = dp[i-1][k1] * (1 - ps[i]);
                dp[i][k1] += dp[i-1][k1-1] * ps[i];
            }
        }

        cout << setprecision(10) << dp[n-1][k] << endl;
    }
}
