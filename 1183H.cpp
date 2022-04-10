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
string s; 
vector<int> v;
int n;
int dp[101][101][101];
int solve(int i,int j,int prev,int x){
    if(i==n){
        return (j==x);
    }
    if(dp[i][j][prev]!=-1)return dp[i][j][prev];
    int ans=0;
    if(s[prev]!=s[i])ans+=solve(i+1,j+1,i,x);
    if(s[prev]==s[i] and v[i]==prev)ans+=solve(i+1,j+1,i,x);
    else ans+=solve(i+1,j,prev,x);
    return dp[i][j][prev]=ans;
}
int32_t main(){
   fastIO
    int k; cin>>n>>k;
    cin>>s;
    s+='?';
    v.resize(n+1);
    int f[26];
    clr(dp,-1);
    clr(f,-1);
    rep(i,0,n){
        v[i]=f[s[i]-'a'];
        f[s[i]-'a']=i;
    }
    int num=0,wh,ans=0;
    repd(j,n,0){
        clr(dp,-1);
        int wh=solve(0,0,n,j);
        wh=min(wh,k);
        k-=wh;
        ans+=wh*(n-j);
        if(k==0)break;
    }
    if(k>0)ans=-1;
    cout<<ans<<"\n";
   return 0;
}