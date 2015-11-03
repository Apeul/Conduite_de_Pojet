#include <stdio.h>

/* crée un fichier qui stocke une série d'entiers positifs
   La série se termine à -1 */
   
void creer_fichier(){
	FILE * fic;
	int nbr;
	char nom_fichier[20];
	printf("Où stocker les nombres ? ");   //Permet la création du fichier de stockage
	scanf("%s", nom_fichier);
	fic = fopen(nom_fichier,"w+");
	scanf("%i", &nbr);
	while(nbr != -1){
		fprintf(fic, "%i ", nbr);
		scanf("%i", &nbr);
		}
	fclose(fic);
}

void compte_mots(){
	FILE * fic;
	char car;
	int espace;
	int alaligne;
	int caractere;
	char nom_fichier[20];
	printf("Quel fichier traiter ? "); 
	scanf("%s", nom_fichier);
	fic = fopen(nom_fichier,"r");
	if(fic != NULL){
		fscanf(fic, "%c", &car);
		while(!feof(fic)){
			fscanf(fic, "%c", &car);
			if(car == ' '){
				espace++;
			}
			else if(car == '\n'){
				alaligne++;
			}
			else{
				caractere++;
			}
		}
		fclose(fic);
	}
	else{
	 	printf("Le fichier n'existe pas");
	}
	printf("Il y a %i caractere, %i lignes, %i mots \n", caractere, alaligne, alaligne+espace);
}
	
int main(void){
	compte_mots();	
	return 0;
}	