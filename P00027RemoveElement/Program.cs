int[] a = [1, 1, 2];
var result = Solution.RemoveElement(a, 1);
Console.WriteLine(result);
Console.WriteLine(string.Join(",", a));
Console.WriteLine("======================");
a = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
result = Solution.RemoveElement(a, 1);
Console.WriteLine(result);
Console.WriteLine(string.Join(",", a));
Console.WriteLine("======================");
a = [0, 0, 0, 0, 0, 1, 1, 1, 1, 1];
result = Solution.RemoveElement(a, 0);
Console.WriteLine(result);
Console.WriteLine(string.Join(",", a));
Console.WriteLine("======================");
a = [0, 0, 0, 0, 0];
result = Solution.RemoveElement(a, 0);
Console.WriteLine(result);
Console.WriteLine(string.Join(",", a));

public class Solution
{
	public static int RemoveElement(int[] nums, int val)
	{
		var valid = 0;

		if (nums.Length == 0) return valid;

		for (var i = 0; i < nums.Length; i++)
		{
			if (nums[i] == val) continue;

			nums[valid] = nums[i];
			valid++;
		}

		return valid;
	}
}