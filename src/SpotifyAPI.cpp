#include <SpotifyAPI.h>

SpotifyAPI::SpotifyAPI(const std::string& clientIDParam, const std::string& clientSecretParam, const std::string& artistParam, const std::string& trackParam, const std::string& marketParam){
    clientID = clientIDParam;
    clientSecret = clientSecretParam;
    artist = artistParam;
    track = trackParam;
    market = marketParam;
}

void SpotifyAPI::getAccessToken(){

    curl = initCURL();

    url = "https://accounts.spotify.com/api/token";
    std::string post_data = "grant_type=client_credentials";

    std::string clientIDSecret = base64Encode(clientID + ":" + clientSecret);

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    std::string auth = "Authorization: Basic " + clientIDSecret;
    headers = curl_slist_append(headers, auth.c_str());

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &accessToken);

    CURLcode res = curl_easy_perform(curl);

    Json::Value root;
    Json::Reader reader;
    reader.parse(accessToken, root);
    accessToken = root["access_token"].asString();

    if (res == CURLE_OK) {
        std::cerr << "getAccessToken request successful!" << std::endl;
    }
    else {
        std::cerr << "getAccessToken request unsuccessful!" << std::endl;
        exit(1);
    }
}

std::string SpotifyAPI::base64Encode(const std::string& input) {
    
    static const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                        "abcdefghijklmnopqrstuvwxyz"
                                        "0123456789+/";
    std::string output;

    output.reserve((input.size() + 2) / 3 * 4);
    for (std::size_t i = 0; i < input.size(); i += 3) {
        unsigned int j = ((unsigned char)input[i]) << 16;
        if (i + 1 < input.size()) j |= ((unsigned char)input[i + 1]) << 8;
        if (i + 2 < input.size()) j |= ((unsigned char)input[i + 2]);

        output.push_back(base64_chars[(j >> 18) & 0x3F]);
        output.push_back(base64_chars[(j >> 12) & 0x3F]);
        if (i + 1 < input.size()) output.push_back(base64_chars[(j >> 6) & 0x3F]);
        if (i + 2 < input.size()) output.push_back(base64_chars[j & 0x3F]);
    }
    while (output.size() % 4 != 0) output.push_back('=');

    return output;
}

std::string SpotifyAPI::encodeURL(const std::string& URL){

    curl = initCURL();
    std::string encodedURL{"None"};

    char* encoded = curl_easy_escape(curl, URL.c_str(), URL.length());
    encodedURL = encoded;

    if (encodedURL == "None"){
        std::cerr << "URL encoding unsuccessful!" << std::endl;
        exit(1);
    }

    return encodedURL;
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

void SpotifyAPI::getAPIResponse(){

    getAccessToken();

    url = "https://api.spotify.com/v1/search?q=" + encodeURL(artist + " " + track) + "&type=track&market=" + market + "&limit=1";

    struct curl_slist* headers = nullptr;
    std::string auth_header = "Authorization: Bearer " + accessToken;
    headers = curl_slist_append(headers, auth_header.c_str());

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &APIresponse);

    CURLcode res = curl_easy_perform(curl);

    if (res == CURLE_OK) {
        std::cerr << "getAPIResponse request successful!" << std::endl;
    }
    else {
        std::cerr << "getAPIResponse request unsuccessful!" << std::endl;
        exit(1);
    }
}

std::string SpotifyAPI::getURL(){

    getAPIResponse();
    Json::Value root;
    Json::Reader reader;

    reader.parse(APIresponse, root);
    Json::Value items = root["tracks"]["items"];
    std::string trackURL = items[0]["preview_url"].asString();

    std::cout << "The track URL is: " << trackURL << std::endl;

    return trackURL;
}