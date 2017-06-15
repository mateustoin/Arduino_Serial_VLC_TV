 #include <stdio.h>
 #include <stdlib.h>
 #include <vlc/vlc.h>

int main(int argc, char* argv[])
{
	int i, command, resp;
	libvlc_media_player_t *mp;
	libvlc_instance_t *vlc;
	libvlc_media_list_t *ml;
	libvlc_media_list_player_t *mlp;
	libvlc_media_t *md1, *md2;
	
	// Carrega a engine VLC 
	vlc = libvlc_new (0, NULL);

	// Cria uma lista vazia
	ml = libvlc_media_list_new(vlc);	 
	// Cria um novo media_list_player
	mlp = libvlc_media_list_player_new(vlc);
	// Cria um objeto media_player vazio
	mp = libvlc_media_player_new(vlc);
	
	/*for(i=1; i < argc ; i++) { 		
        // Cria uma midia para certo arquivo 		
        md = libvlc_media_new_path (vlc, argv[i]); 		
        // Adiciona a instancia da midia a lista de midia 		
        libvlc_media_list_add_media (ml, md); 		 		
        printf (" > %s added to the playlist!\n", argv[i]);
	}*/




	md1 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Anel.mp4");
	md2 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Ed.mp4");
	/*md3 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/Hoje.mp4");
	md4 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/Medo.mp4");
	md5 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/No.mp4");
	md6 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/Trem.mp4");
	md7 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/Tua.mp4");
	md8 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/Zeca.mp3");*/
	libvlc_media_list_add_media (ml, md1);
	libvlc_media_list_add_media (ml, md2);







	// Configura a lista de midia associada com o player
	libvlc_media_list_player_set_media_list (mlp, ml);  
	// Substitui o media player em media_list_player com esta instancia
	//para mudar o volume
	libvlc_media_list_player_set_media_player(mlp, mp);
	resp = 1;
	while(resp) {
		command = getchar();
		switch(command)
		{
			case 's':	// para de tocar
				if(mlp) {
					libvlc_media_list_player_stop(mlp);
					printf ("STOP\n");
				}
				break;
				
			case 'n':	// proxima midia da lista
				if(mlp) {
					libvlc_media_list_player_next(mlp);
					printf ("PROXIMA\n");
				}
				break;
				
			case 'b':	// midia anterior da lista
				if(mlp) {
					libvlc_media_list_player_previous(mlp);
					printf ("ANTERIOR\n");
				}
				break;
				
			case 'q':	// sai e encerra o player
				printf("Adeus!\n");
				resp=0;
				break;
			
			case 'o':   /* pausa a midia atual */
				if(mlp) {
					libvlc_media_list_player_pause(mlp); 
					printf ("PAUSE\n");
				}
			break;
				
			case 'p':	// toca a lista
				if (mlp) {
					libvlc_media_list_player_play(mlp);
					printf ("PLAY\n");
				}
				break;			
		}
	}

	libvlc_release (vlc);

	return 0;
}