#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void solve()
{
    ll n,k;cin>>n>>k;
    vector<ll>t(n);
    vector<ll>v(n);
    for(int i=0;i<n;i++)cin>>t[i];
    for(int i=0;i<n;i++)cin>>v[i];
    ll ans=0;
    
    ll l=0;
    ll cost=0;
    ll time=0;
    for(int i=0;i<n;i++)
    {
        cost+=v[i];
        time+=t[i];
        while(time>k)
        {
            cost-=v[l];
            time-=t[l];
            l++;
        }
        ans=max(ans,cost);
    }
    cout<<ans<<endl;
    cout<<endl;

}


int main() {
    ll t;cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
