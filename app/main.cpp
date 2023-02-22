#include <SpotifyAPI.h>
#include <AudioStream.h>

int main(){

    std::string clientID{""}; // Enter your clientID for the Spotify Developer account
    std::string clientSecret{""}; // Enter your clientSecret for the Spotify Developer account
    std::string artist{"Mayhem"};
    std::string track{"Freezing Moon"};
    std::string market{"RO"};

    SpotifyAPI song1(clientID, clientSecret, artist, track, market);
    song1.getURL();

    AudioStream stream1;
    stream1.saveSong("https://p.scdn.co/mp3-preview/e191464008685582d91fb4a3a33d064021beb96b?cid=72b709a3e58646e69cad9ace78bb6269");
    stream1.getSongData();

    return 0;
}