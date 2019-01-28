//http://lightoj.com/volume_showproblem.php?problem=1231

#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> items;

int dp[2][21][1001];

int recur(int pos, int cnt, int make)
{

	if (pos == items.size() || items[pos].second <cnt || make>k) {
		return 0;
	}

	if (make == k)
	{
		return 1;
	}

	return dp[pos % 2][cnt][make];
}

int main()
{
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		items.clear();
		memset(dp, -1, sizeof(dp));
		cin >> n >> k;

		for (int it = 0; it <n; it++) {
			pair<int, int> item;
			cin >> item.first;
			items.push_back(item);
		}

		for (int it = 0; it < n; it++) {
			cin >> items[it].second;
		}

		for (int pos = n - 1; pos >= 0; pos--)
		{
			for (int make = k; make >= 0; make--)
			{
				for (int cnt = items[pos].second; cnt >= 0; cnt--) {


					int taking = recur(pos, cnt + 1, make + items[pos].first);

					int nottaking = recur(pos + 1, 0, make);

					dp[pos % 2][cnt][make] = (taking + nottaking) % 100000007;
				}
			}
		}

		int res = dp[0][0][0];

		cout << "Case " << t << ": " << res << endl;
	}



	return 0;
}