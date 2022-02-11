#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)

const ll N=1e3;
int parent[N];
int size[N];

void make(int i){
    parent[i]=i;
    size[i] = 1;
}

int find(int i){
    if(parent[i]==i) return i;
    return parent[i] = find(parent[i]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    int size_a  =size[a];
    int size_b = size[b];
    if(a!=b){
        if(size_a<size_b){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}


void solve()
{

int nodes, k;
cin>>nodes>>k;

loop(i,1,nodes+1){
    make(i);
}
int a,b;
loop(i,0,k){
    cin>>a>>b;
    Union(a,b);
}

int cnncted_comp = 0;
for(int i=1;i<=nodes;i++){
    if(parent[i]==i) 
    {
        cnncted_comp++;
        cout<<i<<" -> "<<size[i]<<endl;
    }
}

cout<<cnncted_comp;

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