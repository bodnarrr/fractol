# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /Users/abodnar/UNT/Projects/fractol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/abodnar/UNT/Projects/fractol/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fractol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fractol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fractol.dir/flags.make

CMakeFiles/fractol.dir/main.c.o: CMakeFiles/fractol.dir/flags.make
CMakeFiles/fractol.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abodnar/UNT/Projects/fractol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fractol.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fractol.dir/main.c.o   -c /Users/abodnar/UNT/Projects/fractol/main.c

CMakeFiles/fractol.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fractol.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abodnar/UNT/Projects/fractol/main.c > CMakeFiles/fractol.dir/main.c.i

CMakeFiles/fractol.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fractol.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abodnar/UNT/Projects/fractol/main.c -o CMakeFiles/fractol.dir/main.c.s

CMakeFiles/fractol.dir/init_functions.c.o: CMakeFiles/fractol.dir/flags.make
CMakeFiles/fractol.dir/init_functions.c.o: ../init_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abodnar/UNT/Projects/fractol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/fractol.dir/init_functions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fractol.dir/init_functions.c.o   -c /Users/abodnar/UNT/Projects/fractol/init_functions.c

CMakeFiles/fractol.dir/init_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fractol.dir/init_functions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abodnar/UNT/Projects/fractol/init_functions.c > CMakeFiles/fractol.dir/init_functions.c.i

CMakeFiles/fractol.dir/init_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fractol.dir/init_functions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abodnar/UNT/Projects/fractol/init_functions.c -o CMakeFiles/fractol.dir/init_functions.c.s

CMakeFiles/fractol.dir/iteration_functions.c.o: CMakeFiles/fractol.dir/flags.make
CMakeFiles/fractol.dir/iteration_functions.c.o: ../iteration_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abodnar/UNT/Projects/fractol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/fractol.dir/iteration_functions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fractol.dir/iteration_functions.c.o   -c /Users/abodnar/UNT/Projects/fractol/iteration_functions.c

CMakeFiles/fractol.dir/iteration_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fractol.dir/iteration_functions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abodnar/UNT/Projects/fractol/iteration_functions.c > CMakeFiles/fractol.dir/iteration_functions.c.i

CMakeFiles/fractol.dir/iteration_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fractol.dir/iteration_functions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abodnar/UNT/Projects/fractol/iteration_functions.c -o CMakeFiles/fractol.dir/iteration_functions.c.s

CMakeFiles/fractol.dir/hooks.c.o: CMakeFiles/fractol.dir/flags.make
CMakeFiles/fractol.dir/hooks.c.o: ../hooks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abodnar/UNT/Projects/fractol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/fractol.dir/hooks.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fractol.dir/hooks.c.o   -c /Users/abodnar/UNT/Projects/fractol/hooks.c

CMakeFiles/fractol.dir/hooks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fractol.dir/hooks.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abodnar/UNT/Projects/fractol/hooks.c > CMakeFiles/fractol.dir/hooks.c.i

CMakeFiles/fractol.dir/hooks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fractol.dir/hooks.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abodnar/UNT/Projects/fractol/hooks.c -o CMakeFiles/fractol.dir/hooks.c.s

CMakeFiles/fractol.dir/threads.c.o: CMakeFiles/fractol.dir/flags.make
CMakeFiles/fractol.dir/threads.c.o: ../threads.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abodnar/UNT/Projects/fractol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/fractol.dir/threads.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fractol.dir/threads.c.o   -c /Users/abodnar/UNT/Projects/fractol/threads.c

CMakeFiles/fractol.dir/threads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fractol.dir/threads.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abodnar/UNT/Projects/fractol/threads.c > CMakeFiles/fractol.dir/threads.c.i

CMakeFiles/fractol.dir/threads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fractol.dir/threads.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abodnar/UNT/Projects/fractol/threads.c -o CMakeFiles/fractol.dir/threads.c.s

CMakeFiles/fractol.dir/more_hooks.c.o: CMakeFiles/fractol.dir/flags.make
CMakeFiles/fractol.dir/more_hooks.c.o: ../more_hooks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abodnar/UNT/Projects/fractol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/fractol.dir/more_hooks.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fractol.dir/more_hooks.c.o   -c /Users/abodnar/UNT/Projects/fractol/more_hooks.c

CMakeFiles/fractol.dir/more_hooks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fractol.dir/more_hooks.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abodnar/UNT/Projects/fractol/more_hooks.c > CMakeFiles/fractol.dir/more_hooks.c.i

CMakeFiles/fractol.dir/more_hooks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fractol.dir/more_hooks.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abodnar/UNT/Projects/fractol/more_hooks.c -o CMakeFiles/fractol.dir/more_hooks.c.s

# Object files for target fractol
fractol_OBJECTS = \
"CMakeFiles/fractol.dir/main.c.o" \
"CMakeFiles/fractol.dir/init_functions.c.o" \
"CMakeFiles/fractol.dir/iteration_functions.c.o" \
"CMakeFiles/fractol.dir/hooks.c.o" \
"CMakeFiles/fractol.dir/threads.c.o" \
"CMakeFiles/fractol.dir/more_hooks.c.o"

# External object files for target fractol
fractol_EXTERNAL_OBJECTS =

fractol: CMakeFiles/fractol.dir/main.c.o
fractol: CMakeFiles/fractol.dir/init_functions.c.o
fractol: CMakeFiles/fractol.dir/iteration_functions.c.o
fractol: CMakeFiles/fractol.dir/hooks.c.o
fractol: CMakeFiles/fractol.dir/threads.c.o
fractol: CMakeFiles/fractol.dir/more_hooks.c.o
fractol: CMakeFiles/fractol.dir/build.make
fractol: CMakeFiles/fractol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/abodnar/UNT/Projects/fractol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable fractol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fractol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fractol.dir/build: fractol

.PHONY : CMakeFiles/fractol.dir/build

CMakeFiles/fractol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fractol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fractol.dir/clean

CMakeFiles/fractol.dir/depend:
	cd /Users/abodnar/UNT/Projects/fractol/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abodnar/UNT/Projects/fractol /Users/abodnar/UNT/Projects/fractol /Users/abodnar/UNT/Projects/fractol/cmake-build-debug /Users/abodnar/UNT/Projects/fractol/cmake-build-debug /Users/abodnar/UNT/Projects/fractol/cmake-build-debug/CMakeFiles/fractol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fractol.dir/depend

