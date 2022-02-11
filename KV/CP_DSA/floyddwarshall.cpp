#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)

const ll N = 1e5+5;
const ll INF = 1e18;


void solve()
{
ll n,m;cin>>n>>m;
vector<vector<ll>> dist(n+1,vector<ll>(n+1));
loop(i,1,n+1){
    loop(j,1,n+1){
        if(i==j) dist[i][j]=0;
        else dist[i][j]=INF;
    }
}
ll a,b,c;
loop(i,0,m){
    cin>>a>>b>>c;
    dist[a][b] = c;
}

loop(k,1,n+1){
    loop(i,1,n+1){
        loop(j,1,n+1){
            if(dist[i][k]!=INF && dist[k][j]!=INF)
            dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
}

loop(i,1,n+1){
    loop(j,1,n+1){
      if(dist[i][j]==INF) cout<<"I"<<" ";
      else cout<<dist[i][j]<<" ";
    }
    cout<<endl;
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