public class ListNode
{
	public int val;

	public ListNode? next;

	public ListNode(int val = 0, ListNode? next = null)
	{
		this.val = val;
		this.next = next;
	}
}

public class Solution
{

	public static ListNode SwapPairs(ListNode head)
	{

		var getPair = (ListNode start) =>
		{
			if (start is null || start.next is null)
			{
				return null;
			}

			return new
			{
				First = start,
				Second = start.next,
				Further = start.next is null ? null : start.next.next
			};
		};

		var pair = getPair(head);

		if (pair is null)
		{
			return head;
		}

		var newHead = pair.Second;
		ListNode? previous = null;

		while (pair is not null)
		{
			if (previous is not null)
			{
				previous.next = pair.Second;
			}

			pair.Second.next = pair.First;
			pair.First.next = pair.Further;
			previous = pair.First;

			pair = getPair(pair.Further);
		}

		return newHead;
	}
}