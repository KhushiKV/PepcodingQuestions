#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)

const int N=1e5+5;
const int INF = 1e9+5;
// int n,m;
// int dx[8] = {1, 1,-1,-1,0,0, -1,1};
// int dy[8] = {0,-1,0,  1,1,-1,-1,1};
// vector<vector<int>> mat(N,vector<int>(N,0));
vector<int> visited(N,0);
vector<int> finaldist(N,INF);
vector<pair<int,int>> graph[N];

int dijkstra(int src,int n){
    set<pair<int,int>> dist_node;
    dist_node.insert({0,src});
    finaldist[src] = 0;
    
    while(dist_node.size()>0){
        auto node  = *dist_node.begin();
        int node_dist = node.first;
        int node_v = node.second;
        dist_node.erase(dist_node.begin());
        if(visited[node_v]) continue;
        visited[node_v] = 1;

        for(auto &child:graph[node_v]){
            int child_v = child.first; 
            int wt = child.second;
            if(finaldist[node_v]+wt<finaldist[child_v]){
                finaldist[child_v] = finaldist[node_v]+wt;
                dist_node.insert({finaldist[child_v],child_v});
            }
        }
    }
    
    int ans=0;
    for(int i=1;i<=n;i++){
        if(finaldist[i]==INF) return -1;
        ans = max(ans,finaldist[i]);
    }
    return ans;
}


// void dijkstra(ll src,ll n){
//     priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> dist_node;
//     dist_node.push({0,src});
//     finaldist[src] = (ll)0;
    
//     while(!dist_node.empty()){
//         auto node  = dist_node.top();
//         ll node_dist = node.first;
//         ll node_v = node.second;
//         dist_node.pop();
//         //if(visited[node_v]) continue;
//         //visited[node_v] = 1;

//         for(auto &child:graph[node_v]){
//             ll child_v = child.first; 
//             ll wt = child.second;
//             if(finaldist[node_v]+wt<finaldist[child_v]){
//                 finaldist[child_v] = finaldist[node_v]+wt;
//                 dist_node.push({finaldist[child_v],child_v});
//                 par[child_v] = node_v;
//             }
//         }
//     }
    

// }

void solve()
{
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    ll a,b,c;
    loop(i,0,m){
       cin>>a>>b>>c;
       graph[a].pb({b,c});
    }
    cout<<dijkstra(k,n);
}

// void reset(){
//         for(int i=0;i<N;i++){
//         for(int j=0;j<N;j++){
//             visited[i][j]=0;
//             level[i][j]=INF;
//         }
//         }
// }

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