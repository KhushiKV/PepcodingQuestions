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
int visited[N];
int level[N];
queue<int> q;

void bfs(int vertex){

    q.push(vertex);
    visited[vertex]=1;

    while(!q.empty()){

        int curr_ver = q.front();
        q.pop();
        cout<<curr_ver<<" ";

        for(int &child:graph[curr_ver]){

            if(!visited[child]){
                q.push(child);
                visited[child]=1;

                level[child]=level[curr_ver]+1;
            }
        }
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
    bfs(1);
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<" ver "<<i<<"  level  "<<level[i]<<endl;
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