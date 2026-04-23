/**
 * @file internal/bp_tree.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef BP_TREE_INTERNAL_H
#define BP_TREE_INTERNAL_H

#define BP_TREE_PAGE_SIZE       1024
#define BP_TREE_KEYS_PER_PAGE   ((BP_TREE_PAGE_SIZE - sizeof(BPTreeNodeHeader))/sizeof(BPTreeEntry))

#include "../bp_tree.h"

/**
 * @class BPTreeHeader
 * @brief B+ tree header.
 * @details HeapHeader and BPTreeHeader are read from the same offset in the save file.
 */
typedef struct {
    /// @private
    /// @brief The byte offset to free space in the save file.
    unsigned long freeSpacePtr;

    /// @private
    /// @brief The byte offset to the root node of the index.
    unsigned long rootPtr;
} BPTreeHeader;

/**
 * @class BPTreeNodeHeader
 * @brief B+ tree node header.
 */
typedef struct {
    unsigned char isLeaf;       ///< Whether this node is a leaf.
    unsigned long leftPtr;      ///< Pointer to the left child of this node.
    int numEntries;             ///< The number of entries in this node.
} BPTreeNodeHeader;

/**
 * @class BPTreeEntry
 * @brief B+ tree internal node entry.
 */
typedef struct {
    ChunkID key;            ///< Index entry key.
    unsigned long rightPtr; ///< Pointer to the right child of the owning internal node.
} BPTreeEntry;

/**
 * @class BPTreeLeafEntry
 * @brief B+ tree leaf node entry.
 */
typedef struct {
    ChunkID key;            ///< Index entry key.
    unsigned long value;    ///< Index entry value.
} BPTreeLeafEntry;

/** 
 * @private
 * @memberof BPTree
 * @brief Compares two \ref ChunkID "ChunkIDs".
 * @param [in] keya 1st key to compare.
 * @param [in] keyb 2nd key to compare.
 * @return Negative if keya < keyb, 0 if keya == keyb and positive if keya > keyb.
 */
int compare_keys(ChunkID* keyA, ChunkID* keyB);

/** 
 * @private
 * @memberof BPTree
 * @brief Initializes a BPTree.
 * @param [in] bpTree   BPTree to initialize. Can be NULL to allocate a new BPTree.
 * @return **bpTree** or a new BPTree if **bpTree** was NULL.
 */
void bp_tree_init_tree(BPTree* bpTree);

/** 
 * @private
 * @memberof BPTree
 * @brief Writes node data into the index.
 * @param [in] bpTree   BPTree to write into.
 * @param [in] address  The byte address at which to write the data in the save file.
 * @param [in] page     One node's data, i.e. one page in the index.
 */
void bp_tree_write_page(BPTree* bpTree, unsigned long address, const char* page);

/** 
 * @private
 * @memberof BPTree
 * @brief Appends node data into the index at the index's recorded free space pointer.
 * @param [in] bpTree   BPTree to write into.
 * @param [in] page     One node's data, i.e. one page in the index.
 */
unsigned long bp_tree_append_page(BPTree* bpTree, const char* page);

/** 
 * @private
 * @memberof BPTree
 * @brief Reads node data from the index at a given byte address in the save file.
 * @param [in] bpTree   BPTree to write into.
 * @param [in] address  Byte address in the save file.
 * @param [in] page     The returned data, i.e. one page in the index.
 */
void bp_tree_read_page(BPTree* bpTree, unsigned long address, char* page);

/** 
 * @private
 * @memberof BPTree
 * @brief Returns a BPTreeHeader reflecting the header of the index.
 * @param [in] bpTree   BPTree to retrieve the header of.
 * @returns Index header as a BPTreeHeader.
 */
BPTreeHeader bp_tree_get_header(BPTree* bpTree);

/** 
 * @private
 * @memberof BPTree
 * @brief Sets a BPTreeHeader as the header of the index.
 * @param [in] bpTree   BPTree to write the header of.
 * @param [in] header   Index header.
 */
void bp_tree_set_header(BPTree* bpTree, BPTreeHeader* header);

/** 
 * @private
 * @memberof BPTree
 * @brief Returns a BPTreeNodeHeader given the data from a page (tree node) in the save file index.
 * @param [in] page Data from the First page in the save file.
 * @returns Index node header as a BPTreeNodeHeader.
 */
BPTreeNodeHeader bp_tree_get_node_header(const char* page);

/** 
 * @private
 * @memberof BPTree
 * @brief Sets a BPTreeNodeHeader in the data of a page (tree node) in the save file index.
 * @param [in] page Data from the First page in the save file.
 * @param [in] header Indec node header as a BPTreeNodeHeader.
 */
void bp_tree_set_node_header(char* page, BPTreeNodeHeader* header);

/** 
 * @private
 * @memberof BPTree
 * @brief Creates the data for an internal tree node.
 * @param [in] entries Internal node entries to place in the tree node.
 * @param [in] count Number of entries in **entries**.
 * @param [in] leftPtr Byte offset of the left child of this tree node.
 * @returns The data for an internal tree node.
 */
char* bp_tree_new_node(BPTreeEntry* entries, unsigned int count, unsigned long leftPtr);

/** 
 * @private
 * @memberof BPTree
 * @brief Creates the data for a leaf node.
 * @param [in] entries Internal node entries to place in the leaf node.
 * @param [in] count Number of entries in **entries**.
 * @returns The data for a leaf node.
 */
