# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Ben/frc-2017-season

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Ben/frc-2017-season/build

# Utility rule file for deploy.

# Include the progress variables for this target.
include CMakeFiles/deploy.dir/progress.make

CMakeFiles/deploy: steamworks
	sh -c /Users/Ben/frc-2017-season/deploy.sh\ 5499\ /Users/Ben/frc-2017-season/build/steamworks\ /usr/local/arm-frc-linux-gnueabi/wpilib/ant/robotCommand

deploy: CMakeFiles/deploy
deploy: CMakeFiles/deploy.dir/build.make

.PHONY : deploy

# Rule to build all files generated by this target.
CMakeFiles/deploy.dir/build: deploy

.PHONY : CMakeFiles/deploy.dir/build

CMakeFiles/deploy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/deploy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/deploy.dir/clean

CMakeFiles/deploy.dir/depend:
	cd /Users/Ben/frc-2017-season/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Ben/frc-2017-season /Users/Ben/frc-2017-season /Users/Ben/frc-2017-season/build /Users/Ben/frc-2017-season/build /Users/Ben/frc-2017-season/build/CMakeFiles/deploy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/deploy.dir/depend

