/**
 * @file world_clear_region_command.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef WORLD_CLEAR_REGION_COMMAND_H
#define WORLD_CLEAR_REGION_COMMAND_H

#include "../undo_stack.h"
#include "../box.h"
#include "../world.h"

/**
 * @class WorldClearRegionCommand
 * @brief Command to clear a volume of \ref Block "Blocks".
 */
typedef struct {
    /// @private
    /// @brief Command object.
    Command command;

    /// @private
    /// @brief Voxel World.
    World* world;

    /// @private
    /// @brief Volume definition.
    Box region;

    /// @private
    /// @brief Contains the \ref Block "Blocks" cleared.
    Chunk* chunk;
} WorldClearRegionCommand;

/** 
 * @public
 * @memberof WorldClearRegionCommand
 * @brief Initializes a WorldClearRegionCommand.
 * @param [in] world  Voxel World.
 * @param [in] box    Defines the clear volume. It is internally copied.
 * @returns A WorldClearRegionCommand.
 */
WorldClearRegionCommand* world_clear_region_command_init(World* world, Box* region);

/** 
 * @public
 * @memberof WorldClearRegionCommand
 * @brief Undoes the command.
 * @param [in] command Command object.
 */
void world_clear_region_command_undo(Command* command);

/** 
 * @public
 * @memberof WorldClearRegionCommand
 * @brief (Re)does the command.
 * @param [in] command Command object.
 */
void world_clear_region_command_redo(Command* command);

/** 
 * @public
 * @memberof WorldClearRegionCommand
 * @brief Returns the Command ID of WorldClearRegionCommand.
 * @returns WorldClearRegionCommand Command ID.
 */
int world_clear_region_command_id();

/** 
 * @public
 * @memberof WorldClearRegionCommand
 * @brief Destroys a WorldClearRegionCommand.
 * @param [in] command Command object.
 */
void world_clear_region_command_destroy(Command* command);

#endif // WORLD_CLEAR_REGION_COMMAND_H