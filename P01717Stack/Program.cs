public class Solution {
    private string RemoveSubstring(string s, string p) {
        Stack<char> st = new();

        foreach(char c in s) {
            if(c == p[1] && st.Count != 0 && st.Peek() == p[0]) {
                st.Pop();
            } else {
                st.Push(c);
            }
        }

        List<char> ans = [];
        while(st.Count != 0) {
            ans.Add(st.Peek());
            st.Pop();
        }

        var r = ans.ToArray();
        Array.Reverse(r);
        return new string(r);
    }
    public int MaximumGain(string s, int x, int y) {
        string p1 = "ab";
        string p2 = "ba";
        if(x < y) {
            int t = x;
            x = y;
            y = t;
            string st = p1;
            p1 = p2;
            p2 = st;
        }

        var first = RemoveSubstring(s, p1);

        int ans = (s.Length - first.Length)/2 * x;

        var second = RemoveSubstring(first, p2);

        ans += (first.Length - second.Length)/2*y;

        return ans;
    }
}
