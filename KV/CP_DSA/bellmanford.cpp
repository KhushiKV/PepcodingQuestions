#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)


//chess-board horse moves ******************
const ll N=1e5+5;
const ll INF=1e18;
vector<pair<pair<ll,ll>,ll>> edges;
vector<ll>dist(N,INF);

void bellmanford(ll src, ll n){

    dist[src] = 0;

    for(ll i=1;i<=n-1;i++){
        for(auto&edge: edges){
            ll u = edge.first.first;
            ll v = edge.first.second;
            ll wt = edge.second;
            if(dist[u]!=INF && dist[v]>dist[u]+wt){
                dist[v] = dist[u]+wt;
            }
        }
    }

    for(auto&edge:edges){
            ll u = edge.first.first;
            ll v = edge.first.second;
            ll wt = edge.second;
            if(dist[u]!=INF && dist[v]>dist[u]+wt){
                cout<<"negative weight cycle found"<<endl; return;
            }
    }

    for(ll i=1;i<=n;i++){
        cout<<"shortes dist of "<<i<<"  ->  "<<dist[i]<<endl;
    }
}


void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a,b,c;
    loop(i,0,m){
       cin>>a>>b>>c;
       edges.pb({{a,b},c});
    }

    bellmanford(1,n);

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