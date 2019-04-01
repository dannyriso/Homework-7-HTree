// test_hforest.cc contains the code needed to test all the methods of hforest.

#include "hforest.cc"

int main() {
	// Test constructors
	HForest forest1 = HForest();
	// Building HTrees to put into HForests
	HTree tree1 = HTree(1, 2);
	HTree tree2 = HTree(2, 4);
	HTree tree3 = HTree(3, 6, tree1.point(), tree2.point());
	HTree tree4 = HTree(4, 8);
	HTree tree5 = HTree(5, 10);
	HTree tree6 = HTree(6, 12, tree4.point(), tree5.point());
	HForest::htree_vec vector = {tree3.point(), tree6.point()};
	HForest::htree_vec vector_rev = {tree6.point(), tree3.point()};

	HForest forest2 = HForest(vector);
	HForest forest3 = HForest(vector_rev);
	assert(forest2.get_trees() == forest3.get_trees());

	HForest forest4 = HForest(tree2.point());
	HForest forest5 = HForest(tree6.point());
	assert(forest4.get_trees() != forest5.get_trees());

	// Test size()
	assert(forest1.size() == 0);
	assert((forest2.size() == forest3.size()) && (forest2.size() == 2));
	assert(forest4.size() == forest5.size());
	
	// Test add_tree() and pop_tree()
	HTree tree7 = HTree(7, 20);
	forest2.add_tree(tree7.point());
	assert(forest2.get_trees() != forest3.get_trees());
	assert(forest2.size() == 3);
	
	auto pop1 = forest2.pop_tree();
	assert(pop1 == tree7.point());
	assert(forest2.get_trees() == forest3.get_trees());
	auto pop2 = forest3.pop_tree();
	assert(pop2 == tree6.point());
	assert(forest3.size() == 1);

	// Test compare_trees function
//	assert(HForest::compare_trees(tree2.point(), tree1.point())); // Expected to crash
	assert(HForest::compare_trees(tree1.point(), tree2.point()));
	assert(HForest::compare_trees(tree1.point(), tree3.point()));
	assert(HForest::compare_trees(tree2.point(), tree5.point()));

	return 0;
}
