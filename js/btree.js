class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function inOrderTraversal(root) {
    if (root === null) return;

    // Traverse the left subtree
    inOrderTraversal(root.left);

    // Traverse the right subtree
    inOrderTraversal(root.right);

    // Visit the root node
    console.log(root.data + " ");

}

// Driver Code
let root = new Node(2);
root.left = new Node(1);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);

// Perform inorder traversal
// console.log("In-Order Traversal:");
console.log("Post-Order Traversal:");
inOrderTraversal(root);
