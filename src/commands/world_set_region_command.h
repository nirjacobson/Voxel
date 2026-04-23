#ifndef WORLD_SET_REGION_COMMAND
#define WORLD_SET_REGION_COMMAND

#include "../undo_stack.h"
#include "../box.h"
#include "../world.h"

/**
 * @class WorldSetRegionCommand
 * @brief Command to set a volume of \ref Block Blocks to a certain color and activate them.
 */
typedef struct {
    /// @private
    /// @brief Command object.
    Command command;

    /// @private
    /// @brief Voxel World.
    World* world;

    /// @private
    /// @brief The volume to color.
    Box region;

    /// @private
    /// @brief 9-bit color.
    uint16_t color;

    /// @private
    /// @brief The Blocks that existed in the destination before execution.
    Chunk* chunk;
} WorldSetRegionCommand;

/** 
 * @public
 * @memberof WorldSetRegionCommand
 * @brief Initializes a WorldSetRegionCommand.
 * @param [in] world        Voxel World.
 * @param [in] region       Volume to color and activate.
 * @param [in] color        9-bit color.
 * @returns A WorldSetRegionCommand.
 */
WorldSetRegionCommand* world_set_region_command_init(World* world, Box* region, uint16_t color);

/** 
 * @public
 * @memberof WorldSetRegionCommand
 * @brief Undoes the command.
 * @param [in] command Command object.
 */
void world_set_region_command_undo(Command* command);

/** 
 * @public
 * @memberof WorldSetRegionCommand
 * @brief (Re)does the command.
 * @param [in] command Command object.
 */
void world_set_region_command_redo(Command* command);

/** 
 * @public
 * @memberof WorldSetRegionCommand
 * @brief Returns the Command ID of WorldSetRegionCommand.
 * @returns WorldSetRegionCommand Command ID.
 */
int world_set_region_command_id();

/** 
 * @public
 * @memberof WorldSetRegionCommand
 * @brief Destroys a WorldSetRegionCommand.
 * @param [in] command Command object.
 */
void world_set_region_command_destroy(Command* command);

#endif // WORLD_SET_REGION_COMMAND