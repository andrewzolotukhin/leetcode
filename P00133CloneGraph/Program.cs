/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }

    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class Solution {
    private void Insert(Node node, Dictionary<Node, Node> nodesMap, Dictionary<int, Node> newNodes) {
        if(!newNodes.ContainsKey(node.val)) {
            nodesMap[node] = new Node(node.val);
            newNodes[node.val] = nodesMap[node]; 
        
            foreach(var n in node.neighbors) {
                Insert(n, nodesMap, newNodes);
            }
        }
    }
    public Node CloneGraph(Node node) {
        if(node is null) return null;
        Dictionary<int, Node> newNodes = [];
        Dictionary<Node, Node> nodesMap = [];
        Insert(node, nodesMap, newNodes);

        foreach(var oldNode in nodesMap.Keys) {
            var newNode = nodesMap[oldNode];

            foreach(var n in oldNode.neighbors) {
                newNode.neighbors.Add(nodesMap[n]);
            }
        }

        return nodesMap[node];
    }
}
