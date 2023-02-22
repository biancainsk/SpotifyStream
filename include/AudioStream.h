#ifndef AUDIOSTREAM_H
#define AUDIOSTREAM_H

#include <iostream>
#include <vector>
#include <string>
#include <sndfile.h>
#include <cstring>
#include <fstream>

#include <initCurl.h>
#include <gst/gst.h>

class AudioStream{
private:
    CURL* curl = nullptr;
    std::vector<char> buffer;
public:
    AudioStream() = default;
    ~AudioStream();

    static size_t writeCallBack(char* ptr, size_t size, size_t nmemb, std::vector<char>* buffer);
    void saveSong(std::string URL);
    void getSongData();
    void decodePCM();
};

#endif