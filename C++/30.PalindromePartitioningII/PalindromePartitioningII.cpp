class Solution {
public:
    int minCut(string s) 
    {
        vector<vector<int>> dp;
        vector<int> temp;
        for(int i=0;i<s.size();i++)
        temp.push_back(0);
        
        for(int i=0;i<s.size();i++)
            dp.push_back(temp);
    
        vector<int> cut(s.size()+1,0);
        
        for(int i=s.size()-1;i>=0;i--)
        {
            cut[i]=INT_MAX;
        	for(int j=i;j<s.size();j++)
            {
                if(s.at(i)==s.at(j)&&(j-i<=1||dp[i+1][j-1]==1))
                {
                    dp[i][j]=1;
                    cut[i]=min(1+cut[j+1],cut[i]);  
                }
            }
        }
        return cut[0]-1;  
    }
};
