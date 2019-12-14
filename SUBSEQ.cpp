#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> x(n+1), s(n+1);
        for (int i = 1; i <= n; ++i) cin >> x[i];
        for (int i = 1; i <= n; ++i) s[i] = s[i-1] + x[i];

        map<int, int> count;
        long long res = 0;
        for (auto sum : s) {
            res += count[sum - 47];
            count[sum] += 1;
        }
        cout << res << "\n";
    }
}
