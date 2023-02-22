#include <initCurl.h>
#include <iostream>

CURL* initCURL(){

    CURL* curl;

    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Curl initialization unsuccessful!" << std::endl;
        exit(1);
    }
    return curl;
}