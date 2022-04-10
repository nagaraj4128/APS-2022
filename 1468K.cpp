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
      string s; cin>>s;
        int n= s.ln;
    int x=0,y=0;
    vector<pi> vp;
    rep(i,0,n){
        if(s[i]=='R')x++;
        if(s[i]=='L')x--;
        if(s[i]=='D')y--;
        if(s[i]=='U')y++;
        vp.pub({x,y});
    }
    int xx=vp.back().first,yy=vp.back().se;
    if(xx!=x and yy!=y){
        cout<<0<<" "<<0<<"\n";
        continue;
    }
    x=0,y=0;
    int ansx=0,ansy=0;
    rep(i,0,n){
        int xx=vp[i].first,yy=vp[i].second;
        x=0,y=0;
        rep(j,0,n){
            if(s[j]=='R'){
                if(xx==(x+1) and yy==y)continue;
                else x++;
            }
            if(s[j]=='L'){
                if(xx==(x-1) and yy==y)continue;
                else x--;
            }
            if(s[j]=='U'){
                if(yy==(y+1) and xx==x)continue;
                else y++;
            }
            if(s[j]=='D'){
                if(yy==(y-1) and xx==x)continue;
                else y--;
            }
        }
        if(x==0 and y==0){
           ansx=xx,ansy=yy;
        }
    }
      cout<<ansx<<" "<<ansy<<"\n";
   }
   return 0;
}