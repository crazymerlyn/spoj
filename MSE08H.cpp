#include <bits/stdc++.h>

using namespace std;

long long phi(int n) {
    long long res = n;
    if (n % 2 == 0) res /= 2;
    while (n % 2 == 0) n /= 2;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i) continue;
        res -= res / i;
        while (n % i == 0) n /= i;
    }

    if (n > 1) res -= res / n;

    return res;
}

int main() {
    while (true) {
        int n; cin >> n;
        if (cin.eof()) break;
        vector<int> vs(n);
        for (int i = 0; i < n; ++i) cin >> vs[i];
        sort(vs.begin(), vs.end());

        long long res = 1;
        long long mod = 1e9 + 7;

        for (auto val: vs) {
            res = res * phi(val) % mod;
        }
        cout << res << endl;
    }
    return 0;
}


