#ifndef SPOTIFYAPI_H
#define SPOTIFYAPI_H

#include <iostream>
#include <string>
#include <json/json.h> // include the json library
#include <sstream>

#include <initCurl.h>

class SpotifyAPI{
protected:
    std::string accessToken;

    std::string artist;
    std::string track;
    std::string market;
    std::string clientID;
    std::string clientSecret;
    
    CURL* curl = nullptr;
    std::string url;
    std::string APIresponse;
public:
    SpotifyAPI(const std::string& clientIDParam, const std::string& clientSecretParam, const std::string& artistParam, const std::string& trackParam, const std::string& marketParam);

    void getAccessToken();
    std::string base64Encode(const std::string& input);
    std::string encodeURL(const std::string& URL);
    static size_t writeCallBack(char* ptr, size_t size, size_t nmemb, void* userdata);
    void getAPIResponse();
    std::string getURL();

};


#endif