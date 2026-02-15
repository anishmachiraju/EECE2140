# Testing Checklist

Follow these manual tests to validate required behaviors for the fixed-size circular queue.

1) Enqueue until full (array version)
- Create a queue with small capacity (e.g., 3).
- Enqueue three distinct values: all should succeed.
- Attempt a fourth enqueue: program should throw/print an overflow error.

2) Dequeue until empty
- Starting from a queue with some elements, call dequeue repeatedly until empty.
- Each dequeue returns the expected front element in FIFO order.
- A dequeue when empty should throw/print an underflow error.

3) Wrap-around test (circular indexing)
- Create capacity 3. Enqueue A, B, C.
- Dequeue twice (removes A,B).
- Enqueue D, E (these should occupy the freed slots via wrap-around).
- Print queue: expected order C, D, E.

4) Mixed operations sequence test
- Start capacity 4. Sequence: enqueue 1,2,3; dequeue; enqueue 4; dequeue; enqueue 5; print.
- Verify FIFO order across operations and that size and isEmpty/isFull behave as expected.

Notes
- The implementation throws `std::overflow_error` on enqueue to a full queue and
  `std::underflow_error` on dequeue/front from an empty queue. The interactive menu
  catches these exceptions and prints the message.
