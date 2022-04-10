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
vector<int> v,cnt,mat[200005];
bool check(int m){
    rep(i,0,m+1)mat[i].clear();
    int c=0;
    rep(i,0,v.sz){
        mat[c].pub(v[i]);
        int siz=mat[c].sz;
        if(siz>cnt[v[i]])return false;
        c++;
        c%=m;
    }
    return true;
}
int32_t main(){
   fastIO
    //Binary search over the answer between 1 and n
    //for each mid, check whether you can fit it in mid testcases
    //check will be done using a vector<vector>
    //print the vector obtained at last
    int n,k; cin>>n>>k;
    rep(i,0,n){
        int t; cin>>t;
        v.pub(t);
    }
    sort(all(v)); reverse(all(v));
    cnt.pub(0);
    rep(i,0,k){
        int t; cin>>t;
        cnt.pub(t);
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    bool wh=check(l);
    cout<<l<<"\n";
    rep(i,0,l){
        cout<<mat[i].sz<<" ";
        rep(j,0,mat[i].sz)cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
   return 0;
}