#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
int comulativeS[N + 1];
int comulativeG[N + 1];

int main() {

	string s;
	cin >> s >> s;
	int n = (int)s.size();
	s = "#" + s;

	int count = 0;
	int maxi = 0;

	for (int i = 1; i <= n; i++)
	{
		comulativeS[i] = s[i] == 'S' ? 1 : 0;
		comulativeG[i] = s[i] == 'G' ? 1 : 0;
		comulativeS[i] += comulativeS[i - 1];
		comulativeG[i] += comulativeG[i - 1];

		if (s[i] == 'S')
		{
			maxi = max(maxi, count);
			count = 0;
		}
		else
		{
			count++;
		}
	}

	maxi = max(maxi, count);

	int i = 1;
	int j = i;

	while (true)
	{
		if (comulativeS[j] - comulativeS[i - 1] <= 1) {
			j++;
		}

		if (j > n)
			break;

		while (comulativeS[j] - comulativeS[i - 1] > 1) {
			i++;
		}

		
		if (comulativeG[j] - comulativeG[i - 1] > 0 && (comulativeG[i - 1] > 0 || (j < n &&comulativeG[n]>comulativeG[j])))
		{
			int rest = j - i + 1;
			maxi = max(maxi, rest);
		}
	}

	cout << maxi << endl;


	int pause;
	cin >> pause;
	return 0;
}