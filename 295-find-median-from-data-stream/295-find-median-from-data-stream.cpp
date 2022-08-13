class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top() > num)
            maxheap.push(num);
        else
            minheap.push(num);
        
        //adjusting the size difference
        if(maxheap.size() > minheap.size() + 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size() + 1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        int maxSize = maxheap.size();
        int minSize = minheap.size();
        
        if(maxSize > minSize)
            return double(maxheap.top());
        else if(maxSize < minSize)
            return double(minheap.top());
        else
            return (double(minheap.top()) + double(maxheap.top())) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */