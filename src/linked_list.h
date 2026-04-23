/**
 * @file linked_list.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "global.h"

/**
 * @class LinkedListNode
 * @brief One node in a LinkedList.
 */
typedef struct LinkedListNode {
    /// @private
    /// @brief Node data.
    void* data;

    /// @private
    /// @brief Pointer to the previous node.
    struct LinkedListNode* prev;

    /// @private
    /// @brief Pointer to the next node.
    struct LinkedListNode* next;
} LinkedListNode;

/**
 * @class LinkedList
 * @brief Doubly-linked list.
 */
typedef struct {
    /// @private
    /// @brief Pointer to the first node.
    struct LinkedListNode* head;

    /// @private
    /// @brief Pointer to the last node.
    struct LinkedListNode* tail;

    /// @private
    /// @brief Number of elements in the list.
    int size;
} LinkedList;

/** 
 * @public
 * @memberof LinkedList
 * @brief Initializes a LinkedList.
 * @param [in] l LinkedList to initialize. Can be NULL to allocate a new LinkedList.
 * @return **l** or a new LinkedList if **l** was NULL.
 */
LinkedList* linked_list_init(LinkedList* l);

/** 
 * @public
 * @memberof LinkedList
 * @brief Destroys a LinkedList.
 * @param [in] list       LinkedList to destroy.
 * @param [in] destroy_fn Callback function invoked on each list element in order to destroy it.
 */
void linked_list_destroy(LinkedList* list, void (*destroy_fn)(void*));

/** 
 * @public
 * @memberof LinkedList
 * @brief Inserts an item into the LinkedList.
 * @param [in] list LinkedList to insert into.
 * @param [in] data Pointer to the item to insert into the list.
 */
void linked_list_insert(LinkedList* list, void* data);

/** 
 * @public
 * @memberof LinkedList
 * @brief Inserts an item into the LinkedList while preserving its order.
 * @param [in] list LinkedList to insert into.
 * @param [in] data Pointer to the item to insert into the list.
 * @param [in] comparison Callback function invoked on each list element in order to compare the inserted element with it.
 */
void linked_list_insert_ordered(LinkedList* list, void* data, int (*comparison)(void*, void*));

/** 
 * @public
 * @memberof LinkedList
 * @brief Inserts an item into the LinkedList just before another list node.
 * @param [in] list LinkedList to insert into.
 * @param [in] node LinkedListNode to insert before.
 * @param [in] data Pointer to the item to insert into the list.
 */
void linked_list_insert_before(LinkedList* list, LinkedListNode* node, void* data);

/** 
 * @public
 * @memberof LinkedList
 * @brief Inserts an item into the LinkedList just after another list node.
 * @param [in] list LinkedList to insert into.
 * @param [in] node LinkedListNode to insert after.
 * @param [in] data Pointer to the item to insert into the list.
 */
void linked_list_insert_after(LinkedList* list, LinkedListNode* node, void* data);

/** 
 * @public
 * @memberof LinkedList
 * @brief Iterates over each element in the list and invokes a function on it.
 * @param [in] list LinkedList to insert into.
 * @param [in] comparison Callback function invoked on each list element.
 * @param [in] userData Is passed to **comparison** on each invokation. Can be any value.
 */
void linked_list_foreach(LinkedList* list, void (*visitor)(void*, void*), void* userData);

/** 
 * @public
 * @memberof LinkedList
 * @brief Finds the first node in the list containing an element that is equivalent to a given element.
 * @param [in] list LinkedList to insert into.
 * @param [in] data The element to compare equivalency against.
 * @param [in] equals_fn Callback function to determine the equivalency of two list elements.
 */
LinkedListNode* linked_list_find(LinkedList* list, void* data, char (*equals_fn)(void*, void*));

/** 
 * @public
 * @memberof LinkedList
 * @brief Removes the a node from the list.
 * @param [in] list LinkedList to remove from.
 * @param [in] node The LinkedListNode to remove.
 * @param [in] destroy_fn Callback function invoked on the list element in order to destroy it.
 */
void linked_list_remove(LinkedList* list, LinkedListNode* node, void (*destroy_fn)(void*));

#endif // LINKED_LIST_H
