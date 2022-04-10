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
      int n,m; cin>>n>>m;
      string s1[n],s2[m];
      rep(i,0,n)cin>>s1[i];
      rep(i,0,m)cin>>s2[i];
      map<int,string> mp;
      int p1=0,p2=0;
      rep(i,0,n*m){
        string temp="";
        temp+=s1[p1];
        temp+=s2[p2];
        p1++,p2++;
        if(p1==n)p1=0;
        if(p2==m)p2=0;
        mp[i]=temp;
        //cout<<temp<<"\n";
      }
      int q; cin>>q;
      while(q--){
        int t; cin>>t;
        if(t<=n*m)cout<<mp[t-1]<<"\n";
        else cout<<mp[(t-1)%(n*m)]<<"\n";
      }
   return 0;
}