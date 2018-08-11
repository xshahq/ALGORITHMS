#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<list>
#include<vector>
#define N 1000
//这里默认全域的元素数量n小于N
using namespace std;
struct slot
{
    int key,ele;
    slot* next;
    slot* pre;
};
struct hashtable
{
    slot arr[N];
    hashtable()
    {
        for(int i = 0;i < N;++i)
        {
            arr[i].key = -1;
            if(i != N - 1)
                arr[i].next = &arr[i + 1];
            if(!i)
                arr[i].pre = &arr[i - 1];
        }
    }
    slot* head = &arr[0];
    void add_insert(int key1,int ele1)
    {
        if(arr[key1].key == -1)
        {
            if(head == &arr[key1])
                head = head ->next;
            else
            {
                arr[key1].pre ->next = arr[key1].next;
                if(arr[key1].next)
                    arr[key1].next ->pre = arr[key1].next;
            }
            arr[key1].ele = ele1;
            arr[key1].key = key1;
            arr[key1].next = arr[key1].pre = nullptr;
        }
        else if(arr[key1].key == key1)
        {
            slot* temp = head;
            head = head ->next;
            temp ->ele = ele1;
            temp ->key = key1;
            slot* t = arr[key1].next;
            arr[key1].next = temp;
            temp ->pre = &arr[key1];
            temp ->next = t;
        }
        else
        {
            add_insert(arr[key1].key,arr[key1].ele);
            arr[key1].key = key1;
            arr[key1].ele = ele1;
            arr[key1].next ->pre = arr[key1].pre;
            arr[key1].pre ->next = arr[key1].next;
            arr[key1].pre = arr[key1].next = nullptr;
        }
    }
    int add_delete(int key1,int ele1)
    {
        if(arr[key1].key != key1)
            return 0;
        slot* current = &arr[key1];
        while(current)
        {
            if(current ->ele == ele1)
                break;
            current = current ->next;
        }
        if(!current)
            return -1;
        current ->key = -1;
        if(current == &arr[key1] && current ->next)
        {
            current = current ->next;
            arr[key1].key = current ->key;
            arr[key1].ele = current ->ele;
        }
        if(current ->next)
            current ->next ->pre = current ->pre;
        if(current ->pre)
            current ->pre ->next = current ->next;
        current ->pre = nullptr;
        current ->next = head;
        head = current;
        return 1;
    }
    int add_search(int key1)//搜索函数直接返回key的第一个元素
    {
        if(arr[key1].key == -1)
            return -1;
        return arr[key1].ele;
    }
};

int main()
{
    hashtable ht;
    ht.add_insert(0,1);
    ht.add_insert(1,2);
    ht.add_insert(1,3);
    ht.add_insert(1,4);
    cout << ht.add_delete(0,1);
    cout << ht.add_delete(1,2);
    cout << ht.add_delete(2,3);
    cout << ht.add_delete(3,4);
    cout << ht.add_search(1);
    return 0;
}