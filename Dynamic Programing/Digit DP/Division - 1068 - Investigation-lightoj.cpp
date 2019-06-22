#include<bits/stdc++.h>
using namespace std;

long long dp[10][100][100][2][2];

long long Recur(vector<int> &numbers, int k, int pos, int summod, int mod,int isStarted, int isSmall) {

	if ((int)numbers.size() == pos)
	{
		if (!isStarted) {
			return 0;
		}

		if (summod == 0 && mod == 0)
		{
			return 1;
		}

		return 0;
	}

	if (dp[pos][summod][mod][isStarted][isSmall] != -1)
	{
		return dp[pos][summod][mod][isStarted][isSmall];
	}

	int to = isSmall ? 9 : numbers[pos];

	long long sum = 0;

	for (int i = 0; i <= to; i++)
	{
		sum += Recur(numbers, k, pos + 1, (summod + i) % k, (mod * 10 + i) % k, i>0?true:isStarted, isSmall || i < numbers[pos]);
	}

	return dp[pos][summod][mod][isStarted][isSmall] = sum;
}

long long Solve(long long l, long long k)
{
	memset(dp, -1, sizeof(dp));

	if (k > 100 || l < 1)
		return 0;

	vector<int> numbers;

	while (l)
	{
		numbers.push_back(l % 10);
		l = l / 10;
	}

	reverse(numbers.begin(), numbers.end());

	long long res = Recur(numbers, k, 0, 0, 0, 0,0);

	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;


	for (int c = 1; c <= n; c++)
	{
		long long l, r, k;
		cin >> l >> r >> k;

		long long res1 = Solve(l - 1, k);
		long long res2 = Solve(r, k);

		cout << "Case " << c << ": " << res2- res1 << endl;
	}

	return 0;
}