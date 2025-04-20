/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function (arr, size) {
  const ans = [];

  let c = [];

  for (let i = 0; i < arr.length; i++) {
    if (c.length === size) {
      ans.push(c);
      c = [];
    }
    c.push(arr[i]);
  }
  if (c.length) {
    ans.push(c);
  }

  return ans;
};

