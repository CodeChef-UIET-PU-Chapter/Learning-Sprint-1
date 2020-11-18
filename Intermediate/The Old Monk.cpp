#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define N 1000000
using namespace std;

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}


int main()
{
    io;
    ll test_case;
    cin>>test_case;
    //test_case=1;
    while(test_case--)
    {
        ll n;
        cin>>n;

        ll a[n],b[n],ans=0,limit;
        for(int i=n-1;i>=0;i--) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        if(a[0]>=b[0])
        print(0);
        else
        {
            //reverse(a,a+n);
            for(ll i=n-1;i>=0;i--)
            {
                //cout<<"b: "<<b[i]<<" ";
                limit=upper_bound(a,a+n,b[i])-a;
                //cout<<"limit: "<<limit<<"\n";
                if(a[limit]<=b[i])
                ans=max(ans,i-((n-1)-limit));
                else if(a[limit-1]<=b[i])
                ans=max(ans,i-((n-1)-(limit-1)));

                //cout<<"ans: "<<ans<<"\n";
            }
            print(ans);
        } 
    }
}
