#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n, f; cin >> n >> f;
        vector<pi> edges(n);
        for (int i = 0; i < n; ++i) cin >> edges[i].first >> edges[i].second;
        vector<int> parent(2*n+1), size(2*n+1, 1);
        for (int i = 1; i <= 2*n; ++i) parent[i] = i;

        auto get_parent = [&](int i) {
            while (parent[i] != i) i = parent[i];
            return i;
        };
        auto join = [&](int a, int b){
            a = get_parent(a); b = get_parent(b);
            if (a == b) return;
            if (size[a] < size[b]) swap(a, b);
            size[a] += size[b];
            parent[b] = a;
        };
        for (int i = 0; i < f; ++i) {
            int a, b; cin >> a >> b;
            join(a, b);
        }
        for (int i = 1; i <= 2*n; ++i) parent[i] = get_parent(i);
        map<pi, int> edge_count;
        for (auto edge: edges) {
            pi parent_edge{parent[edge.first], parent[edge.second]};
            if (parent_edge.first > parent_edge.second) swap(parent_edge.first, parent_edge.second);
            else if (parent_edge.first == parent_edge.second) continue;
            edge_count[parent_edge] += 1;
        }

        long long res = 0;
        for (auto pair : edge_count) {
            auto edge = pair.first;
            res += size[edge.first] * size[edge.second];
        }
        cout << res << endl;
    }
}

