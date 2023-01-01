#include <streamAPI.h>

SpotifyAPI::SpotifyAPI(const std::string& accessTokenParam){
    accessToken = accessTokenParam;
}

SpotifyAPI::~SpotifyAPI(){
    curl_easy_cleanup(curl); // clean up and delete the curl handle
    curl = nullptr;
}

void SpotifyAPI::initCURL(){
    CURL* curl = curl_easy_init();
}

std::string SpotifyAPI::encodeURL(const std::string& URL){

    initCURL();

    if (curl) {
        char* encoded = curl_easy_escape(curl, URL.c_str(), URL.length());
        std::string result = encoded;
        return result;
    } 
    else
        return "";
}

size_t SpotifyAPI::writeCallBack(char* ptr, size_t size, size_t nmemb, void* userdata){
    std::stringstream* stream = static_cast<std::stringstream*>(userdata);
    size_t count = size * nmemb;
    stream->write(ptr, count);
    return count;
}

std::string SpotifyAPI::getAPIResponse(const std::string& artist, const std::string& track){

    std::string response = "";
    std::string query = encodeURL(artist + " " + track);
    std::string url = "https://api.spotify.com/v1/search?q=" + query + "&type=track";
    std::cout << query << std::endl;

    initCURL();
    if(curl){
        struct curl_slist* headers = NULL;
        std::string auth_header = "Authorization: Bearer " + accessToken;
        headers = curl_slist_append(headers, auth_header.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cout << "Request successful!" << std::endl;
        }
        else 
            std::cout << "Request unsuccessful!" << std::endl;
    }

    return response;
}

std::string SpotifyAPI::getURL(const std::string& artist, const std::string& track){

    std::string APIresponse = getAPIResponse(artist, track);
    Json::Value root;
    Json::Reader reader;

    reader.parse(APIresponse, root);
    Json::Value items = root["tracks"]["items"];
    std::string trackURL = items[0]["preview_url"].asString();

    std::cout << "The track URL is: " << trackURL << std::endl;

    return trackURL;
}