# Voxel Engine

Voxel divides the world into chunks of blocks, where each chunk is 16 blocks along each side. As the camera moves around the world, Voxel unloads any chunks that are no longer visible, saving them to the save file if they've changed. It then loads any new chunks that are now visible.

The save file has two parts: a chunk heap, where chunks are stored sequentially in the order of discovery by the camera, and a B+ tree index on heap entries. The B+ tree and heap data are interlaced in the file. A Data Access Object (DAO) is used to access the chunk heap and keep the index up-to-date.