/*Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more
details about roman numerals at Roman Numeric System

Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20*/



int priority(char c)
{
    int pr;
    if(c == 'I')
        pr = 1;
    else if(c == 'V')
         pr =  5;
    else if(c == 'X')
         pr =  10;
    else if(c == 'L')
         pr =  50;
    else if(c == 'C')
         pr =  100;
    else if(c == 'D')
        pr = 500;
    else if(c == 'M')
        pr =  1000;
        
    return pr;
}
int Solution::romanToInt(string s) 
{
    stack<int> st;
    int n = s.length();
    int x = priority(s[0]);

    st.push(x);
    for(int i = 1 ; i < n ; i++)
    {
        if(priority(s[i]) < priority(s[i-1]))
            st.push(priority(s[i]));
        else if (priority(s[i]) == priority(s[i-1]))
        {
            int y = st.top();
            st.pop();
            int z = priority(s[i]) + y;
            st.push(z);
        }
        else
        {
            int y = st.top();
            st.pop();
            int z = priority(s[i]) - y;
            st.push(z);
        }

    }
    int result = 0;

    while(!st.empty())
    {
        int w = st.top();
        result += w;
        st.pop();
    }

    //cout<<result<<endl;
    return result;
        
}
