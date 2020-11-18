#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000
#define mod 1000000007
 
template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}
 
bool isvalid(int mid,int n,int c,vector<ll>& arr)
{
    ll cnt=1;
    ll pre=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]-pre>=mid)
        cnt++,pre=arr[i];
    }
    if(cnt>=c) return true;
    return false;
} 
 
ll ans(vector<ll> &arr,int n,int c)
{
    int l=0;
    int h=arr[n-1]-arr[0];
    ll ans=0;
 
    while(l<=h)
    {
        ll mid=(l+h)/2;
        if(isvalid(mid,n,c,arr))
        ans=max(ans,mid),l=mid+1;
        else
        h=mid-1;
    }
 
    return ans;
}
 
int main()
{
    io;
    ll test_case;
    cin>>test_case;
    //test_case=1;
    while(test_case--)
    {
        ll n,c;
        cin>>n>>c;
        vector<ll> barns(n);
 
        for(int i=0;i<n;i++) cin>>barns[i];
 
        sort(barns.begin(),barns.end());
        print(ans(barns,n,c));
    }
} 
