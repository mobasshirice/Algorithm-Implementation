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

void solve(int cas)
{
    int n,q;
    cin>>n>>q;

    vector<int> items;
    items.push_back(0);

    for(int i=1; i<=n; i++)
    {
        int item;
        scanf("%d",&item);
        items.push_back(item);
    }
    segment_tree(items,1,1,n);

    cout<<"Case "<<cas<<":"<<endl;

    while(q--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int st;

            scanf("%d",&st);
            st++;
            int an=query(1,1,n,st,st);
            printf("%d\n",an);
            update(1,1,n,st,0);
        }
        else if(t==2)
        {
            int st,add;

            scanf("%d%d",&st,&add);
            st++;
            int an=query(1,1,n,st,st);
            an+=add;
            update(1,1,n,st,an);
        }
        else
        {
            int l,h;

            scanf("%d%d",&l,&h);
            l++,h++;
            int an=query(1,1,n,l,h);
            printf("%d\n",an);
        }

    }
}

int main()
{
    int t = 1;
    cin>>t;
    int cas=1;

    while (cas<=t)
    {
        solve(cas);
        cas++;
    }

    return 0;
}
