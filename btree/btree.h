#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <memory> // shared_ptr
#include <algorithm> // std::max()

/** 
  * Class: BTree
  * Binary Search Tree
  *
  * Binary Search Tree is essentially a data structure which exploits how
  * efficient binary searches are. Log n search because it can reduce
  * the search space each check. It can also devolve into a linked list
  * and that should be avoided because that would result in worst case!
  *
  * Used In:
  *
  *	Huffman Coding - compression algorithm
  *	Expression Parsers / Solvers
  *	Database Indexing
  *
  * Left sub-tree contains nodes with keys less than the node's key.
  * Right sub-tree contains nodes with keys greater than the node's key.
  * Left & Right sub-tree are also binary trees.
  * Must contain no duplicate nodes.
  *
  * Space: O(n), worst O(n) (linked list)
  * Search: O(log n), worst O(n) 
  * Insert: O(log n), worst O(n) 
  * Delete: O(log n), worst O(n)
  *
  * Author: Michael J. Kiernan
  *
  * TODO: rule of five (for C++11):
  *	  - destructor (x), copy ctr (x), move ctr, copy assignment operator(x), 
  *	  move assignment operator.
  * 
  * Just added move stuff.
  * Pretty sure no rvalues should be used by tree. need to check syntax.
  *	  
  * Decided to use shared_ptr - dat c++11.
  * Unique_ptr isn't an appropriate choice as sometimes nodes need
  *   to temporarily have 2 owners.
  *
*/

template <class dataType>
class BTree
{
    private:

	/**
	  * Tree structure.
	  * Templated data/payload.
	  * Left node and Right node.
	*/
	struct node
	{
	    dataType info;
	    std::shared_ptr<node> left;
	    std::shared_ptr<node> right;

	    // default constructor
	    // forces inserts to be data-centric and without children
	    node(const dataType &data) 
	    : info{data}, left{nullptr}, right{nullptr} {}
	};
	
	/**
	  * Head of tree.
	*/
	std::shared_ptr<node> root;

    public:

	/**
	  * Default constructor.
	  * Prevents implicit conversion.
	*/
	explicit BTree() : root{nullptr} {};	

	/**
	  * Copy constructor. 
	  * Explicit prevents implicit conversion.
	  * @const Btree<dataType>& - const templated tree reference lvalue.
	*/
	explicit BTree<dataType>(const BTree<dataType>&);
	
	/**
	  * Overloaded = operator.
	  * Invokes copy constructor.
	  * @const Btree<dataType>& - const templated tree reference.
	  * Operatoes only on lvalues.
	*/
	const BTree<dataType>& operator=(const BTree<dataType>&) &;
	
	/**
	 * Move constructor.
	 * Explicit prevents implicit conversion.
	 * @Btree<dataType>&& - templated tree reference rvalue.
	*/
	explicit BTree<dataType>(BTree<dataType>&&);

	/**
	  * Overloaded = operator.
	  * Invokes move (-> swap) constructor.
	  * @Btree<dataType> - tree passed by value.
	  * Operates only on rvalues.
	*/
	BTree<dataType>& operator=(BTree<dataType>) &&;

	/**
	 * Swap operation.
	 * Stores right in left and left in right.
	 * @Btree<dataType>& left - templated tree reference.
	 * @Btree<dataType>& right - templated tree reference.
	*/ 
	void swap(BTree<dataType>& left, BTree<dataType>& right);

	/**
	  * Destructor. 
	*/
	~BTree();

	/**
	  * Returns true if empty, false if filled.
	  * Const as tree is not altered.
	*/
	bool isEmpty() const;

	/**
	  * Returns height of binary tree.
	  * Recursively calls height();
	  * Const as tree is not altered.
	*/
	int getHeight() const;

	/**
	 * Prints out the contents of a tree.
	 * Assumes that the datatype is able to be handed by cout.
	 * Could be pretty readily broken due to templating and is mainly used to debug.
	 * */
	void printTree() const;
	
	/**
	  * Get amount of nodes in the tree.
	  * Aka node with a valid left or right link.
	*/	
	int getNodeNum() const;

	/**
	  * Return amount of leaves in the tree.
	  * Aka node with no valid left or right link.
	  *
	*/
	int getLeafNum() const;

	/**
	  * De-allocates tree.
	  * Invoked by the destructor.
	  * Non-const as it alters data.
	*/
	void destroyTree();

	/**
	  * Binary Search.
	  * Returns true if data is located in tree. False otherwise.
	  * Const as function does not alter tree.
	  * @treeInfo - const dataType reference.
	*/
	bool search(const dataType &treeInfo) const;

