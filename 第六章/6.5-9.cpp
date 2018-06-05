typedef struct node
{  
    int value;  
    node *next;  
}node,*pNode;  
  
void insert_node(node *head, node *nenode) 
{  
    node *cur=head;  
    if(head->next==NULL)
        head->next=nenode;  
	else
	{  
        while ((cur->next!=NULL)&&(cur->next->value<nenode->value))
            cur=cur->next;  
        nenode->next=cur->next;  
        cur->next=nenode;  
    }  
}  
  
pNode delete_first_node(node *head) 
{  
    pNode min_value=NULL;  
    if(head->next!=NULL)
	{  
        min_value=head->next;  
        head->next=head->next->next;         
    }  
    return min_value;
}  
  
void min_heapify(pNode *a,int i,int n)//维护最小堆  
{  
    int left=2*i+1;  
    int right=2*i+2;  
    int smallest=i;  
    if(left<n && a[smallest]->value>a[left]->value)
        smallest=left;  
    if(right<n && a[smallest]->value>a[right]->value)
        smallest=right;  
    if(smallest!=i)
	{  
        pNode tmp=a[i];  
        a[i]=a[smallest];  
        a[smallest]=tmp;  
        min_heapify(a,smallest,n);  
    }  
}  
  
void build_min_heapify(pNode *a,int n)
{  
    for(int i=(n-1)/2;i>=0;--i)
        min_heapify(a,i,n);   
}  
  
int heap_extract_min(pNode *a,int n)
{  
    int min_value=a[0]->value;  
    if(a[0]->next!=NULL)
        a[0]=a[0]->next;  
	else
        a[0]->value=numeric_limits<int>::max();  
    min_heapify(a,0,n);  
    return min_value;  
}  