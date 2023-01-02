#include <streamAPI.h>

SpotifyAPI::SpotifyAPI(const std::string& accessTokenParam, const std::string& artistParam, const std::string& trackParam, const std::string& marketParam){
    accessToken = accessTokenParam;
    artist = artistParam;
    track = trackParam;
    market = marketParam;
}

SpotifyAPI::~SpotifyAPI(){
    curl_easy_cleanup(curl); // clean up and delete the curl handle
    curl = nullptr;
}

CURL* SpotifyAPI::initCURL(){

    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Curl initialization unsuccessful!" << std::endl;
        exit(1);
    }
    return curl;
}

std::string SpotifyAPI::encodeURL(const std::string& URL){

    curl = initCURL();
    std::string result{"None"};

    char* encoded = curl_easy_escape(curl, URL.c_str(), URL.length());
    result = encoded;

    if (result == "None"){
        std::cerr << "URL encoding unsuccessful!" << std::endl;
        exit(1);
    }

    return result;
}

size_t SpotifyAPI::writeCallBack(char* ptr, size_t size, size_t nmemb, void* userdata){

    std::string* stream = static_cast<std::string*>(userdata);

    if (!stream){
        std::cerr << "Invalid stream" << std::endl;
        exit(1);
    }

    stream->append(ptr, size * nmemb);  // write to the stream
    return size * nmemb;
}

std::string SpotifyAPI::getAPIResponse(){

    std::string response{""};
    std::string query = encodeURL(artist + " " + track);
    std::string url = "https://api.spotify.com/v1/search?q=" + query + "&type=track&market=" + market + "&limit=1";

    struct curl_slist* headers = nullptr;
    std::string auth_header = "Authorization: Bearer " + accessToken;
    headers = curl_slist_append(headers, auth_header.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    CURLcode res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
        std::cerr << "Request successful!" << std::endl;
        return response;
    }
    else {
        std::cerr << "Request unsuccessful!" << std::endl;
        exit(1);
    }

    return response;
}

std::string SpotifyAPI::getURL(){

    std::string APIresponse = getAPIResponse();
    Json::Value root;
    Json::Reader reader;

    reader.parse(APIresponse, root);
    Json::Value items = root["tracks"]["items"];
    std::string trackURL = items[0]["preview_url"].asString();

    std::cout << "The track URL is: " << trackURL << std::endl;

    return trackURL;
}