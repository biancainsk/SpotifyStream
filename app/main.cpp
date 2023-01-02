#include <streamAPI.h>

int main(){

    std::string accessToken{"BQCIR0V19XkXL8el-TJ0MRLrH-hILvSMeCbEldP5PW3aGfMko_58XiShJnulULTivPKOrXP7jIDtsYYPCDOuWzMI2J1nxTIt-8243-meA5vgRFmxmdkdalmwYnGTaKFXWvQw5wnjtPHD1ZMii35mUGVAF7ht3Nk338WH1y6iKd7KeA3cCTjOG3KazSV0FFau5cDY"};
    std::string artist{"Mayhem"};
    std::string track{"Freezing Moon"};
    std::string market{"RO"};

    SpotifyAPI song1(accessToken, artist, track, market);
    song1.getURL();

    return 0;
}