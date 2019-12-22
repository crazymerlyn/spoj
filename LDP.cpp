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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int limit = sqrt(1e9);
    vector<bool> isprime(limit+1, true);
    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (!isprime[i]) continue;
        primes.push_back(i);
        for (int j = i * i; j <= limit; j += i) isprime[j] = false;
    }

    int n; cin >> n;
    vector<int> vs(n);
    for (int i = 0; i < n; ++i) cin >> vs[i];

    map<int, int> lcm, mul;
    for (auto val : vs) {
        for (auto prime: primes) {
            if (prime * prime > val) break;
            if (val % prime) continue;
            int count = 0;
            while (val % prime == 0) {
                val /= prime;
                count += 1;
            }
            lcm[prime] = max(lcm[prime], count);
            mul[prime] += count;
        }
        lcm[val] = max(lcm[val], 1);
        mul[val] += 1;
    }

    long long res = 1;
    long long mod = 1e9 + 9;
    for (auto pair : mul) {
        res = res * mypow(pair.first, pair.second - lcm[pair.first], mod) % mod;
    }
    cout << res << endl;
}

