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

bool used[101];

void perumte(string &str,string res)
{

	if (res.size()==str.size())
	{
		results.push_back(res);

		return;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (!used[i])
		{
			used[i] = true;
			perumte(str,res+ str[i]);
			used[i] = false;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	string str;
	cin >> str;

	perumte(str, "");

	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << endl;
	}


	int pause;
	cin >> pause;

	return 0;
}