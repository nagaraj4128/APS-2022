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
char mat[1001][1001];
bool check(int l, int i, int j){
    if(j==0)return false;
    bool ok=1;
    rep(c,i-l,i){
        if(mat[c][j]!=mat[c][j-1] or mat[c][j]!=mat[i-l][j])ok=0;
    }
     rep(c,i,i+l){
        if(mat[c][j]!=mat[c][j-1] or mat[c][j]!=mat[i][j])ok=0;
    }
     rep(c,i+l,i+2*l){
        if(mat[c][j]!=mat[c][j-1] or mat[c][j]!=mat[i+l][j])ok=0;
    }
    return ok;
}
int32_t main(){
   fastIO
   int n,m; cin>>n>>m;
   //This solution works in O(n*m) because the topmost point of the middle color
   // is unique for each flag. iterating to find other colors also doesn't increase
   // complexity by much.
   rep(i,0,n){
        rep(j,0,m){
            cin>>mat[i][j];
        }
   }
   int l=0,ans=0;
   rep(i,1,n){
       int pre=0;
       rep(j,0,m){
           if(mat[i][j]==mat[i-1][j])continue;
            int k=i,ok1=0,ok2=0;
            while(k<n and mat[k][j]==mat[i][j])k++;
            l=k-i;
            if(k+l-1<n){
                int ch=mat[k][j];
                int wh=1;
                rep(p,k,k+l){
                    if(ch!=mat[p][j])wh=0;
                }
                if(wh)ok1=1;
            }
            k=i-1;
            if(k-l+1>=0){
                int ch=mat[k][j];
                int wh=1;
                repd(p,k,k-l+1){
                    if(ch!=mat[p][j])wh=0;
                }
                if(wh)ok2=1;
            }
            if(ok1 and ok2){
                if(check(l,i,j))ans+=++pre;
                else ans++,pre=1;
            }
            else pre=1;
       }
   }
   cout<<ans<<"\n";
   return 0;
}