/*pat top level 1004 复杂搜索（带剪枝），要靠模糊剪枝来度日了。。。，中间的两百是假设两百的时候能得到最优解。。*/
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

unordered_map<char,int> mp;
vector<vector<int>> strings;
int Remain = 0x3f3f3f3f;
int Extra = 0x3f3f3f3f;

void dfs(int index, vector<int> need,int extra,int &loop)
{
    if(extra>=Extra|| loop > 200)
        return;
    int use = 0;
    loop++;
    for(int i = 0 ; i < need.size() - 1; i++)
    {
        if(strings[index][i]>need[i])
        {
            use+=need[i];
            need[i] = 0;
        }
        else
        {
            use+=strings[index][i];
            need[i] -= strings[index][i];
        }
    }
    extra +=strings[index].back() - use;
    need.back() -=use;
    if(need.back() == 0)
    {
        Extra = min(Extra,extra);
        Remain = 0;
        return;
    }
    if(index == strings.size() - 1)
    {
        Remain = min(Remain,need.back());
        return;
    }
    for(int i = index+1; i < strings.size(); i++)
    {
        dfs(i,need,extra,loop);
    }
}
int main()
{
    string s;
    int n;
    vector<int> need;
    cin>>s>>n;
    for(char c:s)
    {
        if(mp.find(c) == mp.end())
        {
            mp.insert({c,mp.size()});
            need.push_back(0);
        }
        need[mp[c]]++;
    }
    need.push_back(s.size());
    for(int i = 0; i < n; i++)
    {
        cin>>s;
        vector<int> v(need.size(),0);
        for(char c:s)
        {
            if(mp.find(c)!=mp.end())
            {
                v[mp[c]]++;
            }
        }
        v.push_back(s.size());
        strings.push_back(v);
    }
    int loop = 0;
    for(int i = 0;i < strings.size(); i++)
    {
        dfs(i,need,0,loop);
    }
    sort(strings.begin(),strings.end(),[](const vector<int>&a,const vector<int>&b){
         return a.back()<b.back();
         });
    if(Remain == 0)
        cout<<"Yes"<<" "<<Extra<<endl;
    else cout<<"No"<<" "<<Remain<<endl;
    return 0;
}
