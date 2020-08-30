class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {


    	// 1. step is to make a graph 
    	unordered_set<string> wlst(wordList.begin(),wordList.end());
    	map<string,list<string>>m;
    	queue<string>q;
    	q.push_back(beginWord);
    	int ladder=1;

    	while(!q.empty())
    	{
    		int n=q.size();
    		for(int i=0;i<n;i++)
    		{
    			string word= q.front();
    			q.pop();
    			if(word==endword)
    			{
    				return ladder;
    			}
    			wlst.erase(word);
				for(int i=0;i<word.size();i++)
				{
					char c= word[i];

					for(int j=0;j<26;j++)
					{
						word[j]='a'+j;
						if(wlst.find(word)!=wlst.end())
						{
							q.push(word);
						}
					}
					word[j]=c;
			    }

			}
			ladder++;

    	}
    	
    	return 0;



    	// 2. to find that endword is present in the graph if yes that what is the distance of it from src vertex
        
        
        
    }
};