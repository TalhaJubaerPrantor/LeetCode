class Solution {
public:
    
string reverseWords(string s) {

    string s2="";
    vector<string> v;

    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            s2=s2+s[i];
        }

        if(s[i]==' '&& s2!=""){
            v.push_back(s2);
            s2="";
            continue;
        }
    }

    if(s2!="")v.push_back(s2);

    string ans="";
    for(int i=v.size()-1;i>=0;i--){
        if(i!=0){
            ans+=v[i];
            ans+=" ";
        }else {
            ans+=v[i];
        }
    }

    return ans;
}
};