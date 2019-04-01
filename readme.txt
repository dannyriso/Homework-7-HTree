HTree:

The HTree class holds the methods and members required to make HTree objects with a key, a value, and left and right
HTree children. Each of these members are private, accessed only with getter methods. The path_to method is also public,
and checks that a given key is within the tree (crashing if it isn't) and returning a list to it from the tree's head.

HTree has the attribute pointer_ in order to pass the shared_ptr that refers to each tree. It is accessed publically with
the point() method. Since pointer_ can't be assigned to an object while it is being constructed, it is assigned when
point() is called instead; if the HTree's pointer_ is already assigned, then point() returns it; otherwise, it assigns
and then returns it.

The path_to() method also uses the helper method find(), which was based on the method of the same name from Eitan's
tree.cc, which checks recursively through a tree and returns a bool for whether a given key is in it.


HForest:

The HForest class creates HForest objects, which hold independent HTrees in vectors and organize them in a heap. Each
object has a vector of <HTree>shared_ptrs called trees_, which keeps track of the HTrees belonging to the HForest.
The other public methods that manipulate the contents of an HForest - add_tree(), pop_tree(), update_heap() - do so by
changing trees_.

update_heap() takes in the pointer to trees_ and calls make_heap on it, keeping the HForest's structure a heap whenever
trees_ is modified.
