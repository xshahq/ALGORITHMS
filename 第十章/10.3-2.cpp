#include<bits/stdc++.h>
using namespace std;
#define M 100
#define Null -1  
int head=0,Free=0;
int Allocate_object(int *Array,int*num)  
{  
    static x;  
    if (Free==Null)  
    {    
        cout<<"out of space!"<<endl;  
        return Null;  
    }  
    else  
    {     
        x=Free;  
        Free=Array[x];  
        return x;  
    }  
}  
void Free_object(int *Array,int x)  
{  
    Array[x]=Free;  
    Free=x;  
}  