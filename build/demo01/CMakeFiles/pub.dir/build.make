# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/book/ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/book/ws/build

# Include any dependencies generated for this target.
include demo01/CMakeFiles/pub.dir/depend.make

# Include the progress variables for this target.
include demo01/CMakeFiles/pub.dir/progress.make

# Include the compile flags for this target's objects.
include demo01/CMakeFiles/pub.dir/flags.make

demo01/CMakeFiles/pub.dir/src/pub.cpp.o: demo01/CMakeFiles/pub.dir/flags.make
demo01/CMakeFiles/pub.dir/src/pub.cpp.o: /home/book/ws/src/demo01/src/pub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/book/ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object demo01/CMakeFiles/pub.dir/src/pub.cpp.o"
	cd /home/book/ws/build/demo01 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pub.dir/src/pub.cpp.o -c /home/book/ws/src/demo01/src/pub.cpp

demo01/CMakeFiles/pub.dir/src/pub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pub.dir/src/pub.cpp.i"
	cd /home/book/ws/build/demo01 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/book/ws/src/demo01/src/pub.cpp > CMakeFiles/pub.dir/src/pub.cpp.i

demo01/CMakeFiles/pub.dir/src/pub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pub.dir/src/pub.cpp.s"
	cd /home/book/ws/build/demo01 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/book/ws/src/demo01/src/pub.cpp -o CMakeFiles/pub.dir/src/pub.cpp.s

demo01/CMakeFiles/pub.dir/src/pub.cpp.o.requires:

.PHONY : demo01/CMakeFiles/pub.dir/src/pub.cpp.o.requires

demo01/CMakeFiles/pub.dir/src/pub.cpp.o.provides: demo01/CMakeFiles/pub.dir/src/pub.cpp.o.requires
	$(MAKE) -f demo01/CMakeFiles/pub.dir/build.make demo01/CMakeFiles/pub.dir/src/pub.cpp.o.provides.build
.PHONY : demo01/CMakeFiles/pub.dir/src/pub.cpp.o.provides

demo01/CMakeFiles/pub.dir/src/pub.cpp.o.provides.build: demo01/CMakeFiles/pub.dir/src/pub.cpp.o


# Object files for target pub
pub_OBJECTS = \
"CMakeFiles/pub.dir/src/pub.cpp.o"

# External object files for target pub
pub_EXTERNAL_OBJECTS =

/home/book/ws/devel/lib/demo01/pub: demo01/CMakeFiles/pub.dir/src/pub.cpp.o
/home/book/ws/devel/lib/demo01/pub: demo01/CMakeFiles/pub.dir/build.make
/home/book/ws/devel/lib/demo01/pub: /opt/ros/melodic/lib/libroscpp.so
/home/book/ws/devel/lib/demo01/pub: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/book/ws/devel/lib/demo01/pub: /opt/ros/melodic/lib/librosconsole.so
/home/book/ws/devel/lib/demo01/pub: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/book/ws/devel/lib/demo01/pub: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/book/ws/devel/lib/demo01/pub: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/book/ws/devel/lib/demo01/pub: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/book/ws/devel/lib/demo01/pub: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/book/ws/devel/lib/demo01/pub: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/book/ws/devel/lib/demo01/pub: /opt/ros/melodic/lib/librostime.so
/home/book/ws/devel/lib/demo01/pub: /opt/ros/melodic/lib/libcpp_common.so
/home/book/ws/devel/lib/demo01/pub: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/book/ws/devel/lib/demo01/pub: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/book/ws/devel/lib/demo01/pub: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/book/ws/devel/lib/demo01/pub: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/book/ws/devel/lib/demo01/pub: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/book/ws/devel/lib/demo01/pub: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/book/ws/devel/lib/demo01/pub: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/book/ws/devel/lib/demo01/pub: demo01/CMakeFiles/pub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/book/ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/book/ws/devel/lib/demo01/pub"
	cd /home/book/ws/build/demo01 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo01/CMakeFiles/pub.dir/build: /home/book/ws/devel/lib/demo01/pub

.PHONY : demo01/CMakeFiles/pub.dir/build

demo01/CMakeFiles/pub.dir/requires: demo01/CMakeFiles/pub.dir/src/pub.cpp.o.requires

.PHONY : demo01/CMakeFiles/pub.dir/requires

demo01/CMakeFiles/pub.dir/clean:
	cd /home/book/ws/build/demo01 && $(CMAKE_COMMAND) -P CMakeFiles/pub.dir/cmake_clean.cmake
.PHONY : demo01/CMakeFiles/pub.dir/clean

demo01/CMakeFiles/pub.dir/depend:
	cd /home/book/ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/book/ws/src /home/book/ws/src/demo01 /home/book/ws/build /home/book/ws/build/demo01 /home/book/ws/build/demo01/CMakeFiles/pub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo01/CMakeFiles/pub.dir/depend

