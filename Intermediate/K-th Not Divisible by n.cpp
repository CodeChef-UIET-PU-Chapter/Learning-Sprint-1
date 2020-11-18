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
 
int main()
{
	io;
	ll test_case;
	cin>>test_case;
	//test_case=1;
	while(test_case--)
	{
        ll n,k;
        cin>>n>>k;
        ll start,end;
        if(n==k)
        {
            print(n+1);
            continue;
        }
        start=n;
        end=n*k;
        if(n>k)
        {
            print(k);
            continue;
        }
        while(start<=n*k)
        {
            int mid=(start+end)/n;
            if((start-start/n)<=k&&((start+n)-((start+n)/n))>=k)
            break;
            else
            {
                start+=n;
                if((mid-mid/n)>k)
                end=mid-mid%n;
                else if((end-end/n)==k)
                {
                    start=end-n;
                    break;
                }
                else
                    start=mid-mid%n;
            }    
 
            //cout<<start<<"\n";
        }
        //cout<<start<<"\n";
        ll cnt=start-start/n;
        //cout<<cnt<<"\n";
        cnt=start+k-cnt;
 
        print(cnt);
	}
}
