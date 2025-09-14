class StockSpanner {
public:
    stack<pair<int,int>> stk;
    int idx=-1;
    StockSpanner() {
        int idx=-1;
    }

    int next(int price) {
        idx++;

        if(stk.empty()){
            stk.push({price,idx});
            
        }else{
            if(price<stk.top().first){
                stk.push({price,idx});
                return 1;
            }else{
                while(!stk.empty() && price>=stk.top().first){
                    stk.pop();
                }
                if(stk.empty()){
                    stk.push({price,idx});
                    
                    return stk.top().second+1;
                }
                int temp=stk.top().second;
                
                stk.push({price,idx});
                return idx-temp;
            }
        }
        return 1;
    }
};