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
   int n; cin>>n;
   set<int> s;
   map<int,int> mp;
   vector<int> v,pref(n+1),suf(n+1);
   rep(i,0,n){
       int t; cin>>t;
       v.pub(t);
   }
   int sum=0;
   rep(i,0,n){
       int t=v[i];
       mp[t]++;
       sum+=t;
       s.insert(t);
       while(1){
           auto it=s.lower_bound(t+1);
           if(it==s.end())break;
           int ele=*it;
           sum-=mp[ele]*(ele-t);
           mp[t]+=mp[ele];
           mp[ele]=0;
           s.erase(ele);
       }
       pref[i]=sum;
   }
   mp.clear(); s.clear(); sum=0;
   repd(i,n-1,0){
        int t=v[i];
       mp[t]++;
       sum+=t;
       s.insert(t);
       while(1){
           auto it=s.lower_bound(t+1);
           if(it==s.end())break;
           int ele=*it;
           sum-=mp[ele]*(ele-t);
           mp[t]+=mp[ele];
           mp[ele]=0;
           s.erase(ele);
       }
       suf[i]=sum;
   }
   int ans=0,idx=0;
    rep(i,0,n){
        int wh=suf[i]+pref[i]-v[i];
        if(wh>ans){
            ans=wh;
            idx=i;
        }
    }
    int mn=1e18;
    repd(i,idx,0){
        v[i]=min(v[i],mn);
        mn=min(mn,v[i]);
    }
    mn=1e18;
    rep(i,idx,n){
        v[i]=min(v[i],mn);
        mn=min(mn,v[i]);
    }
    print(v);
   return 0;
}