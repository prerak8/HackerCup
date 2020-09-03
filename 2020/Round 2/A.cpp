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
#define de(x) cout << (#x) << " : " << (x) << end1l;
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
#define rev(a) reverse(a.begin(),a.end1())
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
int s[maxn],x[maxn],y[maxn];
void solve()
{
    int n,k;
    cin>>n>>k;
    int extra = 0, dep = 0;
    int a,b,c,d;
    fpi(1,k,1) cin>>s[i];
    cin>>a>>b>>c>>d;
    fpi(k+1,n,1) s[i] = (a*s[i-2] + b*s[i-1] + c)%d;
    fpi(1,k,1) cin>>x[i];
    cin>>a>>b>>c>>d;
    fpi(k+1,n,1) x[i] = (a*x[i-2] + b*x[i-1] + c)%d;
    fpi(1,k,1) cin>>y[i];
    cin>>a>>b>>c>>d;
    fpi(k+1,n,1) y[i] = (a*y[i-2] + b*y[i-1] + c)%d;
    // pa(s,n,1);
    // pa(x,n,1);
    // pa(y,n,1);
    int leftlimit = 0, rightlimit = 0,tot = 0;
    fpi(1,n,1)
    {
        leftlimit+=x[i];
        rightlimit+=x[i]+y[i];
        tot+=s[i];
    }
    if(tot>=leftlimit && tot<=rightlimit)
    {
        fpi(1,n,1)
        {
            if(s[i]<x[i]) dep+=x[i] - s[i];
            else if(s[i]>x[i]+y[i]) extra+=s[i] - (x[i]+y[i]);
        }
        int temp = min(dep,extra);
        d(dep + extra - temp)
    }
    else
    {
        d(-1)
    }
}   
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    cout<<setprecision(12);
    int t=1;
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