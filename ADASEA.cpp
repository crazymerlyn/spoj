#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> neighbors(pair<int, int> node, int n, int m) {
    vector<pair<int, int>> res;
    if (node.first > 0) res.push_back({node.first - 1, node.second});
    if (node.second > 0) res.push_back({node.first, node.second - 1});
    if (node.first < n - 1) res.push_back({node.first + 1, node.second});
    if (node.second < m - 1) res.push_back({node.first, node.second + 1});
    return res;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m; cin >> n >> m;
        vector<string> g(n);
        vector<vector<bool>> seen(n, vector<bool>(m));
        for (int i = 0; i < n; ++i) cin >> g[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == '~') seen[i][j] = true;
            }
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (seen[i][j]) continue;
                vector<pair<int, int>> q;
                q.push_back({i, j});
                for (size_t k = 0; k < q.size(); ++k) {
                    auto node = q[k];
                    seen[node.first][node.second] = true;
                    for (auto adj: neighbors(node, n, m)) {
                        if (seen[adj.first][adj.second]) continue;
                        q.push_back(adj);
                        seen[adj.first][adj.second] = true;
                    }
                }
                res += q.size() * q.size();
            }
        }

        long long gc = gcd(m * n, res);
        res /= gc;

        if (res == 0) cout << res << endl;
        else if (gc == m * n) cout << res << endl;
        else cout << res << " / " << (m * n / gc) << endl;
    }
    return 0;
}


