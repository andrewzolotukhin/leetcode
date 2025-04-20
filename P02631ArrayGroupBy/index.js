/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function (fn) {
  const ans = {};
  for (let i = 0; i < this.length; i++) {
    const k = fn(this[i]);
    if (k in ans) {
      ans[k].push(this[i]);
    } else {
      ans[k] = [this[i]];
    }
  }
  return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
