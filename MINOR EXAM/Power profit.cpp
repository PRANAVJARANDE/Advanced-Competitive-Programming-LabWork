#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll n,k;cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<=k)
        {
            k-=a[i];
            ans+=(1<<i);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
