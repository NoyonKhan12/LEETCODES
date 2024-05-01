class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        string s,st;
        
        for(int i=0; i<word.size(); i++)
        {
            if(word[i] != ch)
            {
                s = s + word[i];
            }
            else
            {
                s = s + word[i];
                reverse(s.begin(), s.end());
                st = s + word.substr(i+1, word.size());
                break;
            }
        }
        return st.size() > 0 ? st : word;
    }
};