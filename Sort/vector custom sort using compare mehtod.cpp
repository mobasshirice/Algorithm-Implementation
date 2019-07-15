#include<bits/stdc++.h>
using namespace std;


bool compAsc(const int& lhs, const int& rhs)
{
    return lhs<rhs;
}


void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.end(),compAsc);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}

int main()
{
    int t;
    t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
