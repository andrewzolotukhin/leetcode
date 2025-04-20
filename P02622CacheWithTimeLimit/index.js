var TimeLimitedCache = function () {
  this.map = new Map();
  this.timers = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
  if (this.timers.has(key)) {
    clearTimeout(this.timers.get(key));
  }
  this.map.set(key, value);
  let res = this.timers.has(key);
  this.timers.set(key, setTimeout(() => {
    if (this.map.has(key)) {
      this.map.delete(key);
    }
  }, duration));
  return res;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
  if (this.map.has(key)) return this.map.get(key);
  return -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
  return Array.from(this.map.keys()).length;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
