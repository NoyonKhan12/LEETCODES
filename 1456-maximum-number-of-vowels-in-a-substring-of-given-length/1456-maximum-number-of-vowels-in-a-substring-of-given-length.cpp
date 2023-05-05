class Solution {
public: 
    int maxVowels(string s, int k) 
    {
        int count = 0;
        int ans = 0;
        int n = s.size();
        
        bool vowels[26] = {false};
        vowels[0] = vowels[4] = vowels[8] = vowels[14] = vowels[20] = true;

        for(int i=0; i<n; i++) 
        {           
            if(i >= k && vowels[s[i-k]-'a']) 
            {
                count--;
            }

            if(vowels[s[i]-'a'])
            {
                count++;
            }
            ans = max(ans, count);
        }
        return ans ;
    }
};