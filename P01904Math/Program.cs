public class Solution {
    
    public int NumberOfRounds(string loginTime, string logoutTime) {
        List<int> sf = loginTime.Split(':').Select(int.Parse).ToList();
        List<int> ef = logoutTime.Split(':').Select(int.Parse).ToList();
        int lh = sf[0], lm = sf[1];
        int oh = ef[0], om = ef[1];

        int l = lh*60+lm, r = oh*60+om;

        if(l > r) {
            r+= 24*60;
        }

        return Math.Max(0, (r/15 - (l+14)/15));
    }
}
