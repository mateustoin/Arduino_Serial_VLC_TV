# Arduino_Serial_VLC_TV
  Com este código é possível controlar um player de vídeo (**VLC**) com um controle remoto, utilizando um arduino e sensor IR para capturar os comandos.
   Através da **comunicação serial** na porta USB, o comando capturado ganham funcionalidades para o controle do player.
   
## Projeto
Datasheet do sensor IR:

![Datasheet sensor](https://github.com/mateustoin/Arduino_Serial_VLC_TV/blob/master/TSOP%20IR%20receiver.PNG)

Segue em anexo o esquema do arduino.

![Projeto do arduino receptor de sinais IR](https://github.com/mateustoin/Arduino_Serial_VLC_TV/blob/master/Sketch_IR_rec.png)

## Instalando
Bibliotecas do IR Receiver e VLC
### IR Receiver
Você pode encontrar a biblioteca em: [Biblioteca IRremote](https://github.com/z3t0/Arduino-IRremote)

#### Ubuntu
>sudo apt-get update

>sudo apt-get install libvlc-dev

Caso nã tenha o VLC insalado no sistema, talvez dê alguns erros de plugin. Então instale o software também:

>sudo apt-get install vlc

### Windows
`Código não testado no Windows`


## Compilando
Exemplo de compilação com a libvlc

>g++ exemplo.cpp -o example -lvlc

Necessário utilizar a flag `-lvlc`

## Arquivos
Dentre os arquivos está o esquema do projeto para construir o projeto de receptor IR com arduino, código fonte do arduino e as classes 
necessárias para compilar o código em C++. O código original da biblioteca ArduinoSerial se encontra [aqui](https://salilkapur.wordpress.com/2013/03/08/communicating-with-arduino-using-c/).
