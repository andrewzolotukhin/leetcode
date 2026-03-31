class Solution {
public:
    bool canBeEqual(string s1, string s2){
        string ss1 = string(1,s1[0]);
        ss1+=s1[2];
        string ss2 = string(1,s1[1]);
        ss2+=s1[3];
        string ss3 = string(1,s2[0]);
        ss3+=s2[2];
        string ss4 = string(1,s2[1]);
        ss4+=s2[3];
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        sort(ss3.begin(), ss3.end());
        sort(ss4.begin(), ss4.end());
        return ss1==ss3 && ss2==ss4;
    }
};