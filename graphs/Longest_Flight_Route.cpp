#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NEG = -1e15;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<ll> dp(n+1, NEG);      // longest path length from node to destination
    vector<ll> parent(n+1, -1);   // next node on the longest path
    vector<bool> vis(n+1, false);
    ll dest = n;
    function<ll(ll)> dfs = [&](ll node) -> ll{
        if(vis[node]) return dp[node];
        vis[node] = true;
        if(node == dest){
            dp[node] = 1;
            return 1;
        }
        for(auto v: adj[node]){
            ll candidate = dfs(v);
            if(candidate != NEG && candidate + 1 > dp[node]){
                dp[node] = candidate + 1;
                parent[node] = v;
            }
        }
        return dp[node];
    };
    ll ans = dfs(1);
    if(ans < 0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << ans << "\n";
    ll cur = 1;
    while(cur != dest){
        cout << cur << " ";
        cur = parent[cur];
    }
    cout << dest << "\n";
    return 0;
}