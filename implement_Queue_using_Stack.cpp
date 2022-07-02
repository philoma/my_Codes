class MyQueue {
public:
    int size;
    stack<int>s1;
        stack<int>s2;
    MyQueue() {
        
     
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
   
        
    }
    
    int pop() {
        int ans=s1.top();
        s1.pop();
        
        return ans;
        
    }
    
    int peek() {
        return s1.top();
        
        
    }
    
    bool empty() {
        return s1.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/*Adding back the elements of s2 into s1*/
        /*Ex. s1={1,2,3,4}
        Then after performing step1 - s2={4,3,2,1}
        Adding x into s2
        Now s2={5,1,2,3,4}
        Now performing step3, s1={4,3,2,1,5}
        s1 will represent the required queue*/