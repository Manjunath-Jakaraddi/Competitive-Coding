#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<set>

using namespace std;

bool vis[1003];
unordered_map<int, set<int> > adj;

int dfs(int cur) {
    int ans = 1;
    vis[cur] = 1;
    for (int next : adj[cur]) {
        if (!vis[next])     ans+=dfs(next);
    }
    return ans;
}
int main() {
    int n, m;
    cin>>n>>m;
    for (int e=0; e<m; e++) {
        int x, y;
        cin >> x >> y;
        adj[--x].insert(--y);
    }
    
    cout << dfs(0) - 1 - adj[0].size() << "\n";
    return 0;
}