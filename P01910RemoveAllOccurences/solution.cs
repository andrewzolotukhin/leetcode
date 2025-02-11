public class Solution {
    public string RemoveOccurrences(string s, string part) {
        int place = s.IndexOf(part);
        while(place != -1) {
            s = s.Remove(place, part.Length);
            place = s.IndexOf(part);
        }
        return s;
    }
}
