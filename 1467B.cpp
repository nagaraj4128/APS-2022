#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define fi first
#define se second
#define pub push_back
#define pi pair<int,int>
#define all(v) (v).begin(), (v).end()
#define rep(i, l, r) for(int i=(int)(l);i<(int)(r);i++)
#define repd(i, l, r) for (int i=(int)(l);i>=(int)(r);i--)
#define clrg(i, l, r) for(int i=(int)(l);i<(int)(r);i++)vis[i]=0,v[i].clear();
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int powermod(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<" ";}cout<< endl;}}
#define clr(a,x) memset(a,x,sizeof(a))
#define rr(v) for(auto &val:v)
#define print(v) for (const auto itr : v){cout<<itr<<' ';}cout<<"\n";
#define ln length()
#define sz size()
#define mod 1000000007
#define elif else if
int32_t main(){
   fastIO
   int T; cin>>T;
   while(T--){
	 //GO BACK AND UNDERSTAND THE PROBLEM!!
	  int n; cin>>n;
	  vector<int> v,peaks(n+1),downs(n+1);
	  rep(i,0,n){
		  int t; cin>>t;
		  v.pub(t);
	  }
	  rep(i,1,n-1){
		  if(v[i-1]>v[i] and v[i+1]>v[i])downs[i]=1;
		  elif(v[i-1]<v[i] and v[i+1]<v[i])peaks[i]=1;
	  }
	  int ans=0;
	  rr(peaks)ans+=val;
	  rr(downs)ans+=val;
	  int fans=ans;
	  rep(i,1,n-1){
		int wh=ans;
		wh-=(peaks[i] or downs[i]);
		int cur=v[i-1];
		int b1=(peaks[i-1] or downs[i-1]);
		int b2=(peaks[i+1] or downs[i+1]);
		int cor=(peaks[i+1] or downs[i+1]);
		if(cur>v[i+1] and i<n-2 and v[i+1]<v[i+2])fans=min(fans,wh-(b1-cor));
		else if(cur<v[i+1] and i<n-2 and v[i+1]>v[i+2])fans=min(fans,wh-(b1-cor));
		else fans=min(fans,wh-b1-b2);
		cur=v[i+1];
		cor=(peaks[i-1] or downs[i-1]);
		if(cur>v[i-1] and i>1 and v[i-1]<v[i-2])fans=min(fans,wh-(b2-cor));
		else if(cur<v[i-1] and i>1 and v[i-1]>v[i-2])fans=min(fans,wh-(b2-cor));
		else fans=min(fans,wh-b1-b2);
	  }
	  cout<<fans<<"\n";
	  
   }
   return 0;
}