#include <bits/stdc++.h>

using namespace std;

bool isprime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<long long> products(vector<pair<long long, int>> facs, size_t i) {
    vector<long long> res;
    res.push_back(1);
    for (auto t : facs) {
        int val = 1;
        vector<long long> newres(res.begin(), res.end());
        for (int i = 1; i <= t.second; ++i) {
            val *= t.first;
            for (auto old : res) newres.push_back(old * val);
        }
        res = newres;
    }
    return res;
}

vector<long long> divs(long long n) {
    vector<pair<long long, int>> res;
    long long i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                count += 1;
                n /= i;
            }
            res.push_back({i, count});
        }
        i += 1;
    }
    if (n > 1) res.push_back({n,1});
    return products(res, 0);
}

vector<long long> prime_possibs(long long n) {
    vector<long long> res;
    for (auto p: divs(n)) {
        if (isprime(p + 1)) res.push_back(p + 1);
    }
    sort(res.begin(), res.end(), greater<long long>());
    return res;
}

void func(long long n, vector<long long> &ps, size_t i, vector<long long> &res, long long fac = 1) {
    if (n == 1) {
        res.push_back(fac);
        return;
    }
    if (ps.size() == i) return;
    func(n, ps, i + 1, res, fac);
    if (n % (ps[i] - 1) == 0) {
        fac *= ps[i];
        n /= ps[i] - 1;
        func(n, ps, i + 1, res, fac);
        while (n % ps[i] == 0) {
            fac *= ps[i];
            n /= ps[i];
            func(n, ps, i + 1, res, fac);
        }
    }
}

void phi_possibs(long long n, vector<long long> &res) {
    auto ps = prime_possibs(n);
    func(n, ps, 0, res);
}

int main() {
    int t; cin >> t;
    while (t--) {
        long long a, b, c, k; cin >> a >> b >> c >> k;
        vector<long long> res;
        phi_possibs(k, res);
        if (res.size() == 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}



