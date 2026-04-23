# Voxel
Voxel is a volumetric pixel painter. It’s similar to the original MS Paint program in a 3D, Minecraft-esque environment. It has an infinite draw area that is saved to a file as it is explored.

![Voxel](https://static.wixstatic.com/media/a278e6_21e6def0f9734c24b22250ea9127cc8c~mv2.png/v1/fill/w_976,h_475,al_c,q_90,usm_0.66_1.00_0.01,enc_avif,quality_auto/a278e6_21e6def0f9734c24b22250ea9127cc8c~mv2.png)

## Dependencies

Voxel depends on the [cairo](https://www.cairographics.org/) graphics library and [GLFW](https://www.glfw.org/).

```
sudo apt install libcairo2-dev
sudo apt install libglfw3-dev 
```

## Usage

```
git clone https://github.com/nirjacobson/Voxel.git
cd voxel/
make
./voxel
```

## Controls
Use **W**, **A**, **S**, **D**, **↑**, **↓**, **←**, **→** to navigate.

**TAB** toggles the adjacency mode of the picker. The picker can operate on blocks or the positions adjacent to them.  
**ESC** exits the program.

The picker tools have the following hotkeys:
- **1** - Pencil
- **2** - Eraser
- **Q** - Eyedropper
- **Z** - Region select
- **X** - Stamp (copy selection)
- **C** - Move (cut selection)
  
The **pencil**, **eraser** and **select** tools support click-and-drag.  
When placing a selection with the **stamp** or **move** tool, right-click will rotate the target.  
With the **select** tool, **SHIFT+Click** adds to an existing selection.
