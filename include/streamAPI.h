#ifndef STREAMAPI_H
#define STREAMAPI_H

#include <iostream>
#include <string>
#include <string_view>
#include <curl/curl.h> // include the cURL library
#include <json/json.h> // include the json library
#include <sstream>

class SpotifyAPI{
private:
    std::string accessToken{"None"};
    CURL* curl = nullptr;
public:
    SpotifyAPI(const std::string& accessTokenParam);
    ~SpotifyAPI();

    void initCURL();
    std::string encodeURL(const std::string& URL);
    static size_t writeCallBack(char* ptr, size_t size, size_t nmemb, void* userdata);
    std::string getAPIResponse(const std::string& artist, const std::string& track);
    std::string getURL(const std::string& artist, const std::string& track);

};


#endif