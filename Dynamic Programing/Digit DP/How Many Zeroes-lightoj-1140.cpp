#include <bits/stdc++.h> 

using namespace std;

long long dp[33][2][2][100];

long long recur(vector<int> &digits,int pos,bool isStared,bool isSmall,int cnt)
{
	if ((int)digits.size() == pos)
	{
		return cnt;
	}

	if (dp[pos][isStared][isSmall][cnt] != -1)
	{
		return dp[pos][isStared][isSmall][cnt];
	}

	int to = isSmall ? 9 : digits[pos];

	long long sum = 0;

	for (int i = 0; i <= to; i++)
	{
		if (i == 0 && !isStared)
		{
			sum += recur(digits, pos + 1, isStared, i < digits[pos] || isSmall, cnt);
		}
		else
		{
			sum += recur(digits, pos + 1, true, i < digits[pos] || isSmall, (i == 0)?cnt+1:cnt);
		}
	}

	return dp[pos][isStared][isSmall][cnt]=sum;
}

vector<int> getDigits(long long n)
{
	vector<int> digits;

	while (n)
	{
		digits.push_back(n % 10);

		n = n / 10;
	}

	reverse(digits.begin(), digits.end());

	return digits;
}

long long solve(long long n)
{
	if (n < 0)
	{
		return 0;
	}
	memset(dp, -1, sizeof(dp));

	vector<int> digits;
	digits = getDigits(n);

	long long res = recur(digits,0,0,0,0)+1;

	return res;
}



void print(int c, long long res) {
	cout << "Case " << c << ": " << res << endl;
}

int main()
{


	int tc;
	cin >> tc;

	for (int c = 1; c <= tc; c++)
	{
		long long l, r;
		cin >> l>> r;
		long long res1 = solve(l - 1);
		long long res2 = solve(r);
		print(c, res2 - res1);
	}

	return 0;
}