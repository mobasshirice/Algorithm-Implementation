#include<bits/stdc++.h>
using namespace std;

#define     SZ(x)                 ((int)(x).size())

vector<int> input[105];
int visited[101];
int path[105];

int lastv = 0;


int bfs(int start)
{
	visited[start] = 1;

	queue<int> qu;
	qu.push(start);

	while (!qu.empty())
	{
		int front = qu.front();
		qu.pop();


		vector<int> adjacents = input[front];

		for (int i = 0; i <(int)adjacents.size(); i++)
		{
			int adjacent = adjacents[i];

			if (!visited[adjacent]) {
				visited[adjacent] = 1;
				qu.push(adjacent);
				path[adjacent] = front;
				lastv = adjacent;
			}
		}
	}

	return 1;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<long  long> items(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (items[j] * 3ll == items[i]) {
					input[i].push_back(j);
				}

				if (items[i] * 2ll == items[j])
				{
					input[i].push_back(j);
				}
			}
		}
	}

	int last = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= 100; k++)
		{
			visited[k] = 0;
			path[k] = 0;
		}
		int res = bfs(i);

		bool found = false;

		int resc = 0;
		for (int k = 1; k <= 100; k++)
		{
			if (visited[k]>0) {
				resc++;
			}
		}

		if (resc == n)
		{
			last = i;
			break;;
		}
	}

	vector<long long> res;
	res.push_back(items[lastv]);

	int p = lastv;

	while (path[p] != 0)
	{
		res.push_back(items[path[p]]);
		p = path[p];
	}

	for (int i = SZ(res) - 1; i >= 0; i--)
	{
		cout << res[i] << " ";
	}



	int pause;
	cin >> pause;

	return 0;
}