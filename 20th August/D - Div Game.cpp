#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll n;cin>>n;
    ll ans=0;
    ll ACN=n;
    for(int i=2;i*i<=ACN && i<=n;i++)
    {
        int s=0;
        while(n%i==0)
        {
            s++;
            n/=i;
        }
        int tk=1;
        while(s>=tk)
        {
            s-=tk;
            tk++;
            ans++;
        }  
        
    }
    if(n>1)ans++;
    cout<<ans<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
