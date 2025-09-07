/**
 * @param {string[]} operations
 * @return {number}
 */
var finalValueAfterOperations = function (operations) {
  var x = 0;
  operations.map(o => { (o[0] == '+' || o[o.length - 1] == '+') ? x++ : x--; });
  return x;
};
