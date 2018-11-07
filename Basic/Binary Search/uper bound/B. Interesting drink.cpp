//http://codeforces.com/problemset/problem/706/B
#include<bits/stdc++.h>
using namespace std;

int ub(vector<int> &items,int item) {
	int low = 0;
	int high = (int)items.size() - 1;
	
	while (low <= high) {
		int mid = (low + high) / 2;
		
		if (items[mid] <= item) {
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return low;
}

int main() {

	int n;
	cin >> n;

	vector<int> items;

	for (int i = 0; i < n; i++)
	{
		int it;
		cin >> it;
		items.push_back(it);
	}
	sort(items.begin(), items.end());

	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int m;
		cin >> m;
		int res = ub(items, m);
		cout << res << endl;
	}

	int pause;
	cin >> pause;

	return 0;
}