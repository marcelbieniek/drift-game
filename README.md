# raylib-cpp CMake Example Project

Use this template to build a [raylib-cpp](https://github.com/RobLoach/raylib-cpp) project using [CMake](https://cmake.org).

## Build

To build this project, make sure to have CMake installed locally.

### Desktop

```
mkdir build
cd build
cmake ..
make
```

alternative:
```
cmake -B build && cmake --build build
```

### Web

```
mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release
emmake make
```

## Run

```
./raylib-cpp-example
```


## Ideas
- Make it work on web so that you can embed a sample in the portfolio website
