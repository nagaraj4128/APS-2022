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
vector<int> sols;
vector<pair<int,pi>> traps;
int n,m,k,t;
bool check(int mid){
   int lowest=sols[mid];
   multiset<int> ms;
   vector<pi> vp;
   rr(traps){
      if(val.fi<=lowest)continue;
      vp.pub({val.se.se,val.se.fi});
      ms.insert(val.se.fi);
   }
   sort(all(vp));
   ms.insert(n+1);
   int ans=0;
   int me=0,army=0;
   rep(i,0,vp.sz){
      if(*ms.begin()>me){
         ans+=(me-army)+(*ms.begin()-army);
         army=*ms.begin()-1;
         me=army+1;
      }
      ans+=vp[i].fi-me;
      me=vp[i].fi;
      ms.erase(ms.find(vp[i].se));
   }
   if(*ms.begin()>me){
         ans+=(me-army)+(*ms.begin()-army);
         army=*ms.begin()-1;
         me=army+1;
   }
   //cout<<ans<<" "<<mid<<"\n";
   return (ans<=t);
}
int32_t main(){
   fastIO
    cin>>m>>n>>k>>t;
   rep(i,0,m){
      int temp; cin>>temp;
      sols.pub(temp);
   }
   sort(all(sols)); reverse(all(sols));
   rep(i,0,k){
      int l,r,d; cin>>l>>r>>d;
      traps.pub({d,{l,r}});
   }
   int l=0,r=m-1;
   while(l<r){
      int mid=(l+r+1)/2;
      if(check(mid))l=mid;
      else r=mid-1;
   }
   cout<<l+1<<"\n";
   return 0;
}