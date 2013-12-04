#ifndef btree_h
#define btree_h

template <class dataType>
class BTree
{
	public:

		/**
		  * Default constructor.
		  * Prevents implicit conversion.
		  * Done.
		*/
		explicit BTree();	
	
		/**
		  * Destructor. Should this call destroyTree()? Or implement it here.
		  * Done.
		*/
		~BTree();

		/**
		  * Copy constructor for tree. Not allowing for implicit conversion.
		  * Done.
		*/
		explicit BTree(const BTree<dataType>& copyTree);

		/**
		  * Overloaded = operator.
		  * Invokes copy constructor.
		  * Done.
		*/
		const BTree<dataType>& operator= (const BTree<dataType>& otherTree);

		/**
		  * Returns true if empty, false if filled.
		  * Done.
		*/
		bool isEmpty() const;

		/**
		  * Returns height of binary tree.
		  * Recursively calls height();
		  * Done.
		*/
		int getHeight();

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
		
	private:

		/**
		  * Tree structure.
		*/
		struct node
		{
			dataType info;
			node* left;
			node* right;
		};

		/**
		  * Head of tree.
		  * Points to the info it contains and the left and right links.
		*/
		node* root;

		/**
		  * Copy a tree.
		  * Called by copy constructor?
		  * Should this just be in copy constructor?
		  * Why is one a pointer reference and one a pointer?
		  * Should they not both be references?
		*/
		void copyTree(node* &newTree, const node* oldTree);
	
		/**
		  * Destroys tree. Recursively called.
		  * Should this be in destructor?
		*/
		void destroyTree(node* &p);

		/**
		  * Recursively counts height of binary tree.
		  * Returns max of left and right.
		*/
		int getHeight(node* p) const;

		/**
		  * Returns the maximum of 2 values.
		  * Once again just following the book but why wouldn't an STL call be invoked.
		*/
		int max(int x, int y) const;

		/**
		  * Recursively counts the amount of nodes.
		*/
		//int getNodeNum(node* p) const;

		/**
		  * Recursively counts the amount of leaves.
		*/
	//	int getLeafNum(node* p) const;
};

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
BTree<dataType>::BTree(const BTree<dataType>& copyTree)
{
	if(copyTree.root == nullptr)
		root = nullptr;
	else
		copyTree(root, copyTree.root);
}

/**
  * Overloaded = operator.
  * Invokes copy constructor.
*/
template<class dataType>
const BTree<dataType>& BTree<dataType>::operator=(const BTree<dataType>& otherTree)
{
	if(this != &otherTree)
	{
		if(root != nullptr)
			destroy(root);
		if(otherTree.root = nullptr)
			root = nullptr;
		else
			copyTree(root, otherTree.root);
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
int BTree<dataType>::getHeight()
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
		return(false);
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
  * Copy a tree.
  * Called by copy constructor?
  * Should this just be in copy constructor?
*/
template<class dataType>
void BTree<dataType>::copyTree(node* &newTree, const node* oldTree)
{
	if(oldTree == nullptr)
		newTree = nullptr;
	else
	{
		newTree = new node;
		newTree->info = oldTree->info;
		copyTree(newTree->left, oldTree->left);
		copyTree(newTree->right, oldTree->right);
	}
}

/**
  * Destroys tree. Recursively called.
  * Should this be in destructor?
*/
template<class dataType>
void BTree<dataType>::destroyTree(node* &p)
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
		return( (max(height(p->left)), getHeight(p->right)) + 1);
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
