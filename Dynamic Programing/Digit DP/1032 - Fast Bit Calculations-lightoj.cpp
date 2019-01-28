#include<bits/stdc++.h>
using namespace std;

long long dp[34][2][2][34];

long long Recur(vector<int> &bits,int pos,int last,int isSmall,long long cnt) {

	if ((int)bits.size() == pos)
	{
		return cnt;
	}
	if (dp[pos][last][isSmall][cnt] != -1)
	{
		return dp[pos][last][isSmall][cnt];
	}

	long long sum = 0;
	int to = isSmall ? 1 : bits[pos];

	for (int i = 0; i <= to; i++)
	{
		sum += Recur(bits, pos + 1, i, isSmall || i < bits[pos], (i == 1 && last == 1) ? cnt + 1 : cnt);

	}

	return dp[pos][last][isSmall][cnt] = sum;
}

void Solve(int c, long long n)
{
	memset(dp, -1, sizeof(dp));
	vector<int> bits;

	while (n)
	{
		bits.push_back(n%2);
		n = n / 2;
	}

	reverse(bits.begin(), bits.end());

	long long res = Recur(bits, 0, 0, 0, 0);

	cout << "Case " << c << ": " << res << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;


	for (int c = 1; c <=n; c++)
	{
		long long n;
		cin >> n;
		Solve(c, n);
	}

	return 0;
}