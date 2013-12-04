#include "btree.h"
#include <gtest/gtest.h>

int main(int argc, char** argv)
{
	return(RUN_ALL_TESTS());
}
		/**
		  * Default constructor.
		  * Prevents implicit conversion.
		  * Done.
		explicit BTree();	
	
		  * Destructor. Should this call destroyTree()? Or implement it here.
		  * Done.
		~BTree();

		  * Copy constructor for tree. Not allowing for implicit conversion.
		  * Done.
		explicit BTree(const BTree<dataType>& copyTree);

		  * Overloaded = operator.
		  * Invokes copy constructor.
		  * Done.
		const BTree<dataType>& operator= (const BTree<dataType>& otherTree);

		  * Returns true if empty, false if filled.
		  * Done.
		bool isEmpty() const;

		  * Returns height of binary tree.
		  * Recursively calls height();
		  * Done.
		int getHeight();

		  * Get amount of nodes in the tree.
		  * Done.
	//	int getNodeNum();

		  * Return amount of leaves in the tree.
		  * Done.
	//	int getLeafNum();

		  * De-allocates tree.
		  * Should this be in the destructor? Or invoked by the destructor?
		  * Done.
		void destroyTree();

		  * Returns true if data is located in tree. False otherwise.
		  * What type of search? O(n)? O(log n)?
		  * Done.
		bool search(const dataType& searchData) const;

		  * Inserts data into tree.
		void insert(const dataType& insertData);
	
		  * Deletes a node with the same dataType as deleteItem.
		void deleteNode(const dataType& deleteItem);
		
		  * Tree structure.
		struct node
		{
			dataType info;
			node* left;
			node* right;
		};

		  * Head of tree.
		  * Points to the info it contains and the left and right links.
		node* root;

		  * Copy a tree.
		  * Called by copy constructor?
		  * Should this just be in copy constructor?
		  * Why is one a pointer reference and one a pointer?
		  * Should they not both be references?
		void copyTree(node* &newTree, const node* oldTree);
	
		  * Destroys tree. Recursively called.
		  * Should this be in destructor?
		void destroyTree(node* &p);

		  * Recursively counts height of binary tree.
		  * Returns max of left and right.
		int getHeight(node* p) const;

		  * Returns the maximum of 2 values.
		  * Once again just following the book but why wouldn't an STL call be invoked.
		int max(int x, int y) const;

		  * Recursively counts the amount of nodes.
		//int getNodeNum(node* p) const;

		  * Recursively counts the amount of leaves.
	//	int getLeafNum(node* p) const; */
