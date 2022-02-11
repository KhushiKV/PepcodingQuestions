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
vector<int> color(N,-1);
queue<int> q;

int bipartite_dfs(int vertex){

       if(color[vertex]==-1) color[vertex] = 0;

       for(int child:graph[vertex]){
           if(color[child]==-1){
               color[child]= 1-color[vertex];
               if(!bipartite_dfs(child))
               return 0;
           }else
           if(color[child]==color[vertex]) 
           return 0;
       }
       return 1;
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
    
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bipartite_dfs(1)) 
            { cout<<"not bipartite"<<endl; return;}
        }
    }
    cout<<"bipartite"<<endl;
    
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