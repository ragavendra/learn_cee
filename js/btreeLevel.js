class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function levelOrderTraversal(root) {
    if (root === null) return;

    let queue = [root];

    while (queue.length > 0) {
        let current = queue.shift();

        // Visit the root node
        console.log(current.data + " ");

        // Enqueue left child
        if (current.left !== null) {
			queue.push(current.left);
		} else {
			console.log(current.data +"Left end");
		}


        // Enqueue right child
        if (current.right !== null) 
			queue.push(current.right);
		else
			console.log(current.data +"Right end");
    }
}

// Driver Code
let root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);

console.log("Level-Order Traversal:");
levelOrderTraversal(root);
