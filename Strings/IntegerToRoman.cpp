/*Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 


Input Format

The only argument given is integer A.
Output Format

Return a string denoting roman numeral version of A.
Constraints

1 <= A <= 3999
For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"*/

vector<string> getBase(int num)
{
    vector<string> res;
    
    if(num >= 1 && num < 4)
    {
        res.push_back(to_string(1));
        res.push_back("I");
    }
    else if(num >= 4 && num < 5)
    {
        res.push_back(to_string(4));
        res.push_back("IV");
    }
    else if(num >= 5 && num < 9)
    {
        res.push_back(to_string(5));
        res.push_back("V");
    }
    else if(num >= 9 && num < 10)
    {
        res.push_back(to_string(9));
        res.push_back("IX");
    }
    else if(num >= 10 && num < 40)
    {
        res.push_back(to_string(10));
        res.push_back("X");
    }
    else if(num >= 40 && num < 50)
    {
        res.push_back(to_string(40));
        res.push_back("XL");
    }
    else if(num >= 50 && num < 90)
    {
        res.push_back(to_string(50));
        res.push_back("L");
    }
    else if(num >= 90 && num < 100)
    {
        res.push_back(to_string(90));
        res.push_back("XC");
    }
    else if(num >= 100 && num < 400)
    {
        res.push_back(to_string(100));
        res.push_back("C");
    }
    else if(num >= 400 && num < 500)
    {
        res.push_back(to_string(400));
        res.push_back("CD");
    }
    else if(num >= 500 && num < 900)
    {
        res.push_back(to_string(500));
        res.push_back("D");
    }
    else if(num >= 900 && num < 1000)
    {
        res.push_back(to_string(900));
        res.push_back("CM");
    }
    else
    {
        res.push_back(to_string(1000));
        res.push_back("M");
    }
    
    return res;
}

string Solution::intToRoman(int A)
{
    string res = "";
    
    while(A > 0)
    {
        vector<string> temp = getBase(A);
        
        int base = stoi(temp[0]);
        int qnt  = A/base;
        int rem  = A - qnt*A;
        while(qnt--)
            res += temp[1];
        
        A = rem;
        
    }
    //reverse(res.begin(),res.end());
    return res;
}
