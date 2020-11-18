#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 1000000
#define mod 1000000007
 
template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}
 
ll arr[N+1], node[4*(N+1)];
 
void build(ll lx,ll rx, ll x)
{
	if(rx==lx)
	{
		node[x]=arr[lx];
		return;
	}
	
	ll mid=(lx+rx)/2;
	build(lx,mid,2*x);
	build(mid+1,rx,2*x+1);
	node[x]=(node[2*x]+node[2*x+1]);
}
 
ll query(ll l,ll r,ll lx,ll rx,ll x)
{
	if(lx>r||rx<l) return 0;
	if(lx>=l&&rx<=r) return node[x];
 
	ll mid=(lx+rx)/2;
	ll left=query(l,r,lx,mid,2*x);
	ll right=query(l,r,mid+1,rx,2*x+1);
 
	return left+right;
}
 
void update(ll lx,ll rx,ll x,ll i,ll v)
{
	if(lx==rx)
	{
		node[x]+=v;
		return ;
	}
 
	ll mid=(lx+rx)/2;
	if(mid>=i)
	update(lx,mid,2*x,i,v);
	else
	update(mid+1,rx,2*x+1,i,v);
 
	node[x]=node[2*x]+node[2*x+1];
}
 
int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {  
		ll n,q,a,b;
		cin>>n>>q;
		string s;
		build(1,n,1);
 
		//query(1,n,1,n,1);
		for(int i=0;i<q;i++)
		{
			cin>>s>>a>>b;
			if(s=="find")
			print(query(a,b,1,n,1));
			else
			update(1,n,1,a,b);
		}
    }
    return 0;
}
