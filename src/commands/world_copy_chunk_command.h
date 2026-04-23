#ifndef WORLD_COPY_CHUNK_COMMAND
#define WORLD_COPY_CHUNK_COMMAND

#include "../undo_stack.h"
#include "../box.h"
#include "../world.h"

/**
 * @class WorldCopyChunkCommand
 * @brief Command to set a Chunk in the World.
 */
typedef struct {
    /// @private
    /// @brief Command object.
    Command command;

    /// @private
    /// @brief Voxel World.
    World* world;

    /// @private
    /// @brief The Chunk to set.
    Chunk* chunk;

    /// @private
    /// @brief The Blocks that existed in the destination before execution.
    Chunk* chunkBefore;

    /// @private
    /// @brief The (x, y, z) destination in the World.
    int toLocation[3];

    /// @private
    /// @brief Rotation to apply to the Chunk before setting it in the World. \
               See world_set_chunk() implementation for details.
    int rotation;
} WorldCopyChunkCommand;

/** 
 * @public
 * @memberof WorldCopyChunkCommand
 * @brief Initializes a WorldCopyChunkCommand.
 * @param [in] world    Voxel World.
 * @param [in] chunk    Chunk to set in the World.
 * @param [in] location (x, y, z) destination in the World.
 * @param [in] rotation Rotation to apply to the Chunk before setting it in the World. \
                        See world_set_chunk() implementation for details.
 * @returns A WorldCopyChunkCommand.
 */
WorldCopyChunkCommand* world_copy_chunk_command_init(World* world, Chunk* chunk, int* location, int rotation);

/** 
 * @public
 * @memberof WorldCopyChunkCommand
 * @brief Undoes the command.
 * @param [in] command Command object.
 */
void world_copy_chunk_command_undo(Command* command);

/** 
 * @public
 * @memberof WorldCopyChunkCommand
 * @brief (Re)does the command.
 * @param [in] command Command object.
 */
void world_copy_chunk_command_redo(Command* command);
lear_region_command_redo(Command* command);

/** 
 * @public
 * @memberof WorldCopyChunkCommand
 * @brief Returns the Command ID of WorldCopyChunkCommand.
 * @returns WorldCopyChunkCommand Command ID.
 */
int world_copy_chunk_command_id();

/** 
 * @public
 * @memberof WorldCopyChunkCommand
 * @brief Destroys a WorldCopyChunkCommand.
 * @param [in] command Command object.
 */
void world_copy_chunk_command_destroy(Command* command);

#endif // WORLD_COPY_CHUNK_COMMAND