public class Node {
    public int Key { get; set; }
    public int Val { get; set; }
    public Node Prev { get; set; }
    public Node Next { get; set; }
}

public class LRUCache {
    private Dictionary<int, Node> _map = new Dictionary<int, Node>();
    private readonly int _capacity;
    private Node _head;
    private Node _tail;

    public LRUCache(int capacity) {
        _capacity = capacity;
        _head = new Node();
        _tail = new Node();
        _head.Next = _tail;
        _tail.Prev = _head;
    }

    public int Get(int key) {
        if (!_map.TryGetValue(key, out Node node))
            return -1;

        MoveToHead(node);
        return node.Val;
    }

    public void Put(int key, int value) {
        if (_map.TryGetValue(key, out Node node)) {
            node.Val = value;
            MoveToHead(node);
            return;
        }

        if (_map.Count >= _capacity) {
            Node lru = _tail.Prev;
            RemoveNode(lru);
            _map.Remove(lru.Key);
        }

        Node newNode = new Node { Key = key, Val = value };
        _map.Add(key, newNode);
        AddToHead(newNode);
    }

    private void AddToHead(Node node) {
        node.Prev = _head;
        node.Next = _head.Next;
        _head.Next.Prev = node;
        _head.Next = node;
    }

    private void RemoveNode(Node node) {
        node.Prev.Next = node.Next;
        node.Next.Prev = node.Prev;
    }

    private void MoveToHead(Node node) {
        RemoveNode(node);
        AddToHead(node);
    }
}
