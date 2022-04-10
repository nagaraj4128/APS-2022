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
   string s; cin>>s;
   int n=s.ln;
   int prev=-1,prevr=n,pl=-1,ans=0;
   set<pi> vp;
   rep(i,1,n){
      int j=1;
      int l=-1,r=-1;
      while(i-j>=0 and (i+j)<n){
         if(s[i-j]==s[i] and s[i+j]==s[i]){
            l=i-j;
            r=i+j;
            break;
         }
         j++;
      }
      if(l==-1)continue;
      vp.insert({l,r});
   }
   if(vp.empty()){
      cout<<"0\n";
      return 0;
   }
   multiset<pi> ms;
   rr(vp){
      ms.insert({val.se,val.fi});
   }
   rr(ms){
      if(vp.begin()->fi<=val.se){
         int len=val.fi-val.se;
         ans+=(len)*(len-1)/2;
      }
      while(vp.sz and vp.begin()->first<=val.se)vp.erase(vp.begin());
   }
   cout<<n*(n-1)/2-ans<<"\n";
   return 0;
}