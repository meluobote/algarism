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
CMAKE_COMMAND = "F:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\code\cplusplus\algarism

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\code\cplusplus\algarism\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/longestCommonSubSequence.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/longestCommonSubSequence.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/longestCommonSubSequence.dir/flags.make

CMakeFiles/longestCommonSubSequence.dir/dynamicPro/longestCommonSubSequence.cpp.obj: CMakeFiles/longestCommonSubSequence.dir/flags.make
CMakeFiles/longestCommonSubSequence.dir/dynamicPro/longestCommonSubSequence.cpp.obj: ../dynamicPro/longestCommonSubSequence.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cplusplus\algarism\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/longestCommonSubSequence.dir/dynamicPro/longestCommonSubSequence.cpp.obj"
	F:\MinGW64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\longestCommonSubSequence.dir\dynamicPro\longestCommonSubSequence.cpp.obj -c D:\code\cplusplus\algarism\dynamicPro\longestCommonSubSequence.cpp

CMakeFiles/longestCommonSubSequence.dir/dynamicPro/longestCommonSubSequence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/longestCommonSubSequence.dir/dynamicPro/longestCommonSubSequence.cpp.i"
	F:\MinGW64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cplusplus\algarism\dynamicPro\longestCommonSubSequence.cpp > CMakeFiles\longestCommonSubSequence.dir\dynamicPro\longestCommonSubSequence.cpp.i

CMakeFiles/longestCommonSubSequence.dir/dynamicPro/longestCommonSubSequence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/longestCommonSubSequence.dir/dynamicPro/longestCommonSubSequence.cpp.s"
	F:\MinGW64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cplusplus\algarism\dynamicPro\longestCommonSubSequence.cpp -o CMakeFiles\longestCommonSubSequence.dir\dynamicPro\longestCommonSubSequence.cpp.s

# Object files for target longestCommonSubSequence
longestCommonSubSequence_OBJECTS = \
"CMakeFiles/longestCommonSubSequence.dir/dynamicPro/longestCommonSubSequence.cpp.obj"

# External object files for target longestCommonSubSequence
longestCommonSubSequence_EXTERNAL_OBJECTS =

longestCommonSubSequence.exe: CMakeFiles/longestCommonSubSequence.dir/dynamicPro/longestCommonSubSequence.cpp.obj
longestCommonSubSequence.exe: CMakeFiles/longestCommonSubSequence.dir/build.make
longestCommonSubSequence.exe: CMakeFiles/longestCommonSubSequence.dir/linklibs.rsp
longestCommonSubSequence.exe: CMakeFiles/longestCommonSubSequence.dir/objects1.rsp
longestCommonSubSequence.exe: CMakeFiles/longestCommonSubSequence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\code\cplusplus\algarism\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable longestCommonSubSequence.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\longestCommonSubSequence.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/longestCommonSubSequence.dir/build: longestCommonSubSequence.exe

.PHONY : CMakeFiles/longestCommonSubSequence.dir/build

CMakeFiles/longestCommonSubSequence.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\longestCommonSubSequence.dir\cmake_clean.cmake
.PHONY : CMakeFiles/longestCommonSubSequence.dir/clean

CMakeFiles/longestCommonSubSequence.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\code\cplusplus\algarism D:\code\cplusplus\algarism D:\code\cplusplus\algarism\cmake-build-debug D:\code\cplusplus\algarism\cmake-build-debug D:\code\cplusplus\algarism\cmake-build-debug\CMakeFiles\longestCommonSubSequence.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/longestCommonSubSequence.dir/depend

