#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
bool check(ll mid,vector<ll>&a,vector<ll>&b)
{
    ll c=0;
    for(int i=0;i<n;i++)
    {
        if(mid>=a[i])
        {
            c+=abs(mid-a[i]);
        }
        else
        {
            c-=min(abs(a[i]-mid),abs(a[i]-b[i]));
        }
    }
    return c<=0;
}


int main() {
    cin>>n;
    vector<ll>a(n),b(n),c(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)cin>>c[i];
    ll r=0,l=LLONG_MAX;
    for(int i=0;i<n;i++)
    {
        r=max(r,a[i]);
        l=min(l,a[i]);
    }
    ll ans=l;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(check(mid,a,b))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    ll req=0;
    for(int i=0;i<n;i++)
    {
      if(a[i]<ans)
      {
         req+=abs(a[i]-ans);
      }
    }
    
    vector<vector<ll>>arr;
    for(int i=0;i<n;i++)
    {
        if(a[i]>ans)
        {
            ll mov=min(abs(b[i]-a[i]),abs(a[i]-ans));
            arr.push_back({c[i],mov});
        }
            
    }
    sort(arr.begin(),arr.end());
    ll cost=0;
    for(auto x: arr)
    {
        cost+=min(x[1],req)*x[0];
        req-=min(x[1],req);
        if(req<=0)break;
    }
    
    cout<<ans<<" "<<cost<<endl;
    return 0;
}
