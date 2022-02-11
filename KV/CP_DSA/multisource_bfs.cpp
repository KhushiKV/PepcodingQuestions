#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double lld;
#define vi vector<ll>
#define pb push_back
#define loop(i,a,n) for(ll i=a;i<n;i++)

const int N=1e3+5;
const int INF = 1e9;
int n,m;
int dx[8] = {1, 1,-1,-1,0,0, -1,1};
int dy[8] = {0,-1,0,  1,1,-1,-1,1};
vector<vector<int>> mat(N,vector<int>(N,0));
vector<vector<int>> visited(N,vector<int>(N,0));
vector<vector<int>> level(N,vector<int>(N,INF));


int bfs(){

    int mx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           mx = max(mx,mat[i][j]);
        }
    }
    
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(mx==mat[i][j]){
               q.push({i,j});
               visited[i][j]=1;
               level[i][j]=0;
           }
        }
    }

    int mxlevel  =0;
     while(!q.empty()){
         int curr_x = q.front().first;
         int curr_y = q.front().second;
         q.pop();

         for(int k=0;k<8;k++){

             int child_x = curr_x + dx[k];
             int child_y = curr_y  + dy[k];

             if(child_x>=0&&child_y>=0&&child_x<n&&child_y<m){
                 if(!visited[child_x][child_y]){

                     q.push({child_x,child_y});
                     visited[child_x][child_y] = 1;
                     level[child_x][child_y] = level[curr_x][curr_y] + 1;
                     mxlevel = max(mxlevel,level[child_x][child_y]);

                 }
             }
            
         }
     }
     return mxlevel;

}

void solve()
{
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    cout<<bfs()<<endl;
}

void reset(){
        for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=0;
            level[i][j]=INF;
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