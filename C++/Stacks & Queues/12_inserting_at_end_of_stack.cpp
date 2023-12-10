/*
Idea:
recursing till stack is empty (elements are stored in function call stack). inserting element and pushing rest elements
*/

#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    stack<char> items;

public:
    bool isEmpty() const {
        return items.empty();
    }

    char peek() const {
        return items.top();
    }

    void push(char x) {
        items.push(x);
    }

    void pop() {
        items.pop();
    }
};

Stack st;

static void insert_at_bottom(char x)
{
    if (st.isEmpty())
        st.push(x);
    else
    {
        /* All items are held in Function Call Stack until we  reach end of the stack. When the stack becomes  empty,
         the st.size() becomes 0, the above if part is executed and the item is inserted at the bottom */
        char a = st.peek();
        st.pop();
        insert_at_bottom(x);

        //push all the items held in Function Call Stack
        //once the item is inserted at the bottom
        st.push(a);
    }
}

int main()
{
    insert_at_bottom('A');
    insert_at_bottom('B');
    insert_at_bottom('C');

    // Print the elements of the stack
    while (!st.isEmpty())
    {
        cout << st.peek() << " ";
        st.pop();
    }

    return 0;
}
