#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < (int)v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define d(x) cout<<x<<endl;
#define br cout<<'\n'
#define de(x) cout << (#x) << " : " << (x) << endl;
#define fni(x,y,z) for(int i=(int)x;i>=(int)y;i-=(int)z)
#define fnj(x,y,z) for(int j=(int)x;j>=(int)y;j-=(int)z)
#define fpi(x,y,z) for(int i=(int)x;i<=(int)y;i+=(int)z)  
#define fpj(x,y,z) for(int j=(int)x;j<=(int)y;j+=(int)z)
#define fpk(x,y,z) for(int k=(int)x;k<=(int)y;k+=(int)z)  
#define fnk(x,y,z) for(int k=(int)x;k>=(int)y;k-=(int)z)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = (int)10e17;
#define maxn 1000005
const int mod = 1000000007; 
int modexp(int x,int y) 
{ 
    int res = 1;
    x = x % mod; 
    if (x == 0) return 0;
    while (y > 0) 
    {
        if (y & 1LL) 
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;   
    } 
    return res; 
}
int invmod(int n)
{
    return modexp(n,mod-2);
}
set<pair<int,int>> s;
int l[maxn],w[maxn],h[maxn];
int find(int a,int b,int h)
{
    auto itr = s.upper_bound({a,inf});
    if(itr!=s.begin()) itr--;   
    int ans = 0;
    stack<pair<int,int>> st;
    int l = a,r = b;
    for(auto it = itr;it!=s.end();it++)
    {
        if(it->F>b) break;
        if(it->S<a) continue;
        l = min(l,it->F);
        r = max(r,it->S);
        ans+=2*(min(b,it->S) - max(a,it->F));
        ans+=2*h;
        st.push(*it);
    }
    while(!st.empty())
    {
        s.erase(st.top());
        st.pop();
    }
    s.insert({l,r});
    return ans; 
}
void solve()
{
    s.clear();
    int n,k;
    cin>>n>>k;
    fpi(1,k,1) cin>>l[i];
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    fpi(k+1,n,1) l[i] = (a*l[i-2] + b*l[i-1] + c)%d + 1;
    fpi(1,k,1) cin>>w[i];
    cin>>a>>b>>c>>d;
    fpi(k+1,n,1) w[i] = (a*w[i-2] + b*w[i-1] + c)%d + 1;
    fpi(1,k,1) cin>>h[i];
    cin>>a>>b>>c>>d;
    fpi(k+1,n,1) h[i] = (a*h[i-2] + b*h[i-1] + c)%d + 1;
    // pa(l,n,1);
    // pa(w,n,1);
    // pa(h,n,1);
    int ans = 0;
    int p[n+1];
    fpi(1,n,1)
    {
        ans+=(2*w[i]+2*h[i]);
        ans-=find(l[i],l[i]+w[i],h[i]);
        p[i] = ans;
    }
    int fans = 1;
    fpi(1,n,1)
    {
        fans*=(p[i]%mod);
        fans%=mod;
    }
    d(fans)
}   
int32_t main()
{
    IOS;
    #ifndef LOCAL_DEFINE
        freopen("inputLocal.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    cout<<setprecision(12);
    int t;
    cin>>t;
    for(int i = 1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
