# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\code\cplus\algarism

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\code\cplus\algarism\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/algarism.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algarism.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algarism.dir/flags.make

CMakeFiles/algarism.dir/main.cpp.obj: CMakeFiles/algarism.dir/flags.make
CMakeFiles/algarism.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cplus\algarism\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algarism.dir/main.cpp.obj"
	D:\ProgramData\Qt\Tools\mingw730_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\algarism.dir\main.cpp.obj -c D:\code\cplus\algarism\main.cpp

CMakeFiles/algarism.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algarism.dir/main.cpp.i"
	D:\ProgramData\Qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cplus\algarism\main.cpp > CMakeFiles\algarism.dir\main.cpp.i

CMakeFiles/algarism.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algarism.dir/main.cpp.s"
	D:\ProgramData\Qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cplus\algarism\main.cpp -o CMakeFiles\algarism.dir\main.cpp.s

CMakeFiles/algarism.dir/sort.cpp.obj: CMakeFiles/algarism.dir/flags.make
CMakeFiles/algarism.dir/sort.cpp.obj: ../sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cplus\algarism\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/algarism.dir/sort.cpp.obj"
	D:\ProgramData\Qt\Tools\mingw730_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\algarism.dir\sort.cpp.obj -c D:\code\cplus\algarism\sort.cpp

CMakeFiles/algarism.dir/sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algarism.dir/sort.cpp.i"
	D:\ProgramData\Qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cplus\algarism\sort.cpp > CMakeFiles\algarism.dir\sort.cpp.i

CMakeFiles/algarism.dir/sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algarism.dir/sort.cpp.s"
	D:\ProgramData\Qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cplus\algarism\sort.cpp -o CMakeFiles\algarism.dir\sort.cpp.s

# Object files for target algarism
algarism_OBJECTS = \
"CMakeFiles/algarism.dir/main.cpp.obj" \
"CMakeFiles/algarism.dir/sort.cpp.obj"

# External object files for target algarism
algarism_EXTERNAL_OBJECTS =

algarism.exe: CMakeFiles/algarism.dir/main.cpp.obj
algarism.exe: CMakeFiles/algarism.dir/sort.cpp.obj
algarism.exe: CMakeFiles/algarism.dir/build.make
algarism.exe: CMakeFiles/algarism.dir/linklibs.rsp
algarism.exe: CMakeFiles/algarism.dir/objects1.rsp
algarism.exe: CMakeFiles/algarism.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\code\cplus\algarism\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable algarism.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algarism.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algarism.dir/build: algarism.exe

.PHONY : CMakeFiles/algarism.dir/build

CMakeFiles/algarism.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algarism.dir\cmake_clean.cmake
.PHONY : CMakeFiles/algarism.dir/clean

CMakeFiles/algarism.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\code\cplus\algarism D:\code\cplus\algarism D:\code\cplus\algarism\cmake-build-debug D:\code\cplus\algarism\cmake-build-debug D:\code\cplus\algarism\cmake-build-debug\CMakeFiles\algarism.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algarism.dir/depend

