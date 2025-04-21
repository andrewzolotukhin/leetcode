class EventEmitter {

  #callbacks = new Map();

  /**
   * @param {string} eventName
   * @param {Function} callback
   * @return {Object}
   */
  subscribe(eventName, callback) {
    let currentCallBacks;
    if (this.#callbacks.has(eventName)) {
      currentCallBacks = this.#callbacks.get(eventName);
    } else {
      currentCallBacks = new Set();
      this.#callbacks.set(eventName, currentCallBacks);
    }
    currentCallBacks.add(callback);
    return {
      unsubscribe: () => {
        let s = this.#callbacks.get(eventName);
        s.delete(callback);
      }
    };
  }

  /**
   * @param {string} eventName
   * @param {Array} args
   * @return {Array}
   */
  emit(eventName, args = []) {
    if (!this.#callbacks.has(eventName)) {
      return [];
    }
    return Array.from(this.#callbacks.get(eventName)).map((c) => c(...args));
  }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
