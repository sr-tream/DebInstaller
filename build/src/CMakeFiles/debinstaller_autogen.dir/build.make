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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sr-tream/Projects/workspace/DebInstaller

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sr-tream/Projects/workspace/DebInstaller/build

# Utility rule file for debinstaller_autogen.

# Include the progress variables for this target.
include src/CMakeFiles/debinstaller_autogen.dir/progress.make

src/CMakeFiles/debinstaller_autogen: src/ui_debinstaller.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sr-tream/Projects/workspace/DebInstaller/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target debinstaller"
	cd /home/sr-tream/Projects/workspace/DebInstaller/build/src && /usr/bin/cmake -E cmake_autogen /home/sr-tream/Projects/workspace/DebInstaller/build/src/CMakeFiles/debinstaller_autogen.dir MinSizeRel

src/ui_debinstaller.h: ../src/debinstaller.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sr-tream/Projects/workspace/DebInstaller/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating ui_debinstaller.h"
	cd /home/sr-tream/Projects/workspace/DebInstaller/build/src && /usr/bin/cmake -DKDE_UIC_EXECUTABLE:FILEPATH=/usr/lib/qt5/bin/uic -DKDE_UIC_FILE:FILEPATH=/home/sr-tream/Projects/workspace/DebInstaller/src/debinstaller.ui -DKDE_UIC_H_FILE:FILEPATH=/home/sr-tream/Projects/workspace/DebInstaller/build/src/ui_debinstaller.h -DKDE_UIC_BASENAME:STRING=debinstaller -P /usr/lib/x86_64-linux-gnu/cmake/KF5I18n/kf5i18nuic.cmake

debinstaller_autogen: src/CMakeFiles/debinstaller_autogen
debinstaller_autogen: src/ui_debinstaller.h
debinstaller_autogen: src/CMakeFiles/debinstaller_autogen.dir/build.make

.PHONY : debinstaller_autogen

# Rule to build all files generated by this target.
src/CMakeFiles/debinstaller_autogen.dir/build: debinstaller_autogen

.PHONY : src/CMakeFiles/debinstaller_autogen.dir/build

src/CMakeFiles/debinstaller_autogen.dir/clean:
	cd /home/sr-tream/Projects/workspace/DebInstaller/build/src && $(CMAKE_COMMAND) -P CMakeFiles/debinstaller_autogen.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/debinstaller_autogen.dir/clean

src/CMakeFiles/debinstaller_autogen.dir/depend:
	cd /home/sr-tream/Projects/workspace/DebInstaller/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sr-tream/Projects/workspace/DebInstaller /home/sr-tream/Projects/workspace/DebInstaller/src /home/sr-tream/Projects/workspace/DebInstaller/build /home/sr-tream/Projects/workspace/DebInstaller/build/src /home/sr-tream/Projects/workspace/DebInstaller/build/src/CMakeFiles/debinstaller_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/debinstaller_autogen.dir/depend

