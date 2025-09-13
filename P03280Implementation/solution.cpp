/**
 * @param {string} date
 * @return {string}
 */
var convertDateToBinary = function(date) {
  return date.split('-').map(s = > Number(s).toString(2)).join('-');
};
