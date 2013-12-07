#include "btree.h"
#include <gtest/gtest.h>

TEST(Construct, Initial)
{
	BTree<int>* test = new BTree<int>();

	EXPECT_EQ(true, test->isEmpty());

	delete test;
}

TEST(InsertSearch, Number)
{
	BTree<int>* test = new BTree<int>();
	// empty tree

	// search for int 2, shouldn't exist
	EXPECT_EQ(false, test->search(2)); 
	
	// insert int 2
	test->insert(2);

	// search for int 2, should exist
	EXPECT_EQ(true, test->search(2));
	
	delete test;
}

TEST(GetHeight, Number)
{
	BTree<int>* test = new BTree<int>();
	
	EXPECT_EQ(0, test->getHeight());

	test->insert(2);

	EXPECT_EQ(1, test->getHeight());

	delete test;
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
		/**
		  * Overloaded = operator.
		  * Invokes copy constructor.
		  * Done.
		const BTree<dataType>& operator= (const BTree<dataType>& otherTree);

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
