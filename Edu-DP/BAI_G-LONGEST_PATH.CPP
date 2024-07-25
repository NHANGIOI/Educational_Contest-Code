//Nhận xét 1  : là độ thị có hướng ko chu trình (vì có chu trình thì kq là vô cực)
//Nhận xét 2 : có thể duyệt trong O(n) bằng đệ quy có nhớ
// Thuật chuẩn :
/*
dùng qhd duyệt hết M cạnh (ko check (ko có chu trình và để duyệt hết cạnh))
gọi dp[u] là đg đi dài nhất khi xuất phát từ đỉnh u
thì dp[u] += dp[v]
kq BT là *max_element(dp,dp + n);
*/
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
#define          BIT(x,i)   ((1 << i) & x)
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
int n,m;
vector<int> adj[NMAX];
int dp[NMAX];
int DFS(int u){
    if(dp[u])   return dp[u];
    for(int v : adj[u]){
        dp[v] = DFS(v);
        dp[u] = max(dp[u],dp[v] + 1);
    }
    return dp[u];
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
    cin>>n>>m;
    FOR(i,1,m){
        int x,y;    cin>>x>>y;
        adj[x].push_back(y);
    }

    FOR(i,1,n){
        int tmp = DFS(i);
    }
    cout<<*max_element(dp + 1,dp + n + 1);
    cerr <<endl<< "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
    return 0;
}
