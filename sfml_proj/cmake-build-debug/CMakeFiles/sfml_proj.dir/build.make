# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/152/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/152/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/peephole/Desktop/sfml_proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/peephole/Desktop/sfml_proj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sfml_proj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sfml_proj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfml_proj.dir/flags.make

CMakeFiles/sfml_proj.dir/main.cpp.o: CMakeFiles/sfml_proj.dir/flags.make
CMakeFiles/sfml_proj.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/peephole/Desktop/sfml_proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfml_proj.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_proj.dir/main.cpp.o -c /home/peephole/Desktop/sfml_proj/main.cpp

CMakeFiles/sfml_proj.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_proj.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/peephole/Desktop/sfml_proj/main.cpp > CMakeFiles/sfml_proj.dir/main.cpp.i

CMakeFiles/sfml_proj.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_proj.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/peephole/Desktop/sfml_proj/main.cpp -o CMakeFiles/sfml_proj.dir/main.cpp.s

CMakeFiles/sfml_proj.dir/Game.cpp.o: CMakeFiles/sfml_proj.dir/flags.make
CMakeFiles/sfml_proj.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/peephole/Desktop/sfml_proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sfml_proj.dir/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_proj.dir/Game.cpp.o -c /home/peephole/Desktop/sfml_proj/Game.cpp

CMakeFiles/sfml_proj.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_proj.dir/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/peephole/Desktop/sfml_proj/Game.cpp > CMakeFiles/sfml_proj.dir/Game.cpp.i

CMakeFiles/sfml_proj.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_proj.dir/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/peephole/Desktop/sfml_proj/Game.cpp -o CMakeFiles/sfml_proj.dir/Game.cpp.s

CMakeFiles/sfml_proj.dir/GameObject.cpp.o: CMakeFiles/sfml_proj.dir/flags.make
CMakeFiles/sfml_proj.dir/GameObject.cpp.o: ../GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/peephole/Desktop/sfml_proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sfml_proj.dir/GameObject.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_proj.dir/GameObject.cpp.o -c /home/peephole/Desktop/sfml_proj/GameObject.cpp

CMakeFiles/sfml_proj.dir/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_proj.dir/GameObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/peephole/Desktop/sfml_proj/GameObject.cpp > CMakeFiles/sfml_proj.dir/GameObject.cpp.i

CMakeFiles/sfml_proj.dir/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_proj.dir/GameObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/peephole/Desktop/sfml_proj/GameObject.cpp -o CMakeFiles/sfml_proj.dir/GameObject.cpp.s

# Object files for target sfml_proj
sfml_proj_OBJECTS = \
"CMakeFiles/sfml_proj.dir/main.cpp.o" \
"CMakeFiles/sfml_proj.dir/Game.cpp.o" \
"CMakeFiles/sfml_proj.dir/GameObject.cpp.o"

# External object files for target sfml_proj
sfml_proj_EXTERNAL_OBJECTS =

sfml_proj: CMakeFiles/sfml_proj.dir/main.cpp.o
sfml_proj: CMakeFiles/sfml_proj.dir/Game.cpp.o
sfml_proj: CMakeFiles/sfml_proj.dir/GameObject.cpp.o
sfml_proj: CMakeFiles/sfml_proj.dir/build.make
sfml_proj: /usr/lib/x86_64-linux-gnu/libsfml-system.so
sfml_proj: /usr/lib/x86_64-linux-gnu/libsfml-window.so
sfml_proj: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
sfml_proj: /usr/lib/x86_64-linux-gnu/libsfml-network.so
sfml_proj: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
sfml_proj: CMakeFiles/sfml_proj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/peephole/Desktop/sfml_proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable sfml_proj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml_proj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfml_proj.dir/build: sfml_proj

.PHONY : CMakeFiles/sfml_proj.dir/build

CMakeFiles/sfml_proj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfml_proj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfml_proj.dir/clean

CMakeFiles/sfml_proj.dir/depend:
	cd /home/peephole/Desktop/sfml_proj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/peephole/Desktop/sfml_proj /home/peephole/Desktop/sfml_proj /home/peephole/Desktop/sfml_proj/cmake-build-debug /home/peephole/Desktop/sfml_proj/cmake-build-debug /home/peephole/Desktop/sfml_proj/cmake-build-debug/CMakeFiles/sfml_proj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfml_proj.dir/depend
