#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)

const int N = 1e3+10;

// //adj matrix
// int g[N][N];

// void solve()
// {
//   int n,m;
//   cin>>n>>m;
//   int v1,v2;
//   for(int i=0;i<m;i++){
//       cin>>v1>>v2;
//       g[v1][v2]=1;
//       g[v2][v1]=1;
//   }
//   for(int i=1;i<=n;i++){
//       for(int j=1;j<=n;j++){
//           cout<<g[i][j]<<" ";
//       }
//       cout<<endl;
//   }
// }

//*******************************************************************************

// //adj list
vector<int> graph[N];

void solve(){
    int n,m;cin>>n>>m;
    int v1,v2;
    for(int i=0;i<m;i++){
        cin>>v1>>v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);
    }
    for(int i=1;i<=n;i++){
        cout<<i<<"-->";
        for(auto &child:graph[i]){
            cout<<child<<" ";
        }
        cout<<endl;
    }
}

//*******************************************************************************************

// // adj list weighted
// vector<pair<int,int>> graph[N];
// void solve(){
//     int n,m;cin>>n>>m;
//     int v1,v2,w;
//     for(int i=0;i<m;i++){
//         cin>>v1>>v2>>w;
//         graph[v1].pb({v2,w});
//         graph[v2].pb({v1,w});
//     }
//     for(int i=1;i<=n;i++){
//         cout<<i<<"-->";
//         for(auto &child:graph[i]){
//             cout<<child.first<<","<<child.second<<"  ";
//         }
//         cout<<endl;
//     }
// }

//********************************************************************************************************

// //edge list
// vector<pair<int,int>> graph;
// void solve(){
//     int n,m;cin>>n>>m;
//     int v1,v2;
//     for(int i=0;i<m;i++){
//         cin>>v1>>v2;
//         graph.pb({v1,v2});
//     }
//     for(auto &edge: graph){
//         cout<<edge.first<<","<<edge.second<<"  ";
//     }
// }

//***********************************************************************************************************


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