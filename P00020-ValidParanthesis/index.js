/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const stack = [];
  let last;
  for (let i = 0; i < s.length; i++) {
    switch (s[i]) {
      case "(":
        stack.push(")");
        continue;
      case "{":
        stack.push("}");
        continue;
      case "[":
        stack.push("]");
        continue;
      default:
        if (stack.length == 0) return false;
        last = stack[stack.length - 1];
        if (last != s[i]) return false;
        stack.pop();
    }
  }
  return stack.length == 0;
};
