Console.WriteLine(Solution.ThreeSumClosest([-1, 2, 1, -4], 1));
Console.WriteLine(Solution.ThreeSumClosest([0, 0, 0], 1));
Console.WriteLine(Solution.ThreeSumClosest([100, 200, 300, -320, 1], 0));
Console.WriteLine(Solution.ThreeSumClosest([4, 0, 5, -5, 3, 3, 0, -4, -5], -2));

var random = new Random();
Console.WriteLine(Solution.ThreeSumClosest(Enumerable.Range(0, 499).Select(t => random.Next(-1000, 1000)).ToArray(), random.Next(-10000, 10000)));

public class Solution
{
	public static int ThreeSumClosest(int[] nums, int target)
	{
		var sorted = nums.ToList();
		sorted.Sort();

		// Console.WriteLine(string.Join(", ", sorted));

		var minDiff = int.MaxValue;
		var resultSum = sorted[0] + sorted[1] + sorted[2];

		for (var i = 0; i < sorted.Count - 2; i++)
		{
			// if (i > 0 && sorted[i - 1] == sorted[i]) continue;
			int j = i + 1, k = sorted.Count - 1;

			while (j < k)
			{
				var sum = sorted[i] + sorted[j] + sorted[k];
				// Console.WriteLine($"trying ({i} {j} {k}) = {sorted[i]} + {sorted[j]} + {sorted[k]} = {sum}");
				var diff = sum - target;
				if (diff == 0) return target;
				var absDiff = Math.Abs(diff);

				if (absDiff < minDiff)
				{
					minDiff = absDiff;
					resultSum = sum;
				}

				if (diff < 0 && absDiff >= minDiff)
				{
					j++;
					k = sorted.Count - 1;
					continue;
				}

				k--;
			}
		}

		return resultSum;
	}
}