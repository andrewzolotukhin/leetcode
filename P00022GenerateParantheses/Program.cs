
using System.Diagnostics;

for (var i = 1; i < 20; i++)
{
	var sw = new Stopwatch();
	sw.Start();
	var result = Solution.GenerateParenthesis(i);
	sw.Stop();
	Console.WriteLine($"{i} ⸺ {result.Count} ⸺ {sw.Elapsed.TotalSeconds:F2}");
}

public class Solution
{

	public static Dictionary<(int n, int open, int close), IList<string>> memo = [];

	public static IList<string> Work(int n, int open, int close)
	{
		var key = (n, open, close);
		memo.TryGetValue(key, out var result);

		if (result != null)
		{
			return result;
		}

		result = [];

		if (n - open == 0)
		{
			result.Add(new string(Enumerable.Range(0, open - close).Select(_ => ')').ToArray()));
			memo[key] = result;
			return result;
		}

		if (open < n)
		{
			foreach (var r in Work(n, open + 1, close))
			{
				result.Add($"({r}");
			}
		}

		if (close < n && open > 0 && close < open)
		{
			foreach (var r in Work(n, open, close + 1))
			{
				result.Add($"){r}");
			}
		}
		memo[key] = result;
		return result;
	}

	public static IList<string> GenerateParenthesis(int n)
	{
		return Work(n, 0, 0);
	}
}