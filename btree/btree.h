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
		  * TODO: Is a reference more appropriate? Tree could be large.
		*/
		void copyTree(node*& newTree, const node* oldTree);
	
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
		  * TODO: Replace this with <math> max() or something.
		*/
		int max(int x, int y) const;

		/**
		 * Recursively prints out Binary Tree to std out.
		 * Private.
		 * */
		void printTree(const node* refTree) const;
	
	public:

		/**
		  * Default constructor.
		  * Prevents implicit conversion.
		*/
		explicit BTree();	
	
		/**
		  * Copy constructor. 
		  * Not allowing for implicit conversion.
		*/
		explicit BTree(const BTree<dataType>& refTree);
		
		/**
		  * Destructor. 
		  * Public.
		*/
		~BTree();
		
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

		/**
		 * Prints out the contents of a tree.
		 * Assumes that the datatype is able to be handed by cout.
		 * Could be pretty readily broken and is mainly used to debug.
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
		  * Public.
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

/** Templated Function Definitions */

/** Private */

/**
  * Copy a tree.
  * Called by copy constructor.
  * Used recursively on left and right sub tree.
  * Private.
  * TODO: Is a reference more appropriate? Tree could be large.
*/
template<class dataType>
void BTree<dataType>::copyTree(node*& newTree, const node* oldTree)
{
	std::cout << "Value of newTree aka root: " << newTree << std::endl;

	if(oldTree == nullptr)
	{
		newTree = nullptr;
		std::cout << "Old tree node is null so new tree node is null: " << std::endl;
	}
	else // not null
	{
		std::cout << "Old tree node is allocd so new tree node is allocd: " << std::endl;
		std::cout << "newTree prior to alloc: " << &root << " " << root << std::endl;
		std::cout << "new: " << new node(oldTree->info);
		newTree = new node(oldTree->info);
	       	copyTree(newTree->left, oldTree->left);
		copyTree(newTree->right, oldTree->right);
		std::cout << "newTree post alloc: " << &root << " " << root << std::endl;
	}
}

/**
  * Destroys tree. Recursively called.
  * Private.
*/
template<class dataType>
void BTree<dataType>::destroyTree(node* p)
{
	if(p != nullptr)
	{
		destroyTree(p->left);
		
		destroyTree(p->right);
		
		delete(p);
		
		p = nullptr;
		
	}
}

/**
  * Recursively counts height of binary tree.
  * Returns max of left and right.
  * Private.
  * TODO: Remove max() local func for math lib?
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

/**
  * Returns the maximum of 2 values.
  * Once again just following the book but why wouldn't an STL call be invoked.
  * TODO: Replace this with <math> max() or something.
*/
template<class dataType>
int BTree<dataType>::max(int x, int y) const
{
	if(x >= y)
		return(x);
	else
		return(y);
}

/**
 * Recursively prints out Binary Tree to std out.
 * Private.
 * */
template<class dataType>
void BTree<dataType>::printTree(const node* refTree) const
{
	if(refTree != nullptr)
	{
		std::cout << refTree->info << std::endl;
		std::cout << "/ " << std::endl;
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

/**
  * Copy constructor. 
  * Not allowing for implicit conversion.
  * Public.
*/
template<class dataType>
BTree<dataType>::BTree(const BTree<dataType>& refTree)
{
	std::cout << "root: " << root << " " << &root << std::endl;

	if(refTree.root == nullptr)
	{
		root = nullptr;
		std::cout << "\nrefTree.root is null." << std::endl;
	}
	else
	{
		std::cout << "Root before copy: " << &root << " " << root << std::endl;
		copyTree(root, refTree.root);
		std::cout << "Root after copy: " << &root << " " << root << std::endl;
	}
}

/**
  * Destructor. 
  * Public.
  * TODO: Finish this?
*/
template<class dataType>
BTree<dataType>::~BTree()
{
	destroyTree();
}

/**
  * Overloaded = operator.
  * Invokes copy constructor.
  * Public.
*/
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

/**
  * Returns true if empty, false if filled.
  * Public.
*/
template<class dataType>
bool BTree<dataType>::isEmpty() const
{
	return(root == nullptr); // 1/true if null 0/false if not null
}

/**
  * Returns height of binary tree.
  * Recursively calls height();
  * Public.
*/
template<class dataType>
int BTree<dataType>::getHeight() const
{
	return(getHeight(root));
}

/**
 * Prints out the contents of a tree.
 * Assumes that the datatype is able to be handed by cout.
 * Could be pretty readily broken and is mainly used to debug.
 * Public.
 *
 * */
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

/**
  * De-allocates tree.
  * Invoked by the destructor.
  * Public.
*/
template<class dataType>
void BTree<dataType>::destroyTree()
{
	if(root != nullptr)
		destroyTree(root);
}

/**
  * Binary Search.
  * Returns true if data is located in tree. False otherwise.
  * Public.
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
  * Done.
*/
template<class dataType>
void BTree<dataType>::insert(const dataType& insertData)
{
	node* current;
	node* trailCurrent;
	node* newNode;
	
	newNode = new node(insertData);

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
  * Public.
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

#endif
