class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0, n=moves.size(),c=0;
        for(int i = 0;i<n;i++)if(moves[i]=='R'){c--;}else{c++;}
    ans=max(ans,abs(c));
    c=0;
    for(int i=0;i<n;i++)if(moves[i]=='L'){c--;}else{c++;}
    return max(ans, abs(c));
    }
};