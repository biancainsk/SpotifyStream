#include <streamAPI.h>

int main(){

    std::string accessToken{"BQCPxGfyFEz5mtSSmHllRTC6z6_IObwg0uxhjrqge1I3DKiy57TGVNdSgSU6v1bIZOVVd3T-tZ2iBCUS-x1Chwc8srt6DPL6ApYlcAOwyKCc5X5lMjrHgNDztsOMAvtjZtp6Vm_tlcbt7x7K4_VpxYYB5HZceg5bxIoDfFE5-25vltoBadiuLs0lvd1cnMHB4lNf"};
    std::string artist{"Mayhem"};
    std::string track{"Freezing Moon"};

    SpotifyAPI song1(accessToken);
    song1.getURL(artist, track);

    return 0;
}