
var RandomizedSet = function () {
  this.map = new Map();
  this.mod = 1000000007;
  this.ret = 0;
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function (val) {
  let res = this.map.has(val);
  this.ret = 0;
  this.map.set(val, true);
  return !res;
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function (val) {
  let res = this.map.has(val);
  this.ret = 0;
  if (res) this.map.delete(val);
  return res;
};

/**
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function () {
  const keys = Array.from(this.map.keys());
  const now = new Date().getTime();
  this.ret++;

  return keys[(Math.floor(Math.random() * this.mod) % keys.length + this.ret++) % keys.length];
};

/** 
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
