#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 1000000
using namespace std;

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

int arr[N];
struct store
{
    int high,low,count=0;
};
store nodes[4*(N+1)];

void build(int start,int end,int x)
{
    if(start==end)
    {
        nodes[x].count=arr[start];
        nodes[x].high=start;
        nodes[x].low=start;
        return ;
    }
    int mid=(start+end)/2;
    build(start,mid,2*x);
    build(mid+1,end,2*x+1);

    nodes[x].count=nodes[2*x].count+nodes[2*x+1].count;
    nodes[x].high=max(nodes[2*x+1].high,nodes[2*x].high);
    nodes[x].low=min(nodes[2*x+1].low,nodes[2*x].low);

    return ;
}

void update(int start,int end,int index,int x)
{
    if(start==end)
    {
        nodes[x].count=0;
        nodes[x].low=nodes[x].high=start;
        return;
    }
    int mid=(start+end)/2;
    if(mid>=index)
    update(start,mid,index,2*x);
    else
    update(mid+1,end,index,2*x+1);

    nodes[x].count=nodes[2*x].count+nodes[2*x+1].count;
    nodes[x].high=max(nodes[2*x+1].high,nodes[2*x].high);
    nodes[x].low=min(nodes[2*x+1].low,nodes[2*x].low);

    return;
}

int query(int k,int x)
{
    if(nodes[x].low==nodes[x].high) 
    {
        if(nodes[x].count==k)
        return nodes[x].low;
        else
        return -1;
    }    
    if(k>nodes[2*x].count)
    return query(k-nodes[2*x].count,2*x+1);
    else
    return query(k,2*x);
}

int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        ll n,m;
        cin>>n>>m;

        for(int i=1;i<=n;i++) arr[i]=1;

        build(1,n,1);
        int type,val;
        for(int i=0;i<m;i++)
        {
            //cout<<m<<"\n";
            cin>>type>>val;
            if(type==0)
            update(1,n,val,1);
            else
            print(query(val,1));
        }
    }
}
