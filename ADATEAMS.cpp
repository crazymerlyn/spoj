#include <bits/stdc++.h>
using namespace std;

#define LIMIT 1000001

long long mod = 1e9 + 7;
long long fact[LIMIT], invfact[LIMIT];

long long comb(long long a, long long b) {
    return (fact[a] * invfact[b] % mod) * invfact[a-b] % mod;
}

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for (int i = 1; i < LIMIT; ++i) fact[i] = fact[i-1] * i % mod;
    invfact[LIMIT-1] = power(fact[LIMIT-1], mod-2);
    for (int i = LIMIT - 2; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % mod;

    long long n, a, b, d;
    while (cin >> n >> a >> b >> d) {
        cout << comb(n, a) * power(comb(b, d), a) % mod << '\n';
    }
}
