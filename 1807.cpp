#include <bits/stdc++.h>

using namespace std;

int main() {
	string s; cin >> s;
	vector<int> dp(4);

	for (auto c: s) {
		switch (c) {
		case '1':
			dp[0] += 1;
			break;
		case '8':
			if (dp[0]) dp[1] = max(dp[1]+1, dp[0]+1);
			break;
		case '0':
			if (dp[1]) dp[2] = max(dp[2]+1, dp[1]+1);
			break;
		case '7':
			if (dp[2]) dp[3] = max(dp[3]+1, dp[2]+1);
			break;
		}
	}

	cout << dp[3] << endl;
}
