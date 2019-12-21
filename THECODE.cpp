#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int get_dist(vector<int> &children, int start, int end) {
    deque<int> q;
    q.push_back(start);
    vector<int> dist(1024, -1); dist[start] = 0;
    while (q.size()) {
        int node = q.front(); q.pop_front();
        if (node == end) return dist[node];
        for (auto child: children) {
            child |= node;
            if (dist[child] != -1) continue;
            dist[child] = dist[node] + 1;
            q.push_back(child);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        vector<int> vs(n);
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            for (auto c: s) {
                vs[i] |= 1 << (c - '0');
            }
        }
        auto it = unique(vs.begin(), vs.end()); vs.erase(it, vs.end());

        cout << get_dist(vs, 0, 1023) << "\n";
    }
}

