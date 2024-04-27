#include<stdio.h>
#include<stdlib.h>

void chiffrement_xor (char* texte, char* texte_chiffre, int longueur_texte, unsigned char cle){
	for(int i=0 ; i<longueur_texte; i++){
		texte_chiffre[i]= texte[i] ^ cle; //effectue un XOR entre chaque caractere et la cle 
	}
}

void dechiffrement_xor(char* texte_chiffre, char* texte_dechiffre, int longueur_texte, unsigned char cle){
	
	for(int i=0; i<longueur_texte; i++){
		texte_dechiffre[i]= texte_chiffre[i] ^ cle; //effectue un XOR entre chaque caractere chiffre et cle 
	}
}


int main (){
	FILE* file;
	char* texte_chiffre;
	char* texte_dechiffre;
	int taille;
	
	//ouvrir le fichier binaire en mode read
	file = fopen("test.bin","rb");
	if (file == NULL){
		printf("le fichier n'a pas pu etre ouvert");
		return 1;
	}
	
	//determiner la taille du fichier
	fseek(file,0,SEEK_END);
	taille = ftell(file);
	rewind (file);
	
	//allouer la memoire pour le texre chiffre et dechiffre
	texte_chiffre = (char*)malloc(taille);
	texte_dechiffre = (char*)malloc(taille);
	
	if(texte_chiffre == NULL || texte_dechiffre== NULL){
		printf("erreur de l'allocation de memoire ");
		fclose(file);
		return 1;
	}
	
	//lire le texte chiffre depuis le fichier
	fread(texte_chiffre,1,taille,file);
	
	//fermer le fichier
	fclose(file);
	
	//dechiffrer le texte
	unsigned char cle = 0xAB; //cle
	dechiffrement_xor (texte_chiffre, texte_dechiffre, taille, cle);
	
	//afficher le texte dechiffre 
	printf("texte dechiffre : %s\n", texte_dechiffre);
	
}
