int next(vector<int>a, int i)
{
	return (i+a[i]+a.size())%a.size();
}

bool circularArrayLoop(vector<int> & v)
{
	int n=v.size();
	for(int i=0;i<n;i++)
	{
		int slow=i, fast=i;
		if(v[i]==0)
		{
			continue;
		}

		while( v[slow] * v[next(v,slow)]>0 && 
			v[fast]*v[next(v,fast)] && 
			v[fast]*v[next(v,next(v,fast))]>0){
			slow= next(v,slow);
			fast=next(v,next(v,fast));


			if(slow==fast)
			{
				// That means cycle is present , but cycle length should be>1

				if(slow==next(v,slow))
				{
					break;
				}
				return true;
			}
		}

			slow=i;
			int val=v[slow];
			while(val*v[slow]>0)
			{
				int x=slow;
				slow=next(v,slow);
				v[x]=0;
			}
		}

		return false;

	}