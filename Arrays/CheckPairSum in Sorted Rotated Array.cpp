/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool doesPairExists(int* a, int n, int sum)
{
    int i;
    for(i=0;i<n-1;i++)
        if(a[i]>a[i+1])
            break;
    int r = i;
    int l = (i+1);
    while(l!=r)
    {
        if(a[l]+a[r]==sum)
            return true;
        if(a[l]+a[r]<sum)
            l = (l+1)%n;
        if(a[l]+a[r]>sum)
            r= (n+r-1)%n;
    }
    return false;
}

int main()
{
    int a[]={11,15,4,5,6,9};
    int n = sizeof(a)/sizeof(a[0]);
    if(doesPairExists(a,n,22))
        cout<<"The given pair sum exists "<<endl;
    else
        cout<<"Does not exist"<<endl;
    return 0;
}
