class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> str;
        for(int i=1; i<=n; i++)
        {
            if(i%3==0 && i%5!=0)
            {
                str.push_back("Fizz");
            }
            else if(i%3!=0 && i%5==0)
            {
                str.push_back("Buzz");
            }
            else if(i%3==0 && i%5==0)
            {
                str.push_back("FizzBuzz"); 
            }
            else
            {
                string x = to_string(i);
                str.push_back(x);
            }
        }
        return str;      
    }
};