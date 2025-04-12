/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

function bfs(node, level, result) {
  if (!node) return;
  if (level % 2 == 0) {
    if (node.left) {
      result[level + 1] = result[level + 1] || [];
      result[level + 1].push(node.left);
      result[level + 1].push(node.right);
      bfs(node.left, level + 1, result);
      bfs(node.right, level + 1, result);
    }
  } else {
    bfs(node.left, level + 1, result);
    bfs(node.right, level + 1, result);
  }
};

/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var reverseOddLevels = function (root) {
  var res = {};
  bfs(root, 0, res);

  for (k in res) {
    const n = res[k].length;
    for (let i = 0; i < n / 2; i++) {
      const t = res[k][i].val;
      res[k][i].val = res[k][n - 1 - i].val;
      res[k][n - 1 - i].val = t;
    }
  }
  return root;
};
