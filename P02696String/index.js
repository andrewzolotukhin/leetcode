/**
 * @param {string} s
 * @return {number}
 */
var minLength = function (s) {
  let prev = s;
  while (true) {
    const n = s.replaceAll('AB', '').replaceAll('CD', '');
    if (n === prev) return n.length;
    prev = s;
    s = n;
  }
};
