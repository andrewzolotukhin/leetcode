/**
 * @param {string} s
 * @param {string[]} words
 * @return {boolean}
 */
var isPrefixString = function(s, words) {
  let ss = '';
  for (let i = 0; i < words.length; i++) {
    ss += words[i];
    if (s.length < ss.length)
      continue;
    if (ss.startsWith(s))
      return true;
    if (ss.length >= s.length)
      return false;
  }
  return false;
};
