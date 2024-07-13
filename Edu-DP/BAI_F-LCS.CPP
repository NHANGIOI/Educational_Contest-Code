#include <bits/stdc++.h>
using namespace std;

#define                fi   first
#define                se   second
#define              endl   '\n'
#define           MASK(i)   (1LL << (i))
#define            all(a)   a.begin(),a.end()
#define        FOR(i,a,b)   for(int i=(a),_b = (b);i <= _b;++i)
#define        REP(i,a,b)   for(int i=(a),_b = (b);i < _b;++i)
#define       FORD(i,a,b)	for(int i=(a),_b = (b);i >= _b;--i)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){ return l+rng()%(r-l+1);}

const ll oo = 1e18+7;
const int INF = 1e9+7;
const ll MOD = 1e9 + 7;
const int NMAX = 3e3 + 10;
/*
    ,_
    (OvO)
    /)_")
    /_/
*/
int n,m;
string a,b;
int dp[NMAX][NMAX];
signed main()
{
 	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define TASK "a"
    if(fopen(TASK".inp", "r")){
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }
    cin>>a>>b;
    n = a.size();
    m = b.size();
    FOR(i,1,n)  FOR(j,1,m){
        dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        if(a[i - 1] == b[j - 1])    dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
    }
    string ans;
    int i = n,j = m;
    while(i != 0 && j != 0){
        if(a[i - 1] == b[j - 1])    ans += a[i - 1],--i,--j;
        else{
            if(dp[i][j - 1] < dp[i - 1][j])    --i;
            else    --j;
        }
    }
    FORD(i,ans.size() - 1,0)    cout<<ans[i];
    cerr <<endl<< "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
    return 0;
}
