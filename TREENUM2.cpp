#include <bits/stdc++.h>
using namespace std;

#define LIMIT 1000001

long long mod = 1ll << 32;
map<unsigned long long, unsigned long long> tothree, tothreesum;

unsigned long long leftmost(unsigned long long n) {
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    n |= (n >> 32);
    return n - (n >> 1);
}

unsigned long long tothreeimpl(unsigned long long n) {
    unsigned long long res = 1;
    while (n > 1) {n /= 2; res = res * 3 % mod; }
    return res;
}
void calctwothree() {
    for (int i = 0; i <= 63; ++i) tothree[1ull << i] = tothreeimpl(1ull << i);
    tothreesum[1] = tothree[1];
    for (int i = 1; i <= 63; ++i) tothreesum[1ull << i] = (tothree[1ull << i] + tothreesum[1ull << (i-1)]) % mod;
}

unsigned long long threebits(unsigned long long n) {
    if (n == 0) return 0;
    unsigned long long left = leftmost(n);
    unsigned long long rest = left ^ n;
    return (rest+1) * tothree[left] + (left / 2) * tothreesum[left/2] + threebits(rest);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calctwothree();

    int t; cin >> t;
    while (t--) {
        unsigned long long l, r; cin >> l >> r;
        cout << (threebits(r) - threebits(l-1) + mod) % mod << '\n';
    }
}
