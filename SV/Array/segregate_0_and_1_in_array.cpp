//https://www.interviewbit.com/problems/segregate-0s-and-1s-in-an-array/

vector<int> Solution::solve(vector<int> &v) {
    int cnt=0;
    for(auto x:v)
    {
        if(x==0)
        {
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        v[i]=0;
    }
    for(int i=cnt;i<v.size();i++)
    {
        v[i]=1;
    }
    return v;
}
