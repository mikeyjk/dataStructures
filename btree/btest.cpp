#include "btree.h"
#include <gtest/gtest.h>

// functions to check:
//
// default ctor done
// copy ctor done
// operator= done
// isEmpty() done
// getHeight() done
// getNodeNum() done
// getLeafNum() done
// search() done
// insert() done

// default constructor
TEST(IsEmpty, Initial)
{
	BTree<int>* emptIntTree = new BTree<int>();
	BTree<double>* emptDoubTree = new BTree<double>();

	// make sure newly constructed trees are al empty
	EXPECT_EQ(true, emptIntTree->isEmpty());
	EXPECT_EQ(true, emptDoubTree->isEmpty());

	delete emptIntTree;
	delete emptDoubTree;
}

// copy cstror
TEST(CopyConstruct, Initial)
{
	// empty tree
	BTree<int> original;

	// search for int 2, shouldn't exist
	EXPECT_EQ(false, original.search(2)); 
	
	// insert int 2
	original.insert(2);

	// search for int 2, should exist
	EXPECT_EQ(true, original.search(2));

	//original.printTree();

	// btree using copy constructor
	BTree<int> copied{original};

	// search for 2, should be true
	EXPECT_EQ(true, copied.search(2));	

	//copied.printTree();
}

// equals operator
TEST(EqOp, Initial)
{
	// empty tree
	BTree<int> original;

	// search for int 2, shouldn't exist
	EXPECT_EQ(false, original.search(2)); 
	
	// insert int 2
	original.insert(2);

	// search for int 2, should exist
	EXPECT_EQ(true, original.search(2));

	//original.printTree();

	// btree using copy constructor
	BTree<int> copied;
	
	copied = original;

	// search for 2, should be true
	EXPECT_EQ(true, copied.search(2));	

	//copied.printTree();
}

// insert an element and be able to find it
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

// getHeight
TEST(GetHeight, Number)
{
	BTree<int>* test = new BTree<int>();
	
	// just created, height should be 0
	EXPECT_EQ(0, test->getHeight());

	// 0 -> 1000, 1001 total
	// store non-linearly
	for(int i = 0; i < 1000; ++i)
	{
	    if(i % 2 == 0)
		test->insert(i/2);
	    else
		test->insert(i);
	}

	EXPECT_EQ(501, test->getHeight());
	
	//test->printTree();

	// this is an example of a bstree
	// devolving into a linked list:

	//for(int i = 0; i < 1000; ++i)
	//{
	//    test->insert(i);
	//}

	// height should be 1001
	//EXPECT_EQ(998, test->getHeight());

	delete test;
}
// get node num
TEST(nodeNum, Number)
{
	BTree<int>* test = new BTree<int>();
	
	// just created, height should be 0
	EXPECT_EQ(0, test->getNodeNum());

	// 0 -> 1000, 1001 total
	// store non-linearly
	for(int i = 0; i < 1000; ++i)
	{
	    if(i % 2 == 0)
		test->insert(i/2);
	    else
		test->insert(i);
	}

	EXPECT_EQ(750, test->getNodeNum());
	
	//test->printTree();

	// this is an example of a bstree
	// devolving into a linked list:

	//for(int i = 0; i < 1000; ++i)
	//{
	//    test->insert(i);
	//}

	// height should be 1001
	//EXPECT_EQ(998, test->getHeight());

	delete test;
}

// get leaf num
TEST(leafNum, Number)
{
	BTree<int>* test = new BTree<int>();
	
	// just created, height should be 0
	EXPECT_EQ(0, test->getLeafNum());

	// 0 -> 1000, 1001 total
	// store non-linearly
	for(int i = 0; i < 1000; ++i)
	{
	    if(i % 2 == 0)
		test->insert(i/2);
	    else
		test->insert(i);
	}

	EXPECT_EQ(250, test->getLeafNum());
	
	//test->printTree();

	// this is an example of a bstree
	// devolving into a linked list:

	//for(int i = 0; i < 1000; ++i)
	//{
	//    test->insert(i);
	//}

	// height should be 1001
	//EXPECT_EQ(998, test->getHeight());

	delete test;
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
