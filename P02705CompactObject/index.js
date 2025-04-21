/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
  if (Array.isArray(obj)) return obj.filter(v => v).map(v => compactObject(v));
  if (typeof obj != 'object') return obj;
  let ans = {};
  for (let k in obj) {
    if (typeof obj[k] === 'object') {
      if (obj[k])
        ans[k] = compactObject(obj[k]);
    } else {
      if (obj[k]) ans[k] = obj[k];
    }
  }

  return ans;
};
