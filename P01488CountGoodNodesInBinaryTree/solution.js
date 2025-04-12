/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

function bfs(node, vals, inc) {
  if (!node) return;
  if (vals.filter(v => v > node.val).length === 0) inc();

  const newM = [...vals, node.val];
  bfs(node.left, newM, inc);
  bfs(node.right, newM, inc);
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var goodNodes = function (root) {
  let ans = 0;
  bfs(root, [], () => {
    ans++;
  });
  return ans;
};
