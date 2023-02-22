set(HEADER_LIST "${SpotifyStreamDSP_SOURCE_DIR}/include/SpotifyAPI.h"
                "${SpotifyStreamDSP_SOURCE_DIR}/include/AudioStream.h"
                "${SpotifyStreamDSP_SOURCE_DIR}/include/initCurl.h")
add_library(streamDSPLibrary SpotifyAPI.cpp AudioStream.cpp initCurl.cpp ${HEADER_LIST})

target_include_directories(streamDSPLibrary PUBLIC ../include)
target_compile_features(streamDSPLibrary PUBLIC cxx_std_17)
target_link_libraries(streamDSPLibrary PRIVATE CURL::libcurl)
