// HForest is a collection of independent HTrees, stored as a heap.

#pragma once

#include "htree.cc"
#include <vector>
#include <algorithm>

class HForest {
	public:
		using htree_ptr = HTree::tree_ptr_t;
		using htree_vec = std::vector<htree_ptr>;
	private:
		htree_vec trees_;
	public:
		// Constructors: no-arg default, single-HTree, and a vector of HTrees
		HForest() = default;
		HForest(htree_ptr tree);
		HForest(htree_vec vector);
		
		// Destructor: default only
		~HForest() = default;
		
		// Return the vector of HTrees contained in the HForest
		htree_vec get_trees() const;

		// Return number of HTrees in the current HForest
		uint64_t size() const;
		
		// Adds an HTree to the HForest and reorganizes the heap
		void add_tree(htree_ptr tree);
		
		// Removes the HTree with the highest value from the current HForest, returns it,
		// and reorganizes the remaining HTree.
		htree_ptr pop_tree();		
	
		// Compares two HTrees and returns true if the value of the first is less than
		// or equal to the value of the second.
		static bool compare_trees(htree_ptr tree1, htree_ptr tree2);

		// Takes in a vector of HTrees and makes them into a heap
		void update_heap(htree_vec* vector);
	
};
