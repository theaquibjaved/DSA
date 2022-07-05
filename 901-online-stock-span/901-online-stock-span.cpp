class StockSpanner {
public:
    stack<pair<int,int>> s;
    int index = -1;
    
    StockSpanner() {
       // int index = -1;
    }
    
    int next(int price) {
        index +=1;
        
        while(!s.empty() && s.top().second<=price)    //Find the previous greater element
            s.pop();
        //If there is no previous greater element
        if(s.empty())
        {   s.push({index,price});      return index+1;   }
        
        int result = s.top().first;
        s.push({index,price});
        return index-result; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */