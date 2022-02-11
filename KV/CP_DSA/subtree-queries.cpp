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
vector<int> even_cnt(N,0);

void dfs(int vertex,int par=-1){
  
    subtree_sum[vertex] = vertex;
    if(vertex%2==0) even_cnt[vertex] += 1;

    for(auto &child: graph[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_cnt[vertex] += even_cnt[child];
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
    for(int i=1;i<=n;i++){
        cout<<subtree_sum[i]<<" ";
    }cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<even_cnt[i]<<" ";
    }
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