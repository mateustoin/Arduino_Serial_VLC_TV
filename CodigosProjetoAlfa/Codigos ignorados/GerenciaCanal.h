#ifndef GERENCIA_CANAL_H
#define GERENCIA_CANAL_H

#include "VLC.h"
#include "ArduinoSerial.h"
#include <string>

using namespace std;

class GerenciaCanal {
private:
	/*VLC player;
	ArduinoSerial arduino;*/	

public:
	GerenciaCanal();
	void iniciaPlaylist();

};

#endif