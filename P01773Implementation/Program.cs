public class Solution {
    public int CountMatches(IList<IList<string>> items, string ruleKey, string ruleValue) {
        int k = 0;
        if(ruleKey == "color") k = 1;
        if(ruleKey == "name") k = 2;
        return items.Count(item => item[k] == ruleValue);
    }
}
