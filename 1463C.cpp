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
      vector<int> v;
      map<int,int> mp;
      rep(i,0,n){
          int t,p; cin>>t>>p;
          v.pub(t);
          mp[t]=p;
      }
      v.pub(1e18);
      int x=mp[v[0]],cfl=v[0],ox=0,ans=0;
      rep(i,0,n){
        if(cfl+llabs(x-ox)<=v[i]){
            cfl=v[i];
            ox=x;
            x=mp[v[i]];
        }
        //check
        int d=llabs(mp[v[i]]-ox),tar=mp[v[i]];
        if((tar>=x and tar<=ox) or (tar>=ox and tar<=x))if(cfl+d<=v[i+1] and cfl+d>=v[i])ans++;
      }
      cout<<ans<<"\n";
   }
   return 0;
}