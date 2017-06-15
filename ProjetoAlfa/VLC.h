#ifndef VLC_H
#define VLC_H

#include "ArduinoSerial.h"
#include <stdio.h>
#include <stdlib.h>
#include <vlc/vlc.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class VLC {
private:
	//Criados para normal
	libvlc_instance_t * inst;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;

    //Criados para playlist
    int i, comando, resp, volume, mute;
	libvlc_media_player_t *mpp;
	libvlc_instance_t *vlc;
	libvlc_media_list_t *ml;
	libvlc_media_list_player_t *mlp;
	libvlc_media_t *md1, *md2, *md3, *md4, *md5, *md6, *md7, *md8, *md9; //Cada "md" vai receber um endereço de vídeo para a playlist"


public:
	VLC();
	void Play();
	void Stop();
	void Playlist(ArduinoSerial&);
};

#endif