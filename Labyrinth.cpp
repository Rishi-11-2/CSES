#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);

        solve();
}
void solve()
{
    long long n,m;
    cin>>n>>m;

    vector<vector<char>>grid(n+1,vector<char>(m));
    pair<long long,long long>start,end;

    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A')
            {
                start.first=i;
                start.second=j;
            }
            if(grid[i][j]=='B')
            {
                end.first=i;
                end.second=j;
            }
        }
    }
    // debug(end.first,end.second);
    vector<vector<pair<long long,long long>>>parents(n+1,vector<pair<long long,long long>>(m+1));
    vector<vector<long long>>vis(n,vector<long long>(m,0));
    vector<vector<long long>>dis(n,vector<long long>(m,(long long)(1e9)));



    dis[start.first][start.second]=0;

    priority_queue<  vector<long long> , vector<vector<long long>>, greater<vector<long long>> > pq;
    pq.push({0,start.first,start.second,-1,-1});

    while(!pq.empty())
    {

        auto it=pq.top();
        pq.pop();
        long long i=it[1];
        long long j=it[2];
        long long pI=it[3];
        long long pJ=it[4];
        parents[i][j]={pI,pJ};
        long long a[]={-1,1,0,0};
        long long b[]={0,0,-1,1};
        if(i==end.first && j==end.second)
        break;

        for(long long k=0;k<4;k++)
        {
            long long x=a[k]+i;
            long long y=b[k]+j;
            if(x>=0 && y>=0 && x<n && y<m)
            {
                if( grid[x][y]!='#' && (dis[x][y]>(dis[i][j]+1)))
                {
                    // debug(x,y);
                    dis[x][y]=dis[i][j]+1;
                    pq.push({dis[x][y],x,y,i,j});
                }
            }
        }
    }   
    if(dis[end.first][end.second]==(long long)(1e9))
    {
        cout<<"NO"<<endl;
        return;

    }

    vector<char>paths;

    auto it=end;

    pair<long long,long long> bb={-1,-1};
    while(it!=bb)
    {
        long long i=it.first;
        long long j=it.second;
        // debug(i,j);
        it=parents[i][j];
        long long newI=it.first;
        long long newJ=it.second;
        if(it==bb)
        break;
        if(i==newI)
        {
            if(j-1==newJ)
            paths.push_back('R');
            else
            paths.push_back('L');
        }
        else{
            if(i-1==newI)
            paths.push_back('D');
            else
            paths.push_back('U');
        }
    }
    reverse(all(paths));
    cout<<"YES"<<endl;
    cout<<(long long)(paths.size())<<endl;

    for(auto it:paths)
    {
        cout<<it;
    }
    cout<<endl;


}