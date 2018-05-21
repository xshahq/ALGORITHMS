#define N 100
int arr[N];
struct QUEUE
{
    int tail,head;
};
int ENQUEUE(QUEUE& q,int x)
{
    if((!q.head && q.tail == N -1) || q.head - 1 == q.tail)
        return -1;
    arr[q.tail] = x;
    if(q.tail == N - 1)
        q.tail = 0;
    else
        q.tail += 1;
    return q.tail;
}
int DEQUEUE(QUEUE& q)
{
    if(q.head == q.tail)
        return -1;
	int x = arr[q.head];
    if(q.head == N -1)
       q.head = 0;
	else
		q.head += 1;
    return  x;
}