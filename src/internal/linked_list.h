/**
 * @file internal/linked_list.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef LINKED_LIST_INTERNAL_H
#define LINKED_LIST_INTERNAL_H

#include "../linked_list.h"

/**
 * @private
 * @memberof LinkedListNode
 * @brief Initializes a LinkedListNode.
 * @param [in] node LinkedListNode to initialize.
 */
void linked_list_node_init(LinkedListNode* node);

#endif // LINKED_LIST_INTERNAL_H
