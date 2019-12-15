#include <bits/stdc++.h>

using namespace std;
#define LIMIT 10000000
bool seen[LIMIT];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long limit = 1e7;
    vector<bool> isprime(limit+1, true);
    vector<int> primes(664579); int pi = 0;
    for (long long i = 2; i <= limit; ++i) {
        if (!isprime[i]) continue;
        primes[pi++] = i;
        for (long long j = i * i; j <= limit; j += i) isprime[j] = false;
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> xs(n);
        memset(seen, 0, sizeof(seen));
        for (int i = 0; i < n; ++i) cin >> xs[i];
        for (auto x : xs) {
            for (auto prime : primes) {
                if (isprime[x]) break;
                if (x % prime == 0) seen[prime] = true;
                while (x % prime == 0) x /= prime;
            }
            seen[x] = true;
        }
        for (auto p : primes) {
            if (seen[p]) continue;
            cout << p << "\n";
            break;
        }
    }
}
