
int distributeCandies(vector<int> & candies)
{

	 unordered_map<int,int>m;
	int count=0;
	for(int i=0;i<candies.size();i++)
	{
		if(m.find(candies[i])==m.end())
		{
			m.insert({candies[i],1});
			count++;
		}
		else
			m[candies[i]]++;
	}

	int ans= (count < candies.size()/2) ? count : candies.size()/2;
    return ans;
        
        
       

}

  // map<int,bool> m;
  //       for(int i=0;i<candies.size();i++)
  //       {
  //           m[candies[i]]=true;
  //       }
        
  //       return min(m.size(),candies.size()/2);