	/**
	  * Inserts data into tree.
	  * @treeInfo - const dataType reference. not modifiable.
	  * Non const as function alters tree.
	*/
	void insert(const dataType &treeInfo);

	/**
	  * Deletes a node with the same dataType as deleteItem.
	  * @treeInfo - node pointer reference. 
	  * Non const as function alters tree.
	*/	
	void deleteNode(std::shared_ptr<node> deleteItem);
    
    private:
	    
	/**
	  * Copy a tree.
	  * Called by copy constructor.
	  * Used recursively on left and right sub tree.
	  * Non const function as it alters newTree.
	  * @newTree - node pointer reference.
	  * @oldTree - const node pointer to a const node reference.
	*/
	void copyTree(std::shared_ptr<node>& newTree, const std::shared_ptr<node> &oldTree);

	/**
	  * Destroys tree. Recursively called.
	  * Non const function as it alters tree.
	  * @tree - node pointer reference. non const as this is altered.
	*/
	void destroyTree(std::shared_ptr<node> &tree);

	/**
	  * Recursively counts height of binary tree.
	  * Returns max of left and right.
	  * Const function as it does not alter any data.
	  * @tree - const node pointer to a const node reference.
	  *
	*/
	int getHeight(const std::shared_ptr<node> &tree) const;

	/**
	  * Recursively counts the amount of nodes.
	*/
	int getNodeNum(const std::shared_ptr<node> &tree) const;

	/**
	  * Recursively counts the amount of leaves.
	*/
	int getLeafNum(const std::shared_ptr<node> &tree) const;

	/**
	 * Recursively prints out Binary Tree to std out.
	 * Private.
	 * Const function as it does not alter any data.
	 * @tree - const node pointer to const node reference.
	 * */
	void printTree(const std::shared_ptr<node> &tree) const;

};

/** Templated Function Definitions */

/** Public */

template<class dataType>
BTree<dataType>::BTree(const BTree<dataType>& refTree)
{
    if(refTree.root == nullptr)
	root = nullptr;
    else
	copyTree(root, refTree.root);
}

template<class dataType>
void BTree<dataType>::swap(BTree<dataType>& left, BTree<dataType>& right)
{
    // go as far left as possible
    swap(left.root->left, right.root->left);
    // go as far right as possible
    swap(left.root->right, right.root->right);
    // swap from bottom up
    std::swap(left.root, right.root);
}

template<class dataType>
BTree<dataType>::~BTree()
{
    destroyTree();
}

template<class dataType>
const BTree<dataType>& BTree<dataType>::operator=(const BTree<dataType>& lVal) &
{
    if(this != &lVal) // if they don't match, otherwise we automatically have achieved our goal
    {
	if(root != nullptr) // if root isn't null
	{
	    destroyTree(root); // clear it / make it null
	    root = nullptr;
	}

	if(lVal.root != nullptr) // if rvalue is null
	    copyTree(root, lVal.root);
    }

    return(*this);
}

template<class dataType>
BTree<dataType>& BTree<dataType>::operator=(BTree<dataType> rVal) &&
{
    swap(*this, rVal);
    return(*this);
}

template<class dataType>
bool BTree<dataType>::isEmpty() const
{
    return(root == nullptr); // 1/true if null 0/false if not null
}

template<class dataType>
int BTree<dataType>::getHeight() const
{
    return(getHeight(root));
}

template<class dataType>
int BTree<dataType>::getNodeNum() const
{
    return(getNodeNum(root));
}

template<class dataType>
int BTree<dataType>::getLeafNum() const
{
    return(getLeafNum(root));
}

template<class dataType>
void BTree<dataType>::printTree() const
{
    if(root != nullptr)
    {
	std::cout << root->info << std::endl;
	printTree(root->left);
	printTree(root->right);
    }
    else
    {
	std::cout << "Null." << std::endl;
    }
}

template<class dataType>
void BTree<dataType>::destroyTree()
{
    if(root != nullptr)
	destroyTree(root);
}

template<class dataType>
bool BTree<dataType>::search(const dataType& searchData) const
{
    std::shared_ptr<node> current = nullptr; // temp node pointer to iterate tree
    
    bool found = false;

    if(root == nullptr) // tree not initialised, exit obviously
	found = false;
    else
    {
	current = root;
	
	while(current != nullptr && !found)
	{
	    if(current->info == searchData)
		found = true;
	    else if(current->info > searchData)
		current = current->right;
	    else
		current = current->left;
	}
    }

    return(found);
}

