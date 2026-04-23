#ifndef UNDO_STACK_H
#define UNDO_STACK_H

#include <stdbool.h>

#include "linked_list.h"

typedef struct Command Command;

/**
 * @class Command
 * @brief Abstract class for an undo command.
 */
struct Command {
    /// @private
    /// @brief Subclass object (a specific command).
    void* parent;

    /// @private
    /// @brief Undo function.
    void (*undo)(Command*);

    /// @private
    /// @brief Redo function.
    void (*redo)(Command*);

    /// @private
    /// @brief Subclass ID. Used to merge like commands.
    int (*id)(void);

    /// @private
    /// @brief Attempts to merge two like commands so they are undone and redone atomically.
    bool (*merge)(Command*, Command*);

    /// @private
    /// @brief Destroy function from the subclass.
    void (*destroy)(Command*);
};

/**
 * @class UndoStack
 * @brief A stack of \ref Command "Commands" that can be performed (pushed) and undone (popped).
 */
typedef struct {
    /// @brief Stack of \ref Command "Commands".
    LinkedList commands;

    /// @brief Reference to the top of the Command stack (most recently performed command).
    LinkedListNode* top;
} UndoStack;

/** 
 * @public
 * @memberof UndoStack
 * @brief Initializes the UndoStack.
 * @param [in] stack  Voxel UndoStack.
 */
void undo_stack_init(UndoStack* stack);

/** 
 * @public
 * @memberof UndoStack
 * @brief Destroys the UndoStack.
 * @param [in] stack  Voxel UndoStack.
 */
void undo_stack_destroy(UndoStack* stack);

/** 
 * @public
 * @memberof UndoStack
 * @brief Performs a command.
 * @param [in] stack    Voxel UndoStack.
 * @param [in] command  Command to perform.
 */
void undo_stack_push(UndoStack* stack, Command* command);

/** 
 * @public
 * @memberof UndoStack
 * @brief Undoes the last command.
 * @param [in] stack    Voxel UndoStack.
 */
void undo_stack_undo(UndoStack* stack);

/** 
 * @public
 * @memberof UndoStack
 * @brief Redoes the last undone command.
 * @param [in] stack    Voxel UndoStack.
 */
void undo_stack_redo(UndoStack* stack);

#endif // UNDO_STACK_H