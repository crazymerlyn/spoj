#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int v; cin >> v;
            if (v) g[i].push_back(j);
        }
    }
    auto func = [n, &g] (int root) {
        vector<int> q; q.push_back(root);
        vector<int> dist(n, -1);
        dist[root] = 0;
        size_t i = 0;
        while (i < q.size()) {
            int node = q[i++];
            for (auto child: g[node]) {
                if (dist[child] == 0) return dist[node] + 1;
                if (dist[child] > 0) continue;
                dist[child] = dist[node] + 1;
                q.push_back(child);
            }
        }
        return 0;
    };

    for (int root = 0; root < n; ++root) {
        int res = func(root);
        if (res)
            cout << res << "\n";
        else
            cout << "NO WAY\n";
    }
}
