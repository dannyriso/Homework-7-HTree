// HForest defines all the declarations from hforest.hh needed to create an HForest object.

#include "hforest.hh"

HForest::HForest(htree_vec vector) {
	trees_ = vector;
	update_heap(&trees_);
}
HForest::HForest(HForest::htree_ptr tree) {
	trees_.push_back(tree);
}

HForest::htree_vec HForest::get_trees() const {
	return trees_;
}

uint64_t HForest::size() const {
	return trees_.size();
}

void HForest::add_tree(HForest::htree_ptr tree) {
	trees_.push_back(tree);
	update_heap(&trees_);
}

HForest::htree_ptr HForest::pop_tree() {
	auto highest = *(trees_.begin());
	trees_.erase(trees_.begin());
	update_heap(&trees_);
	return highest;
}

// Used from the Moodle description of Homework 7
bool HForest::compare_trees(htree_ptr tree1, htree_ptr tree2) {
	return tree1->get_value() < tree2->get_value();
}

void HForest::update_heap(htree_vec* vector) {
	std::make_heap(vector->begin(), vector->end(), compare_trees);
}
