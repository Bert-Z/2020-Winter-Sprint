#include<string>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {

        int count=0,ssize=s.size();
        map<char,int> smap;
        map<char,int> tmap;
        
        cout<<s<<endl;
        cout<<t<<endl;
        
        for(int i=0;i<ssize;i++){
            if(smap.find(s[i])!=smap.end())
                smap[s[i]]++;
            else
                smap[s[i]]=1;
            
            if(tmap.find(t[i])!=tmap.end())
                tmap[t[i]]++;
            else
                tmap[t[i]]=1;
        }
        
        for(auto it=tmap.begin();it!=tmap.end();it++){
            cout<<it->first<<endl;
            if(smap.find(it->first)==smap.end()){
                count+=it->second;
            }else{
                int m=it->second-smap[it->first];
                if(m>0)
                    count+=m;
            }
            cout<<"count:"<<count<<endl;
        }
        
        return count;
    }
};