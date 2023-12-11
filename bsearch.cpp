#include<iostream>
using namespace std;
int bin(int str,int endd,int key,int arr[])
{
    if(str==endd)
    {
        if(arr[str]==key)
            return str;
        else
            return -1;
    }
    else
    {
        int mid=(str+endd)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            return bin(str,mid-1,key,arr);
        else
            return bin(mid+1,endd,key,arr);
    }
}

int bini(int str,int endd,int key,int arr[])
{
    while(1)
    {
        if(str==endd)
    {
        if(arr[str]==key)
            return str;
        else
            return 0;
    }
    else{
         int mid=(str+endd)/2;
         if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
                endd=mid-1;
        else
            str=mid+1;
    }
    }
}


int main()
{
    int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   int key;
   cin>>key;
   int a=bini(0,n,key,arr);
   if(a!=-1)
   cout<<a+1;
   else
    cout<<-1;
}
