set(HEADER_LIST "${SpotifyStreamDSP_SOURCE_DIR}/include/getURL.h"
                "${SpotifyStreamDSP_SOURCE_DIR}/include/streamURL.h")
add_library(streamDSPLibrary getURL.cpp streamURL.cpp ${HEADER_LIST})

target_include_directories(streamDSPLibrary PUBLIC ../include)
target_compile_features(streamDSPLibrary PUBLIC cxx_std_17)
target_link_libraries(streamDSPLibrary PRIVATE CURL::libcurl)