#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define c1 cout<<"-1\n"
#define all(x) x.begin(),x.end()
#define re(x) x.rbegin(),x.rend()
#define F first
#define S second
#define ii pair<ll,ll>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9+7;
int f(int a,int b,vector<vector<int>> &dp){
		if(a==b)return 0;
	if(dp[a][b]!=-1)return dp[a][b];
	int ans  = INT_MAX;
	for(int i = 1;i<b;i++){
		ans = min(ans,(1+f(a,b-i,dp)+f(a,i,dp)));
	}
	for(int i = 1;i<a;i++){
		ans =min(ans,1+f(a-i,b,dp)+f(i,b,dp));
	}
	return dp[a][b]=ans;
}
void solve(){
int A,B;
cin>>A>>B;
 vector<vector<int> > dp(A + 1, vector<int>(B + 1, 1e9));
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            // If the rectangle is already a square, then 0
            // cuts are required
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                // Iterate over all the possible cuts we can
                // make horizontally
                for (int k = 1; k < j; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[i][k] + dp[i][j - k] + 1);
                }
                // Iterate over all the possible cuts we can
                // make vertically
                for (int k = 1; k < i; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[k][j] + dp[i - k][j] + 1);
                }
            }
        }
    }
    // Return the minimum  number of cuts required to cut a
    // rectangle of size (A X B) into squares
    cout<<dp[A][B];
}
int main() {
	IOS
	int t;
	t=1;
	while(t--){
		solve();
	}
}