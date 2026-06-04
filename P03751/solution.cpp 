class Solution {
public:
    int totalWaviness(int num1, int num2) 
    {
        int cnt = 0;
        for(int i=num1;i<=num2;i++)
        {
            int n = i;
            vector<int>t;
            while(n>0)
            {
                t.push_back(n%10);
                n=n/10;
            }
            for(int j=1;j<t.size()-1;j++)
            {
                if(t[j]>t[j-1] && t[j]>t[j+1]) cnt++;
                else if(t[j]<t[j-1] && t[j]<t[j+1]) cnt++;
            }
        }
        return cnt;
    }
//please upvote...
};