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
int parent[200005];
int find(int i){
    if(parent[i]==i)return i;
    else{
        //Recurse until main parent os found.
        int j=find(parent[i]);
        //Path compression
        parent[i]=j;
        return j;
    }
}
void set_union(int x,int y){
    //Find both of their (main) parents
    int x1=find(x);
    int y1=find(y);
    parent[x1]=y1;
}
int32_t main(){
   fastIO
   int T; cin>>T;
   while(T--){
     //GO BACK AND UNDERSTAND THE PROBLEM!!
     int n,m,k; cin>>n>>m>>k;
      rep(i,0,n+1)parent[i]=i;
      vector<pair<int,pi>> vp;
      rep(i,0,m){
          int a,b,c; cin>>a>>b>>c;
          vp.pub({c,{a,b}});
      }
      sort(all(vp));
      bool ok=0;
      int c=0,idx=0,ans=1e18,tans=0;
      rep(i,0,m){
          int a=vp[i].se.fi,b=vp[i].se.se;
          int w=vp[i].fi;
          if(find(a)!=find(b)){
            tans+=(max(0ll,w-k));
              set_union(a,b);
              c++;
          }
          idx=i+1;
          if(c==n-1){
            if(tans)ok=1;
            tans+=max(0ll,k-w);
            break;
          }
      }
      if(ok){
          cout<<tans<<"\n";
          continue;
      }
        ans=tans;
       rep(i,idx,m){
            int w=vp[i].fi;
            ans=min(ans,llabs(k-w));
            if(w>=k)break;
       }
       cout<<ans<<"\n";
   }
   return 0;
}