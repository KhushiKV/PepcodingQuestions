#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pi pair<ll,ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)

const int N=1e5+10;
vector<pair<int,int>> graph[N]; //node_wt
vector<int> visited(N,0);
priority_queue<pi,vector<pi>,greater<pi>> q;//dist_node

ll prims(ll ver){
       q.push({0,ver});
       ll ans = 0;

       while(!q.empty()){
           ll dist = q.top().first; ll to_node = q.top().second;
           q.pop();

           if(visited[to_node]) continue;

           visited[to_node]=1;
           ans+=dist;  
           for(auto &child:graph[to_node]){
                ll child_v = child.first;
                ll child_wt = child.second;
                if(!visited[child_v]){
                    q.push({child_wt,child_v});
                }
           }         

       }
       return ans;
}

void solve()
{
   ll n,m;cin>>n>>m;
   ll v1,v2,wt;
    for(ll i=0;i<m;i++){
        cin>>v1>>v2>>wt;
        graph[v1].pb({v2,wt});
        graph[v2].pb({v1,wt});
    }
    cout<<prims(1)<<endl;
    
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