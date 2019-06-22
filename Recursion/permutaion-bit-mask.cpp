#include<bits/stdc++.h>
using namespace std;

int setBit(int n,int pos)
{
	int masks = n | (1 << pos);

	return masks;
}

int getBit(int n, int pos)
{
	int value = n & (1 << pos);

	return value;
}

vector<string> results;

void perumte(string &str, int mask, string res)
{

	if (mask == (1<< str.size())-1)
	{
		results.push_back(res);

		return;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (!getBit(mask, i))
		{
			cout << i << endl;
			perumte(str, setBit(mask,i), res+ str[i]);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	string str;
	cin >> str;

	perumte(str, 0, "");

	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << endl;
	}


	int pause;
	cin >> pause;

	return 0;
}