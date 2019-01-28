//http://lightoj.com/volume_showproblem.php?problem=1231

#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> items;

int dp[51][21][1001];

int recur(int pos, int cnt, int make)
{

	if (pos == items.size() || items[pos].second <cnt || make>k) {
		return 0;
	}

	if (make == k)
	{
		return 1;
	}

	if (dp[pos][cnt][make] != -1)
	{
		return dp[pos][cnt][make];
	}

	int taking = recur(pos, cnt + 1, make + items[pos].first);

	int nottaking = recur(pos + 1, 0, make);

	return dp[pos][cnt][make] = (taking + nottaking) % 100000007;
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

		int res = recur(0, 0, 0);

		cout << "Case " << t << ": " << res << endl;
	}



	return 0;
}