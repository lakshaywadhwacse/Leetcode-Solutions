int longestArithmeticSeqLength(vector<int>&A)
{
	int n=A.size();
	if(n==1) return 1;
	map<int,list<int>>m;
	for(int i=0;i<n;i++)
	{
		m[A[i]].push_back(i);
	}
	int len=2;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int d=A[j]-A[i];
			int num=A[j]+d;
			int count=2;
			int pos=j;
			while(m.find(num)!=m.end())
			{
				bool flag=false;

				for(auto node: m[num])
				{
					if(node>pos)
					{
						count++;
						num+=d;
						pos=node;
						flag=true;
						break;
					}
				}
				if(!flag)break;
			}

			len=max(len,count);

		}
	}

	return len;
}