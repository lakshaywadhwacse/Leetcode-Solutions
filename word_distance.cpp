#include<bits/stdc++.h>
using namespace std;
int shortestworddistance(vector<string>words, string word1, string word2)
{
	int w1=-1;
	int w2=-1;
	int mindis=words.size();

	for(int i=0;i<words.size();i++)
	{
		if(words[i]==word1)
		{
			w1=i;
		}
		if(words[i]==word2)
		{
			w2=i;
		}

		if(w1!=-1 and w2!=-1)
		{
			mindis=min(mindis,abs(w2-w1));
		}

	}

	return mindis;

}

int main()
{
	vector<string>words;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string elem;
		cin>>elem;
		words.push_back(elem);
	}
	string word1,word2;

	cin>>word1>>word2;
	cout<<shortestworddistance(words,word1,word2)<<endl;
}