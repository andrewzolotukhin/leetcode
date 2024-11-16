public class ListNode
{
	public int val;
	public ListNode next;
	public ListNode(int val = 0, ListNode next = null)
	{
		this.val = val;
		this.next = next;
	}
}

public class Solution
{

	/// <summary>
	/// Took from P00023 (overkill for just two lists, but obviously works)
	/// </summary>
	/// <param name="lists"></param>
	/// <returns></returns>
	public static ListNode MergeKLists(ListNode[] lists)
	{
		var queue = new PriorityQueue<ListNode, int>();

		for (var i = 0; i < lists.Length; i++)
		{
			if (lists[i] is not null)
			{
				// Console.WriteLine($"{lists[i].val} {i}");
				queue.Enqueue(lists[i], lists[i].val);
			}
		}

		var getItem = () =>
		{
			if (queue.Count == 0) return null;

			var first = queue.Dequeue();

			if (first.next is not null)
			{
				queue.Enqueue(first.next, first.next.val);
			}

			return first;
		};

		var head = getItem();

		var last = head;
		var previous = head;

		while (last is not null)
		{
			last = getItem();
			if (last is not null)
			{
				previous!.next = last;
			}
			previous = last;
			if (queue.Count == 1)
			{
				last = getItem();
				previous!.next = last;
				return head;
			}
		}

		return head;
	}

	public ListNode MergeTwoLists(ListNode list1, ListNode list2)
	{
		return MergeKLists([list1, list2]);
	}
}