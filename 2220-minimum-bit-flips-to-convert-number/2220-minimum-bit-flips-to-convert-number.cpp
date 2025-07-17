class Solution {
public:
    string decTOBin(int n) {
        if(n==0)return "0";
        string result = "";
        while (n > 1) {
            if (n % 2 == 1)
                result += '1';
            else
                result += '0';
            n /= 2;
        }
        result += '1';
        reverse(result.begin(), result.end());
        return result;
    }

    int minBitFlips(int start, int goal) {
        int temp = start ^ goal;
        int cnt = 0;
        string s = decTOBin(temp);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                cnt++;
        }
        return cnt;
    }
};