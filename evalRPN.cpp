/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * 
 * Note:
 * 
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
 * 
 * Example 1:
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * Example 2:
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 **/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(string c : tokens){
            if(c == "*"){
                int tmp1 = st.top();
                st.pop();
                int tmp2 = st.top();
                st.pop();
                int tmp = tmp2 * tmp1;
                st.push(tmp);
            }
            else if(c == "+"){
                int tmp1 = st.top();
                st.pop();
                int tmp2 = st.top();
                st.pop();
                int tmp = tmp2 + tmp1;
                st.push(tmp);
            }
            else if(c == "-"){
                int tmp1 = st.top();
                st.pop();
                int tmp2 = st.top();
                st.pop();
                int tmp = tmp2 - tmp1;
                st.push(tmp);
            }
            else if(c == "/"){
                int tmp1 = st.top();
                st.pop();
                int tmp2 = st.top();
                st.pop();
                int tmp = tmp2 / tmp1;
                st.push(tmp);
            }
            else{
                st.push(atoi(c.c_str()));
            }
                    
        }
        return st.top();
    }
};