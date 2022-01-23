#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)


void solve()
{

ll n,k;cin>>n>>k;
vector<ll> a;
ll x;
ll tot = 0;
loop(i,0,n){
    cin>>x;
    a.pb(x);
    tot+=x;
}

ll  maxsubsum= a[0];ll ansmaxsubsum=a[0];
for(ll i = 1;i<n;i++){
    maxsubsum = max(maxsubsum+a[i],a[i]);
    ansmaxsubsum = max(ansmaxsubsum,maxsubsum);
}
if(k==1){
    cout<<ansmaxsubsum<<endl;
    return;
}
vector<ll>b;
loop(i,0,2){
    loop(j,0,n){
        b.pb(a[j]);
    }
}
ll twicesubsum= b[0], anstwicesubsum = b[0];
for(ll i = 1;i<2*n;i++){
    twicesubsum = max(twicesubsum+b[i],b[i]);
    anstwicesubsum = max(anstwicesubsum,twicesubsum);
}
ll anss = 0;
anss = max((tot*(k-2) + anstwicesubsum),anstwicesubsum);
cout<<anss<<endl;


}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
    ll t = 1;
    cin >> t;

    while (t--)
    {
       solve();
    }
}