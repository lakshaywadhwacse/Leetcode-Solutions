


int equalize(int i, int j, string &s1, strint &s2)
{

	if(i== s1.length()) return s2.length()-1;
	else if(j== s2.length()) return s1.length()-i;


	// recursive case
	// insert
	int op1= 1+ equalize(i,j+1,s1,s2);


	// delete
	int op2= 1+ equalize(i+1,j,s1,s2);

	//replace;
	int op3;
	if(s1[i]==s2[i])
	{
		op3= equalize(i+1,j+1,s1,s2);
	}
	else op3= 1+ equalize(i+1,j+1,s1,s2);
	

	return min(op1,min(op2,op3));

}
int top_down(int i, int j, string &s1, string &s2,int **dp)
{
	if(dp[i][j]==-1)
	{

	if(i== s1.length())
	{
		dp[i][j]=s2.length()-1;
		return dp[i][j];

	} 
	else if(j== s2.length())
		{
			dp[i][j]=s1.length()-i;
			return dp[i][j];
		}


	// recursive case
	// insert
	int op1= 1+ top_down(i,j+1,s1,s2,dp);


	// delete
	int op2= 1+ top_down(i+1,j,s1,s2,dp);

	//replace;
	int op3;
	if(s1[i]==s2[i])
	{
		op3= equalize(i+1,j+1,s1,s2,dp);
	}
	else op3= 1+ equalize(i+1,j+1,s1,s2,dp);
	dp[i][j]=min(op1,min(op2,op3));
	return min(op1,min(op2,op3));

	}
	else
	{
		return dp[i][j];
	}
}

int bottom_up(int i, int j, string &s1, string &s2)
{
	int m=s1.length();
	int n= s2.length();
	int **dp = new int*[m+1];

	for(int i=0;i<=m;i++) dp[i]= new int[n+1];

	int len2= n;
	
	for(int j=0;j<=n;j++)
	{
		dp[m][j]= len2;
		len2--;
	}

	int len1= m;
	for(int i=0;i<=m;i++)
	{
		dp[i][n]= len1;
		len1--;
	}

	for(int i=m-1;i>=0;i--)
	{
		for(int i=n-1;j>=0;j--)
		{
			if(s1[i]==s2[j])
			{
				dp[i][j]= min(1+dp[i+1][j],min(1+dp[i][j+1],dp[i+1][j+1]));

			}
			else dp[i][j]=min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]))+1:

		}
	}

	return dp[0][0];
}