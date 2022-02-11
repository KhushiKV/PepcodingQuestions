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
vector<int> par(N,-1);
vector<int> even_cnt(N,0);

void dfs(int vertex,int p=-1){
  
    par[vertex] = p;
    for(auto &child: graph[vertex]){
        if(child==p) continue;
        dfs(child,vertex);
    }
}

vector<int> path(int v){
    vector<int> ans;
    while(v!=-1){
        ans.pb(v);
        v = par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    dfs(1);
    int x,y;cin>>x>>y;

    vector<int>path_x = path(x);
    vector<int> path_y = path(y);

    int ln = min(path_x.size(),path_y.size());
    int lca=-1;
    for(int i=0;1<ln;i++){
        if(path_x[i]==path_y[i]) lca=path_x[i];
        else break;
    }
    cout<<lca;
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