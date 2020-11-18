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

vector<int> sum(N+1);
void create_sum()
{
    for(int i=0;i<=N;i++)
    sum[i]=i;
    for(int i=1;i<=N;i++)
    sum[i]+=sum[i-1];
}

int main()
{
    io;
    create_sum();
    ll test_case;
    cin>>test_case;
    //test_case=1;
    while(test_case--)
    {
        int n;
        cin>>n;
        print(upper_bound(sum.begin(),sum.end(),n)-sum.begin()-1);
    }
}
