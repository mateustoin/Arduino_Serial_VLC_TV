#include <iostream>
#include "ArduinoSerial.h"
#include "VLC.h"
#include <stdio.h> //Biblioteca necessária para usar getchar

using namespace std;


int main(int argc, char * argv[])
{ 
	VLC player;
	ArduinoSerial arduino ("/dev/ttyACM0"); //Cria um objeto da classe ArduinoSerial e tem a porta setada para o arduino como parâmetro
	int comando;
	player.Playlist(arduino); //Objeto da classe do player VLC que recebe um objeto de ArduinoSerial para conectar os dados seriais 
	
	return 0;
}