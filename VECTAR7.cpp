#include <bits/stdc++.h>

using namespace std;
long long mod = 1e9 + 7;

long long mypow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

long long comb(int n, int r) {
    long long num = 1, denom = 1;
    for (int i = 1; i <= r; ++i) {
        denom = denom * i % mod;
        num = num * (n - i + 1) % mod;
    }
    return num * mypow(denom, mod - 2) % mod;
}

long long ways(int a, int b) {
    if (b <= 24) return 0;
    if (a >= 24 && b - a != 2) return 0;
    long long res = comb(min(a, 24) + 24, 24);
    return res * mypow(2, max(0, a - 24)) % mod;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << ways(min(a, b), max(a, b)) << endl;
    }
}
