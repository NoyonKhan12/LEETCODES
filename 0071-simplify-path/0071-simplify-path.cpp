class Solution {
public:
    string simplifyPath(string path) 
    {
        string result, temp;
        vector<string> st;
        stringstream ss(path);
        
        while(getline(ss, temp, '/')) 
        {
            if(temp == "" or temp == ".") 
            {
                continue;
            }
            if(temp != "..") 
            {
                st.push_back(temp);
            }
            else if(!st.empty()) 
            {
                st.pop_back();
            }
        }
        
        for(auto str : st) 
        {
            result += "/" + str;
        }
        return result.empty() ? "/" : result;
    }
};