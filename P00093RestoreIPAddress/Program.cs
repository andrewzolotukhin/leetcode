public class Solution {
    public IList<string> RestoreIpAddresses(string s) {
        List<string> ans = new();
        int n = s.Length;
        if(n < 4) return ans;
        if(n > 12) return ans;
        for(int i = 0; i < n-3; i++) {
            if(i > 2) break;
            if(i > 0 && s[0] == '0') break;
            var p1 = s.AsSpan(0, i+1);
            if(i == 2 && int.Parse(p1) > 255) break;
            for(int j = i + 1; j < n-2; j++) {
                int l1 = j - i;
                if(l1 > 3) break;
                if(j > i+1 && s[i+1] == '0') break;
                var p2 = s.AsSpan(i+1, l1);
                if(l1 == 3 && int.Parse(p2) > 255) break;
                for(int k = j + 1; k < n-1; k++) {
                    int l2 = k - j;
                    if(k > j + 1 && s[j+1] == '0') break;
                    if(l2 > 3) break;
                    var p3 = s.AsSpan(j+1, l2);
                    if(l2 == 3 && int.Parse(p3) > 255) break;

                    var p4 = s.AsSpan(k+1);
                    if(p4.Length > 1 && p4[0] == '0') continue;
                    if(p4.Length > 3) continue;
                    if(p4.Length == 3 && int.Parse(p4) > 255) continue;
                    ans.Add($"{p1}.{p2}.{p3}.{p4}");
                }
            }
        }

        return ans;
    }
}
