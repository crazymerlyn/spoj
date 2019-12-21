#include <bits/stdc++.h>

using namespace std;

#define LIMIT 10001
int sq[LIMIT];
int vals[LIMIT];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 1; i < LIMIT; ++i) sq[i] = sqrt(i);

    int t; cin >> t;
    while (t--) {
        int l, k; cin >> l >> k;
        for (int i = 1; i <= l; ++i) vals[i] = 1;
        for (int idx = l; k && idx; idx--) {
            int val = min(vals[idx], k);
            k -= val;
            vals[idx] -= val;
            vals[sq[idx]] += val;
        }
        int ans = 0;
        for (int i = 1; i <= l; ++i) ans += i * vals[i];
        cout << ans << "\n";
    }
}

