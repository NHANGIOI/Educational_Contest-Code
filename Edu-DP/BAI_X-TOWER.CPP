#include <bits/stdc++.h>
using namespace std;

#define                fi   first
#define                se   second
#define              endl   '\n'
#define           MASK(i)   (1LL << (i))
#define            all(a)   a.begin(),a.end()
#define        FOR(i,a,b)   for(int i=(a),_b = (b);i <= _b;++i)
#define        REP(i,a,b)   for(int i=(a),_b = (b);i < _b;++i)
#define       FORD(i,a,b)   for(int i=(a),_b = (b);i >= _b;--i)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){ return l+rng()%(r-l+1);}

const ll oo = (ll)1e18+7;
const int INF = 1e9 + 7;
const ll MOD = (ll)1e9 + 7;
const int N = 1e3 + 100;
const int M = 200;
/*
    ,_
    (OvO)
    /)_")
    /_/
*/
struct ptu{
    int w,s,v;
};
int n;
ptu block[N];
ll dp[(int)1e7 + 1];
void solve(){
    cin >> n;
    int total = 0;
    FOR(i,1,n){
        int w,s,v;  cin >> w >> s >> v;
        total += w;
        block[i] = {w,s,v};
    }
    sort(block + 1,block + n + 1,[](const ptu lhs,const ptu rhs){
        return lhs.w + lhs.s < rhs.w + rhs.s;
    });
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    FOR(i,1,n)  FORD(j,block[i].s,0)    if(dp[j] != -1){
        dp[j + block[i].w] = max(dp[j + block[i].w],dp[j] + (ll)block[i].v);
    }
//    FOR(i,0,10) cout << dp[i] << " ";
    ll ans = 0;
    FOR(i,1,total)  ans = max(ans,dp[i]);
    cout << ans;
}
signed main()
{
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define TASK "a"
    if(fopen(TASK".INP", "r")){
        freopen(TASK".INP", "r", stdin);
//        freopen(TASK".OUT", "w", stdout);
    }
    solve();
    return 0;
}