template<class dataType>
void BTree<dataType>::insert(const dataType &treeInfo)
{
    std::shared_ptr<node> newNode = std::make_shared<node>(treeInfo); // initialise a node with data to be inserted

    if(root == nullptr) // if tree has not yet been initialised
    {
	root = newNode; // data to be inserted is now the head of the tree
    }
    else // root is not null / tree is initialised
    {
	std::shared_ptr<node> current = nullptr;
	std::shared_ptr<node> trailCurrent = nullptr;
	
	current = root;

	// loops through the tree
	// traverses left if insert data is smaller than tree node
	// traverses right if insert data is larger than tree node 
	// once current == nullptr an appropriate position in the tree is found
	while(current != nullptr)
	{
	    trailCurrent = current;
	    if(current->info == treeInfo) // a duplicate data value
	    {
		//throw(std::out_of_range{"Duplicate data forbidden."});
		return; 
	    }
	    else  // not a duplicate
	    {
		if(treeInfo < current->info) // smaller goes to the left
		    current = current->left;
		else
		    current = current->right; // larger goes to the right
	    }
	}

	// current is now nullptr so this cannot be reference
	// hence trailCurrent which has a null left node and null right node (current)
	// newNode is then assigned to this null node thus completeing insertion
	if(treeInfo < trailCurrent->info)
	    trailCurrent->left = newNode;
	else
	    trailCurrent->right = newNode;
    }
}

template<class dataType>
void BTree<dataType>::deleteNode(std::shared_ptr<node> deleteItem)
{
    std::shared_ptr<node> current = nullptr;
    std::shared_ptr<node> trailCurrent = nullptr;
    std::shared_ptr<node> temp = nullptr;

    // nothing to delete
    if(deleteItem == nullptr)
    {
	return;
    }
    else if(deleteItem->left == nullptr && deleteItem->right == nullptr)
    {
	deleteItem = nullptr;
    }
    else if(deleteItem->left == nullptr)
    {
	temp = deleteItem;
	deleteItem = temp->right;
	temp = nullptr;
    }
    else if(deleteItem->right == nullptr)
    {
	temp = deleteItem;
	deleteItem = temp->left;
	temp = nullptr;
    }
    else
    {
	current = deleteItem->left;
	trailCurrent == nullptr;

	while(current->right != nullptr)
	{
	    trailCurrent = current;
	    current = current->right;
	}

	deleteItem->info = current->info;

	if(trailCurrent == nullptr)
	    deleteItem->left = current->left;
	else
	    trailCurrent->right = current->left;

	current = nullptr;
    }
}

/** Private */

template<class dataType>
void BTree<dataType>::copyTree(std::shared_ptr<node>& newTree, const std::shared_ptr<node> &oldTree)
{
    if(oldTree == nullptr) // old tree is null, so new tree is null
    {
	newTree = nullptr;
    }
    else // not null
    {
	newTree = std::make_shared<node>(oldTree->info); // store data
	copyTree(newTree->left, oldTree->left); // attempt left link
	copyTree(newTree->right, oldTree->right); // attempt right link
    }
}

template<class dataType>
void BTree<dataType>::destroyTree(std::shared_ptr<node> &tree)
{
    if(tree != nullptr)
    {
	destroyTree(tree->left); // check left
	    
	destroyTree(tree->right); // check right
	    
	tree = nullptr; // should let shared_ptr know to delete
    }
}

template<class dataType>
int BTree<dataType>::getHeight(const std::shared_ptr<node> &tree) const
{
    if(tree == nullptr)
	return(0);
    else
    {
	return(1+(std::max(getHeight(tree->left), getHeight(tree->right))));
    }
}

template<class dataType>
int BTree<dataType>::getNodeNum(const std::shared_ptr<node> &tree) const
{
    if(tree == nullptr)
	return(0);
    else
    {
	if(tree->left == nullptr && tree->right == nullptr)
	    return(1);
	else
	    return(1 + (getNodeNum(tree->left) + getNodeNum(tree->right)));
    }
}

template<class dataType>
int BTree<dataType>::getLeafNum(const std::shared_ptr<node> &tree) const
{
    if(tree == nullptr)
	return(0);
    else
    {
	if(tree->left == nullptr && tree->right == nullptr)
	    return(1);
	else
	    return(getLeafNum(tree->left) + getLeafNum(tree->right));
    }
}

template<class dataType>
void BTree<dataType>::printTree(const std::shared_ptr<node> &refTree) const
{
    if(refTree != nullptr)
    {
	std::cout << "  " << refTree->info << std::endl;
	std::cout << " / " << std::endl;
	printTree(refTree->left);
	std::cout << " \\" << std::endl;
	printTree(refTree->right);	
    }
    else
    {
	std::cout << "-" << std::endl;
    }
}

#endif
