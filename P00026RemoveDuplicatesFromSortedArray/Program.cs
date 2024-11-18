int[] a = [1, 1, 2];
var result = Solution.RemoveDuplicates(a);
Console.WriteLine(result);
Console.WriteLine(string.Join(",", a));
Console.WriteLine("======================");
a = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
result = Solution.RemoveDuplicates(a);
Console.WriteLine(result);
Console.WriteLine(string.Join(",", a));
Console.WriteLine("======================");
a = [0, 0, 0, 0, 0, 1, 1, 1, 1, 1];
result = Solution.RemoveDuplicates(a);
Console.WriteLine(result);
Console.WriteLine(string.Join(",", a));
Console.WriteLine("======================");
a = [0, 0, 0, 0, 0];
result = Solution.RemoveDuplicates(a);
Console.WriteLine(result);
Console.WriteLine(string.Join(",", a));

public class Solution
{
	public static int RemoveDuplicates(int[] nums)
	{
		var i = 0;

		if (nums.Length == 0) return 0;

		var rangeStart = 0;
		var uniq = 0;

		while (++i < nums.Length)
		{
			if (nums[i - 1] == nums[nums.Length - 1])
			{
				nums[uniq] = nums[rangeStart];
				uniq++;
				return uniq;
			}

			if (nums[rangeStart] != nums[i])
			{
				nums[uniq] = nums[rangeStart];
				uniq++;
				rangeStart = i;
			}

		}

		nums[uniq] = nums[nums.Length - 1];
		uniq++;

		return uniq;
	}
}