// var res = Solution.FindSubstring("barfoothefoobarman", ["foo", "bar"]);
// var res = Solution.FindSubstring("wordgoodgoodgoodbestword", ["word", "good", "best", "word"]);
// Console.WriteLine("barfoofoobarthefoobarman");
// Console.WriteLine("bar, foo, the");
// var res = Solution.FindSubstring("barfoofoobarthefoobarman", ["bar", "foo", "the"]);
// var res = Solution.FindSubstring("wordgoodgoodgoodbestgoodgoodword", ["good", "good", "word"]);

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

		SortedList<(string, int), string> sortedWords = new();
		Dictionary<string, bool> knownWords = new();

		int l = 0;
		foreach (var w in words)
		{
			sortedWords.TryAdd((w, l++), w);
			knownWords[w] = true;
		}


		for (var i = 0; i < wordLength; i++)
		{
			List<string> list = [];
			for (var j = i; j <= s.Length - wordLength; j += wordLength)
			{
				var word = s.Substring(j, wordLength);
				if (!knownWords.ContainsKey(word) && (s.Length - j - wordLength) < matchLength)
				{
					break;
				}
				list.Add(word);
			}

			if (list.Count < words.Length) continue;


			var sl = new SortedList<(string, int), string>();

			int right = 0;

			while (right < list.Count)
			{
				if (sl.Count < words.Length)
				{
					if (knownWords.ContainsKey(list[right]))
					{
						sl.Add((list[right], right), list[right]);
					}
					else
					{
						sl.Clear();
					}
				}

				right++;

				if (sl.Count == words.Length)
				{
					var k = 0;
					foreach ((_, var value) in sl)
					{
						if (value != sortedWords.GetValueAtIndex(k))
						{
							break;
						}
						k++;
					}

					if (k == words.Length)
					{
						result.Add(i + ((right - words.Length) * wordLength));
					}

					sl.Remove((list[right - words.Length], right - words.Length));
				}
			}

		}

		return result;

	}
}