#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)

const int N=1e5+5;
const int INF = 1e9;
vector<pair<int,int>> graph[N];
vector<int> level(N,INF);
int n;


int bfs(){
    
    deque<int> dq;
    dq.push_back(1);
    level[1]=0;

   while(!dq.empty()){
       int curr_v = dq.front();
       dq.pop_front();

       for(auto each:graph[curr_v]){
           int node = each.first;
           int wt = each.second;
           if(level[curr_v]+wt<level[node]){
               level[node] = level[curr_v]+wt;
               if(wt==1){
                   dq.push_back(node);
               }
               else{
                   dq.push_front(node);
               }
           }
       }
       
   }
   return level[n]==INF?-1:level[n];

}

void solve()
{
    int m;
    cin>>n>>m;
    int a,b;
    loop(i,0,m){
        cin>>a>>b;
        if(a==b) continue;
        graph[a].push_back({b,0});
        graph[b].push_back({a,1});
    }
    
    cout<<bfs();
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