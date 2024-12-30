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
void solve(){
int n,a,b;
cin>>n>>a>>b;
vector<int> arr(n);
vector<int> p(n+1);
p[0]=0;
for(int i = 0;i<n;i++){cin>>arr[i];p[1]=1;}
deque<int> dq;
for(int i = 0;i<=n;i++){
	if(i>=a){
		while(!dq.empty() and p[dq.back()]>p[i-a])dq.pop_back();
		dq.push_back(i-a);
	}
	if(i>=b){
		if(dq.front()<=i-b);dq.pop_front();
	}
}
		
		
}
int main() {
	IOS
	int t;
	t=1;
	while(t--){
		solve();
	}
}