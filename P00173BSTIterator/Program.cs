/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class BSTIterator {
    private readonly TreeNode _root;
    private readonly IEnumerator<TreeNode> _enumerator;
    private bool _hasNext = false;
    public BSTIterator(TreeNode root) {
        _root = root;
        _enumerator = Nodes(_root).GetEnumerator();
        _hasNext = _enumerator.MoveNext();
    }

    private IEnumerable<TreeNode> Nodes(TreeNode root) {
        if(root is null) yield break;
        foreach(var node in Nodes(root.left)) {
            yield return node;
        }
        yield return root;
        foreach(var node in Nodes(root.right)) {
            yield return node;
        }
    }
    
    public int Next() {
        var val =  _enumerator.Current.val;
        _hasNext = _enumerator.MoveNext();
        return val;
    }
    
    public bool HasNext() {
        return _hasNext;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.Next();
 * bool param_2 = obj.HasNext();
 */
