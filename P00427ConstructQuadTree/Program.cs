/*
// Definition for a QuadTree node.
public class Node {
    public bool val;
    public bool isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {
        val = false;
        isLeaf = false;
        topLeft = null;
        topRight = null;
        bottomLeft = null;
        bottomRight = null;
    }
    
    public Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = null;
        topRight = null;
        bottomLeft = null;
        bottomRight = null;
    }
    
    public Node(bool _val,bool _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
}
*/

public class Solution {
    private void Display(Node node, int depth, int wstart, int hstart, int wend, int hend) {
        var tab = depth == 0 ? "" : new string(' ', depth*2);
        Console.WriteLine($"{tab} - ({wstart},{hstart})/({wend},{hend}) - {node.val} - {node.isLeaf}");
        if(!node.isLeaf) {
            Display(node.topLeft, depth+1, wstart, hstart, wstart + (wend-wstart+1)/2-1, hstart + (hend-hstart+1)/2-1);
            Display(node.topRight, depth+1, wstart+(wend-wstart+1)/2, hstart, wend, hstart+(hend-hstart+1)/2-1);
            Display(node.bottomLeft, depth+1, wstart, hstart+(hend-hstart+1)/2, wstart + (wend-wstart+1)/2, hend);
            Display(node.bottomRight, depth+1, wstart+(wend-wstart+1)/2, hstart+(hend-hstart+1)/2, wend, hend);
        }
    }
    public Node Construct(int[][] grid, int ws = 0, int hs = 0, int we = -1, int he = -1) {
        int n = grid.Length;
        if(we == -1) {
            var res = Construct(grid, 0, 0, n-1, n-1);
            //Display(res, 0, 0, 0, n-1, n-1);
            return res;
        }
        //Console.WriteLine($"{ws}, {hs} -- {we}, {he}");
        var node = new Node();
        if(ws==we) {
            node.val = grid[ws][hs] == 1;
            node.isLeaf = true;
        } else {
            node.topLeft = Construct(grid, ws, hs, ws + (we - ws+1)/2-1, hs + (he - hs+1)/2-1);
            node.topRight = Construct(grid, ws, hs + (he - hs + 1) / 2, ws + (we - ws + 1) / 2 - 1, he);
            node.bottomLeft = Construct(grid, ws + (we - ws + 1) / 2, hs, we, hs + (he - hs + 1) / 2 - 1);
            node.bottomRight = Construct(grid, ws + (we-ws+1)/2, hs + (he-hs+1)/2, we, he);
            //node.val = true;


            if(node.topLeft.isLeaf && node.topRight.isLeaf  && node.bottomLeft.isLeaf && node.bottomRight.isLeaf) {
                if(node.topLeft.val == node.topRight.val && node.topLeft.val == node.bottomLeft.val && node.topLeft.val == node.bottomRight.val) {
                    return new Node(node.topLeft.val, true);
                }
            }
            return new Node(false, false, node.topLeft, node.topRight, node.bottomLeft, node.bottomRight);
        }

        return node;
    }
}
