# Kollision
Kollision is a 2D C++ physics engine with a builtin renderer.
Kollision is designed with ease-of-use in mind and reliability in mind.

## Dependencies
 * Kollision requires [CLSTL](https://github.com/Code-Log/clstl) to compile.
 * OpenGL, GLFW, GLEW
 * CMake
 
## Building

### Linux / MacOS
Simply run the build.sh script with the desired build type, e.g. `$ ./build.sh release`
then cd into the build directory and run `$ make`
 
### Windows
 * Run the following command in the main directory: 
 `C:\path_to_build_directory> cmake . -G "CodeBlocks - MinGW Makefiles"`
 * Then simply import the newly generated Code::Blocks project and compile.
 
## Installing

### Linux
 * In the build directory, simply run `# make install`