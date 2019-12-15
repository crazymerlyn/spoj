#include <bits/stdc++.h>

using namespace std;

bool mymatch(string s, string l) {
    unordered_set<size_t> indices;
    indices.insert(0);
    for (auto c: l) {
        unordered_set<size_t> newindices;
        for (auto i: indices) {
            if (i == s.size()) continue;
            if (s[i] == c) newindices.insert(i + 1);
            else if (c == '*') {
                for (size_t j = i; j <= s.size(); j++) {
                    newindices.insert(j);
                }
            }
            else if (c == '?') {
                newindices.insert(i + 1);
                newindices.insert(i);
            }
        }
        indices = newindices;
    }
    return indices.find(s.size()) != indices.end();
}

int main() {
    int t; cin >> t;
    while (t--) {
        string l, s;
        cin >> l >> s;

        if (mymatch(s, l)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
