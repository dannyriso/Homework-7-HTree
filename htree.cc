/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"

// Initialize with a key and a value:
HTree::HTree(int key, uint64_t value, tree_ptr_t left, tree_ptr_t right) {
	
}

// Destroys the tree
HTree::~HTree() {
	
}

// Return key in current node
int HTree::get_key() const {

};
// Return value in current node	
uint64_t HTree::get_value() const {
	
};

// Return the child of this node indicated by dir.
// If the child is nullptr (current node is a leaf), returns nullptr.
HTree::tree_ptr_t HTree::get_child(HTree::Direction dir) const {
	
};

// Return a list of directions from root to a node of a given key.
// Crashes (with an assert) if key not contained in this tree
HTree::path_t HTree::path_to(int key) const{
	
};

