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
vector<int> A(N);
vector<int> par(N,-1);
vector<int> isleaf(N,0);

void dfs(int vertex,int p,int &currcnt,int &cnt,int C){

    for(auto &child: graph[vertex]){
        if(graph[child].size()==1) {isleaf[child]=1;}
        if(child==p) continue;
        if(A[child]==1) currcnt++;
        dfs(child,vertex,currcnt,cnt,C);
    }
    if(isleaf[vertex]==1 && currcnt<=C){
        cnt++;
    }
    if(A[vertex]==1) currcnt--;
}



void solve()
{
   int n,m;cin>>n>>m;
   loop(i,1,n+1){
       cin>>A[i];
   }
   int v1,v2;
    for(int i=0;i<m;i++){
        cin>>v1>>v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);
    }
    int C;cin>>C;
    int currcnt=0;
    if(A[1]==1) currcnt=1;
    int cnt=0;
    dfs(1,-1,currcnt,cnt,C);
    cout<<cnt<<endl;

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