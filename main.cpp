#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll k,n;
vector<ll> arr;

bool f(ll mid){
    ll sum=0;
    ll ktr=1;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) return false;
        if(sum+arr[i]>mid){
            sum=0;
            ktr++;
        }
        sum+=arr[i];
    }
    return (ktr<=k);
}

int main(){
    cin>>n>>k;
    arr.resize(n);
    ll r=1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        r+=arr[i];
    }
    ll l=0,ans,mid;
    while(r>l){
        mid=(r+l)/2;
        if(f(mid)){
            r=mid;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
}
