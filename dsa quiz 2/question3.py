#function that takes the head of a linked list and returns the reversed list:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def reverseLinkedList(head):
    prev = None
    current = head
    
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    
    return prev

#  function to print the linked list
def printLinkedList(head):
    current = head
    while current:
        print(current.val, end=" ")
        current = current.next
    print()

# Test the function with an example
node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)

node1.next = node2
node2.next = node3

print("Original linked list:")
printLinkedList(node1)  # Output: 1 2 3

reversed_head = reverseLinkedList(node1)

print("Reversed linked list:")
printLinkedList(reversed_head)  # Output: 3 2 1
