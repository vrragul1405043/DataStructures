/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
#define N 10

using namespace std;

int stack_array[N];
int top1 = -1;
int top2 = N;

void push1(int x)
{
    if(top1<top2-1)
        stack_array[++top1]=x;
    else
        cout<<"Stack Overflow"<<endl;
}

void push2(int x)
{
    if(top1<top2-1)
        stack_array[--top2]=x;
    else
        cout<<"Stack Overflow"<<endl;
}

void pop1()
{
    if(top1>=0)
        top1--;
    else
        cout<<"Stack Underflow"<<endl;
}

void pop2()
{
    if(top2<=N-1)
        top2++;
    else
        cout<<"Stack Underflow"<<endl;
}

int topStack1()
{
    if(top1>=0)
        return stack_array[top1];
    else
        return -1;
}

int topStack2()
{
    if(top2<N)
        return stack_array[top2];
    else
        return -1;
}

int main()
{
    push1(10);
    push1(20);
    cout<<topStack1()<<endl;//20
    push2(43);
    push2(58);
    cout<<topStack2()<<endl;//58
    push1(48);
    push2(52);
    cout<<topStack1()<<endl;//48
    pop1();
    cout<<topStack1()<<endl;//20
    return 0;
}
