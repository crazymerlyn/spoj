#include <bits/stdc++.h>

using namespace std;
#define LIMIT 100000001

int mobius[LIMIT];

int main() {
    for (int i = 2; i * i < LIMIT; ++i) {
        if (mobius[i*i]) continue;
        for (int j = i*i; j < LIMIT; j += i*i) mobius[j] = 1;
    }
    for (int i = 1; i < LIMIT; ++i) mobius[i] += mobius[i-1];

    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        cout << mobius[b] - mobius[a-1] << '\n';
    }
}
