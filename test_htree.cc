/*
 * test_htree.cc contains a main function which tests the functionality of htree.hh and htree.cc
 */

#include "htree.cc"
#include <typeinfo>

int main() {
	// Test constructors
	HTree tree1 = HTree();
	HTree tree2 = HTree(1, 2);
	HTree tree3 = HTree(4, 4, tree1.point(), tree2.point());
	HTree tree4 = HTree(6, 3, tree3.point());

	// Test get_ methods
	assert(typeid(tree4.get_key()) == typeid(int));
	assert(typeid(tree1.get_key()) == typeid(int));
	assert(typeid(tree1.get_value()) == typeid(uint64_t));
	assert(tree2.get_key() == 1);
	assert(tree3.get_value() == 4);
	
	assert(tree2.get_child(HTree::Direction::LEFT) == nullptr);
	assert(tree3.get_child(HTree::Direction::RIGHT) == tree2.point());
	assert(tree3.get_child(HTree::Direction::LEFT) == tree1.point());
	assert(tree4.get_child(HTree::Direction::RIGHT) == nullptr);
	assert(tree4.get_child(HTree::Direction::LEFT) == tree3.point());

	// Test the find() helper function
//	assert(tree2.find(3)); // Expected to crash here
	assert(tree2.find(1));
	assert(tree4.find(1));
	assert(!(tree4.find(8)));

	// Test path_to() method
	HTree::path_t path_none = {};
	HTree::path_t path1 = {{HTree::Direction::LEFT}};
	HTree::path_t path2 = {{HTree::Direction::LEFT}, {HTree::Direction::RIGHT}};
	HTree::path_t path3 = {{HTree::Direction::RIGHT}};
	assert(tree4.path_to(4) == path1);
	assert(tree4.path_to(1) == path2);
	assert(tree3.path_to(1) == path3);
	assert(tree4.path_to(6) == path_none);

	return 0;
}
