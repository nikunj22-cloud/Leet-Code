class MedianFinder {
public:
   priority_queue<int>left_max_heap;
   priority_queue<int , vector<int> , greater<int>>right_min_heap;
    MedianFinder() {
          //khali chor
    }
    
    void addNum(int num) {
        //do condition check krlo 
        //theek h number dalne ko bol rha h  dalde normal no ko check krke daldo
        //agr aane wala no chota h left max heap k top element se to direct dal do left max heap m
        if(left_max_heap.empty() || num < left_max_heap.top()){
            left_max_heap.push(num);
        }
        else{
            right_min_heap.push(num);
        }
        //theek h number toh dal diya ab yeh dekhna h ki no ko shi jgh toh dala h mtlb left max heap or right min heap k size m diff ya toh 0  ho ya fir 1 ho 

        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        else if(left_max_heap.size() < right_min_heap.size()){
                left_max_heap.push(right_min_heap.top());
                right_min_heap.pop();
        }

    }
    
    double findMedian() {
        double median;
        if(left_max_heap.size() == right_min_heap.size()){
           return ((double)left_max_heap.top() + right_min_heap.top())/2;
        }
        else{
            return left_max_heap.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */