# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kadirgonul/CLionProjects/data_compression_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kadirgonul/CLionProjects/data_compression_project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/data_compressor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/data_compressor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data_compressor.dir/flags.make

CMakeFiles/data_compressor.dir/main.cpp.o: CMakeFiles/data_compressor.dir/flags.make
CMakeFiles/data_compressor.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kadirgonul/CLionProjects/data_compression_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/data_compressor.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/data_compressor.dir/main.cpp.o -c /Users/kadirgonul/CLionProjects/data_compression_project/main.cpp

CMakeFiles/data_compressor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/data_compressor.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kadirgonul/CLionProjects/data_compression_project/main.cpp > CMakeFiles/data_compressor.dir/main.cpp.i

CMakeFiles/data_compressor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/data_compressor.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kadirgonul/CLionProjects/data_compression_project/main.cpp -o CMakeFiles/data_compressor.dir/main.cpp.s

CMakeFiles/data_compressor.dir/huffman.cpp.o: CMakeFiles/data_compressor.dir/flags.make
CMakeFiles/data_compressor.dir/huffman.cpp.o: ../huffman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kadirgonul/CLionProjects/data_compression_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/data_compressor.dir/huffman.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/data_compressor.dir/huffman.cpp.o -c /Users/kadirgonul/CLionProjects/data_compression_project/huffman.cpp

CMakeFiles/data_compressor.dir/huffman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/data_compressor.dir/huffman.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kadirgonul/CLionProjects/data_compression_project/huffman.cpp > CMakeFiles/data_compressor.dir/huffman.cpp.i

CMakeFiles/data_compressor.dir/huffman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/data_compressor.dir/huffman.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kadirgonul/CLionProjects/data_compression_project/huffman.cpp -o CMakeFiles/data_compressor.dir/huffman.cpp.s

CMakeFiles/data_compressor.dir/util.cpp.o: CMakeFiles/data_compressor.dir/flags.make
CMakeFiles/data_compressor.dir/util.cpp.o: ../util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kadirgonul/CLionProjects/data_compression_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/data_compressor.dir/util.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/data_compressor.dir/util.cpp.o -c /Users/kadirgonul/CLionProjects/data_compression_project/util.cpp

CMakeFiles/data_compressor.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/data_compressor.dir/util.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kadirgonul/CLionProjects/data_compression_project/util.cpp > CMakeFiles/data_compressor.dir/util.cpp.i

CMakeFiles/data_compressor.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/data_compressor.dir/util.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kadirgonul/CLionProjects/data_compression_project/util.cpp -o CMakeFiles/data_compressor.dir/util.cpp.s

CMakeFiles/data_compressor.dir/image_manager.cpp.o: CMakeFiles/data_compressor.dir/flags.make
CMakeFiles/data_compressor.dir/image_manager.cpp.o: ../image_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kadirgonul/CLionProjects/data_compression_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/data_compressor.dir/image_manager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/data_compressor.dir/image_manager.cpp.o -c /Users/kadirgonul/CLionProjects/data_compression_project/image_manager.cpp

CMakeFiles/data_compressor.dir/image_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/data_compressor.dir/image_manager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kadirgonul/CLionProjects/data_compression_project/image_manager.cpp > CMakeFiles/data_compressor.dir/image_manager.cpp.i

CMakeFiles/data_compressor.dir/image_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/data_compressor.dir/image_manager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kadirgonul/CLionProjects/data_compression_project/image_manager.cpp -o CMakeFiles/data_compressor.dir/image_manager.cpp.s

# Object files for target data_compressor
data_compressor_OBJECTS = \
"CMakeFiles/data_compressor.dir/main.cpp.o" \
"CMakeFiles/data_compressor.dir/huffman.cpp.o" \
"CMakeFiles/data_compressor.dir/util.cpp.o" \
"CMakeFiles/data_compressor.dir/image_manager.cpp.o"

# External object files for target data_compressor
data_compressor_EXTERNAL_OBJECTS =

data_compressor: CMakeFiles/data_compressor.dir/main.cpp.o
data_compressor: CMakeFiles/data_compressor.dir/huffman.cpp.o
data_compressor: CMakeFiles/data_compressor.dir/util.cpp.o
data_compressor: CMakeFiles/data_compressor.dir/image_manager.cpp.o
data_compressor: CMakeFiles/data_compressor.dir/build.make
data_compressor: /usr/X11R6/lib/libpng.dylib
data_compressor: CMakeFiles/data_compressor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kadirgonul/CLionProjects/data_compression_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable data_compressor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data_compressor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data_compressor.dir/build: data_compressor

.PHONY : CMakeFiles/data_compressor.dir/build

CMakeFiles/data_compressor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/data_compressor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/data_compressor.dir/clean

CMakeFiles/data_compressor.dir/depend:
	cd /Users/kadirgonul/CLionProjects/data_compression_project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kadirgonul/CLionProjects/data_compression_project /Users/kadirgonul/CLionProjects/data_compression_project /Users/kadirgonul/CLionProjects/data_compression_project/cmake-build-debug /Users/kadirgonul/CLionProjects/data_compression_project/cmake-build-debug /Users/kadirgonul/CLionProjects/data_compression_project/cmake-build-debug/CMakeFiles/data_compressor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/data_compressor.dir/depend
