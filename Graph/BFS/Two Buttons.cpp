//B. Two Buttons
//http://codeforces.com/problemset/problem/520/B
#include<bits/stdc++.h>
using namespace std;

const int N = 1000009;
int level[N + 1];
int visited[N + 1];

int bfs(int from, int to) {

	level[from] = 0;
	visited[from] = 1;

	queue<int> qu;
	qu.push(from);

	while (!qu.empty())
	{
		int front = qu.front();
		qu.pop();

		if (front == to)
		{
			return level[front];
		}

		vector<int> adjacents= { front * 2 ,front -1};

		for (int i = 0; i < (int)adjacents.size(); i++)
		{
			int adjacent = adjacents[i];

			if (adjacent >= 1 && adjacent <= N&&visited[adjacent] != 1)
			{
				qu.push(adjacent);
				level[adjacent] = level[front] + 1;
				visited[adjacent] = 1;
			}
		}
	}

	return 0;
}

int main() {

	int n, m;
	cin >> n >> m;

	int result = bfs(n, m);

	cout << result << endl;
	

	int pause;
	cin >> pause;

	return 0;
}