#include<iostream>
#include<queue>
using namespace std;

class Queue
{
	int *arr;
	int f,cs,ms,r;
public:

	Queue(int n)
	{
		arr= new int[n];
		cs=0;
		ms=n;
		r=0;
		f=0;
	}

	void push(int data)
	{
		if(cs==ms) return;
		arr[r]=data;
		r=(r+1)%ms;
		cs++;
	}

	int pop()
	{
		if(cs==0) return 0;
		f=(f+1)%ms;
		cs--;
	}

	int front()
	{
		return arr[f];
	}

	bool full()
	{
		return cs==ms;
	}
	int size()
	{
		return cs;
	}
};
void  CircularQueue()
{
	int k;cin>>k;
	Queue q(k);
	int n;
	cin>>n;
	int sum=0;
	while(n!=-1)
	{
		sum+=n;
		if(q.full())
		{
			sum-=q.front();
			q.pop();
		}
		q.push(n);
		cout<<(double)(sum)/q.size()<<" ";
		cin>>n;

	}

	cout<<endl;

}
void Average()
{
	int k;cin>>k;
	queue<int>q;
	int n;
	cin>>n;
	int sum=0;
	while(n!=-1)
	{
		sum+=n;
		q.push(n);
		if(q.size()>k)
		{
			sum-=q.front();
			q.pop();
		}
		cout<<(double)(sum)/q.size()<<" ";
		cin>>n;

	}

	cout<<endl;
}

int main()
{
	//CircularQueue();
	Average();
	return 0;

}