public class Solution
{
	public int FindMaximizedCapital(int k, int w, int[] profits, int[] capital)
	{
		Array.Sort(capital, profits);
		var queue = new PriorityQueue<int, int>();
		int index = 0;
		while (k > 0)
		{
			while (index < profits.Length && capital[index] <= w)
			{
				queue.Enqueue(profits[index], -profits[index]);
				index++;
			}
			if (queue.Count == 0) break;
			w += queue.Dequeue();
			k--;
		}
		return w;
	}
}
