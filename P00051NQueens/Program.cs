var input1 = 9;

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
	public static void Permute(IList<int> items, IList<int> rest, IList<IList<string>> result, HashSet<int> vm, HashSet<int> hm, string[] outS)
	{
		if (rest.Count == 0)
		{
			List<string> rr = [];
			for (var i = 0; i < items.Count; i++)
			{
				// var c = new string('.', items.Count).ToCharArray();
				// c[items[i]] = 'Q';
				// rr.Add(string.Join("", c));
				rr.Add(outS[items[i]]);
			}
			result.Add(rr);
			return;
		}

		for (var i = 0; i < rest.Count; i++)
		{
			var r = rest[i];
			var v = items.Count + r;
			var h = items.Count - r;

			if (vm.Contains(v) || hm.Contains(h))
			{
				continue;
			}

			if (items.Count > 0 && Math.Abs(items[items.Count - 1] - r) <= 1)
			{
				continue;
			}


			vm.Add(v);
			hm.Add(h);
			items.Add(r);
			rest.RemoveAt(i);
			Permute(items, rest, result, vm, hm, outS);
			rest.Insert(i, r);
			items.RemoveAt(items.Count - 1);
			vm.Remove(v);
			hm.Remove(h);
		}
	}

	public static IList<IList<string>> SolveNQueens(int n)
	{
		IList<IList<string>> result = [];

		var queens = Enumerable.Range(0, n).ToList();

		var vm = new HashSet<int>();
		var hm = new HashSet<int>();

		string[] outS = [.. queens.Select((int q) =>
		{
			var a = new string('.', n).ToCharArray();
			a[q] = 'Q';
			return string.Join("", a);
		})];

		Permute([], queens, result, vm, hm, outS);

		return result;
	}
}