char* bp_tree_new_leaf_node(BPTreeLeafEntry* entries, unsigned int count);

/** 
 * @private
 * @memberof BPTree
 * @brief Inserts an entry into an internal node while preserving the ascending order of entries.
 * @param [in] bpTree  BPTree to insert the entry into.
 * @param [in] address The byte offset in the save file where the internal node is stored.
 * @param [in] page Data from the internal node's page in the save file.
 * @param [in] entryToInsert The entry to insert into the internal node.
 */
void bp_tree_insert_entry_sorted(BPTree* bpTree, unsigned long address, char* page, BPTreeEntry* entryToInsert);

/** 
 * @private
 * @memberof BPTree
 * @brief Inserts an entry into a leaf node while preserving the ascending order of entries.
 * @param [in] bpTree  BPTree to insert the entry into.
 * @param [in] address The byte offset in the save file where the leaf node is stored.
 * @param [in] page Data from the leaf node's page in the save file.
 * @param [in] entryToInsert The entry to insert into the leaf node.
 */
void bp_tree_insert_leaf_entry_sorted(BPTree* bpTree, unsigned long address, char* page, BPTreeLeafEntry* entryToInsert);

/** 
 * @private
 * @memberof BPTree
 * @brief Inserts an entry into a leaf node by overwriting the entry with the same key.
 * @param [in] bpTree  BPTree to insert the entry into.
 * @param [in] address The byte offset in the save file where the leaf node is stored.
 * @param [in] page Data from the leaf node's page in the save file.
 * @param [in] entryToInsert The entry to insert into the leaf node.
 * @returns 1 if successful, 0 if unsuccessful.
 */
char bp_tree_insert_leaf_entry_over(BPTree* bpTree, unsigned long address, char* page, BPTreeLeafEntry* entryToInsert);

/** 
 * @private
 * @memberof BPTree
 * @brief Inserts an entry into an internal node and splits the node's entries between it and a new right child.
 * @param [in] bpTree  BPTree to insert the entry into.
 * @param [in] address The byte offset in the save file where the internal node is stored.
 * @param [in] page Data from the internal node's page in the save file.
 * @param [in] entryToInsert The entry to insert into the internal node.
 * @returns The new rightmost entry in the now split internal node.
 */
BPTreeEntry* bp_tree_insert_split_insertion(BPTree* bpTree, unsigned long address, char* page, BPTreeEntry* entryToInsert);

/** 
 * @private
 * @memberof BPTree
 * @brief Inserts an entry into a leaf node and splits the node's entries between it and a new right sibling.
 * @param [in] bpTree  BPTree to insert the entry into.
 * @param [in] address The byte offset in the save file where the leaf node is stored.
 * @param [in] page Data from the leaf node's page in the save file.
 * @param [in] entryToInsert The entry to insert into the leaf node.
 * @returns The new rightmost entry in the now split internal node.
 */
BPTreeEntry* bp_tree_insert_split_leaf_insertion(BPTree* bpTree, unsigned long address, char* page, BPTreeLeafEntry* entryToInsert);

/** 
 * @private
 * @memberof BPTree
 * @brief Inserts a leaf node entry starting at an index node at a given address, working down the tree as needed.
 * @details If a tree node is split in the process, the split is propagated up the tree as necessary.
 * @param [in] bpTree  BPTree to insert the entry into.
 * @param [in] address The byte offset in the save file where the the starting index node is stored.
 * @param [in] entryToInsert The entry to insert into the index.
 * @returns Internal node entry to propagate up the tree. The return value is only used by the function itself, because it is recursive.
 */
BPTreeEntry* bp_tree_insert_entry_helper(BPTree* bpTree, unsigned long address, BPTreeLeafEntry* entryToInsert);

/** 
 * @private
 * @memberof BPTree
 * @brief Attempts to find a leaf node entry in a given leaf node.
 * @details If a tree node is split in the process, the split is propagated up the tree as necessary.
 * @param [in] page      Data from the leaf node's page in the save file.
 * @param [in] key       The key of the entry.
 * @param [out] valuePtr The value stored in the entry.
 * @returns 1 if the entry was found, 0 if not.
 */
char bp_tree_find_entry_in_leaf_page(const char* page, ChunkID* key, unsigned long* valuePtr);

/** 
 * @private
 * @memberof BPTree
 * @brief Attempts to find a leaf node entry starting from the index node at a given byte address in the save file.
 * @param [in] bpTree    BPTree to find the leaf node entry in.
 * @param [in] address   The byte offset in the save file where the the starting index node is stored.
 * @param [in] key       The key of the entry to find.
 * @param [out] valuePtr The value stored in the entry.
 * @returns 1 if the entry was found, 0 if not.
 */
char bp_tree_find_entry_helper(BPTree* bpTree, unsigned long address, ChunkID* key, unsigned long* valuePtr);

/** 
 * @private
 * @memberof BPTree
 * @brief Recursive function to print the contents of the index in JSON starting at a given node.
 * @param [in] bpTree    BPTree to print the contents of.
 * @param [in] address   The byte offset in the save file where the the starting index node is stored.
 */
void bp_tree_print_helper(BPTree* bpTree, unsigned long address);

#endif // BP_TREE_INTERNAL_H