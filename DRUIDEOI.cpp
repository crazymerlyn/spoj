#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> hs(n);
        for (int i = 0; i < n; ++i) cin >> hs[i];
        int j = max_element(hs.begin(), hs.end()) - hs.begin();
        for (int i = 0; i <= j; ++i) {
            hs.push_back(hs[i]);
        }

        vector<int> stack;
        vector<int> left(n+j+1),right(n+j+1);
        for (int i = j; i <= n + j; ++i) {
            while (stack.size() && hs[stack.back()] <= hs[i]) stack.pop_back();
            if (stack.size()) left[i] = stack.back() % n + 1;
            else left[i] = -1;
            stack.push_back(i);
        }
        stack.clear();
        for (int i = n + j; i >= j; --i) {
            while (stack.size() && hs[stack.back()] <= hs[i]) stack.pop_back();
            if (stack.size()) right[i] = stack.back() % n + 1;
            else right[i] = -1;
            stack.push_back(i);
        }

        for (int i = 0; i < j; ++i) {
            cout << left[i + n] << " " << right[i + n] << "\n";
        }
        for (int i = j; i < n; ++i) {
            cout << left[i] << " " << right[i] << "\n";
        }
    }
}
