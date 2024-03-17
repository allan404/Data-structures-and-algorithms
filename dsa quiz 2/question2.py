#To find the node where the cycle begins in a linked list we use Floyd's Tortoise and Hare algorithm 
# to detect the cycle and then determine the starting point of the cycle.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def detectCycle(head):
    if not head or not head.next:
        return None
    
    slow = head
    fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            break
    
    if not fast or not fast.next:
        return None
    
    slow = head
    
    while slow != fast:
        slow = slow.next
        fast = fast.next
    
    return slow

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

cycle_start_node = detectCycle(node1)
if cycle_start_node:
    print("Output: tail connects to node index", cycle_start_node.val)  # Output: tail connects to node index 2
else:
    print("Output: no cycle")

# Example 2
node1 = ListNode(1)
node2 = ListNode(2)

node1.next = node2
node2.next = node1

cycle_start_node = detectCycle(node1)
if cycle_start_node:
    print("Output: tail connects to node index", cycle_start_node.val)  # Output: tail connects to node index 1
else:
    print("Output: no cycle")

# Example 3
node1 = ListNode(1)

cycle_start_node = detectCycle(node1)
if cycle_start_node:
    print("Output: tail connects to node index", cycle_start_node.val)
else:
    print("Output: no cycle")  # Output: no cycle
