'''
Problem: Check if two BSTs are identical or not.
BST or Binary Search Tree is a tree data structure that has following properties:
1. left node is smaller than its root node
2. right node is greater than its root node
3. both left and right subtrees are also BSTs.

To check whether two BSTs are identical or not, we follow a recursive approach
where we check whether the value of current node is equal or not.
If it is, we then check whether the left and right substrees
are identical or not using recursion.
If all the three conditions are true, BSTs are identical
Otherwise they are not
'''


# Class that defines a node of BST
class BSTNode:
    def __init__(self, data):
        self.val = data
        self.left = None
        self.right = None


def check_identical(bst1, bst2):
    # if bst2 is None & bst1 is not, they are not identical
    if bst1 and not bst2:
        return False

    # if bst1 is None & bst2 is not, they are not identical
    if bst2 and not bst1:
        return False

    # if both bst1 & bst2 are None
    if not bst1 and not bst2:
        return True

    # if both bst1 & bst2 are not empty/None, check if they are identical
    while bst1 and bst2:
        # check if current node values are same
        # check if left and right subtrees are also identical
        if bst1.val == bst2.val and check_identical(bst1.left, bst2.left) and check_identical(bst1.right, bst2.right):
            return True
        else:
            return False


def insert_node(root, value):
    # If root is empty, create a new node
    if root is None:
        return BSTNode(value)

    # if the value already exists, return the root
    if root.val == value:
        return root

    # insert the value in left subtree if it is less than the root value
    if value < root.val:
        root.left = insert_node(root.left, value)

    # insert the value in right subtree if it is greater than the root value
    else:
        root.right = insert_node(root.right, value)

    return root


def main():
    bst1 = None
    bst2 = None
    # Input Binary Search Tree I
    res1 = input("Want to enter nodes in BST1? (y/n) ")
    if res1 == 'y':
        flag = True
        while flag:
            node_value = int(input("Enter node value: "))
            bst1 = insert_node(bst1, node_value)
            res = input("Want to add more? (y/n) ")
            if res == "y":
                flag = True
            else:
                flag = False

    # Input Binary Search Tree 2
    res2 = input("Want to enter nodes in BST2? (y/n) ")
    if res2 == 'y':
        flag = True
        while flag:
            node_value = int(input("Enter node value: "))
            bst2 = insert_node(bst2, node_value)
            res = input("Want to add more? (y/n) ")
            if res == "y":
                flag = True
            else:
                flag = False

    # Checking whether the input BSTs are identical or not
    print("Checking if BSTs are identical ....")
    print('---------------------------')
    if check_identical(bst1, bst2):
        print("YESSSS! They are identical!")
    else:
        print("OPPSSS!! They are not identical!")
    print('---------------------------')


if __name__ == '__main__':
    main()

'''
Input Sample:
1.
Want to enter nodes in BST1? (y/n) y
Enter node value: 10
Want to add more? (y/n) y
Enter node value: 8
Want to add more? (y/n) y
Enter node value: 15
Want to add more? (y/n) y
Enter node value: 12
Want to add more? (y/n) n
Want to enter nodes in BST2? (y/n) y
Enter node value: 10
Want to add more? (y/n) y
Enter node value: 8
Want to add more? (y/n) y
Enter node value: 15
Want to add more? (y/n) y
Enter node value: 12
Want to add more? (y/n) n
Checking if BSTs are identical ....
---------------------------
YESSSS! They are identical!
---------------------------

2.
Want to enter nodes in BST1? (y/n) y
Enter node value: 5
Want to add more? (y/n) n
Want to enter nodes in BST2? (y/n) n
Checking if BSTs are identical ....
---------------------------
OPPSSS!! They are not identical!
---------------------------

3.
Want to enter nodes in BST1? (y/n) n
Want to enter nodes in BST2? (y/n) n
Checking if BSTs are identical ....
---------------------------
YESSSS! They are identical!
---------------------------
'''
