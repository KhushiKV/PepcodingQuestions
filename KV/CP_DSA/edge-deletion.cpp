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
vector<int> subtree_sum(N,0);
//vector<int> val(N,0);

void dfs(int vertex,int par=-1){
  
    subtree_sum[vertex] += vertex;

    for(auto &child: graph[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        subtree_sum[vertex] += subtree_sum[child];
    }
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
    ll ans=0;
    for(int i=2;i<=n;i++){
        ll part1 = subtree_sum[i];
        ll part2 = subtree_sum[1]-part1;
        ans=max(ans,part1*part2);
    }
  cout<<ans;
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