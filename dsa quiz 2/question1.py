#To determine if a linked list has a cycle in it we can use Floyd's Tortoise and Hare (Cycle Detection) algorithm.
#This algorithm uses two pointers moving at different speeds to detect a cycle in a linked list.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def hasCycle(head):
    if not head or not head.next:
        return False
    
    slow = head
    fast = head.next
    
    while slow != fast:
        if not fast or not fast.next:
            return False
        slow = slow.next
        fast = fast.next.next
    
    return True

# Test the algorithm with examples
# Example 1
node1 = ListNode(3)
node2 = ListNode(2)
node3 = ListNode(0)
node4 = ListNode(-4)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node2

print(hasCycle(node1))  # Output: True

# Example 2
node1 = ListNode(1)
node2 = ListNode(2)

node1.next = node2
node2.next = node1

print(hasCycle(node1))  # Output: True

# Example 3
node1 = ListNode(1)

print(hasCycle(node1))  # Output: False
