#include <bits/stdc++.h>

using namespace std;

long long func_old(long long p, long long n) {
    long long res = 0;
    while (n) {
        n /= p;
        res += n;
    }
    return res;
}

__int128 func(__int128 p, __int128 n) {
    if (n < p) return 0;
    auto v = n / p;
    auto r = n - v*p + 1;
    __int128 res = p*v*(v-1) / 2 + func(p, v-1) * p;
    res += v*r + r *func_old(p, v);
    return res;
}

string pretty(__int128 x) {
    if (x == 0) return "0";
    vector<char> res;
    while (x) {
        res.push_back(48 + x % 10);
        x /= 10;
    }
    return string(res.rbegin(), res.rend());
}

int main() {
    int t; cin >> t;
    while (t--) {
        long long p, n; cin >> p >> n;
        auto res = func(p, n);
        cout << pretty(res) << "\n";
    }
}
