#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)

const int N=1e5+10;
vector<int> graph[N];
bool visited[N];

bool dfs(int vertex, int par){
    
    visited[vertex]  =true;
    bool isloopexists = false;

    for(auto &child: graph[vertex]){
        if(visited[child] && child!=par)
        { return true; }
        if(visited[child])
        { continue; }
        visited[child]=true;
        isloopexists |= dfs(child,vertex);
    }
    return isloopexists;
}

void solve()
{
   int n,m;cin>>n>>m;
   int v1,v2;
    for(int i=0;i<m;i++){
        cin>>v1>>v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);
    }
    cout<<dfs(1,-1);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
    ll t = 1;
    //cin >> t;

    while (t--)
    {
       solve();
    }
}