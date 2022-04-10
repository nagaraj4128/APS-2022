//To debug :  g++ -g file.cpp -o code
//to flush output : fflush(stdout) or cout.flush()
//cout<<setprecision(p)<<fixed<<var
//use 1LL<<i to for 64 bit shifting , (ll)2 because by default 2 is ll
//take care of precedence rule of operators 
//do not forget to change the sizes of arrays and value of contants and other things after debugging  
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,n) for(i=a;i<n;++i)
#define irep(i,n,a) for(i=n;i>a;--i)
#define mod 1000000007
#define pb push_back
#define big 9223372036854775807
#define big1 LONG_MAX
#define big2 ll_MAX
#define big3 1000000000
#define sma1 LONG_MIN
#define sma2 ll_MIN
#define sma3 -1000000000
#define mp make_pair
#define dub double
#define ivec vector<ll>
#define lvec vector<long long>
#define cvec vector<char>
#define svec vector<string>
#define mt make_tuple
#define MOD 998244353
#define ld long double
#define pi acos(-1.0)
 
#define SZ(x)  (ll)(x.size())
 
//comment the below if not required
 
/*
 
#define ss second.second
#define ff first.first
#define f first
#define s second
#define sf second.first
#define fs first.second
*/
 
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
//cout<<"Case #"<<c<<": "<<ans<<"\n" ;

const ll N = 2e5+1;

ll a[N];

int main()
{

    ll t,n,k,i,j,mx,ind,l,r,f;

    cin>>t;

    while(t--)
    {
        cin>>n>>k;

        f = 1;

        rep(i,1,n+1)
            cin>>a[i];

        l = max(a[1]+1-k,0LL);
        r = a[1]+k-1;

        if(l>r)
            f=0;

        for(i=2;i<=n;++i)
        {
            if(a[i]<l || a[i]>r)
                f=0;

            if(i==n)
                break;

            l = max(a[i]+1-k-(k-1),0LL);
            r = min(r+k-1,a[i]+k-1+k-1);
        
            if(l>r)
                f=0;
        }

        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}