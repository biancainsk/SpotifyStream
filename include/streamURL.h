#ifndef STREAMURL_H
#define STREAMURL_H

#include <iostream>
#include <vector>
#include <string>
#include <curl/curl.h>
#include <getURL.h>

class audioStream{
private:
    CURL* curl = nullptr;
    std::vector<unsigned char> buffer;
public:
    audioStream() = default;
    ~audioStream();
    static size_t writeCallBack(char* ptr, size_t size, size_t nmemb, std::vector<unsigned char>* buffer);
    void saveSong(std::string URL);
};

#endif