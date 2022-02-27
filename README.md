# Implementation-Deque
Deque is the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container
<br><br>
- deque() - initialize a blank deque. -> O(1)
- deque(n,x) - initialize a deque of length n with all values as x. -> O(n)
- push_back(x) - append data x at the end. -O(1) pop_back() - erase data at the end. -> O(1)
- push_front(x) - append data x at the beginning. O(1) pop_front() - erase data at the beginning. -> O(1)
- front() - returns the first element(value) in the deque. -> O(1)
- back() - returns the last element(value) in the deque. -> O(1)
- empty() - returns true if deque is empty else returns false. O(1) size() - returns the current size of deque. -> O(1)
- resize(x, d) - changes the size dynamically. If the new size is greater than the current size of the deque, then fill the empty space with the default value d. -> O(n)
- clear() - remove all elements of deque. -> O(1)
- D[n] - returns the nth element of the deque. -> O(1)
