/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"

// Initialize with a key and a value:
HTree::HTree(int key, uint64_t value, tree_ptr_t left, tree_ptr_t right)
	:key_(key), value_(value), left_(left), right_(right)
{
	HTree::tree_ptr_t pointer_ = nullptr;
}

// Return key in current node
int HTree::get_key() const {
	return key_;
}
// Return value in current node	
uint64_t HTree::get_value() const {
	return value_;
}

// Return the shared_ptr that refers to the given HTree
HTree::tree_ptr_t HTree::point() {
	if(!pointer_) {
		pointer_ = std::make_shared<HTree>(*this);
		return pointer_;
	} else {
		return pointer_;
	}
}

// Return the child of this node indicated by dir.
// If the child is nullptr (current node is a leaf), returns nullptr.
HTree::tree_ptr_t HTree::get_child(HTree::Direction dir) const {
	if(left_ && dir == Direction::LEFT) {
		return left_;
	} else if(right_ && dir == Direction::RIGHT) {
		return right_;
	} else {
		return nullptr;
	}
}

// find() helper function used from Eitan's tree.cc
// It checks for a given key in the tree and returns true if it is found
bool HTree::find(int key) const {
	tree_ptr_t left_tree = get_child(Direction::LEFT);
	tree_ptr_t right_tree = get_child(Direction::RIGHT);
	return this &&
		(key_ == key
		 || (left_tree && left_tree->find(key))
		 || (right_tree && right_tree->find(key)));
}

// Return a list of directions from root to a node of a given key.
// Crashes (with an assert) if key not contained in this tree
HTree::path_t HTree::path_to(int key) const {
	assert(find(key));
	
	HTree::path_t path;
	tree_ptr_t left_tree = get_child(Direction::LEFT);
	tree_ptr_t right_tree = get_child(Direction::RIGHT);
	
	if(key_ == key) {
		return path;
	} else if(left_tree && left_tree->find(key)) {
		path = left_tree->path_to(key);
		path.insert(path.begin(), Direction::LEFT);
		return path;
	} else {
		path = right_tree->path_to(key);
		path.insert(path.begin(), Direction::RIGHT);
		return path;
	}
}
