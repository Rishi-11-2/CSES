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
	const long long mod=(long long)(1e9)+7;

	tree< pair<long long,long long> , null_type, less<pair<long long,long long>> ,  rb_tree_tag , tree_order_statistics_node_update   >s;


	long long n,m;
	cin>>n>>m;
	int arr[n];
	for(long long i=0;i<n;i++)
	{
		cin>>arr[i];
		s.insert({arr[i],i});
	}
	vector<long long>res;
	for(long long i=1;i<=m;i++)
	{
		char ch;
		cin>>ch;

		if(ch=='?')
		{
			long long a,b;
			cin>>a>>b;
			long long x=s.order_of_key({b,mod});
			long long y=s.order_of_key({a,mod});
			// debug(x,y);
			res.push_back(s.order_of_key({b,mod})-s.order_of_key({a-1,mod}));
		}
		else
		{
			long long k,x;
			cin>>k>>x;
			k--;

			s.erase({arr[k],k});
			arr[k]=x;
			s.insert({arr[k],k});
		}
	}
	for(auto it:res)
	cout<<it<<endl;
}