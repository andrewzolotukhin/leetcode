public class Solution {
    private Dictionary<string, bool> dict = new();
    public bool CanTransform(string start, string result, string prev = null) {
      // TLE:
      /*  if(start == result) return true;

        if(dict.ContainsKey(start)) return dict[start];

        int s = 0;
        int found;

        while((found = start.IndexOf("XL", s)) != -1) {
            string newStr = start.Substring(0,found) + "LX" + start.Substring(found+2);
            s = found + 2;
            if(newStr == prev) continue;
            dict[start] = CanTransform(newStr, result, start);
            if(dict[start]) return true;
        }

        found = -1;
        s = 0;
        while((found = start.IndexOf("RX", s)) != -1) {
            string newStr = start.Substring(0,found) + "XR" + start.Substring(found+2);
            s = found + 2;
            if(newStr == prev) continue;
            dict[start] = CanTransform(newStr, result, start);
            if(dict[start]) return true;
        }


        return dict[start] = false;*/

        if (start.Replace("X", "") != result.Replace("X", "")) return false;
        int i = 0, j = 0, n = start.Length;
        while (i < n && j < n) {
            while (i < n && start[i] == 'X') i++;
            while (j < n && result[j] == 'X') j++;
            if (i == n || j == n) break;

            if (start[i] != result[j]) return false;
            if (start[i] == 'L' && i < j) return false; 
            if (start[i] == 'R' && i > j) return false;
            i++;
            j++;
        }

        return true;

    }
}
