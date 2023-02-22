cmake_minimum_required(VERSION 3.0.0)
project(SpotifyStreamDSP VERSION 0.1.0 DESCRIPTION "DSP Project for increasing the bass of a song" LANGUAGES CXX)

find_package(CURL REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})
pkg_check_modules(SNDFILE sndfile)
link_libraries(${SNDFILE_LIBRARIES})
pkg_check_modules(GST REQUIRED gstreamer-1.0)
include_directories(${GST_INCLUDE_DIRS})
link_directories(${GST_LIBRARY_DIRS})

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_EXTENSIONS OFF)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  include(CTest)

  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

include(FetchContent)

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 5.3.0)
FetchContent_MakeAvailable(fmtlib)


add_subdirectory(src)
add_subdirectory(app)

