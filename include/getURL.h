#ifndef GETURL_H
#define GETURL_H

#include <iostream>
#include <string>
#include <curl/curl.h> // include the cURL library
#include <json/json.h> // include the json library
#include <sstream>

class SpotifyAPI{
private:
    std::string accessToken{""};

    std::string artist{"None"};
    std::string track{"None"};
    std::string market{"None"};
    std::string clientID{"None"};
    std::string clientSecret{"None"};
    
    static CURL* curl;
    std::string url{"None"};
    std::string APIresponse{""};
public:
    SpotifyAPI(const std::string& clientIDParam, const std::string& clientSecretParam, const std::string& artistParam, const std::string& trackParam, const std::string& marketParam);
    ~SpotifyAPI();

    static CURL* initCURL();
    void getAccessToken();
    std::string base64Encode(const std::string& input);
    std::string encodeURL(const std::string& URL);
    static size_t writeCallBack(char* ptr, size_t size, size_t nmemb, void* userdata);
    void getAPIResponse();
    std::string getURL();

};


#endif