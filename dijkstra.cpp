#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,start,end) for(int i=start; i<=end; i++)
#define repd(i,start,end) for(int i=start; i>=end; i--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << "(" << #x << ": " << x << ") ";
#define nl cerr << endl;
#define INF 1e18

//Dijkstra works for graphs with non-negative weights only... It also does work for cyclic graphs
void solve() {
	int n,m;
	cin >> n >> m;
	vector<pair<ll,ll>> adj[n+1]; // 1 indexed undirected graph.. Usually DAG are given in dijkstra

	rep(i,m) {
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].pb({v,cost});
		adj[v].pb({u,cost});
	}

	vector<ll> dist(n+1), pred(n+1); //pred is the predecessor array
	dist.assign(n+1,INF);
	pred.assign(n+1,-1);

	priority_queue<pll, vector<pll>, greater<pll>> q; //key is the (distance to the node,node) pair.. We use min heap to extract min element in log N time
	int src = 1; //problem states source to be 1
	dist[src] = 0;
	q.push({0, src});
	
	while(!q.empty()) {
		int v = q.top().ss; //extract minimum element vertex
		ll d_v = q.top().ff;
		q.pop();

		if(d_v != dist[v]) //older entry in the queue so ignore.. Since we can't remove elements from priority queue so older entries exist
			continue; 

		for(auto [to, len]: adj[v]) { //update all its neighbours if smaller distance found
			if(dist[v] + len < dist[to]) {
				dist[to] = dist[v] + len;
				pred[to] = v;
				q.push({dist[to], to});
			}
		}
	}

	if(dist[n] == INF) //if no path found
		cout << -1 << endl;
	else {
		vector<int> path;
		for(int i=n; i!=src; i=pred[i])
			path.pb(i);
		path.pb(src);
		reverse(all(path));
		for(auto x: path)
			cout << x << " ";
		cout << endl;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}