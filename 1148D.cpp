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
   int n; cin>>n;
   vector<pair<pi,int>> vp1,vp2;
   stack<int> s;
   vector<int> ans;
   rep(i,0,n){
      int a,b; cin>>a>>b;
      if(a>b)vp1.pub({{a,b},i+1});
      else vp2.pub({{a,b},i+1});
   }
   sort(all(vp1)); sort(all(vp2));
   reverse(all(vp2));
   if(vp1.sz>vp2.sz){
      cout<<vp1.sz<<"\n";
      rr(vp1)cout<<val.se<<" ";
   }
   else{
      cout<<vp2.sz<<"\n";
      rr(vp2)cout<<val.se<<" ";
   }
   cout<<"\n";
   return 0;
}