# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild

# Utility rule file for catch-populate.

# Include the progress variables for this target.
include CMakeFiles/catch-populate.dir/progress.make

CMakeFiles/catch-populate: CMakeFiles/catch-populate-complete


CMakeFiles/catch-populate-complete: catch-populate-prefix/src/catch-populate-stamp/catch-populate-install
CMakeFiles/catch-populate-complete: catch-populate-prefix/src/catch-populate-stamp/catch-populate-mkdir
CMakeFiles/catch-populate-complete: catch-populate-prefix/src/catch-populate-stamp/catch-populate-download
CMakeFiles/catch-populate-complete: catch-populate-prefix/src/catch-populate-stamp/catch-populate-update
CMakeFiles/catch-populate-complete: catch-populate-prefix/src/catch-populate-stamp/catch-populate-patch
CMakeFiles/catch-populate-complete: catch-populate-prefix/src/catch-populate-stamp/catch-populate-configure
CMakeFiles/catch-populate-complete: catch-populate-prefix/src/catch-populate-stamp/catch-populate-build
CMakeFiles/catch-populate-complete: catch-populate-prefix/src/catch-populate-stamp/catch-populate-install
CMakeFiles/catch-populate-complete: catch-populate-prefix/src/catch-populate-stamp/catch-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'catch-populate'"
	/usr/bin/cmake -E make_directory /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles
	/usr/bin/cmake -E touch /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles/catch-populate-complete
	/usr/bin/cmake -E touch /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-done

catch-populate-prefix/src/catch-populate-stamp/catch-populate-install: catch-populate-prefix/src/catch-populate-stamp/catch-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'catch-populate'"
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-build && /usr/bin/cmake -E echo_append
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-build && /usr/bin/cmake -E touch /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-install

catch-populate-prefix/src/catch-populate-stamp/catch-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'catch-populate'"
	/usr/bin/cmake -E make_directory /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-src
	/usr/bin/cmake -E make_directory /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-build
	/usr/bin/cmake -E make_directory /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix
	/usr/bin/cmake -E make_directory /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/tmp
	/usr/bin/cmake -E make_directory /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp
	/usr/bin/cmake -E make_directory /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src
	/usr/bin/cmake -E make_directory /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp
	/usr/bin/cmake -E touch /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-mkdir

catch-populate-prefix/src/catch-populate-stamp/catch-populate-download: catch-populate-prefix/src/catch-populate-stamp/catch-populate-gitinfo.txt
catch-populate-prefix/src/catch-populate-stamp/catch-populate-download: catch-populate-prefix/src/catch-populate-stamp/catch-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'catch-populate'"
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps && /usr/bin/cmake -P /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/tmp/catch-populate-gitclone.cmake
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps && /usr/bin/cmake -E touch /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-download

catch-populate-prefix/src/catch-populate-stamp/catch-populate-update: catch-populate-prefix/src/catch-populate-stamp/catch-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing update step for 'catch-populate'"
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-src && /usr/bin/cmake -P /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/tmp/catch-populate-gitupdate.cmake

catch-populate-prefix/src/catch-populate-stamp/catch-populate-patch: catch-populate-prefix/src/catch-populate-stamp/catch-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'catch-populate'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-patch

catch-populate-prefix/src/catch-populate-stamp/catch-populate-configure: catch-populate-prefix/tmp/catch-populate-cfgcmd.txt
catch-populate-prefix/src/catch-populate-stamp/catch-populate-configure: catch-populate-prefix/src/catch-populate-stamp/catch-populate-update
catch-populate-prefix/src/catch-populate-stamp/catch-populate-configure: catch-populate-prefix/src/catch-populate-stamp/catch-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'catch-populate'"
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-build && /usr/bin/cmake -E echo_append
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-build && /usr/bin/cmake -E touch /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-configure

catch-populate-prefix/src/catch-populate-stamp/catch-populate-build: catch-populate-prefix/src/catch-populate-stamp/catch-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'catch-populate'"
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-build && /usr/bin/cmake -E echo_append
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-build && /usr/bin/cmake -E touch /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-build

catch-populate-prefix/src/catch-populate-stamp/catch-populate-test: catch-populate-prefix/src/catch-populate-stamp/catch-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'catch-populate'"
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-build && /usr/bin/cmake -E echo_append
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-build && /usr/bin/cmake -E touch /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-test

catch-populate: CMakeFiles/catch-populate
catch-populate: CMakeFiles/catch-populate-complete
catch-populate: catch-populate-prefix/src/catch-populate-stamp/catch-populate-install
catch-populate: catch-populate-prefix/src/catch-populate-stamp/catch-populate-mkdir
catch-populate: catch-populate-prefix/src/catch-populate-stamp/catch-populate-download
catch-populate: catch-populate-prefix/src/catch-populate-stamp/catch-populate-update
catch-populate: catch-populate-prefix/src/catch-populate-stamp/catch-populate-patch
catch-populate: catch-populate-prefix/src/catch-populate-stamp/catch-populate-configure
catch-populate: catch-populate-prefix/src/catch-populate-stamp/catch-populate-build
catch-populate: catch-populate-prefix/src/catch-populate-stamp/catch-populate-test
catch-populate: CMakeFiles/catch-populate.dir/build.make

.PHONY : catch-populate

# Rule to build all files generated by this target.
CMakeFiles/catch-populate.dir/build: catch-populate

.PHONY : CMakeFiles/catch-populate.dir/build

CMakeFiles/catch-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/catch-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/catch-populate.dir/clean

CMakeFiles/catch-populate.dir/depend:
	cd /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild /mnt/c/Users/Bianca/SpotifyStream/build/_deps/catch-subbuild/CMakeFiles/catch-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/catch-populate.dir/depend

