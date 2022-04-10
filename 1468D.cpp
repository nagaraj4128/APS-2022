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
vector<int> v;
bool check(int m,int k,int p){
    int tot=p+k;
    bool ok=(p>=m);
    int c=1;
    repd(i,m,1){
        if(tot-c+1<v[i])ok=0;
        c++;
    }
    return ok;
}
int32_t main(){
   fastIO
   int T; cin>>T;
   while(T--){
     //GO BACK AND UNDERSTAND THE PROBLEM!!
      int n,m,a,b; cin>>n>>m>>a>>b;
      v.clear();
      v.pub(0);
        rep(i,0,m){
            int t; cin>>t;
            v.pub(t);
        }
        sort(all(v));
        int jk=llabs(b-a)-1, extra=0;
        if(a>b)extra=n-a;
        else extra=a-1;
        int l=0,r=m;
        while(l<r){
            int mid=(l+r+1)/2;
            if(check(mid,extra,jk))l=mid;
            else r=mid-1;
        }
        cout<<l<<"\n";
   }
   return 0;
}