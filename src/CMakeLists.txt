set(HEADER_LIST "${SpotifyStreamDSP_SOURCE_DIR}/include/streamAPI.h")
add_library(streamDSPLibrary streamAPI.cpp ${HEADER_LIST})
target_include_directories(streamDSPLibrary PUBLIC ../include)
target_compile_features(streamDSPLibrary PUBLIC cxx_std_17)