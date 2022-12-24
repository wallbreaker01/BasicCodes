#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const ll N=100000;
ll s[N];

// void swap(ll arr[],ll i, ll j)
// {
//     ll temp=arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp;
// }

void bubbleSort(ll arr[],ll n)
{
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

void selectionSort(ll arr[],ll n)
{
    for(ll i=0;i<n;i++)
    {
        ll mn=i;
        for(ll j=i+1;j<n;j++)
        {
            if(arr[j]<arr[mn]) mn=j;
        }
        swap(arr[i],arr[mn]);
    }
}

void insertionSort(ll arr[],ll n)
{
    ll key,j;
    for(ll i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void merge(ll arr[], ll l, ll mid, ll r)
{
    ll n1=mid-l+1;
    ll n2=r-mid;
    ll a[n1];
    ll b[n2];

    for(ll i=0;i<n1;i++) a[i]=arr[l+i];
    for(ll i=0;i<n2;i++) b[i]=arr[mid+1+i];

    ll i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
        }
    }

    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }

}
void mergeSort(ll arr[],ll l,ll r)
{
    if(l<r)
    {
        ll mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int partition(ll arr[],ll l, ll r)
{
    ll pivot=arr[r];
    ll i=l-1;
    for(ll j=l;j<r5;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(ll arr[],ll l, ll r)
{
    if(l<r)
    {
        ll pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}



int main()
{
    ll n;
    cin>>n;
    ll s[n];
    for(ll i=0;i<n;i++) cin>>s[i];
    //bubbleSort(s,n);
    //selectionSort(s,n);
    //insertionSort(s,n);
    //mergeSort(s,0,n);
    //quickSort(s,0,n-1);

    for(ll i=0;i<n;i++) cout<<s[i]<<" ";
}
