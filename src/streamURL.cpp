#include <streamURL.h>

audioStream::~audioStream(){
    curl_easy_cleanup(curl); // clean up and delete the curl handle
    curl = nullptr;
}

size_t audioStream::writeCallBack(char* ptr, size_t size, size_t nmemb, std::vector<unsigned char>* buffer){

    size_t realsize = size * nmemb;
    buffer->insert(buffer->end(), ptr, ptr + realsize);
    return realsize;
}

void audioStream::saveSong(std::string URL){

    curl = SpotifyAPI::initCURL();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
    }

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
            std::cout << "Failed to fetch data: " << curl_easy_strerror(res) << std::endl;
        }
    else {
        std::cout << "Data fetched successfully" << std::endl;
        // use buffer variable to hold the audio data
    }

    std::cout << "Buffer contents: ";
    for(auto i: buffer) {
        std::cout << i;
    }
    std::cout << std::endl;

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}