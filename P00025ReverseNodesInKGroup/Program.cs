/**
 * Definition for singly-linked list.
 */
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

	public (ListNode? further, ListNode? newLast, ListNode? newFirst) TryReverseK(ListNode? head, int k)
	{
		if (head is null) return (null, null, null);

		if (k == 1)
		{
			return (head.next, head, head);
		}

		if (head.next is null)
		{
			return (null, null, null);
		}

		var innerResult = TryReverseK(head.next, k - 1);

		if (innerResult is (null, null, null))
		{
			return innerResult;
		}

		(ListNode? innerFurther, ListNode? innerNewLast, ListNode? innerNewFirst) = innerResult;

		if (innerNewLast is not null)
		{
			innerNewLast.next = head;
		}

		return (innerFurther, head, innerNewFirst);
	}

	public ListNode ReverseKGroup(ListNode head, int k)
	{
		var firstResult = TryReverseK(head, k);
		if (firstResult is (null, null, null)) return head;

		var (further, last, first) = firstResult;

		var newHead = first!;

		while ((further, last, first) is not (null, null, null))
		{
			last!.next = further;

			var prevLast = last;

			(further, last, first) = TryReverseK(further, k);

			if ((further, last, first) is (null, null, null))
			{
				break;
			}

			prevLast.next = first;
		}

		return newHead;
	}
}