
string[] input1 = ["eat", "tea", "tan", "ate", "nat", "bat"];
string[] input2 = [""];

var input = input2;

var result = Solution.GroupAnagrams(input);

foreach (var s in result)
{
	Console.WriteLine(string.Join(", ", s));
}

public class Solution
{
	public static IList<IList<string>> GroupAnagrams(string[] strs)
	{
		IList<IList<string>> result = [];
		Dictionary<string, List<string>> map = [];
		foreach (var s in strs)
		{
			var splitted = s.ToCharArray().ToList();
			splitted.Sort();
			var key = string.Join(string.Empty, splitted);

			if (map.TryGetValue(key, out List<string>? value))
			{
				value.Add(s);
			}
			else
			{
				map[key] = [s];
			}
		}

		foreach (var k in map.Keys)
		{
			result.Add(map[k]);
		}

		return result;
	}
}