#include<bits/stdc++.h>
using namespace std;
#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pii            pair < ll, ll>
#define  ff             first
#define  ss             second
#define  Case(x)        cout<<"Query "<<x<<": "

struct node
{
    int indx;
    node* bit[2];
    node()
    {
        indx=0;
        bit[0]=bit[1]=NULL;
    }
}*root;

void add(int n,int pos)
{
    node* cur=root;
    for(int i=31; i>=0; i--)
    {
        bool b=(n&(1<<i));
        if(cur->bit[b]==NULL)
            cur->bit[b]=new node();
        cur=cur->bit[b];
    }
    cur->indx=pos;
}
pii search(ll a)
{
    node* cur = root;
    ll ans = 0 ;
    for( ll i = 31 ; i>=0 ;i--)
    {
        bool b = (a&(1ll<<i));
        if(cur->bit[b^1ll]!=NULL)
        {
            ans|=(1ll<<i);
            cur=cur->bit[b^1];
        }
        else cur=cur->bit[b];
    }
    return {ans,cur->indx};
}

int main()
{
    CIN;
    ll  i,n,q,a;
    cin >>n;
    root=new node();
    for( i = 1 ; i <= n ; i++)
    {
        cin >> a;
        add(a,i);
    }
    cin>>q;
    for( i = 1 ; i <= q ; i++)
    {
        cin >>a;
        pii ans = search(a);
        Case(i);
        cout<<ans.ss<<" "<<ans.ff<<endl;
    }
    return 0 ;
}
//https://toph.co/p/maxxor/
