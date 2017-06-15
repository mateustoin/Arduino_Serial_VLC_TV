#include "ArduinoSerial.h"

ArduinoSerial::ArduinoSerial(string porta)
{
    fd = open(porta.c_str(), O_RDWR | O_NOCTTY);
    cout << "Conexao Estabelecida: " <<  fd << endl;
    n = 0;
    //construtor
}

void ArduinoSerial::recebeSinal(){ //Método que recebe continuamente o que entra na porta serial e exibe na tela
    /* Espera o Arduino dar reboot */
	usleep(35000);

  	/* Pega as configurações da porta serial */
  	tcgetattr(fd, &toptions);
  	/* Seta uma frequência de 9600 para os dois lados */
  	cfsetispeed(&toptions, B9600);
  	cfsetospeed(&toptions, B9600);
  	/* 8 bits, no parity, no stop bits */
  	toptions.c_cflag &= ~PARENB;
  	toptions.c_cflag &= ~CSTOPB;
  	toptions.c_cflag &= ~CSIZE;
  	toptions.c_cflag |= CS8;
  	/* Canonical mode */
  	toptions.c_lflag |= ICANON;
  	/* commit the serial port settings */
  	tcsetattr(fd, TCSANOW, &toptions);

  	/* Send byte to trigger Arduino to send string back */
      //write(fd, "0", 1);


  	/* Recebe string do Arduino*/

  	while (1){
      //Armazena no buffer o que está entrando na porta
    	n = read(fd, buf, 255);
      
      // insere uma terminação 0 na string do buffer 	
      buf[n] = 0;

    	//n é o número de bytes recebidos e buf o que foi recebido do arduino
      cout << n << " bytes lidos. " << buf << endl;

 	}
}

int ArduinoSerial::recebeSinali(){ //Método que pega o dado armazenado no buffer, converte em inteiro e retorna
  // Espera o reboot do arduino
	usleep(350);

	/* Pega a configuração da porta serial */
	tcgetattr(fd, &toptions);
	/* Seta frequência 9600 para os dois lados */
	cfsetispeed(&toptions, B9600);
	cfsetospeed(&toptions, B9600);
	/* 8 bits, no parity, no stop bits */
	toptions.c_cflag &= ~PARENB;
	toptions.c_cflag &= ~CSTOPB;
	toptions.c_cflag &= ~CSIZE;
	toptions.c_cflag |= CS8;
	/* Canonical mode */
	toptions.c_lflag |= ICANON;
	/* commit the serial port settings */
	tcsetattr(fd, TCSANOW, &toptions);

	/* Send byte to trigger Arduino to send string back */
    //write(fd, "0", 1);
	/* Recebe string do Arduino*/

 	n = read(fd, buf, 255);
  /* insere uma terminação 0 na string do buffer */
  buf[n] = 0;

  return atoi(buf);
}