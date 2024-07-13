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
const int NMAX = 1e3 + 10;
/*
    ,_
    (OvO)
    /)_")
    /_/
*/
void add(int &x,int y){
    ll res = x + y;
    if(res >= MOD)  x = (int)(res - MOD);
    else    x = (int)res;
}
int n,m;
bool a[NMAX][NMAX];
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
    cin>>n>>m;
    FOR(i,1,n)  FOR(j,1,m){
        char x; cin>>x;
        if(x == '.')    a[i][j] = 1;    
    }
    if(a[1][1]) dp[1][1] = 1;
    FOR(i,1,n)  FOR(j,1,m)  if((i ^ 1) || (j ^ 1)) {
        if((i ^ 1) && (a[i - 1][j])) add(dp[i][j],dp[i - 1][j]);
        if((j ^ 1) && (a[i][j - 1])) add(dp[i][j],dp[i][j - 1]);
    }
    cout<<dp[n][m];
    cerr <<endl<< "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
    return 0;
}
