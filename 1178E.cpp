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
   string s; cin>>s;
    int n=s.ln;
    string ans1="",ans2="";
    int l=0,r=n-1;
    while((r-l)>=4){
        if(s[l]==s[r] or s[l]==s[r-1]){
            //cout<<s[l]<<" "<<s[r]<<" "<<s[r-1]<<" 1\n";
            ans1+=s[l];
            ans2+=s[l];
            if(s[l]==s[r])l++,r--;
            else l++,r-=2;
        }
        elif(s[l+1]==s[r] or s[l+1]==s[r-1]){
            //cout<<s[l+1]<<" "<<s[r]<<" "<<s[r-1]<<" 2\n";
            ans1+=s[l+1];
            ans2+=s[l+1];
            if(s[l+1]==s[r])l+=2,r--;
            else l+=2,r-=2;
        }
    }
    if(l<=r)ans1+=s[l];
    reverse(all(ans2));
    //cout<<n<<"\n";
    cout<<ans1<<ans2<<"\n";
   return 0;
}