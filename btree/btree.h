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
  *	  - destructor, copy ctr, move ctr, copy assignment operator, 
  *	  move assignment operator.
  *	  
  *	  UPDATE PTRS TO REFS
  *
  * Notes: C++ passes pointers by value unless an ampersand is used to denote pass
  * by reference.
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

			// default constructor
			// forces inserts to be data-centric and without children
			node(const dataType& data) 
			: info(data), left(nullptr), right(nullptr) {}
		};

		/**
		  * Head of tree.
		*/
		node* root;

		/**
		  * Copy a tree.
		  * Called by copy constructor.
		  * Used recursively on left and right sub tree.
		  * Non const function as it alters newTree.
		  * @newTree - node pointer reference.
		  * @oldTree - const node pointer to a const node reference.
		*/
		void copyTree(node*& newTree, const node* const &oldTree);
	
		/**
		  * Destroys tree. Recursively called.
		  * Non const function as it alters tree.
		  * @tree - node pointer reference. non const as this is altered.
		*/
		void destroyTree(node* &tree);

		/**
		  * Recursively counts height of binary tree.
		  * Returns max of left and right.
		  * Const function as it does not alter any data.
		  * @tree - const node pointer to a const node reference.
		  *
		*/
		int getHeight(const node* const &tree) const;

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

		/**
		  * Returns the maximum of 2 values.
		  * Once again just following the book but why wouldn't an STL call be invoked.
		  * Const function as it does not alter any data.
		  * TODO: Replace this with <math> max() or something.
		*/
		int max(int x, int y) const;

		/**
		 * Recursively prints out Binary Tree to std out.
		 * Private.
		 * Const function as it does not alter any data.
		 * @tree - const node pointer to const node reference.
		 * */
		void printTree(const node* const &tree) const;
	
	public:

		/**
		  * Default constructor.
		  * Prevents implicit conversion.
		*/
		explicit BTree();	
	
		/**
		  * Copy constructor. 
		  * Prevents implicit conversion.
		  * @tree - const templated tree reference.
		*/
		explicit BTree(const BTree<dataType>& tree);
		
		/**
		  * Destructor. 
		*/
		~BTree();
		
		/**
		  * Overloaded = operator.
		  * Invokes copy constructor.
		  * @rVal - const templated tree reference.
		*/
		const BTree<dataType>& operator=(const BTree<dataType>& rVal);

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
		*/	
	//	int getNodeNum();

		/**
		  * Return amount of leaves in the tree.
		*/
	//	int getLeafNum();

		/**
		  * De-allocates tree.
		  * Invoked by the destructor.
		*/
		void destroyTree();

		/**
		  * Binary Search.
		  * Returns true if data is located in tree. False otherwise.
		  * Const as function does not alter tree.
		  * @treeInfo - const dataType reference.
		*/
		bool search(const dataType& treeInfo) const;

		/**
		  * Inserts data into tree.
		  * @treeInfo - const dataType reference. not modifiable.
		  * Non const as function alters tree.
		*/
		void insert(const dataType& treeInfo);
	
		/**
		  * Deletes a node with the same dataType as deleteItem.
		  * @treeInfo - const dataType reference. not modifiable.
		  * Non const as function alters tree.
		*/	
		void deleteNode(const dataType& deleteItem);
		
};

/** Templated Function Definitions */

/** Private */

template<class dataType>
void BTree<dataType>::copyTree(node*& newTree, const node* const &oldTree)
{
	if(oldTree == nullptr)
	{
		newTree = nullptr;
	}
	else // not null
	{
		newTree = new node(oldTree->info);
	       	copyTree(newTree->left, oldTree->left);
		copyTree(newTree->right, oldTree->right);
	}
}

template<class dataType>
void BTree<dataType>::destroyTree(node* &tree)
{
	if(tree != nullptr)
	{
		destroyTree(tree->left);
		
		destroyTree(tree->right);
		
		delete(tree);
		
		tree = nullptr;
		
	}
}

template<class dataType>
int BTree<dataType>::getHeight(const node* const &tree) const
{
	if(tree == nullptr)
		return(0);
	else
		return( (max(getHeight(tree->left), getHeight(tree->right)) + 1));
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

template<class dataType>
void BTree<dataType>::printTree(const node* const &refTree) const
{
	if(refTree != nullptr)
	{
		std::cout << refTree->info << std::endl;
		std::cout << " / " << std::endl;
		printTree(refTree->left);
		std::cout << " \\" << std::endl;
		printTree(refTree->right);	
	}
	else
	{
		std::cout << "Null." << std::endl;
	}
}

/** Public */

template<class dataType>
BTree<dataType>::BTree()	
{
	root = nullptr;
}

template<class dataType>
BTree<dataType>::BTree(const BTree<dataType>& refTree)
{
	if(refTree.root == nullptr)
		root = nullptr;
	else
		copyTree(root, refTree.root);
}

template<class dataType>
BTree<dataType>::~BTree()
{
	destroyTree();
}

template<class dataType>
const BTree<dataType>& BTree<dataType>::operator=(const BTree<dataType>& rVal)
{
	if(this != &rVal) // if they don't match, otherwise we automatically have achieved our goal
	{
		if(root != nullptr) // if root isn't null
		{
			destroyTree(root); // clear it / make it null
			root = nullptr;
		}

		if(rVal.root != nullptr) // if rvalue is null
			copyTree(&root, rVal.root);
	}

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

template<class dataType>
void BTree<dataType>::destroyTree()
{
	if(root != nullptr)
		destroyTree(root);
}

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

template<class dataType>
void BTree<dataType>::insert(const dataType& treeInfo)
{
	node* current;
	node* trailCurrent;
	node* newNode;
	
	newNode = new node(treeInfo);

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
			
			if(current->info == treeInfo)
				return;
			else if(current->info > treeInfo)
				current = current->left;
			else
				current = current->right;
		}
	
		if(trailCurrent->info > treeInfo)
			trailCurrent->left = newNode;
		else
			trailCurrent->right = newNode;
	}
}

/**
 * TODO: Pretttyyy sure this is broken. How can I derference a templated type.
 * Clearly this is meant to be a node.
 * */
template<class dataType>
void BTree<dataType>::deleteNode(const dataType &deleteItem)
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

#endif
