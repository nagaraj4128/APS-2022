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
#define mod 998244353
#define elif else if
int32_t main(){
    fastIO
    int n; cin>>n;
    int mat[n+1][n+1];
    clr(mat,0);
    vector<pi> vp;
    rep(i,0,n){
        int a,b; cin>>a>>b;
        vp.pub({a,b});
    }
    map<pi,int> mp;
    rep(i,0,n){
        map<pi,vector<int>> mp1;
        rep(j,i+1,n){
            if(mat[i][j]==-1)continue;
            int num=(vp[j].se-vp[i].se);
            int den=(vp[j].fi-vp[i].fi);
            int g=__gcd(num,den);
            num/=g,den/=g;
            mp1[{num,den}].pub(j);
        }
        rr(mp1){
            mp[val.fi]++;
            rep(j,0,val.se.sz){
                rep(k,j+1,val.se.sz){
                    mat[val.se[j]][val.se[k]]=-1;
                }
            }
        }
    }
    int c=0;
    rr(mp)c+=val.se;
    int ans=c*(c-1)/2;
    rr(mp){
        int cnt=val.se;
        ans-=cnt*(cnt-1)/2;
    }
    cout<<ans<<"\n";
   return 0;
}