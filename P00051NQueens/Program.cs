var input1 = 10;

var input = input1;

var result = Solution.SolveNQueens(input);

foreach (var item in result)
{
	Console.WriteLine("Solution:");
	foreach (var row in item)
	{
		Console.WriteLine(row);
	}
	Console.WriteLine();
}

Console.WriteLine(result.Count);

public class Solution
{
	public static void Permute(IList<int> items, IList<int> rest, IList<IList<int>> result)
	{
		if (rest.Count == 0)
		{
			result.Add([.. items]);
			return;
		}

		for (var i = 0; i < rest.Count; i++)
		{
			var r = rest[i];
			var x = items.Count + r;
			var y = items.Count - r;

			if (items.Count > 0 && Math.Abs(items[items.Count - 1] - r) <= 1)
			{
				continue;
			}

			if (items.Select((v, i) => (i + v, i - v, v)).Any(t => t.Item1 == x || t.Item2 == y))
			{
				continue;
			}

			items.Add(r);
			rest.RemoveAt(i);
			Permute(items, rest, result);
			rest.Insert(i, r);
			items.RemoveAt(items.Count - 1);
		}
	}

	public static IList<IList<string>> SolveNQueens(int n)
	{
		IList<IList<string>> result = [];

		IList<IList<int>> notFormatedResult = [];

		var queens = Enumerable.Range(0, n).ToList();

		Permute([], queens, notFormatedResult);

		foreach (var r in notFormatedResult)
		{
			var k = r.ToList();

			List<string> rr = [];

			for (var i = 0; i < k.Count; i++)
			{
				var c = new string('.', n).ToCharArray();
				c[k[i]] = 'Q';
				rr.Add(string.Join("", c));
			}

			result.Add(rr);
		}

		return result;
	}
}