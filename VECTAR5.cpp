#include <bits/stdc++.h>

using namespace std;

long long mypow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main() {
    int t; cin >> t;
    long long mod = 1e9 + 7;
    while (t--) {
        int n; cin >> n;
        long long res = mypow(4, n, mod);
        res = (res + mypow(2, n, mod)) % mod;
        res = (res + mod - mypow(3, n, mod)) % mod;
        res = (res + mod - mypow(3, n, mod)) % mod;
        cout << res << endl;
    }
}
