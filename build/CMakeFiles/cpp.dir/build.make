# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\cpp\xiao_xiong_mao\cpp_src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\cpp\xiao_xiong_mao\cpp_src\build

# Include any dependencies generated for this target.
include CMakeFiles/cpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp.dir/flags.make

CMakeFiles/cpp.dir/cpp_01.cpp.obj: CMakeFiles/cpp.dir/flags.make
CMakeFiles/cpp.dir/cpp_01.cpp.obj: ../cpp_01.cpp
CMakeFiles/cpp.dir/cpp_01.cpp.obj: CMakeFiles/cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\cpp\xiao_xiong_mao\cpp_src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp.dir/cpp_01.cpp.obj"
	c:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpp.dir/cpp_01.cpp.obj -MF CMakeFiles\cpp.dir\cpp_01.cpp.obj.d -o CMakeFiles\cpp.dir\cpp_01.cpp.obj -c F:\cpp\xiao_xiong_mao\cpp_src\cpp_01.cpp

CMakeFiles/cpp.dir/cpp_01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp.dir/cpp_01.cpp.i"
	c:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\cpp\xiao_xiong_mao\cpp_src\cpp_01.cpp > CMakeFiles\cpp.dir\cpp_01.cpp.i

CMakeFiles/cpp.dir/cpp_01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp.dir/cpp_01.cpp.s"
	c:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\cpp\xiao_xiong_mao\cpp_src\cpp_01.cpp -o CMakeFiles\cpp.dir\cpp_01.cpp.s

# Object files for target cpp
cpp_OBJECTS = \
"CMakeFiles/cpp.dir/cpp_01.cpp.obj"

# External object files for target cpp
cpp_EXTERNAL_OBJECTS =

cpp.exe: CMakeFiles/cpp.dir/cpp_01.cpp.obj
cpp.exe: CMakeFiles/cpp.dir/build.make
cpp.exe: CMakeFiles/cpp.dir/linklibs.rsp
cpp.exe: CMakeFiles/cpp.dir/objects1.rsp
cpp.exe: CMakeFiles/cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\cpp\xiao_xiong_mao\cpp_src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp.dir/build: cpp.exe
.PHONY : CMakeFiles/cpp.dir/build

CMakeFiles/cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cpp.dir/clean

CMakeFiles/cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\cpp\xiao_xiong_mao\cpp_src F:\cpp\xiao_xiong_mao\cpp_src F:\cpp\xiao_xiong_mao\cpp_src\build F:\cpp\xiao_xiong_mao\cpp_src\build F:\cpp\xiao_xiong_mao\cpp_src\build\CMakeFiles\cpp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp.dir/depend

