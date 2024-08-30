void solve()
{
    ll n,m,k;cin>>n>>m>>k;
    vll a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<vector<ll>> q;
    for(int i=0;i<m;i++)
    {
        ll u,v,z;cin>>u>>v>>z;
        u--;
        v--;
        q.push_back({u,v,z});
    }
    vll exec(m+1,0);
    while(k--)
    {
        ll u,v;cin>>u>>v;
        u--;
        v--;
        exec[u]++;
        if(v+1<m)exec[v+1]--;
    }
    for(int i=1;i<m;i++)exec[i]+=exec[i-1];
    for(int i=0;i<m;i++)exec[i]*=q[i][2];
    
    vector<ll>psum(n+1,0);
    for(int i=0;i<m;i++)
    {
        psum[q[i][0]]+=exec[i];
        if(q[i][1]+1<n)psum[q[i][1]]-=exec[i];
    }

    for(int i=1;i<n;i++)psum[i]+=psum[i-1];
    
    for(int i=0;i<n;i++)
    {
        a[i]+=psum[i];
        cout<<a[i]<<" ";
    }
    cout<<endl;

}
