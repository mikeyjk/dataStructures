#ifndef btree_h
#define btree_h

#include <iostream>

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
  * Left & Right sub-tree are also BSTrees.
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
  *	  - destructor, copy ctr, move ctr, copy assignment operator, move assignment operator
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
			node* left;
			node* right;
		};

		void printTree(node*& tree) const;
	
		/**
		  * Head of tree.
		*/
		node* root;

		/**
		  * Copy a tree.
		  * Called by copy constructor.
		  * Used recursively on left and right sub tree.
		  * TODO: Is a reference more appropriate? Tree could be large.
		*/
		void copyTree(node* newTree, const node*& oldTree);
	
		/**
		  * Destroys tree. Recursively called.
		*/
		void destroyTree(node* p);

		/**
		  * Recursively counts height of binary tree.
		  * Returns max of left and right.
		*/
		int getHeight(node* p) const;

		/**
		  * Returns the maximum of 2 values.
		  * Once again just following the book but why wouldn't an STL call be invoked.
		  * TODO: Replace this with <math> max() or something.
		*/
		int max(int x, int y) const;

		/**
		  * Recursively counts the amount of nodes.
		  * TODO: This.
		*/
		//int getNodeNum(node* p) const;

		/**
		  * Recursively counts the amount of leaves.
		  * TODO: This.
		*/
	//	int getLeafNum(node* p) const;
	
	public:

		/**
		  * Default constructor.
		  * Prevents implicit conversion.
		*/
		explicit BTree();	
	
		/**
		  * Destructor. 
		*/
		~BTree();

		/**
		  * Copy constructor. 
		  * Not allowing for implicit conversion.
		*/
		explicit BTree(const node& refTree);

		/**
		  * Overloaded = operator.
		  * Invokes copy constructor.
		  * TODO: Broken due to reference usage?
		*/
		const BTree<dataType>& operator= (const BTree<dataType>& rVal);

		/**
		  * Returns true if empty, false if filled.
		*/
		bool isEmpty() const;

		/**
		  * Returns height of binary tree.
		  * Recursively calls height();
		*/
		int getHeight() const;

		void printTree() const;
		
		/**
		  * Get amount of nodes in the tree.
		*/	
	//	int getNodeNum();

		/**
		  * Return amount of leaves in the tree.
		*/
	//	int getLeafNum();

		/**
		  * De-allocates tree.
		  * Should this be in the destructor? Or invoked by the destructor?
		  * Done.
		*/
		void destroyTree();

		/**
		  * Returns true if data is located in tree. False otherwise.
		  * What type of search? O(n)? O(log n)?
		  * Done.
		*/
		bool search(const dataType& searchData) const;

		/**
		  * Inserts data into tree.
		  * Done.
		*/
		void insert(const dataType& insertData);
	
		/**
		  * Deletes a node with the same dataType as deleteItem.
		  * Done.
		*/	
		void deleteNode(const dataType& deleteItem);
		
};

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
		std::cout << "\nroot is null.";
	}
}

template<class dataType>
void BTree<dataType>::printTree(node*& tree) const
{
	if(tree != nullptr)
	{
		std::cout << tree->info << std::endl;
		printTree(tree->left);
		printTree(tree->right);	
	}
	else
	{
		std::cout << "\nnode is null.";
	}
}

/** Templated Function Definitions */

/**
  * Default constructor.
  * Prevents implicit conversion.
*/
template<class dataType>
BTree<dataType>::BTree()	
{
	root = nullptr;
}

/**
  * Destructor. Should this call destroyTree()? Or implement it here.
*/
template<class dataType>
BTree<dataType>::~BTree()
{
}

/**
  * Copy constructor for tree. Not allowing for implicit conversion.
*/
template<class dataType>
BTree<dataType>::BTree(const node& refTree)
{	
	if(refTree == nullptr)
	{
		root = nullptr;
		std::cout << "\ntree to copy is null." << std::endl;
	}
	else
	{
		copyTree(root, refTree);
	}
}

/**
  * Copy a tree.
  * Called by copy constructor?
  * Should this just be in copy constructor?
*/
template<class dataType>
void BTree<dataType>::copyTree(node* newTree, const node*& oldTree)
{
	if(oldTree == nullptr)
	{
		newTree = nullptr;
		std::cout << "\noldTree: " << oldTree << std::endl;
		std::cout << "\nOld tree is null so new tree is null: " << std::endl;
	}
	else
	{
		newTree = new node();
		newTree->info = oldTree->info;
		std::cout << "\nnewtree%: " << newTree << std::endl;
		std::cout << "\nnewtreeinfo: " << newTree->info << std::endl;
		std::cout << "\noldtreeinfo: " << oldTree->info << std::endl;
		copyTree(newTree->left, oldTree->left);
		copyTree(newTree->right, oldTree->right);
	}

	std::cout << "\nnewTree out of if else: " << newTree;
}

