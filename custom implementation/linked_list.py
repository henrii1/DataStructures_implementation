# use break when you still have code within the condition you want ran,
#use return at the end of the condition, both can be a part of a single condition.

# slingly linked list

class Node:
    def __init__(self, data: int):
        self.data = data
        self.ref = None

class Linked_List:
    def __init__(self):
        self.head = None

    def traverse_ll(self):
        if self.head is None:
            print("There is no element in Linked-list")
            return
        n = self.head
        while n is not None:
            print(n.data, '-->', end=" ")
            n = n.ref

    def add_begin(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
        else:
            new_node.ref = self.head
            self.head = new_node
            n = self.head
            while n.ref != new_node.ref:
                n = n.ref
            n.ref = self.head

    def add_end(self, value):
        if self.head is None:
            self.head = Node(value)
            return
        n = self.head
        while n.ref is not None:
            n = n.ref
        n.ref = Node(value)

    def add_after(self, value, x):
        if self.head is None:
            self.head = Node(value)
            return
        n = self.head
        while n is not None:
            if n.data == x:
                new_node = Node(value)
                if n.ref is None:
                   n.ref = new_node
                else:
                    new_node.ref = n.ref
                    n.ref = new_node
                    return
            n = n.ref
        print(f"value {x} is not present in linked-list")
                   
                   
    def add_before(self, value, x):
        if self.head is None:
            self.head = Node(value)
            return
        new_node = Node(value)
        if self.head.data == x:
            new_node.ref = self.head
            self.head = new_node
        n = self.head
        while n.ref.ref is not None:
            if n.ref.data == x:
                new_node.ref = n.ref
                n.ref = new_node
                return
            n = n.ref
        print(f"value {x} is not present in list")

    def insert_empty(self, value):
        if self.head is None:
            self.head = Node(value)
        else:
            print("The Linked-list is not none")

    def delete_begin(self):
        if self.head is None:
            print("There is no element in the list to delete")
            return
        if self.head.ref is None:
            self.head = None
        else:
            self.head = self.head.ref

    def delete_end(self):
        if self.head is None:
            print("There is no element in list to delete")
            return
        if self.head.ref is None:
            self.head = None
            return
        n = self.head
        while n.ref.ref is not None:
            n = n.ref
        n.ref = None

    def delete_by_value(self, value):
        if self.head is None:
            print("the linked-list is empty")
            return
        if self.head.data == value:
            self.head = self.head.ref
        n = self.head
        while n.ref is not None:
            if n.ref.data == value:
                if n.ref.ref is None:
                    n.ref = None
                else:
                    n.ref = n.ref.ref
                return
            n = n.ref
        print(f"value {value} is not present in list")





"""Circular Linked list"""

# Traverse in each function and assign self.head to last value

class Node:
    def __init__(self, data: int):
        self.data = data
        self.ref = None

class circular_linked_List:
    def __init__(self):
        self.head = None

    def traverse_ll(self):
        if self.head is None:
            print("There is no element in Linked-list")
            return
        n = self.head
        while n:
            print(n.data, '-->', end=" ")
            if n.ref == self.head:
                break
            n = n.ref
        return

    def add_begin(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            new_node.ref = self.head
        else:
            new_node.ref = self.head
            self.head = new_node

    def add_end(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            new_node.ref = self.head
            return
        n = self.head
        while n.ref != self.head:
            n = n.ref
        n.ref = new_node
        new_node.ref = self.head

    def add_after(self, value, x):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            new_node.ref = self.head
            return
        n = self.head
        while n.ref != self.head:
            if n.data == x:
                new_node.ref = n.ref
                n.ref = new_node
                return  
            n = n.ref
        if n.data == x:
            n.ref = new_node
            new_node.ref = self.head
            return
        print(f"value {x} is not present in linked-list")
                   
                   
    def add_before(self, value, x):
        new_node = Node(value)
        n = self.head
        if n is None:
            self.head = new_node
            new_node.ref = self.head
            return
        if n.data == x:
            new_node.ref = self.head
            while n.ref != self.head:
                n = n.ref
            n.ref = new_node
            self.head = new_node
            return
        while n.ref != self.head:
            if n.ref.data == x:
                new_node.ref = n.ref
                n.ref = new_node
                return
            n = n.ref
        print(f"value {x} is not present in list")

    def insert_empty(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            new_node.ref = self.head
        else:
            print("The Linked-list is not none")

    def delete_begin(self):
        if self.head is None:
            print("There is no element in the list to delete")
            return
        if self.head.ref == self.head:
            self.head = None
        else:
            n = self.head
            while n.ref != self.head:
                n = n.ref
            self.head = self.head.ref
            n.ref = self.head

    def delete_end(self):
        if self.head is None:
            print("There is no element in list to delete")
            return
        if self.head.ref == self.head:
            self.head = None
            return
        n = self.head
        while n.ref.ref != self.head:
            n = n.ref
        n.ref = self.head

    def delete_by_value(self, value):
        if self.head is None:
            print("the linked-list is empty")
            return
        n = self.head
        if n.data == value:
            if n.ref == self.head:
                self.head = None
                return
            while n.ref != self.head:
                n = n.ref
            self.head = self.head.ref
            n.ref = self.head

        while n.ref != self.head:
            if n.ref.data == value:
                if n.ref.ref == self.head:
                    n.ref = self.head
                else:
                    n.ref = n.ref.ref
                return
            n = n.ref
        print(f"value {value} is not present in list")       


                
                
"""Double Linked List"""

class Node:
    def __init__(self, data: int):
        self.data = data
        self.pref = None
        self.nref = None

class Linked_List:
    def __init__(self):
        self.head = None

    def traverse_ll(self):
        if self.head is None:
            print("There is no element in Linked-list")
            return
        n = self.head
        while n is not None:
            print(n.data, '-->', end=" ")
            n = n.nref

    def add_begin(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
        else:
            new_node.nref = self.head
            self.head = new_node

    def add_end(self, value):
        if self.head is None:
            self.head = Node(value)
            return
        n = self.head
        new_node = Node(value)
        while n.nref is not None:
            n = n.nref
        new_node.pref = n
        n.nref = new_node

    def add_after(self, value, x):
        if self.head is None:
            self.head = Node(value)
            return
        n = self.head
        new_node = Node(value)
        while n is not None:
            if n.data == x:
                if n.nref is None:
                   n.nref = new_node
                   new_node.pref = n
                else:
                    new_node.nref = n.nref
                    new_node.pref = n
                    n.nref.pref = new_node
                    n.nref = new_node
                    return
            n = n.nref
        print(f"value {x} is not present in linked-list")
                   
                   
    def add_before(self, value, x):
        if self.head is None:
            self.head = Node(value)
            return
        new_node = Node(value)
        n = self.head
        if n.data == x:
            new_node.nref = self.head
            n.pref = new_node
            self.head = new_node
        while n.nref is not None:
            if n.data == x:
                new_node.nref = n
                new_node.pref = n.pref
                n.pref = new_node
                n.pref.nref = new_node
                return
            n = n.nref
        print(f"value {x} is not present in list")

    def insert_empty(self, value):
        if self.head is None:
            self.head = Node(value)
        else:
            print("The Linked-list is not none")

    def delete_begin(self):
        if self.head is None:
            print("There is no element in the list to delete")
            return
        n = self.head
        if n.nref is None:
            self.head = None
        else:
            self.head = n.nref
            n.nref.pref = None

    def delete_end(self):
        if self.head is None:
            print("There is no element in list to delete")
            return
        n = self.head
        if n.nref is None:
            self.head = None
            return
        while n.nref.nref is not None:
            n = n.nref
        n.nref = None

    def delete_by_value(self, value):
        if self.head is None:
            print("the linked-list is empty")
            return
        n = self.head
        if n.data == value:
            n.nref.pref = None
            self.head = n.nref
            return
        while n.nref is not None:
            if n.data == value:
                if n.nref is None:
                    n.pref.nref = None
                else:
                    n.pref.nref = n.nref
                    n.nref.pref = n.pref
                return
            n = n.nref
        print(f"value {value} is not present in list")




"""Double Circular Linked List"""      
        

class Node:
    def __init__(self, data: int):
        self.data = data
        self.pref = None
        self.nref = None

class circular_Double_linked_List:
    def __init__(self):
        self.head = None

    def traverse_ll(self):
        if self.head is None:
            print("There is no element in Linked-list")
            return
        n = self.head
        while n:
            print(n.data, '-->', end=" ")
            if n.nref == self.head:
                break
            n = n.nref
        return

    def add_begin(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            new_node.pref, new_node.nref = new_node
        else:
            new_node.nref = self.head
            self.head = new_node
            n = self.head
            while n.nref != new_node.nref:
                n = n.nref
            new_node.pref = n
            n.nref = self.head

    def add_end(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            new_node.nref, new_node.pref = self.head
            return
        n = self.head
        while n.nref != self.head:
            n = n.ref
        n.nref = new_node
        new_node.nref = self.head
        new_node.pref = n
        self.head.pref = new_node

    def add_after(self, value, x):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            new_node.nref, new_node.pref = self.head
            return
        n = self.head
        while n.nref != self.head:
            if n.data == x:
                new_node.nref = n.nref
                new_node.pref = n
                n.nref.pref = new_node
                n.nref = new_node
                return  
            n = n.nref
        if n.data == x:
            n.nref = new_node
            new_node.pref = n
            new_node.nref = self.head
            self.head.pref = new_node
            return
        print(f"value {x} is not present in linked-list")
                   
                   
    def add_before(self, value, x):
        new_node = Node(value)
        n = self.head
        if n is None:
            self.head = new_node
            new_node.nref, new_node.pref = self.head
            return
        if n.data == x:
            new_node.nref = self.head
            while n.nref != self.head:
                n = n.nref
            n.nref = new_node
            new_node.pref = n
            self.head = new_node
            return
        while n.nref != self.head:
            if n.nref.data == x:
                new_node.nref = n.nref
                new_node.pref = n
                n.nref.pref = new_node
                n.nref = new_node
                return
            n = n.nref
        print(f"value {x} is not present in list")

    def insert_empty(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            new_node.nref, new_node.pref = self.head
        else:
            print("The Linked-list is not none")

    def delete_begin(self):
        if self.head is None:
            print("There is no element in the list to delete")
            return
        if self.head.nref == self.head:
            self.head = None
        else:
            n = self.head
            while n.nref != self.head:
                n = n.nref
            self.head.nref.pref = n
            self.head = self.head.nref
            n.nref = self.head

    def delete_end(self):
        if self.head is None:
            print("There is no element in list to delete")
            return
        if self.head.nref == self.head:
            self.head = None
            return
        n = self.head
        while n.nref.nref != self.head:
            n = n.nref
        n.nref = self.head
        self.head.pref = n

    def delete_by_value(self, value):
        if self.head is None:
            print("the linked-list is empty")
            return
        n = self.head
        if n.data == value:
            if n.nref == self.head:
                self.head = None
                return
            while n.nref != self.head:
                n = n.nref
            self.head = self.head.nref
            self.head.pref = n
            n.nref = self.head
        while n.nref != self.head:
            if n.nref.data == value:
                if n.nref.nref == self.head:
                    n.ref = self.head
                    self.head.pref = n
                else:
                    n.nref.nref.pref = n
                    n.nref = n.nref.nref
                return
            n = n.nref
        print(f"value {value} is not present in list")       



# some mistakes may be present.