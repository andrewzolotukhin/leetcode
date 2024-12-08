var input1 = 15;

var input = input1;

var result = Solution.SolveNQueens(input);

// foreach (var item in result)
// {
// 	Console.WriteLine("Solution:");
// 	foreach (var row in item)
// 	{
// 		Console.WriteLine(row);
// 	}
// 	Console.WriteLine();
// }

Console.WriteLine(result.Count);

public class Solution
{
	public static void Permute(IList<int> items, IList<int> rest, IList<IList<string>> result, bool[] vm, bool[] hm, string[] outS)
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

			if (vm[100 + v] || hm[100 + h])
			{
				continue;
			}

			if (items.Count > 0 && Math.Abs(items[items.Count - 1] - r) <= 1)
			{
				continue;
			}


			vm[100 + v] = true;
			hm[100 + h] = true;
			items.Add(r);
			rest.RemoveAt(i);
			Permute(items, rest, result, vm, hm, outS);
			rest.Insert(i, r);
			items.RemoveAt(items.Count - 1);
			vm[100 + v] = false;
			hm[100 + h] = false;
		}
	}

	public static IList<IList<string>> SolveNQueens(int n)
	{
		IList<IList<string>> result = [];

		var queens = Enumerable.Range(0, n).ToList();

		var vm = new bool[300];
		var hm = new bool[300];

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