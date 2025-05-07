class Solution {
public:
    
string largestOddNumber(string num) {
    string s="";
    int flag=0;
    for(int i=num.size()-1;i>=0;i--){
        if((num[i]-'0')%2==1){
            flag=1;
        }

        if(flag==1){
            s+=num[i];
        }

    }

    reverse(s.begin(),s.end());
    return s;
}
};