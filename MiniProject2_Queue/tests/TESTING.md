
`TESTING.md`


# Testing Notes

## Test 1: Enqueue until full
- Capacity = 3
- Enqueue: 1, 2, 3 (all succeed)
- Enqueue: 4 → expected overflow error
- Result: PASS

## Test 2: Dequeue until empty
- Start with queue [5, 6]
- Dequeue → 5
- Dequeue → 6
- Dequeue again → expected underflow error
- Result: PASS

## Test 3: Wrap-around (circular indexing)
- Capacity = 4
- Enqueue: 10, 20, 30, 40 (full)
- Dequeue twice (remove 10, 20)
- Enqueue: 50, 60 (should wrap to front slots)
- Expected order now: [30, 40, 50, 60]
- Result: PASS

## Test 4: Mixed operations sequence
- Capacity = 5
- Enqueue 1, 2
- Dequeue (1)
- Enqueue 3, 4
- Peek should be 2
- Size should be 3
- Clear then size should be 0 and isEmpty = true
- Result: PASS
