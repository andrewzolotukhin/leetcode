/**
 * @param {string} s
 * @return {boolean}
 */
var isSubstringPresent = function (s) {
  let rev = '';
  if (s.length < 2) return false;
  for (let i = s.length - 1; i >= 0; i--) {
    rev += s[i];
  }

  for (let i = 0; i < s.length - 1; i++) {
    if (rev.indexOf(s[i] + s[i + 1]) != -1) {
      return true;
    }
  }

  return false;
};
