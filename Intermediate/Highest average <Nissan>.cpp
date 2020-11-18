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

int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        ll n;
        cin>>n;

        ll arr[n],avg[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        ll temp=arr[0];
        avg[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            //cout<<arr[i]+temp<<"\n";
            avg[i]=(arr[i]+temp)/(i+1);
            temp+=arr[i];
        }    

        ll q;
        int maxlen=0;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            cin>>temp;
            if(temp>avg[n-1])
            print(n);
            else
            print((lower_bound(avg,avg+n,temp)-avg));
        }
    }
}
