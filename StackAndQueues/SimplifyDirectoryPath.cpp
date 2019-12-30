/*Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.



Input Format

The only argument given is string A.
Output Format

Return a string denoting the simplified absolue path for a file (Unix-style).
For Example

Input 1:
    A = "/home/"
Output 1:
    "/home"

Input 2:
    A = "/a/./b/../../c/"
Output 2:
    "/c"*/

string Solution::simplifyPath(string A) 
{
    stack<string> st;
    int n = A.size();
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == '/')
            continue;
        if(A[i] == '.')
        {
            if(i+1 < n && A[i+1] == '.')
            {
                if(!st.empty())
                    st.pop();
                i++;
            }
        }
        else
        {
            string tem="";
            while(i < n && A[i] != '/')
            {
                tem += A[i];
                i++;
            }
            st.push(tem);
        }
    }
    string ans = "";
    while(!st.empty())
    {
        ans = "/"+st.top()+ans;
        st.pop();
    }
    
    if(ans.size() == 0)
        return "/";
    else
        return ans;
 
    
}