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
		const binaryTreeType<dataType>& operator= (const BTree<dataType>&);

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
		virtual bool search(const dataType& searchData) const = 0;

		/**
		  * Inserts data into tree.
		*/
		virtual void insert(const dataType& insertData) const = 0;
	
		/**
		  * Deletes a node with the same dataType as deleteItem.
		*/	
		virtual void deleteNode(const dataType& deleteItem) = 0;
		
	private:

		/**
		  * Head of tree.
		  * Points to the info it contains and the left and right links.
		*/
		node<dataType> *root;

		/**
		  * Copy a tree.
		  * Called by copy constructor?
		  * Should this just be in copy constructor?
		*/
		void copyTree(node<dataType>* &newTree, const node<dataType>* &oldTree);
	
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
		  * Recursively counts the amount of nodes.
		*/
		int getNodeNum(node<dataType>* p) const;

		/**
		  * Recursively counts the amount of leaves.
		*/
		int getLeafNum(node<dataType>* p) const;

		/**
		  * Tree structure.
		*/
		struct node
		{
			dataType info;
			node<dataType>* left;
			node<dataType>* right;
		};
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
}

/**
  * Overloaded = operator.
  * Invokes copy constructor.
*/
template<class dataType>
const BTree<dataType>::binaryTreeType<dataType>& operator= (const BTree<dataType>&)
{
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
}

/**
  * Get amount of nodes in the tree.
*/	
template<class dataType>
int BTree<dataType>::getNodeNum()
{
}

/**
  * Return amount of leaves in the tree.
*/
template<class dataType>
int BTree<dataType>::getLeafNum()
{
}

/**
  * De-allocates tree.
  * Should this be in the destructor? Or invoked by the destructor?
*/
template<class dataType>
void BTree<dataType>::destroyTree()
{
}

/**
  * Returns true if data is located in tree. False otherwise.
*/
template<class dataType>
virtual bool BTree<dataType>::search(const dataType& searchData) const = 0;

/**
  * Inserts data into tree.
*/
template<class dataType>
virtual void BTree<dataType>::insert(const dataType& insertData) const = 0;

/**
  * Deletes a node with the same dataType as deleteItem.
*/	
template<class dataType>
virtual void BTree<dataType>::deleteNode(const dataType& deleteItem) = 0;

/**
  * Copy a tree.
  * Called by copy constructor?
  * Should this just be in copy constructor?
*/
void BTree<dataTye>::copyTree(node<dataType>* &newTree, const node<dataType>* &oldTree)
{
}

/**
  * Destroys tree. Recursively called.
  * Should this be in destructor?
*/
void BTree<dataType>::destroyTree(node<dataType>* &p)
{
}

/**
  * Recursively counts height of binary tree.
  * Returns max of left and right.
*/
int BTree<dataType>::getHeight(node<dataType>* p) const
{
}

/**
  * Recursively counts the amount of nodes.
*/
int BTree<dataType>::getNodeNum(node<dataType>* p) const
{
}

/**
  * Recursively counts the amount of leaves.
*/
int BTree<dataType>::getLeafNum(node<dataType>* p) const
{
}

#endif
