//https://leetcode.com/problems/integer-replacement/

int integerReplacement(int n)
{


	// Base case
	if(n==1)
	{
		return 0;
	}

	if(n==INT_MAX) return 32;

	//Rec cases
	if(n%2==0) return integerReplacement(n/2)+1;


	if(n==3|| n%4==1)
	{
		return integerReplacement(n-1)+1;
	}

	return integerReplacement(n+1)+1;


}