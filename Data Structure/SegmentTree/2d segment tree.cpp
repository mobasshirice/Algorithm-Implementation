//https://devskill.com/CodingProblems/ViewProblem/417
#include<bits/stdc++.h>

using namespace std;

#define  SZ(items) (int)items.size()
#define  CLR(a)  memset(a,0,sizeof(a))
#define  SET(a)  memset(a,-1,sizeof(a))

template <class T> inline T bigmod(T p, T e, T m)
{
    T ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1)
            ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return (T)ret;
}

#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " is " << arg1 << std::endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " is " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define debug(...)
#endif

#define  N          200010

class segment
{
    public:

    int tree[400005];

    void segment_tree(vector<int> &ar,int node,int low,int high)
    {
        if(low==high)
        {
            tree[node]=ar[low];
            return;
        }
        int left=2*node;
        int right=2*node+1;
        int mid=(low+high)/2;
        segment_tree(ar,left,low,mid);
        segment_tree(ar,right,mid+1,high);
        tree[node]=tree[left]+tree[right];
    }
    void update(int node,int low,int hi,int i,int value)
    {

        if(low==hi)
        {
            tree[node]=value;
            return;
        }
        int mid=(low+hi)/2;
        int left=2*node;
        int right=left+1;
        if(i<=mid)
            update(left,low,mid,i,value);
        else
            update(right,mid+1,hi,i,value);
        tree[node]=tree[left]+tree[right];
    }
    int query(int node,int low,int hi,int i,int j)
    {
        if(i>hi||j<low)
            return 0;
        if(low>=i&&hi<=j)
            return tree[node];
        int mid=(low+hi)/2;
        int left=2*node;
        int right=left+1;
        int x= query(left,low,mid,i,j);
        int y= query(right,mid+1,hi,i,j);
        return x+y;
    }
};



void solve()
{
    string str;
    cin>>str;
    str="?"+str;

    vector<segment> items(27);

    vector<int> it[27];

    for(int i=0;i<27;i++){
        it[i].resize((int)str.size());
    }

    for(int i=1;i<(int)str.size();i++){

        it[str[i]-'a'][i]=1;
    }

    for(int i=0;i<27;i++){
        items[i].segment_tree(it[i],1,1,(int)it[i].size()-1);
    }


    int q;
    cin>>q;

    while(q--){
        int n;
        cin>>n;

        if(n==1){
            int index;
            char change;
            cin>>index>>change;
            index++;

            char old=str[index];
            str[index]=change;

            items[old-'a'].update(1,1,(int)str.size()-1,index,0);
            items[change-'a'].update(1,1,(int)str.size()-1,index,1);
        }
        else{
            int l,h;
            char c;
            cin>>c>>l>>h;

            l++;
            h++;

            cout<<items[c-'a'].query(1,1,(int)str.size()-1,l,h)<<endl;

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}
