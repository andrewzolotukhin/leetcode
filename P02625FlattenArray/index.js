/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
  let ans = [];

  for (let i = 0; i < arr.length; i++) {
    if (n > 0 && Array.isArray(arr[i])) {
      const nested = flat(arr[i], n - 1);
      for (let j = 0; j < nested.length; j++) {
        ans.push(nested[j]);
      }
    } else {
      ans.push(arr[i]);
    }
  }

  return ans;
};
