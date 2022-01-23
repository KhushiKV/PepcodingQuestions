//https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double lld;
typedef pair<ll, ll> pi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;

#define vi vector<ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)
#define mod 1000000007
#define inf 1e18

ll gcd(ll a, ll b) {if (b == 0) {return a;} return gcd(b, a % b);}
ll pow(ll x, ll a) {if (x == 1 || a == 0) {return 1;} if (a & 1) {return x * pow(x, a / 2) * pow(x, a / 2);} else {return pow(x, a / 2) * pow(x, a / 2);}}
ll rev(ll n) {ll ans = 0; while (n) {ans = (ans * 10) + n % 10; n = n / 10;} return ans;}
ll pow_mod(ll a, ll b) {ll ans = 1; if (a >= mod) {a = a % mod;} while (b) {if (b & 1) {ans = (ans * a) % mod;} a = (a * a) % mod; b = b >> 1;} return ans % mod;}
bool compare(pair<ll, ll> p1, pair<ll, ll> p2) {return p2.second > p1.second;}

ll max_sum(vi v)
{
    ll ans = 0;
    ll sum = 0;
    bool flag = false;
    loop(i, 0, v.size())
    {
        if (v[i] > 0)
            flag = true;
        sum += v[i];
        if (sum < 0)
        {
            sum = 0;
        }
        ans = max(ans, sum);
    }
    if (!flag)
        return *max_element(all(v));
    return ans;
}

void solve()
{
    ll n; cin >> n;
    vi v(n);
    ll sum = 0;
    loop(i, 0, n) cin >> v[i];
    ll sum1 = max_sum(v);
    loop(i, 0, n)
    {
        sum += v[i];
        v[i] = 0 - v[i];
    }
    cout << max(sum1, sum + max_sum(v)) << endl;
    // cout << max_sum(v, n) << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
