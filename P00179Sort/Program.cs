public class Solution {
    public class Comparer : IComparer<string>
    {
        public int Compare(string x, string y)
        {
            var s1 = x + y;
            var s2 = y + x;

            return s2.CompareTo(s1);
        }
    }
    public string LargestNumber(int[] nums) {
        var strs = nums.Select(t => t.ToString()).OrderBy(t => t, new Comparer()).ToList();
        string ans = String.Join("", strs);
        bool allZeroes = true;
        foreach(var c in ans) {
            if(c!= '0') {
                allZeroes = false;
                break;
            }
        }
        if(allZeroes) return "0";
        return ans;
    }
}
