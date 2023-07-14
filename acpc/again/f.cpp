#include<iostream>
#include<unordered_map>
#include<set>
#include<queue>
#include<algorithm>


using namespace std;
const int oo = 1e5+5;
unordered_map<int, set<int> > adj;

int eraseOverlapIntervals(vector<pair<int,int> >& intervals) {
    sort(intervals.begin(), intervals.end());
    int erased_intervals = 0;
    int previous_end = intervals[0].second;
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first < previous_end) {
            erased_intervals++;
            previous_end = min(previous_end, intervals[i].second);
        } else {
            previous_end = intervals[i].second;
        }
    }
    return erased_intervals;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vector<int> dist(n+1, oo);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : adj[curr]) {
            if (dist[next] > dist[curr] + 1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    int C;
    cin >> C;
    vector<pair<int,int> > intervals(C);
    for (int c=0; c<C; c++) {
        int pst, t;
        cin>>pst>>t;
        intervals.push_back(make_pair(dist[pst], dist[pst]+t));
    }
    int ans = C - eraseOverlapIntervals(intervals);
    cout << ans << "\n";
    return 0;
}