"""
Idea:
recursing till stack is empty (elements are stored in function call stack). inserting element and pushing rest elements
"""


class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def peek(self):
        return self.items[-1]

    def push(self, x):
        self.items.append(x)

    def pop(self):
        return self.items.pop()


def insert_at_bottom(x):
    if st.is_empty():
        st.push(x)
    else:
        # All items are held in Function Call Stack until we  reach end of the stack. When the stack becomes  empty,
        # the st.size() becomes 0, the above if part is executed and the item is inserted at the bottom
        a = st.peek()
        st.pop()
        insert_at_bottom(x)

        # push all the items held in Function Call Stack
        # once the item is inserted at the bottom
        st.push(a)


# Example usage
st = Stack()
insert_at_bottom('A')
insert_at_bottom('B')
insert_at_bottom('C')

# Print the elements of the stack
while not st.is_empty():
    print(st.peek(), end=" ")
    st.pop()
