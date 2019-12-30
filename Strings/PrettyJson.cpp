/*Given a string A representating json object. Return an array of string denoting json object with proper indentaion.

Rules for proper indentaion:

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Note:

[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.



Input Format

The only argument given is the integer array A.
Output Format

Return a list of strings, where each entry corresponds to a single line. The strings should not have "\n" character in them.
For Example

Input 1:
    A = "{A:"B",C:{D:"E",F:{G:"H",I:"J"}}}"
Output 1:
    { 
        A:"B",
        C: 
        { 
            D:"E",
            F: 
            { 
                G:"H",
                I:"J"
            } 
        } 
    }

Input 2:
    A = ["foo", {"bar":["baz",null,1.0,2]}]
Output 2:
   [
        "foo", 
        {
            "bar":
            [
                "baz", 
                null, 
                1.0, 
                2
            ]
        }
    ]*/


vector<string> Solution::prettyJSON(string A) 
{
    int n = A.size(),i,j;
    vector< string >ans;
    int tbctr = 0;
    i = 0;
    bool flag = false;
    while(i < n)
    {
        string row = "";
        for(j = 0; j < tbctr;j++)
            row += '\t';
            flag = false;
        for(j = i; j < n;j++)
        {
            if(A[j] == '[' || A[j] == '{')
            {
                if(flag)
                    ans.push_back(row);
                row = "";
                for(int k=0;k<tbctr;k++)
                    row += '\t';
                row += A[j];
                ans.push_back(row);
                i = j+1;
                tbctr++;
                
                break;
            }
            if(A[j] == ']' || A[j] == '}')
            {
                tbctr--;
                if(flag)
                    ans.push_back(row);
                row = "";
                for(int k=0;k<tbctr;k++)
                    row += '\t';
                row += A[j];
                if(j + 1 < n && A[j+1] == ',')
                    row += A[++j];
                ans.push_back(row);
                i = j+1;
                break;
            }
            row += A[j];
            flag = true;
            i = j+1;
            if(A[j] == ',')
            {
                if(flag)
                    ans.push_back(row);
                i = j+1;
                break;
            }
        }
     
    }
    return ans;
    
}
