# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProjects\boolANF

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\boolANF\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/boolANF.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boolANF.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boolANF.dir/flags.make

CMakeFiles/boolANF.dir/main.c.obj: CMakeFiles/boolANF.dir/flags.make
CMakeFiles/boolANF.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\boolANF\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/boolANF.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\boolANF.dir\main.c.obj -c D:\CLionProjects\boolANF\main.c

CMakeFiles/boolANF.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/boolANF.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\boolANF\main.c > CMakeFiles\boolANF.dir\main.c.i

CMakeFiles/boolANF.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/boolANF.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\boolANF\main.c -o CMakeFiles\boolANF.dir\main.c.s

# Object files for target boolANF
boolANF_OBJECTS = \
"CMakeFiles/boolANF.dir/main.c.obj"

# External object files for target boolANF
boolANF_EXTERNAL_OBJECTS =

boolANF.exe: CMakeFiles/boolANF.dir/main.c.obj
boolANF.exe: CMakeFiles/boolANF.dir/build.make
boolANF.exe: CMakeFiles/boolANF.dir/linklibs.rsp
boolANF.exe: CMakeFiles/boolANF.dir/objects1.rsp
boolANF.exe: CMakeFiles/boolANF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\boolANF\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable boolANF.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\boolANF.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boolANF.dir/build: boolANF.exe

.PHONY : CMakeFiles/boolANF.dir/build

CMakeFiles/boolANF.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\boolANF.dir\cmake_clean.cmake
.PHONY : CMakeFiles/boolANF.dir/clean

CMakeFiles/boolANF.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\boolANF D:\CLionProjects\boolANF D:\CLionProjects\boolANF\cmake-build-debug D:\CLionProjects\boolANF\cmake-build-debug D:\CLionProjects\boolANF\cmake-build-debug\CMakeFiles\boolANF.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boolANF.dir/depend
