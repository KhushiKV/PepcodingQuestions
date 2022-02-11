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
vector<int> depth(N,0);
vector<int> height(N,0);

void dfs(int vertex,int par=-1){
    for(auto &child:graph[vertex]){
        if(child==par){
            continue;
        }
        depth[child] = depth[vertex]+1;
        dfs(child,vertex);
        height[vertex] = max(height[vertex],height[child]+1);
    }
}


void solve()
{
    int n,m;cin>>n>>m;
    int v1,v2;
    loop(i,0,m){
          cin>>v1>>v2;
          graph[v1].pb(v2);
          graph[v2].pb(v1);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<depth[i]<<" ";
    }cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<height[i]<<" ";
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