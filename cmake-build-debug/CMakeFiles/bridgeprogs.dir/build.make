# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jacintogomez/Downloads/bridgeprogs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jacintogomez/Downloads/bridgeprogs/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bridgeprogs.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/bridgeprogs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bridgeprogs.dir/flags.make

CMakeFiles/bridgeprogs.dir/quick.cpp.o: CMakeFiles/bridgeprogs.dir/flags.make
CMakeFiles/bridgeprogs.dir/quick.cpp.o: quick.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jacintogomez/Downloads/bridgeprogs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bridgeprogs.dir/quick.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bridgeprogs.dir/quick.cpp.o -c /Users/jacintogomez/Downloads/bridgeprogs/cmake-build-debug/quick.cpp

CMakeFiles/bridgeprogs.dir/quick.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bridgeprogs.dir/quick.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jacintogomez/Downloads/bridgeprogs/cmake-build-debug/quick.cpp > CMakeFiles/bridgeprogs.dir/quick.cpp.i

CMakeFiles/bridgeprogs.dir/quick.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bridgeprogs.dir/quick.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jacintogomez/Downloads/bridgeprogs/cmake-build-debug/quick.cpp -o CMakeFiles/bridgeprogs.dir/quick.cpp.s

# Object files for target bridgeprogs
bridgeprogs_OBJECTS = \
"CMakeFiles/bridgeprogs.dir/quick.cpp.o"

# External object files for target bridgeprogs
bridgeprogs_EXTERNAL_OBJECTS =

bridgeprogs: CMakeFiles/bridgeprogs.dir/quick.cpp.o
bridgeprogs: CMakeFiles/bridgeprogs.dir/build.make
bridgeprogs: CMakeFiles/bridgeprogs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jacintogomez/Downloads/bridgeprogs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bridgeprogs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bridgeprogs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bridgeprogs.dir/build: bridgeprogs
.PHONY : CMakeFiles/bridgeprogs.dir/build

CMakeFiles/bridgeprogs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bridgeprogs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bridgeprogs.dir/clean

CMakeFiles/bridgeprogs.dir/depend:
	cd /Users/jacintogomez/Downloads/bridgeprogs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jacintogomez/Downloads/bridgeprogs /Users/jacintogomez/Downloads/bridgeprogs /Users/jacintogomez/Downloads/bridgeprogs/cmake-build-debug /Users/jacintogomez/Downloads/bridgeprogs/cmake-build-debug /Users/jacintogomez/Downloads/bridgeprogs/cmake-build-debug/CMakeFiles/bridgeprogs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bridgeprogs.dir/depend

