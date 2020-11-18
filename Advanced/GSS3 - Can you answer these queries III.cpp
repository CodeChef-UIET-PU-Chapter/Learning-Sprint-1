#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000
#define limit 10000
 
template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}
 
int arr[N+1];
struct store
{
    ll left,right,segsum,bestsum;
};
store node[4*(N+1)];
 
void build(int start,int end,int x)
{
    if(start==end)
    {
        node[x].segsum=arr[start];
        node[x].bestsum=arr[start];
        node[x].left=arr[start];
        node[x].right=arr[start];
        return;
    }
 
    int mid=(start+end)/2;
    build(start,mid,2*x+1);
    build(mid+1,end,2*x+2);
 
    node[x].segsum=node[2*x+1].segsum+node[2*x+2].segsum;
    node[x].left=max(node[2*x+1].segsum+node[2*x+2].left,node[2*x+1].left);
    node[x].right=max(node[2*x+2].segsum+node[2*x+1].right,node[2*x+2].right);
    node[x].bestsum=max(max(node[2*x+1].bestsum,node[2*x+2].bestsum),node[2*x+1].right+node[2*x+2].left);
}
 
void update(int start,int end,int x,int i,int v)
{
    if(start==end)
    {
        arr[start]=v;
        node[x].segsum=arr[start];
        node[x].bestsum=arr[start];
        node[x].left=arr[start];
        node[x].right=arr[start];
        return;
    }
 
    int mid=(start+end)/2;
    if(i<=mid)
    update(start,mid,2*x+1,i,v);
    else
    update(mid+1,end,2*x+2,i,v);
 
    node[x].segsum=node[2*x+1].segsum+node[2*x+2].segsum;
    node[x].left=max(node[2*x+1].segsum+node[2*x+2].left,node[2*x+1].left);
    node[x].right=max(node[2*x+2].segsum+node[2*x+1].right,node[2*x+2].right);
    node[x].bestsum=max(max(node[2*x+1].bestsum,node[2*x+2].bestsum),node[2*x+1].right+node[2*x+2].left);
}
 
store query(int start,int end,int l,int r,int x)
{
    if(end<l||start>r) {
        store n;
        n.left=INT_MIN;
        n.right=INT_MIN;
        n.segsum=INT_MIN;
        n.bestsum=INT_MIN;
 
        return n;
    }    
    if(start>=l&&end<=r) return node[x];
 
    int mid=(start+end)/2;
    store left=query(start,mid,l,r,2*x+1);
    store right=query(mid+1,end,l,r,2*x+2);
    //cout<<left.bestsum<<" "<<right.bestsum<<" "<<x<<"\n";
    store ans;
    ans.segsum=left.segsum+right.segsum;
    ans.left=max(left.segsum+right.left,left.left);
    ans.right=max(right.segsum+left.right,right.right);
    ans.bestsum=max(max(left.bestsum,right.bestsum),left.right+right.left);
 
    return ans;
}
 
int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        ll n,m,i,x,t;
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        cin>>m;
        build(0,n-1,0);
        int ans;
        //ll ans=query(0,n-1,0,n-1,0).bestsum;
        //print(ans<0?0:ans);
        for(int p=0;p<m;p++)
        {
            cin>>t>>i>>x;
            //cout<<"m: "<<i<<"\n";
            if(t==0)
            update(0,n-1,0,i-1,x);
            else
            {
                ans=query(0,n-1,(i-1),(x-1),0).bestsum;
                print(ans);
            }    
        }
    }
} 
