// Javascript program to implement Tree Sort 
// In BST, left is less than N,
// and N is less than R
class Node { 
	constructor(item) { 
		this.key = item; 
		this.left = this.right = null; 
	} 
} 

/* A recursive function to 
insert a new key in BST */
function insertBinaryNode(root, key) { 

	/* If the tree is empty, 
return a new node */
	if (root == null) { 
		root = new Node(key); 
		return root; 
	} 

	// insert to left if less than Node
	if (key < root.key) 
		root.left = insertBinaryNode(root.left, key); 
	else if (key > root.key) 
		root.right = insertBinaryNode(root.right, key); 

	/* return the root */
	return root; 
} 

// A function to do 
// inorder traversal of BST - LNR
function inorderTraverse(root) { 
	if (root != null) { 
		inorderRec(root.left); 
		console.log(root.key + " "); 
		inorderRec(root.right); 
	} 
} 

// Root of BST 
let root = new Node(); 
root = null; 

// let arr = [5, 4, 7, 2, 11]; 
let arr = [8, 7, 6 ,5 , 4, 3, 2, 1]

// bst insertion
for (let i = 0; i < arr.length; i++) { 
	root = insertBinaryNode(root, arr[i]); 
} 

// bst traversal
inorderTraverse(root); 

/* 
total time complexity of O(n log n) in the average case, and O(n^2) in the worst case

Finally, the worst-case time complexity of sorting a binary tree using the steps of the tree sort algorithm is as follows:
T(SortingBinaryTree) =  T(BST Insertion) +  T(BST Traversal) = O(n^2) + O(n) = O(n^2) */

// insert a key is done in O(n) in the worst case, and O(log n) in avg case
// This code is contributed 
// by Saurabh Jaiswal 