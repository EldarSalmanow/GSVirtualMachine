# GSVirtualMachine
EN: GSVirtualMachine - VM for executing bitecode from GSLanguageCompiler written in C++20. The VM is under development.<br>
RU: GSVirtualMachine - ВМ для исполнения байткода из GSLanguageCompiler, написанная на C++20. ВМ находится в стадии разработки.

# Getting source
```shell
1) cd {pathToDir}
2) git clone https://github.com/EldarSalmanow/GSVirtualMachine.git
```
1. Go to the directory to clone the repository.
2. Cloning repository.

# Build
```shell
1) cd {pathToDir}/GSVirtualMachine
2) mkdir build
3) cd build
4) cmake -G "Visual Studio 16 2019" ../ or cmake -G "MinGW Makefiles" ../
5) cmake --build . --target GSVirtualMachine
```
1. Go to the directory with the cloned repository.
2. Create a directory for storing assembly files.
3. Go to the previously created directory.
4. Generating assembly files via CMake.<br>You can choose either configuration via MinGW or via MSVC.<br>Support for other compilers is not guaranteed at this time.
5. Building an executable file via target "GSVirtualMachine"

# Install
```shell
1) cd {pathToDir}/GSVirtualMachine
2) cd build
3) cmake --install .
```
1. Go to the directory with the cloned repository.
2. Go to the build directory.
3. Install binaries to {pathToDir}/GSVirtualMachine/bin.

# Run
Run without additional flags
```shell
GSVirtualMachine.exe --file {pathToInputFile}.gsvm
```

Run with testing of each executing step
```shell
GSVirtualMachine.exe --file {pathToInputFile}.gsvm --test
```

Run with profiling of each executing step.
```shell
GSVirtualMachine.exe --file {pathToInputFile}.gsvm --profiling
```
