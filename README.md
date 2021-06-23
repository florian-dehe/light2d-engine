# Light2D Engine

Lightweight 2D C++ Engine based on OpenGL

![](logo.png)

## Description

This project aims at creating a little, lightweight OpenGL engine in C++.

## Dependencies

Light2D is using ![GLFW](https://www.glfw.org/), ![GLEW](http://glew.sourceforge.net/), ![GLM](https://github.com/g-truc/glm). Make sure you have these ones. Installation instructions are found below, under the "Build" section.

## Build

This project is using CMake. See the targets below :

### Targets

|Targets | Description |
|--------|-------------|
|light2d            | The library itself. |
|light2D-example    | An example project for light2d (Builds also light2d). |
|docs               | Builds the docs if you have Doxygen installed. |
|all (default)      | All the targets excluding docs. |
|clean              | Clean the build files. |

If you don't know how to build with CMake, look at following instructions according to your system :

### Dependencies

#### Linux (Debian Buster)

Installation command for GLFW, GLEW and GLM is : `sudo apt install libglfw3-dev libglew-dev libglm-dev`.

The `-dev` packages also install runtime libraries.

#### Windows MSYS2

Installation command for x86_64 systems : `pacman -S mingw-w64-x86_64-glfw mingw-w64-x86_64-glew mingw-w64-x86_64-glm`.

If you want to build for i686 systems, please go to MSYS2 packages website.

### Generating build files with CMake :

You may want to build in a separate folder (in the MSYS2 (or MinGW64) shell on Windows) :

    $ cd [light2d-folder]
    $ mkdir build && cd build
    $ cmake ..

You can also use Ninja, if you have it installed (available in MSYS2 packages): `cmake .. -G Ninja`

### Building with your favorite build system :

Then build using Make (in the MSYS2 (or MinGW64) shell on Windows) : 

    $ make [target]

... or Ninja :

    $ ninja [target]

## Author

The author is ![Florian DEHE](https://github.com/florian-dehe).
