#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MOD 1000000007
#define pb push_back
#define pf printf
#define sf scanf
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(auto i=s; i<=e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define oo 987654321
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int n;
string beginWord,endWord,x;
map<string,int> wordList;
vector<int> dist;
vector<string> getWords(string word)
{
  vector<string> res;
  for(int i=0;i<word.length();i++)
  {
    for(int j=0;j<26;j++)
    {
      string temp=word;
      temp[i]=('a'+j);
      if((word[i]!='a'+j)&&wordList[temp])  res.pb(temp);
    }
  }
  return res;
}
int solve()
{
  cin>>beginWord>>endWord>>n;
  rep(i,1,n)
  {
    cin>>x;
    wordList[x]=i;
  }
  if(!wordList[endWord])  return 0;
  dist.assign(n+1,INT_MAX);
  queue<string> q;
  q.push(beginWord);
  dist[wordList[beginWord]]=0;
  while(!q.empty())
  {
    string word=q.front();q.pop();
    vector<string> edges=getWords(word);
    for(auto it:edges)
    {
      if(dist[wordList[it]]>dist[wordList[word]]+1)
      {
        dist[wordList[it]]=dist[wordList[word]]+1;
        q.push(it);
        if(it==endWord) return dist[wordList[it]]+1;
      }
    }
  }
}
int main()
{
	prep();
  cout<<solve()<<"\n";
	return 0;
}
