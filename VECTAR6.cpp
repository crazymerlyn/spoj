#include <bits/stdc++.h>

using namespace std;

#define LIMIT 10000001
long long res[LIMIT], s[LIMIT];

int main() {
    int t; cin >> t;
    long long mod = 1e9 + 7;
    res[0] = 1;
    s[0] = 1;
    for (int i = 1; i < LIMIT; ++i) {
        res[i] = res[i-1] * s[i-1] % mod;
        s[i] = (s[i-1] + res[i]) % mod;
    }
    while (t--) {
        int n; cin >> n;
        cout << res[n] << "\n";
    }
}
