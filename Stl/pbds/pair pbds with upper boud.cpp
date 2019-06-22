//https://www.codechef.com/viewsolution/23580267

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pair<long long,long long>, null_type,less<pair<long long,long long>>, rb_tree_tag,tree_order_statistics_node_update>


#define  SZ(items) (int)items.size()
#define  CLR(a)  memset(a,0,sizeof(a))
#define  SET(a)  memset(a,-1,sizeof(a))


int dx[] = { 0,0,1,-1,-1,-1,1,1 };
int dy[] = { 1,-1,0,0,-1,1,1,-1 };

template <class T> inline T gcd(T a, T b) { while (b) { a = a%b; swap(a, b); } return a; }





int arr[10005];


long long ub(ordered_set &items, int search)
{
	int l = 0;
	int h = items.size() - 1;

	while (l <= h)
	{
		int md = (l + h) / 2;

		pair<long, long> item = (pair<long, long>)(*items.find_by_order(md));

		if (item.first <= search)
		{
			l = md + 1;
		}
		else
		{
			h = md - 1;
		}
	}

	if (items.size() <= l)
	{
		return -1;
	}
	else
	{
		pair<long, long> item = (pair<long, long>)(*items.find_by_order(l));

		return item.second;
	}
}


void solve() {


	int n, q;
	cin >> n >> q;

	ordered_set items;

	for (int i = 1; i <= n; i++)
	{
		int item;
		cin >> item;
		items.insert({ item,i });
		arr[i] = item;
	}

	for (int i = 1; i <= q; i++)
	{
		long long id, qs;
		cin >> id >> qs;

		items.erase(items.find({ arr[id],id }));

		long long  res = ub(items, qs);

		if (i == 1)
		{
			cout << res;
		}
		else
		{
			cout << " " << res;
		}

	}

	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		solve();
	}


	return 0;
}
