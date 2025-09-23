/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function (version1, version2) {
  const parts1 = version1.split('.').map(t => parseInt(t));
  const parts2 = version2.split('.').map(t => parseInt(t));

  for (let i = 0; i < Math.max(parts1.length, parts2.length); i++) {
    if (typeof parts1[i] === 'undefined' && parts2[i] === 0) continue;
    if (typeof parts1[i] === 'undefined') return -1;
    if (typeof parts2[i] === 'undefined' && parts1[i] === 0) continue;
    if (typeof parts2[i] === 'undefined') return 1;
    if (parts1[i] < parts2[i]) return -1;
    if (parts1[i] > parts2[i]) return 1;
  }
  return 0;
};
