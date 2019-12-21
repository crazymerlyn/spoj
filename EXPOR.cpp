#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long t; cin >> t;
    while (t--) {
        unsigned long long n; cin >> n;
        vector<unsigned long long> xs(n);
        for (unsigned long long i = 0; i < n; ++i) cin >> xs[i];
        unsigned long long count[32] = {};
        for (unsigned long long i = 0; i < 32; ++i) {
            for (auto x: xs) {
                count[i] += (x >> i) & 1;
            }
        }

        unsigned long long num = 0;
        for (unsigned long long i = 0; i < 32; ++i) count[i] = count[i] * (n-1) - count[i] * (count[i] -1) / 2;
        for (unsigned long long i = 0; i < 32; ++i) num += count[i] << i;
        unsigned long long denom = n * (n - 1) / 2;
        unsigned long long gcd = __gcd(num, denom);
        cout << num/gcd << "/" << denom/gcd << "\n";
    }
}

