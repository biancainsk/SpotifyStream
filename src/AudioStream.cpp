#include <AudioStream.h>

AudioStream::~AudioStream(){
    curl_easy_cleanup(curl); // clean up and delete the curl handle
    curl = nullptr;
}

size_t AudioStream::writeCallBack(char* ptr, size_t size, size_t nmemb, std::vector<char>* buffer){

    size_t realsize = size * nmemb;
    buffer->insert(buffer->end(), ptr, ptr + realsize);
    return realsize;
}
static size_t WriteData(void *buffer, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(buffer, size, nmemb, (FILE *)stream);
    return written;
}

void AudioStream::saveSong(std::string URL){

    curl = initCURL();
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
    }

    std::ofstream file("output.bin", std::ios::out | std::ios::binary);
    file.write(reinterpret_cast<char*>(buffer.data()), buffer.size());
    file.close();
}

void AudioStream::getSongData(){

    SF_INFO info;
    SNDFILE *sndfile = sf_open("song.wav", SFM_READ, &info);
    if (!sndfile) {
        std::cout << "Error opening file: " << sf_strerror(sndfile) << "\n";
        exit(1);
    }

    std::cout << "Sample rate: " << info.samplerate << "\n";
    std::cout << "Number of channels: " << info.channels << "\n";
    std::cout << "Bit depth: " << info.format << "\n";

    sf_close(sndfile);
}


void AudioStream::decodePCM(){
    
}