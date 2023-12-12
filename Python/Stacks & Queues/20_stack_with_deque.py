"""
Idea:
inserting and deleting and the end of deque.
"""


class node:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None


class Deque:
    def __init__(self):
        self.head = self.tail = None

    def isEmpty(self):
        if self.head is None: return True
        return False

    # insert at last position of deque
    def insert_last(self, element):
        newP = node(element)
        if self.head is None:
            self.head = self.tail = newP
            return
        newP.prev = self.tail
        self.tail.next = newP
        self.tail = newP

    def size(self):
        curr = self.head
        len = 0
        while curr is not None:
            len += 1
            curr = curr.next
        return len

    # remove element at the last position
    def remove_last(self):
        if self.isEmpty():
            print('List is Empty')
            return
        self.tail = self.tail.prev
        if self.tail is not None: self.tail.next = None

    def display(self):
        if self.isEmpty():
            print('List is Empty')
            return
        curr = self.head
        while curr is not None:
            print(curr.val, end=' ')
            curr = curr.next
        print()


class Stack:
    def __init__(self):
        self.stack = Deque()

    # push to push element at top of stack using insert at last function of deque
    def push(self, element):
        self.stack.insert_last(element)

    # pop to remove element at top of stack using remove at last function of deque
    def pop(self):
        self.stack.remove_last()

    def size(self):
        return self.stack.size()

    def display(self):
        self.stack.display()


stk = Stack()

# push 7 and 8 at top of stack
stk.push(7)
stk.push(8)
print("Stack: ")
stk.display()

# pop an element
stk.pop()
print("Stack: ")
stk.display()

print("Size of stack is ", stk.size())
