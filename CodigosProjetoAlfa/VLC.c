#include <stdio.h>
#include <stdlib.h>
#include <vlc/vlc.h>
#include <unistd.h>
 
 int main(int argc, char* argv[])
 {
     libvlc_instance_t * inst;
     libvlc_media_player_t *mp;
     libvlc_media_t *m;
     
     /* Carrega a engine VLC */
     inst = libvlc_new (0, NULL);
  
     /* Cria um item, aqui voce pode carregar qualquer arquivo de mídia */
     m = libvlc_media_new_path (inst, "/home/mateustoin/Documentos/Projeto_LP1/CodigosProjetoAlfa/Ed.mp4");
        
     /* Cria um objeto Media Player a partir de uma mídia */
     mp = libvlc_media_player_new_from_media (m);
     
     /* Não necessita manter a mídia agora */
     libvlc_media_release (m); 
 
     /* Inicia o media_player e toca a mídia */
     libvlc_media_player_play (mp);

    /* Espera a mídia tocar um pouco */
     sleep (1000); 
    
     /* Para de tocar */
     libvlc_media_player_stop (mp);
 
     /* Libera o media_player */
     libvlc_media_player_release (mp);
 
     libvlc_release (inst);
 
     return 0;
 }