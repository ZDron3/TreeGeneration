# TreeGeneration

###### Random Tree Creation generator consists of around 100K Randomly generated tree using UE4

## Instructions

Use **W,A,S,D** to move around the game using Mouse Axis to look around. Use **Left Mouse Button** to click and select any tree from the random generated tree or click any surface to create a new tree.

## How it Works

We are generating a random struct with values for the position, height and radius for the tree, thereafter we pool these struct and use them to render the trees
I am using *Hierarchical Instanced Static Mesh Component* instead of using regular *StaticMesh* for the tree as this reduces the total number of draw calls by batching them together thereby optimizing the performance and helping us push the limitation for rendering multiple (same kind of objects). This HISM Component is prefered over *InstanceStaticMeshComponent* is that even though they work the same way, HISM helps us maintain the LOD(Level of details) integrity for each of the Static Mesh added to world by HISM.

###### Video

[You can find the working video here](https://imgur.com/a/J5No1iO)

