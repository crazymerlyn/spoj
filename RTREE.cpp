#include <bits/stdc++.h>
using namespace std;

#define LIMIT 100001
vector<int> graph[LIMIT];
int height[LIMIT], res[LIMIT];

void fastscan(int &number) 
{ 
	register int c; 

	number = 0; 

	// extract current character from buffer 
	c = getchar(); 

	// Keep on extracting characters if they are integers 
	// i.e ASCII Value lies from '0'(48) to '9' (57) 
	for (; (c>47 && c<58); c=getchar()) 
		number = number *10 + c - 48; 
} 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; fastscan(n);
    vector<int> depth(n+1, -1);
    for (int i = 1; i < n; ++i) {
        int u, v; fastscan(u); fastscan(v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int r; fastscan(r);

    vector<int> todo(1);
    todo.reserve(n);
    todo[0] = r;
    depth[r] = 0;
    size_t todoi = 0;

    while (todoi < todo.size()) {
        int node = todo[todoi];
        todoi += 1;
        for (auto child: graph[node]) {
            if (depth[child] != -1) continue;
            depth[child] = depth[node] + 1;
            todo.push_back(child);
        }
    }

    for (int i = n-1; i >= 0; --i) {
        int node = todo[i];
        height[node] = 0;
        res[node] = 0;
        for (auto child: graph[node]) {
            if (depth[child] < depth[node]) continue;
            res[node] = max(res[node], height[node] + height[child] + 1);
            res[node] = max(res[child], res[node]);
            height[node] = max(height[node], height[child] + 1);
        }
    }

    int q; fastscan(q);
    while (q--) {
        int s; fastscan(s);
        cout << res[s] << '\n';
    }
}
