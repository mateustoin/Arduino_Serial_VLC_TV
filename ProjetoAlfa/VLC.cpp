#include "VLC.h"

VLC::VLC(){
	/* Carrega a engine VLC */
	inst = libvlc_new (0, NULL);

	/* Cria um item, aqui voce pode carregar qualquer arquivo de mídia */
    m = libvlc_media_new_path (inst, "/home/mateustoin/Documentos/Projeto_LP1/Ed.mp4");

    /* Cria um objeto Media Player a partir de uma mídia */
    mp = libvlc_media_player_new_from_media (m);

    /* Não necessita manter a mídia agora */
    libvlc_media_release (m);

    //Comandos da playlist//

    // Carrega a engine VLC 
	vlc = libvlc_new (0, NULL);

	// Cria uma lista vazia
	ml = libvlc_media_list_new(vlc);	 
	// Cria um novo media_list_player
	mlp = libvlc_media_list_player_new(vlc);
	// Cria um objeto media_player vazio
	mpp = libvlc_media_player_new(vlc);
	volume = 80;
	mute = 1;

}

void VLC::Play(){
	/* Inicia o media_player e toca a mídia */
	libvlc_media_player_play (mp);

    /* Espera a mídia tocar um pouco */
    	//sleep (1000); 
}

void VLC::Stop(){
	/* Para de tocar */
    libvlc_media_player_stop (mp);
 
    /* Libera o media_player */
    	//libvlc_media_player_release (mp);
 
    	//libvlc_release (inst);
}


void VLC::Playlist(ArduinoSerial &a){

	/*for(i=1; i < argc ; i++) { 		
        // Cria uma midia para certo arquivo 		
        md = libvlc_media_new_path (vlc, argv[i]); 		
        // Adiciona a instancia da midia a lista de midia 		
        libvlc_media_list_add_media (ml, md); 		 		
        printf (" > %s added to the playlist!\n", argv[i]);
	}*/

	/*md1 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Anel.mp4");
	md2 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Ed.mp4");
	md3 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/Hoje.mp4");
	md4 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/Medo.mp4");
	md5 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/No.mp4");
	md6 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/Trem.mp4");
	md7 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/Tua.mp4");
	md8 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/Playlist/Zeca.mp3");*/

	//Criação da playlist da TV
	md1 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/PlaylistTV/DiscoveryChannel.mp4");
	md2 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/PlaylistTV/Filme.mp4");
	md3 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/PlaylistTV/futebol.mp4");
	md4 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/PlaylistTV/Masterchief.mp4");
	md5 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/PlaylistTV/SilvioReiFinal.mp4");
	md6 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/PlaylistTV/SimpsonsFinal.mp4");
	md7 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/PlaylistTV/TemerGolpisto.mp4");
	md8 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/PlaylistTV/TheNoite.mp4");
	md9 = libvlc_media_new_path (vlc, "/home/mateustoin/Documentos/Projeto_LP1/PlaylistTV/TheVoice.mp4");

	libvlc_media_list_add_media (ml, md1);
	libvlc_media_list_add_media (ml, md2);
	libvlc_media_list_add_media (ml, md3);
	libvlc_media_list_add_media (ml, md4);
	libvlc_media_list_add_media (ml, md5);
	libvlc_media_list_add_media (ml, md6);
	libvlc_media_list_add_media (ml, md7);
	libvlc_media_list_add_media (ml, md8);
	libvlc_media_list_add_media (ml, md9);


	libvlc_media_release(md1);
    libvlc_media_release(md2);
    libvlc_media_release(md3);
    libvlc_media_release(md4);
    libvlc_media_release(md5);
    libvlc_media_release(md6);
    libvlc_media_release(md7);
    libvlc_media_release(md8);
    libvlc_media_release(md9);


	// Configura a lista de midia associada com o player
	libvlc_media_list_player_set_media_list (mlp, ml);  
	// Substitui o media player em media_list_player com esta instancia
	//para mudar o volume
	libvlc_media_list_player_set_media_player(mlp, mpp);
	resp = 1;
	while(resp) {
		comando = a.recebeSinali();
		switch(comando)
		{
			case 14:	// toca a lista
				if (mlp) {
					libvlc_media_list_player_play(mlp);
					cout << "Midia iniciada." << endl;
				}
				break;

			case 15:	// para de tocar (botão sleep)
				if(mlp) {
					libvlc_media_list_player_stop(mlp);
					cout << "Playlist interrompida." << endl;
				}
				break;

			case -1:	// sai e encerra o player (botão 2)
				cout << "Playlist encerrada." << endl;
				resp=0;
				break;

			case 0:	// seta canal
				if (mlp) {
					libvlc_media_list_player_play_item_at_index (mlp, 0);
					cout << "Canal: 1" << endl;
				}
				break;

			case 1:	// seta canal
				if (mlp) {
					libvlc_media_list_player_play_item_at_index (mlp, 1);
					cout << "Canal: 2" << endl;
				}
				break;

			case 2:	// seta canal
				if (mlp) {
					libvlc_media_list_player_play_item_at_index (mlp, 2);
					cout << "Canal: 3" << endl;
				}
				break;

			case 3:	// seta canal
				if (mlp) {
					libvlc_media_list_player_play_item_at_index (mlp, 3);
					cout << "Canal: 4" << endl;
				}
				break;

			case 4:	// Seta canal
				if (mlp) {
					libvlc_media_list_player_play_item_at_index (mlp, 4);
					cout << "Canal: 5" << endl;
				}
				break;

			case 5:	// Seta canal
				if (mlp) {
					libvlc_media_list_player_play_item_at_index(mlp, 5);
					cout << "Canal: 6" << endl;
				}
				break;

			case 6:	// Seta canal
				if (mlp) {
					libvlc_media_list_player_play_item_at_index(mlp, 6);
					cout << "Canal: 7" << endl;
				}
				break;

			case 7:	// Seta canal
				if (mlp) {
					libvlc_media_list_player_play_item_at_index(mlp, 7);
					cout << "Canal: 8" << endl;
				}
				break;

			case 8:	// Seta canal
				if (mlp) {
					libvlc_media_list_player_play_item_at_index(mlp, 8);
					cout << "Canal: 9" << endl;
				}
				break;

			case 9: //Aumentar volume
			if (mlp){
				if (volume == 200){
					volume = 190;
				}
				libvlc_audio_set_volume (mpp, volume += 10);
				cout << "Volume atual: " << volume << endl;
			}
			break;

			case 10: //Diminuir volume
			if (mlp){
				if (volume == 0){
					volume = 10;
				}
				libvlc_audio_set_volume (mpp, volume -= 10);
				cout << "Volume atual: " << volume << endl;
			}
			break;

			case 11:	// proxima midia da lista
				if(mlp) {
					libvlc_media_list_player_next(mlp);
					cout << "Avança: midia." << endl;
				}
				break;
				
			case 12:	// midia anterior da lista
				if(mlp) {
					libvlc_media_list_player_previous(mlp);
					cout << "Retrocede: midia." << endl;
				}
				break;
			
			case 13:   /* muta mídia */
				if(mlp) {
					if (mute == 0){
						libvlc_audio_set_mute(mpp, 0);
						mute++;
					}

					else if (mute == 1){
						libvlc_audio_set_mute(mpp, 1);
						mute--;
					}

					cout << "Midia pausada." << endl;
				}
			break;

			case 16:   /* pausa a midia atual */
				if(mlp) {
					libvlc_media_list_player_pause(mlp); 
					cout << "Midia pausada." << endl;
				}
			break;

		}
	}

	libvlc_release (vlc);
}