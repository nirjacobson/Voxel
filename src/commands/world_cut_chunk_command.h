#ifndef WORLD_CUT_CHUNK_COMMAND
#define WORLD_CUT_CHUNK_COMMAND

#include "../undo_stack.h"
#include "../box.h"
#include "../world.h"

/**
 * @class WorldCutChunkCommand
 * @brief Command to set a Chunk in the World after removing it elsewhere.
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
    /// @brief The (x, y, z) origin in the World.
    int fromLocation[3];

    /// @private
    /// @brief The (x, y, z) destination in the World.
    int toLocation[3];

    /// @private
    /// @brief Rotation to apply to the Chunk before setting it in the World. \
               See world_set_chunk() implementation for details.
    int rotation;
} WorldCutChunkCommand;

/** 
 * @public
 * @memberof WorldCutChunkCommand
 * @brief Initializes a WorldCutChunkCommand.
 * @param [in] world        Voxel World.
 * @param [in] chunk        Chunk to set in the World.
 * @param [in] fromLocation (x, y, z) origin in the World.
 * @param [in] toLocation   (x, y, z) destination in the World.
 * @param [in] rotation Rotation to apply to the Chunk before setting it in the World. \
                        See world_set_chunk() implementation for details.
 * @returns A WorldCutChunkCommand.
 */
WorldCutChunkCommand* world_cut_chunk_command_init(World* world, Chunk* chunk, int* fromLocation, int* toLocation, int rotation);

/** 
 * @public
 * @memberof WorldCutChunkCommand
 * @brief Undoes the command.
 * @param [in] command Command object.
 */
void world_cut_chunk_command_undo(Command* command);

/** 
 * @public
 * @memberof WorldCutChunkCommand
 * @brief (Re)does the command.
 * @param [in] command Command object.
 */
void world_cut_chunk_command_redo(Command* command);

/** 
 * @public
 * @memberof WorldCutChunkCommand
 * @brief Returns the Command ID of WorldCutChunkCommand.
 * @returns WorldCutChunkCommand Command ID.
 */
int world_cut_chunk_command_id();

/** 
 * @public
 * @memberof WorldCutChunkCommand
 * @brief Destroys a WorldCutChunkCommand.
 * @param [in] command Command object.
 */
void world_cut_chunk_command_destroy(Command* command);

#endif // WORLD_CUT_CHUNK_COMMAND