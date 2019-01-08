/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 **/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        data.push(x);
        if(min_data.empty() || x <= min_data.top()) min_data.push(x);   
    }
    
    void pop() {
        int tmp = data.top();
        data.pop();
        if (tmp == min_data.top()){
            min_data.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_data.top();
    }
private:
    stack<int> min_data;
    stack<int> data;
};