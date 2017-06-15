#ifndef ARDUINO_SERIAL_H
#define ARDUINO_SERIAL_H

/* www.chrisheydrick.com

   June 23 2012
   CanonicalArduinoRead write a byte to an Arduino, and then
   receives a serially transmitted string in response.
   The call/response Arduino sketch is here:
   https://gist.github.com/2980344
   Arduino sketch details at www.chrisheydrick.com
*/

/*Código modificado: 
  Junho de 2017
  Autor: Mateus Antonio da Silva
  Mudanças: >Código convertido de c para c++
  >Métodos que armazenam dados da porta serial em string e retornam como inteiros
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>

#define DEBUG 1

using namespace std;

class ArduinoSerial
{
    private:
        int fd;
        int n;
        int i;
        char buf[255];
        struct termios toptions;
    public:
        ArduinoSerial(string);
        void recebeSinal();
        int recebeSinali();
        void enviaSinal();
    protected:

};

#endif // ARDUINO_SERIAL_H