/**
  * Overloaded = operator.
  * Invokes copy constructor.
*/
template<class dataType>
const BTree<dataType>& BTree<dataType>::operator=(const BTree<dataType>& rVal)
{
	if(this != &rVal)
	{
		if(root != nullptr)
			destroy(root);
		if(rVal.root = nullptr)
			root = nullptr;
		else
			copyTree(root, rVal.root);
	}

	return(*this);
}

/**
  * Returns true if empty, false if filled.
*/
template<class dataType>
bool BTree<dataType>::isEmpty() const
{
	return(root == nullptr); // 1/true if null 0/false if not null
}

/**
  * Returns height of binary tree.
  * Recursively calls height();
*/
template<class dataType>
int BTree<dataType>::getHeight() const
{
	return(getHeight(root));
}

/**
  * Get amount of nodes in the tree.
template<class dataType>
int BTree<dataType>::getNodeNum()
{
	return(getNodeNum(root));
}*/

/**
  * Return amount of leaves in the tree.
template<class dataType>
int BTree<dataType>::getLeafNum()
{
	return(getLeafNum(root));
}*/

/**
  * De-allocates tree.
  * Should this be in the destructor? Or invoked by the destructor?
*/
template<class dataType>
void BTree<dataType>::destroyTree()
{
	destroyTree(root);
}

/**
  * Returns true if data is located in tree. False otherwise.
*/
template<class dataType>
bool BTree<dataType>::search(const dataType& searchData) const
{
	node* current;

	bool found = false;

	if(root == nullptr)
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
		}
	}

	return(found);
}

/**
  * Inserts data into tree.
*/
template<class dataType>
void BTree<dataType>::insert(const dataType& insertData)
{
	node* current;
	node* trailCurrent;
	node* newNode;
	
	newNode = new node();
	newNode->info = insertData;
	newNode->left = nullptr;
	newNode->right = nullptr;

	if(root == nullptr)
	{
		root = newNode; 
	}
	else
	{
		current = root;
		
		while(current != nullptr)
		{
			trailCurrent = current;
			
			if(current->info == insertData)
				return;
			else if(current->info > insertData)
				current = current->left;
			else
				current = current->right;
		}
	
		if(trailCurrent->info > insertData)
			trailCurrent->left = newNode;
		else
			trailCurrent->right = newNode;
	}
}

/**
  * Deletes a node with the same dataType as deleteItem.
*/	
template<class dataType>
void BTree<dataType>::deleteNode(const dataType& deleteItem)
{
	node* current;
	node* trailCurrent;
	node* temp;

	if(deleteItem == nullptr)
		return;
	else if(deleteItem->left == nullptr && deleteItem->right == nullptr)
	{
		temp = deleteItem;
		deleteItem = nullptr;
		delete temp;
	}
	else if(deleteItem->left == nullptr)
	{
		temp = deleteItem;
		deleteItem = temp->right;
		delete temp;
	}
	else if(deleteItem->right == nullptr)
	{
		temp = deleteItem;
		deleteItem = temp->left;
		delete temp;
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

		if(trailCurrent = nullptr)
			deleteItem->left = current->left;
		else
			trailCurrent->right = current->left;

		delete current;
	}
}

/**
  * Destroys tree. Recursively called.
  * Should this be in destructor?
*/
template<class dataType>
void BTree<dataType>::destroyTree(node* p)
{
	if(p != nullptr)
	{
		destroy(p->left);
		destroy(p->right);
		delete(p);
		p = nullptr;
	}
}

/**
  * Recursively counts height of binary tree.
  * Returns max of left and right.
  * Why not just use math lib for max rather than invoking a private func??
*/
template<class dataType>
int BTree<dataType>::getHeight(node* p) const
{
	if(p == nullptr)
		return(0);
	else
		return( (max(getHeight(p->left), getHeight(p->right)) + 1));
}

/**
  * Recursively counts the amount of nodes.
template<class dataType>
int BTree<dataType>::getNodeNum(node* p) const
{
}*/

/**
  * Recursively counts the amount of leaves.
template<class dataType>
int BTree<dataType>::getLeafNum(node* p) const
{
}*/

template<class dataType>
int BTree<dataType>::max(int x, int y) const
{
	if(x >= y)
		return(x);
	else
		return(y);
}


#endif
