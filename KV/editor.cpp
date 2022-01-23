#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)

void dfs(int vertex,vector<int> graph[],vector<int> &visited_times,int par=-1){
    visited_times[vertex]++;
    for(auto &child:graph[vertex]){
        if(child==par) continue;
        dfs(child,graph,visited_times,vertex);
    }
}

void solve()
{

ll n;cin>>n;
vector<int> graph[n+1];
vector<int> visited_times(n+1,0);


ll a,b;
loop(i,0,n-1){
  cin>>a>>b;
  graph[a].pb(b);
}

for(int i=1;i<=n;i++){
    dfs(i,graph,visited_times);
}

for(int i=1;i<=n;i++){
    if(visited_times[i]==n){
        cout<<i<<endl;
        return;
    }
}
cout<<-1<<endl;

}




int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
    ll t = 1;
   // cin >> t;

    while (t--)
    {
       solve();
    }
}