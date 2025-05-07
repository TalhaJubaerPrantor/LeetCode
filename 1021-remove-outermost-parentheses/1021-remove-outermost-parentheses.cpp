class Solution {
public:
    string removeOuterParentheses(string s) {

    int cnt=0;
    string s2="";
    for(int i=0;i<s.size();i++){

        if(s[i]=='('){
            if(cnt>0){
                s2=s2+s[i];
            }
            cnt++;
        }else{
            cnt--;
            if(cnt>0){
                s2=s2+s[i];
            }
        }

    }
    return s2;
}

};