#ifndef btree_h
#define btree_h

template <class dataType>
class BTree
{
	public:

		/**
		  * Default constructor.
		  * Prevents implicit conversion.
		*/
		explicit BTree();	
	
		/**
		  * Destructor. Should this call destroyTree()? Or implement it here.
		*/
		~BTree();

		/**
		  * Copy constructor for tree. Not allowing for implicit conversion.
		*/
		explicit BTree(const BTree<dataType>& copyTree);

		/**
		  * Overloaded = operator.
		  * Invokes copy constructor.
		*/
		const BTree<dataType>& operator= (const BTree<dataType>& otherTree);

		/**
		  * Returns true if empty, false if filled.
		*/
		bool isEmpty() const;

		/**
		  * Returns height of binary tree.
		  * Recursively calls height();
		*/
		int getHeight();

		/**
		  * Get amount of nodes in the tree.
		*/	
		int getNodeNum();

		/**
		  * Return amount of leaves in the tree.
		*/
		int getLeafNum();

		/**
		  * De-allocates tree.
		  * Should this be in the destructor? Or invoked by the destructor?
		*/
		void destroyTree();

		/**
		  * Returns true if data is located in tree. False otherwise.
		*/
		bool search(const dataType& searchData) const;

		/**
		  * Inserts data into tree.
		*/
		void insert(const dataType& insertData);
	
		/**
		  * Deletes a node with the same dataType as deleteItem.
		*/	
		void deleteNode(const dataType& deleteItem);
		
	private:

		/**
		  * Tree structure.
		*/
		template<class dataType>
		struct node
		{
			dataType info;
			node<dataType>* left;
			node<dataType>* right;
		};

		/**
		  * Head of tree.
		  * Points to the info it contains and the left and right links.
		*/
		node<dataType> *root;

		/**
		  * Copy a tree.
		  * Called by copy constructor?
		  * Should this just be in copy constructor?
		  * Why is one a pointer reference and one a pointer?
		  * Should they not both be references?
		*/
		void copyTree(node<dataType>* &newTree, const node<dataType>* oldTree);
	
		/**
		  * Destroys tree. Recursively called.
		  * Should this be in destructor?
		*/
		void destroyTree(node<dataType>* &p);

		/**
		  * Recursively counts height of binary tree.
		  * Returns max of left and right.
		*/
		int getHeight(node<dataType>* p) const;

		/**
		  * Returns the maximum of 2 values.
		  * Once again just following the book but why wouldn't an STL call be invoked.
		*/
		int max(int x, int y) const;

		/**
		  * Recursively counts the amount of nodes.
		*/
		int getNodeNum(node<dataType>* p) const;

		/**
		  * Recursively counts the amount of leaves.
		*/
		int getLeafNum(node<dataType>* p) const;

}

/** Templated Function Definitions */

/**
  * Default constructor.
  * Prevents implicit conversion.
*/
template<class dataType>
explicit BTree<dataType>:BTree()	
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
explicit BTree<dataType>::BTree(const BTree<dataType>& copyTree)
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
const BTree<dataType>::binaryTreeType<dataType>& operator= (const BTree<dataType>& otherTree)
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
*/	
template<class dataType>
int BTree<dataType>::getNodeNum()
{
	return(getNodeNum(root));
}

/**
  * Return amount of leaves in the tree.
*/
template<class dataType>
int BTree<dataType>::getLeafNum()
{
	return(getLeafNum(root));
}

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
	node<dataType>* current;

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
void BTree<dataType>::insert(const dataType& insertData) const
{
	node<dataType>* current;
	node<dataType>* trailCurrent;
	node<dataType>* newNode;
	
	newNode = new node<dataType>;
	newNode->info = insertData;
	newNode->left = nullptr;
	newNode->right = nullptr;

	if(root == nullptr)
		root = node;
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
	node<dataType>* current;
	node<dataType>* trailCurrent;
	node<dataType>* temp;

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
void BTree<dataTye>::copyTree(node<dataType>* &newTree, const node<dataType>* oldTree)
{
	if(oldTree == nullptr)
		newTree = nullptr;
	else
	{
		newTree = new node<dataType>
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
void BTree<dataType>::destroyTree(node<dataType>* &p)
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
int BTree<dataType>::getHeight(node<dataType>* p) const
{
	if(p == nullptr)
		return(0);
	else
		return( (max(height(p->left)), getHeight(p->right)) + 1);
}

/**
  * Recursively counts the amount of nodes.
*/
template<class dataType>
int BTree<dataType>::getNodeNum(node<dataType>* p) const
{
}

/**
  * Recursively counts the amount of leaves.
*/
template<class dataType>
int BTree<dataType>::getLeafNum(node<dataType>* p) const
{
}

template<class dataType>
int BTree<dataType>::max(int x, int y) const
{
	if(x >= y)
		return(x);
	else
		return(y);
}


#endif
