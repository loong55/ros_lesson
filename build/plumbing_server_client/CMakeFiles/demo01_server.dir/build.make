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
include plumbing_server_client/CMakeFiles/demo01_server.dir/depend.make

# Include the progress variables for this target.
include plumbing_server_client/CMakeFiles/demo01_server.dir/progress.make

# Include the compile flags for this target's objects.
include plumbing_server_client/CMakeFiles/demo01_server.dir/flags.make

plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o: plumbing_server_client/CMakeFiles/demo01_server.dir/flags.make
plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o: /home/book/ws/src/plumbing_server_client/src/demo01_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/book/ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o"
	cd /home/book/ws/build/plumbing_server_client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o -c /home/book/ws/src/plumbing_server_client/src/demo01_server.cpp

plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo01_server.dir/src/demo01_server.cpp.i"
	cd /home/book/ws/build/plumbing_server_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/book/ws/src/plumbing_server_client/src/demo01_server.cpp > CMakeFiles/demo01_server.dir/src/demo01_server.cpp.i

plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo01_server.dir/src/demo01_server.cpp.s"
	cd /home/book/ws/build/plumbing_server_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/book/ws/src/plumbing_server_client/src/demo01_server.cpp -o CMakeFiles/demo01_server.dir/src/demo01_server.cpp.s

plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o.requires:

.PHONY : plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o.requires

plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o.provides: plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o.requires
	$(MAKE) -f plumbing_server_client/CMakeFiles/demo01_server.dir/build.make plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o.provides.build
.PHONY : plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o.provides

plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o.provides.build: plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o


# Object files for target demo01_server
demo01_server_OBJECTS = \
"CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o"

# External object files for target demo01_server
demo01_server_EXTERNAL_OBJECTS =

/home/book/ws/devel/lib/plumbing_server_client/demo01_server: plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: plumbing_server_client/CMakeFiles/demo01_server.dir/build.make
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /opt/ros/melodic/lib/libroscpp.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /opt/ros/melodic/lib/librosconsole.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /opt/ros/melodic/lib/librostime.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /opt/ros/melodic/lib/libcpp_common.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/book/ws/devel/lib/plumbing_server_client/demo01_server: plumbing_server_client/CMakeFiles/demo01_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/book/ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/book/ws/devel/lib/plumbing_server_client/demo01_server"
	cd /home/book/ws/build/plumbing_server_client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo01_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plumbing_server_client/CMakeFiles/demo01_server.dir/build: /home/book/ws/devel/lib/plumbing_server_client/demo01_server

.PHONY : plumbing_server_client/CMakeFiles/demo01_server.dir/build

plumbing_server_client/CMakeFiles/demo01_server.dir/requires: plumbing_server_client/CMakeFiles/demo01_server.dir/src/demo01_server.cpp.o.requires

.PHONY : plumbing_server_client/CMakeFiles/demo01_server.dir/requires

plumbing_server_client/CMakeFiles/demo01_server.dir/clean:
	cd /home/book/ws/build/plumbing_server_client && $(CMAKE_COMMAND) -P CMakeFiles/demo01_server.dir/cmake_clean.cmake
.PHONY : plumbing_server_client/CMakeFiles/demo01_server.dir/clean

plumbing_server_client/CMakeFiles/demo01_server.dir/depend:
	cd /home/book/ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/book/ws/src /home/book/ws/src/plumbing_server_client /home/book/ws/build /home/book/ws/build/plumbing_server_client /home/book/ws/build/plumbing_server_client/CMakeFiles/demo01_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plumbing_server_client/CMakeFiles/demo01_server.dir/depend
