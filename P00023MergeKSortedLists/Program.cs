var list13 = new ListNode(5);
var list12 = new ListNode(4, list13);
var list1 = new ListNode(1, list12);

var list23 = new ListNode(4);
var list22 = new ListNode(3, list23);
var list2 = new ListNode(1, list22);

var list32 = new ListNode(6);
var list3 = new ListNode(2, list32);
Solution.MergeKLists([list1, list2, list3]);

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
}