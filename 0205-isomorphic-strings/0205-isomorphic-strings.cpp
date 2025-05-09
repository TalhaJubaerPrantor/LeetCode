class Solution {
public:
    
bool isIsomorphic(string s, string t) {

    set<char>a,b;

    for(int i=0;i<s.size();i++){
        a.insert(s[i]);
        b.insert(t[i]);
    }

    if(a.size()!=b.size()) return false;

    map<char,char> m;

    for(int i=0;i<s.size();i++){
        m.insert({s[i],t[i]});

    }

    string x="";

    for(int i=0;i<s.size();i++){
        x+=m[s[i]];
    }

    if(t==x) return true;
    return false;
}

};