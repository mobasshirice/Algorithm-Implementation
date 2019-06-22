//https://uva.onlinejudge.org/external/103/p10305.pdf
#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	while (cin >> n >> m)
	{
		vector<vector<int>> items(n + 1);
		vector<int> indegree(n + 1);

		for (int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;
			items[u].push_back(v);
			indegree[v]++;
		}

		vector<int> results;

		while (true)
		{
			vector<int> next;

			for (int i = 1; i <= n; i++)
			{
				if (indegree[i] == 0)
				{

					results.push_back(i);
					indegree[i]--;


					//adjacents
					for (int k = 0; k < items[i].size(); k++)
					{
						next.push_back(items[i][k]);
					}
				}
			}

			for (int i = 0; i < next.size(); i++)
			{
				indegree[next[i]]--;
			}


			if (next.size() == 0)
				break;
		}


		for (int i = 0; i < (int)results.size(); i++)
		{
			if (i == 0)
			{
				cout << results[i];
			}
			else
			{
				cout << " " << results[i];
			}
		}
		cout << endl;
	}

	return 0;
}