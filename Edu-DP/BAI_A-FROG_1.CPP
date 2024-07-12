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
const int NMAX = 1e5 + 10;
/*
    ,_
    (OvO)
    /)_")
    /_/
*/
int n;
int a[NMAX];
int dp[NMAX];
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
    cin>>n;
    FOR(i,1,n)  cin>>a[i];
    FOR(i,0,n)  dp[i] = INF;
    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    FOR(i,3,n)  dp[i] = min({dp[i],dp[i - 1] + abs(a[i] - a[i - 1]),dp[i - 2] + abs(a[i] - a[i - 2])});
    cout<<dp[n];
    cerr <<endl<< "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
    return 0;
}
