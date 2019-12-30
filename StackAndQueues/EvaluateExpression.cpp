/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.



Input Format

The only argument given is character array A.
Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.
For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9
    
Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6*/

#include<string>
int Solution::evalRPN(vector<string> &A) 
{
    int res = 0;
    stack<int> st;
    int n = A.size();
    
    for(int i = 0; i < n; i++)
    {
        string temp = A[i];
        if(temp == "+" || temp == "-" || temp == "*" || temp == "/")
        {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            
            if(temp == "+")
                st.push(x+y);
            else if(temp == "-")
                st.push(y-x);
            else if(temp == "*")
                st.push(y*x);
            else if(temp == "/")
                st.push(y/x);
        }
        else
        {
            int tappu = atoi(A[i].c_str());
            st.push(tappu);
        }
        
    }
    res = st.top();
    
    return res;
    
}
