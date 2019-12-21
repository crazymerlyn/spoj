#include <bits/stdc++.h>

using namespace std;

int next_power(int n) {
    int res = 1;
    while (res < n) res *= 2;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q; cin >> n >> q;
    vector<int> vs(next_power(n));
    for (int i = 0; i < n; ++i) cin >> vs[i];
    long long mod = 1e9+7;
    n = next_power(n);

    vector<vector<long long>> segment(2*n), segment_mul(2*n);
    for (int i = 0; i < n; ++i) {
        segment[i+n].push_back(vs[i]);
    }
    for (int i = n-1; i > 0; --i) {
        for (auto x: segment[2*i]) segment[i].push_back(x);
        for (auto x: segment[2*i + 1]) segment[i].push_back(x);
    }
    for (int i = 0; i < 2*n; ++i) {
        sort(segment[i].begin(), segment[i].end());
        segment_mul[i] = segment[i];
    }
    for (int i = 0; i < n; ++i) {
        for (size_t j = 1; j < segment_mul[i].size(); ++j)
            segment_mul[i][j] = segment_mul[i][j-1] * segment_mul[i][j] % mod;
    }

    auto get_segment = [&](int i, int h) {
        auto idx = upper_bound(segment[i].begin(), segment[i].end(), h) - segment[i].begin();
        return idx ? segment_mul[i][idx-1] : 1;
    };

    auto query = [&](int l, int r, int h) {
        long long res = 1;
        for (l += n, r += n; l < r; l >>=1, r >>= 1) {
            if (l % 2) {
                res = res * get_segment(l++, h) % mod;
            }
            if (r % 2) {
                res = res * get_segment(--r, h) % mod;
            }
        }
        return res;
    };
    
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        cout << query(l, r+1, k) << "\n";
    }
}

