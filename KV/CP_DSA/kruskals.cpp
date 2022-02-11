#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)

const ll N=1e5+10;
ll parent[N];
ll sizes[N];

void make(ll i){
    parent[i]=i;
    sizes[i] = 1;
}

ll find(ll i){
    if(parent[i]==i) return i;
    return parent[i] = find(parent[i]);
}

void Union(ll a, ll b){
    a = find(a);
    b = find(b);
    int size_a  =sizes[a];
    int size_b = sizes[b];
    if(a!=b){
        if(size_a<size_b){
            swap(a,b);
        }
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}


void solve()
{

ll nodes, k;
cin>>nodes>>k;

loop(i,1,nodes+1){
    make(i);
}
vector<pair<int,pair<int,int>>> edges;
ll a,b,wt;
loop(i,0,k){
    cin>>a>>b>>wt;
    edges.pb({wt,{a,b}});
 }
 sort(edges.begin(),edges.end());

 int totcost = 0;
 for(auto&edge:edges){
     int wt = edge.first;
     int v1 = edge.second.first;
     int v2 = edge.second.second;
     if(find(v1)==find(v2)) continue;
     Union(v1,v2);
     cout<<v1<<"  "<<v2<<endl;
     totcost += wt;
 }
 cout<<totcost<<endl;
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