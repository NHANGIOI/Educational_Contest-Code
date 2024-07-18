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
const int mod = 1e9 + 7;
const int NMAX = 1e5 + 10;
/*
    ,_
    (OvO)
    /)_")
    /_/
*/
int n;
vector<int> adj[NMAX];
int dp[NMAX][2];
int add(int x,int y){
    if((x += y) >= mod) return x - mod;
    return x;
}
void mul(int &x,int y){
    ll res = 1LL * x * y;
    if(res >= MOD)  x = (int)(res % MOD);
    else    x = (int)res;
}
void DFS(int u,int p){
    dp[u][0] = dp[u][1] = 1;
    for(int v : adj[u]) if(v != p){
        DFS(v,u);
        mul(dp[u][1],dp[v][0]);
        mul(dp[u][0],add(dp[v][0],dp[v][1]));
        //++cnt;
    }
}
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
    FOR(i,1,n-1){
        int x,y;    cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1,0);
    cout<<add(dp[1][0],dp[1][1]);
    cerr <<endl<< "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
    return 0;
}
