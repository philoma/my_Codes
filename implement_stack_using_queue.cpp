class MyStack {
    priority_queue<int> q1,q2;
public:
    MyStack() {
    }
    void push(int x) {
        q2.push(x); // push number to q2
        while(!q1.empty()) // flip q2 to q1
        {
            q2.push(q1.top());
            q1.pop();
        }
        swap(q1,q2); // make q1 the default storage for numbers
    }
    //link: https://leetcode.com/problems/implement-stack-using-queues/submissions/
    int pop() {
        int temp=q1.top();
        q1.pop();
        return temp;
    }
    
    int top() {
        return q1.top();
    }
    
    bool empty() {
      return q1.empty();  
    }
};