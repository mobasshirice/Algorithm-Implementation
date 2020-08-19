//https://www.geeksforgeeks.org/two-pointers-technique/
// if there is a pair in A[0..N-1] with given sum. 

#include<bits/stdc++.h>
using namespace std;

int count(string &s, int x, int y)
{
	int c = 0;
	for (int i = x; i <= y; i++)
	{
		if (s[i] == 'G')
			c++;
	}

	return c;
}


int main() {


	int n;
	cin >> n;


	string s;
	cin >> s;

	vector<int> index;

	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == 'S')
			index.push_back(i);
	}

	if ((int)s.size() == (int)index.size())
	{
		cout << 0 << endl;
	}
	else if ((int)index.size() == 0)
	{
		cout << (int)s.size() << endl;
	}
	else if ((int)index.size() == 1)
	{
		cout << ((int)s.size() - 1) << endl;
	}
	else if ((int)index.size() == 2 && (s[0] == 'S' || s[(int)s.size() - 1] == 'S'))
	{
		cout << ((int)s.size() - 2) << endl;
	}
	else
	{
		int maxi = 0;

		for (int i = 1; i < (int)index.size(); i++)
		{
			if (i == 1)
			{
				int res = count(s, 0, index[i]);

				maxi = max(res, maxi);
			}
			else if ((int)index.size() - 1 == i)
			{
				int res = count(s, index[i - 1], n-1);

				maxi = max(res, maxi);
			}
			else
			{
				int res = count(s, index[i - 2], index[i]);

				maxi = max(res, maxi);
			}
		}

		if (maxi != count(s,0, n-1))
		{
			maxi++;
		}

		cout << maxi << endl;
	}

	long long pause;
	cin >> pause;

	return 0;
}