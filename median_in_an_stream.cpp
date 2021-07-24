priority_queue <double,vector<double>,greater<double>> minpq;
    priority_queue<double> maxpq;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxpq.size()==0){
            maxpq.push(x);
        }
        else if(maxpq.top()<x){
            minpq.push(x);
        }
        else{
            maxpq.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        while(abs(minpq.size()-maxpq.size())>1){
            if(minpq.size()>maxpq.size()){
                double num = minpq.top();
                minpq.pop();
                maxpq.push(num);
            }
            else{
                double num = maxpq.top();
                maxpq.pop();
                minpq.push(num);
            }
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(minpq.size()>maxpq.size()){
            return (double)minpq.top();
        }
        else if(minpq.size()<maxpq.size()){
            return (double)maxpq.top();
        }
        else{
            return ((double)maxpq.top()+ (double)minpq.top())/2;
        }
        
    }