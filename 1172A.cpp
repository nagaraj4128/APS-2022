#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//#define int long long int
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
multiset<int> ms;
vector<int> f,u;
int n;
bool check(int m){
    vector<int> ff=f,v=u;
    int l=0;
    rep(i,0,m){
        if(ff[0]==0)return true;
        ff[0]--;
        v.pub(0);
        ff[v[l++]]++;
    }
    rep(i,1,n+1){
        if(ff[i]==0)return false;
        ff[i]--;
        v.pub(i);
        ff[v[l++]]++;
    }
    return true;
}
int32_t main(){
   fastIO
   //Binary search to check how many zeroes you need to add before starting
   //The "sorting"
     cin>>n;
     f.resize(n+1);
    rep(i,0,n){
        int t; cin>>t;
        f[t]++;
        ms.insert(t);
    }
    rep(i,0,n){
        int t; cin>>t;
        u.pub(t);
    }
    bool ok=1;
    int idx=-1;
    rep(i,0,n){
        if(u[i]==1)idx=i;
    }
    if(idx==-1)ok=0;
    else rep(i,idx+1,n){
        if(u[i]!=(u[i-1]+1))ok=0;
    }
    int l=0,ans=0;
    if(ok){
        while(ms.find(u.back()+1)!=ms.end()){
            u.pub(u.back()+1);
            ms.erase(u.back());
            ms.insert(u[l++]);
            ans++;
        }
        if(u.back()==n){
            cout<<ans<<"\n";
        }
        else{
            while(u[l]!=1){
                ans++,l++;
            }
            cout<<ans+n+1<<"\n";
        }
        return 0;
    }
    //else binsearch
    int lp=0,rp=n;
    while(lp<rp){
        int mid=(lp+rp)/2;
        if(check(mid))rp=mid;
        else lp=mid+1;
    }
    //cout<<lp<<"\n";
    cout<<lp+n<<"\n";
   return 0;
}