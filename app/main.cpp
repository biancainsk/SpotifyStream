#include <streamAPI.h>

int main(){

    std::string clientID{"..."}; // Enter your clientID for the Spotify Developer account
    std::string clientSecret{"..."}; // Enter your clientSecret for the Spotify Developer account
    std::string artist{"Mayhem"};
    std::string track{"Freezing Moon"};
    std::string market{"RO"};

    SpotifyAPI song1(clientID, clientSecret, artist, track, market);
    song1.getURL();

    return 0;
}