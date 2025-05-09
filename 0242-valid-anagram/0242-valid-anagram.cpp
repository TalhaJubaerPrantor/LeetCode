class Solution {
public:
  bool isAnagram(string s, string t) {

    if(s.size()!=t.size()) return false;

    map<char,int>a,b;
    for(int i=0;i<s.size();i++){

        if(a.find(s[i])==a.end()){
            a.insert({s[i],1});
        }else{
            a[s[i]]++;
        }

        if(b.find(t[i])==b.end()){
            b.insert({t[i],1});
        }else{
            b[t[i]]++;
        }

    }



    if(a==b) return true;
    return false;

}
};