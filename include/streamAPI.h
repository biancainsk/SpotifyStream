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
    std::string artist{"None"};
    std::string track{"None"};
    std::string market{"None"};
    CURL* curl = nullptr;
public:
    SpotifyAPI(const std::string& accessTokenParam, const std::string& artistParam, const std::string& trackParam, const std::string& marketParam);
    ~SpotifyAPI();

    CURL* initCURL();
    std::string encodeURL(const std::string& URL);
    static size_t writeCallBack(char* ptr, size_t size, size_t nmemb, void* userdata);
    std::string getAPIResponse();
    std::string getURL();

};


#endif