#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    constexpr int limit = 1e5;

    bitset<limit+1> possible;
    possible[0] = 1;

    for (auto coin: coins) {
        possible |= possible << coin;
    }

    vector<int> count(limit+1);
    for (int i = 1; i <= limit; ++i) {
        count[i] = count[i-1] + possible[i];
    }

    while (q--) {
        int b, e; cin >> b >> e;
        cout << count[e] - count[b-1] << "\n";
    }
}
