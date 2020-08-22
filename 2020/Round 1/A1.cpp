#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
#define rev(a) reverse(a.begin(),a.en())
const int inf = (int)10e12;
#define MAX 1000005
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
int L[MAX],heigth[MAX];
void solve(int caseno)
{
    cout<<"Case #"<<caseno<<": ";
    int n,k,w;
    cin>>n>>k>>w;
    fpi(1,k,1) cin>>L[i];
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    fpi(k+1,n,1) L[i] = (a*L[i-2] + b*L[i-1] + c)%d  + 1;
    fpi(1,k,1) cin>>heigth[i];
    cin>>a>>b>>c>>d;
    fpi(k+1,n,1) heigth[i] = (a*heigth[i-2] + b*heigth[i-1] + c)%d  + 1;
    int p[n+1];
    int mx = heigth[1];
    p[1] = 2*(w + heigth[1]);
    p[1]%=mod;
    unordered_map<int,int> m;
    fpi(L[1],L[1]+w,1) m[i] = max(m[i],heigth[1]);
    fpi(2,n,1)
    {
        if(L[i]<=L[i-1] + w)
        {
            p[i] = p[i-1] + 2*(L[i]-L[i-1]) + 2*max(heigth[i] - m[L[i]],0LL);
            p[i]%=mod;
            fpj(L[i],L[i]+w,1) m[j] = max(m[j],heigth[i]);
        }
        else
        {
            p[i] = p[i-1] + 2*(heigth[i] + w);
            p[i]%=mod;
            fpj(L[i],L[i]+w,1) m[j] = max(m[j],heigth[i]);
        }
    }
    // br;
    // pa(L,n,1);
    // pa(heigth,n,1);
    // pa(p,n,1);
    int ans = 1;
    fpi(1,n,1) {ans*=p[i];ans%=mod;}
    d(ans)
}   
int32_t main()
{
    IOS;
    #ifndef LOCAL_DEFINE
        freopen("inputLocal.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    cout<<setprecision(12);
    int t=1,cou = 1;
    cin>>t;
    while(t--) solve(cou++);
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
