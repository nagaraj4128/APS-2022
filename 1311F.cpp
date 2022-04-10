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
struct SegmentTree
{
    struct data
   {
    //Use required attributes
    int mn;
   
    //Default Values
    data() : mn(0) {}; //infinity for min query, 0 for sum
   };
 
    int N;
    vector<data> st;
    vector<bool> cLazy;
    vector<int> lazy;
 
    SegmentTree(int n)
    {
        N = n;
        st.resize(4 * N + 5);
        cLazy.assign(4 * N + 5, false);
        lazy.assign(4 * N + 5, 0);
    }
 
    //Write reqd merge functions
    void merge(data &cur, data &l, data &r) 
    {
        cur.mn = l.mn + r.mn;
    }
    
    //Handle lazy propagation appriopriately, currently for sum.
    // Also check query and update functions carefully.
    void propagate(int node, int L, int R)
    {
        if(L==R)st[node].mn+=lazy[node];
           if(L != R)
        {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2] += lazy[node];  
            lazy[node*2 + 1] += lazy[node];
            
        }
            lazy[node]=0;
            cLazy[node] = 0;
    }
 
    void build(int node, int L, int R)
    {
        if(L==R)
        {
            st[node].mn = 0;
            return;
        }
        int M=(L + R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        merge(st[node], st[node*2], st[node*2+1]);
    }
 
    data Query(int node, int L, int R, int i, int j)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(j<L || i>R)
            return data();
        if(i<=L && R<=j){
            return st[node];
        }
        int M = (L + R)/2;
        data left=Query(node*2, L, M, i, j);
        data right=Query(node*2 + 1, M + 1, R, i, j);
        data cur;
        merge(cur, left, right);
        return cur;
    }
 
    data pQuery(int node, int L, int R, int pos)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(L == R)
            return st[node];
        int M = (L + R)/2;
        if(pos <= M)
            return pQuery(node*2, L, M, pos);
        else
            return pQuery(node*2 + 1, M + 1, R, pos);
    }   
 
    void Update(int node, int L, int R, int i, int j, int val)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(j<L || i>R)
            return;
        if(i<=L && R<=j)
        {
            cLazy[node] = 1;
            lazy[node] += val;
            //st[node].mn+=val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, val);
        Update(node*2 + 1, M + 1, R, i, j, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }
 
    void pUpdate(int node, int L, int R, int pos,int val)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(L == R)
        {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        if(pos <= M)
            pUpdate(node*2, L, M, pos, val);
        else
            pUpdate(node*2 + 1, M + 1, R, pos, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }
 
    data query(int pos)
    {
        return pQuery(1, 1, N, pos);
    }
 
    data query(int l, int r)
    {
        return Query(1, 1, N, l, r);
    }
 
    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }
 
    void update(int l, int r, int val)
    {
        Update(1, 1, N, l, r, val);
    }
};
int32_t main(){
   fastIO
   int n; cin>>n;
   vector<pi> vp;
   vector<int> v,pref(n);
   map<int,vector<int>,greater<>> mp;
   SegmentTree st(n+1),st2(n+1);
   set<int> s;
   rep(i,0,n){
      int t; cin>>t;
      v.pub(t);
      s.insert(t);
   }
   rep(i,0,n){
      int t; cin>>t;
      vp.pub({v[i],t});
   }
   sort(all(vp));
   rep(i,0,n){
      mp[vp[i].se].pub(i);
   }
   sort(all(v));
   rep(i,0,n){
      st.update(i+1,v[i]);
      st2.update(i+1,1);
   }
   int ans=0;
   rr(mp){
      rep(j,0,val.se.sz){
         int id=val.se[j];
         int len=st2.query(1,id).mn;
         ans+=((len*v[id])-st.query(1,id).mn);
      }
      rep(j,0,val.se.sz){
         st.update(val.se[j]+1,-v[val.se[j]]);
         st2.update(val.se[j]+1,-1);
      }
   }
   cout<<ans<<"\n";
   return 0;
}