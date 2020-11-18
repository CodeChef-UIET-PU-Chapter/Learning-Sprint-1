#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
#define N 100000
#define mod 1000000007
 
template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}
 
ll solve(ll a[],int p,ll n)
{
    ll l=0,r=n-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(l==r&&l==0)
        {
            //cout<<"p: "<<p<<" "<<l<<" "<<r<<"\n";
            if(a[l]<=p)
            return 1;
            else
            return 0;
        }
        if(a[mid]>p&&a[mid-1]<=p)
        return mid;
        if(a[mid]<=p)
        l=mid+1;
        else
        r=mid-1; 
    }
 
    return -1;
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
        ll a[n],b[m];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
 
        sort(a,a+n);
        ll ans;
        for(int i=0;i<m;i++)
        {
            ans=solve(a,b[i],n);
            if(ans==-1)
            {
                if(b[i]<a[0])
                cout<<0<<" ";
                else
                cout<<n<<" ";
            }
            else
            cout<<ans<<" ";
        }
        cout<<"\n";
	}
}
