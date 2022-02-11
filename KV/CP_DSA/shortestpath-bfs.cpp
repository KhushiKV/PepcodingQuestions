#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)


//chess-board horse moves ******************

const int INF=1e9+10;
queue<pair<int,int>> q;
int visited[8][8];
int level[8][8];

vector<pair<int,int>> movmts = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

int getx(string a){
    return a[0]-'a';
}

int gety(string a){
    return a[1]-'1';
}

int isValid(int x,int y){
    if(x>=0&&x<8&&y>=0&&y<8) return 1;
    return 0;
}

int bfs(string src,string dest){
    int sourcex = getx(src); int sourcey = gety(src);
    int destx = getx(dest); int desty = gety(dest);

    q.push({sourcex,sourcey});
    visited[sourcex][sourcey] = 1;
    level[sourcex][sourcey] = 0;

    while(!q.empty()){

        pair<int,int> curr_ver = q.front();
        int currx = curr_ver.first; int curry = curr_ver.second;
        q.pop();

        for(pair<int,int> mvmt:movmts){
           int childx = mvmt.first + currx;
           int childy = mvmt.second + curry;

           if(!isValid(childx,childy)) continue;
           if(!visited[childx][childy]){
               q.push({childx,childy});
               visited[childx][childy] = 1;
               level[childx][childy] = level[currx][curry] + 1;
           }
        
           if(level[destx][desty]!=INF){
               break;
            } 
        }   
    }
    return level[destx][desty];   
}

void solve()
{
    string s1,s2;cin>>s1>>s2;
    cout<<bfs(s1,s2)<<endl;
}

void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            level[i][j] = INF;
            visited[i][j]=0;
        }
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
    cin >> t;

    while (t--)
    {
       reset();
       solve();
    }
}