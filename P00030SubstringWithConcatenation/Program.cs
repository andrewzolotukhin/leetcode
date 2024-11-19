// var res = Solution.FindSubstring("barfoothefoobarman", ["foo", "bar"]);
// var res = Solution.FindSubstring("wordgoodgoodgoodbestword", ["word", "good", "best", "word"]);
// Console.WriteLine("barfoofoobarthefoobarman");
// Console.WriteLine("bar, foo, the");
// var res = Solution.FindSubstring("barfoofoobarthefoobarman", ["bar", "foo", "the"]);
// var res = Solution.FindSubstring("wordgoodgoodgoodbestgoodgoodword", ["good", "good", "word"]);
// var res = Solution.FindSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", ["fooo", "barr", "wing", "ding", "wing"]);
// var res = Solution.FindSubstring("bcabbcaabbccacacbabccacaababcbb", ["c", "b", "a", "c", "a", "a", "a", "b", "c"]);

var s = new string('a', 10000) + string.Concat(Enumerable.Repeat("bc", 15)) + new string('a', 10000);
var words = new string[] { new string('a', 30), string.Concat(Enumerable.Repeat("bc", 15)) };
var res = Solution.FindSubstring(s, words);

foreach (var r in res)
{
	Console.WriteLine(r);
}


public class Solution
{
	public static IList<int> FindSubstring(string s, string[] words)
	{
		var result = new List<int>();
		if (words.Length == 0) return result;

		var wordLength = words[0].Length;
		var matchLength = wordLength * words.Length;

		if (s.Length < matchLength) return result;

		Dictionary<string, int> knownWords = new();

		foreach (var w in words)
		{
			knownWords[w] = knownWords.ContainsKey(w) ? knownWords[w] + 1 : 1;
		}


		for (var i = 0; i < wordLength; i++)
		{
			List<(string val, int index)> list = [];

			var addedKnown = 0;
			for (var j = i; j <= s.Length - wordLength; j += wordLength)
			{
				var word = s.Substring(j, wordLength);
				var exists = knownWords.ContainsKey(word);

				list.Add((word, j));

				if (exists)
				{
					addedKnown++;
				}
				else
				{
					if (addedKnown < words.Length)
					{
						list.Clear();
						addedKnown = 0;
					}
					if ((s.Length - j - wordLength) < matchLength) break;
				}
			}

			if (list.Count < words.Length) continue;

			var dir = new Dictionary<string, int>();

			for (var current = 0; current < list.Count; current++)
			{
				dir[list[current].val] = dir.TryGetValue(list[current].val, out var val) ? val + 1 : 1;
				if (current >= words.Length - 1)
				{
					if (dir.Keys.Count == knownWords.Keys.Count)
					{
						var j = 0;
						foreach (var (k, v) in dir)
						{
							if ((!knownWords.ContainsKey(k)) || (knownWords.ContainsKey(k) && knownWords[k] != v))
							{
								break;
							}
							j++;
						}
						if (j == knownWords.Keys.Count)
						{
							result.Add(list[current - words.Length + 1].index);
						}
					}

					var cv = dir[list[current - words.Length + 1].val];

					if (cv == 1)
					{
						dir.Remove(list[current - words.Length + 1].val);
					}
					else
					{
						dir[list[current - words.Length + 1].val]--;
					}
				}

			}

		}

		return result;

	}
}