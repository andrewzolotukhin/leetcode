int[] a = [1, 1, 2];
var result = Solution.RemoveDuplicates(a);
Console.WriteLine(result);
Console.WriteLine(string.Join(",", a));
Console.WriteLine("======================");
a = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
result = Solution.RemoveDuplicates(a);
Console.WriteLine(result);
Console.WriteLine(string.Join(",", a));

public class Solution
{
	public static int RemoveDuplicates(int[] nums)
	{
		var i = 0;
		var ranges = new List<(int, int)>();

		if (nums.Length == 0) return 0;

		var rangeStart = 0;

		while (++i < nums.Length)
		{
			if (nums[rangeStart] != nums[i])
			{
				ranges.Add((rangeStart, i - 1));
				rangeStart = i;
			}

		}

		ranges.Add((rangeStart, nums.Length - 1));

		i = 0;
		foreach (var (k, _) in ranges)
		{
			nums[i++] = nums[k];
		}

		return ranges.Count;
	}
}