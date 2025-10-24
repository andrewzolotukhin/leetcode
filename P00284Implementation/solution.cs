// C# IEnumerator interface reference:
// https://docs.microsoft.com/en-us/dotnet/api/system.collections.ienumerator?view=netframework-4.8

class PeekingIterator {
    private int _current = -1;
    private IEnumerator<int> _enumerator;
    private bool _hasNext = true;
    // iterators refers to the first element of the array.
    public PeekingIterator(IEnumerator<int> iterator) {
        // initialize any member here.
        _enumerator = iterator;
        _current = _enumerator.Current;
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    public int Peek() {
        return _current;
    }
    
    // Returns the next element in the iteration and advances the iterator.
    public int Next() {
        int res = _current;
        _hasNext = _enumerator.MoveNext();
        _current = _enumerator.Current;
        return res;
    }
    
    // Returns false if the iterator is refering to the end of the array of true otherwise.
    public bool HasNext() {
		return _hasNext;
    }
}
