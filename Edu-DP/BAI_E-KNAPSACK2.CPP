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
int n,W;
int w[110],v[110];
ll dp[NMAX];
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
    cin>>n>>W;
    FOR(i,1,n)  cin>>w[i]>>v[i];
    FOR(i,1,(int)1e5)   dp[i] = oo;
    //dp[i][j] = min(dp[i][j],dp[i - 1][j - v[i]] + w[i]);
    FOR(i,1,n)  FORD(j,(int)1e5,v[i]){
        dp[j] = min(dp[j],dp[j - v[i]] + 1LL * w[i]);
    }
    FORD(i,(int)1e5,0)  if(dp[i] <= 1LL * W){
        cout<<i;
        break;
    }
    cerr <<endl<< "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
    return 0;
}
