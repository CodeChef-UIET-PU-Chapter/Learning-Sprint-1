#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000000
#define limit 10000

int cnt;
void tower(int n,char from,char to,char aux)
{
    cnt++;
    if(n==1)
    {
        cout<<"move disk 1 from rod "<<from<<" to rod "<<to<<"\n";
        return ;
    }
    tower(n-1,from,aux,to);
    cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<"\n";
    tower(n-1,aux,to,from);
}

int main()
{
    io;
    ll test_case;
    cin>>test_case;
    while(test_case--)
    {
        cnt=0;
        int n;
        cin>>n;
        tower(n,'1','3','2');
        cout<<cnt<<"\n";
    }
    return 0;
}
