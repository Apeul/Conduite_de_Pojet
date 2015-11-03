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

void afficher_fichier(){
	FILE * fic;
	int nbr;
	char nom_fichier[20];
	printf("Quel fichier afficher ? "); 
	scanf("%s", nom_fichier);
	fic = fopen(nom_fichier,"r");
	if(fic != NULL){
		fscanf(fic, "%i", &nbr);
		while(!feof(fic)){
			printf("%i ", nbr);
			fscanf(fic, "%i", &nbr);
		}
		fclose(fic);
	}
	else{
	 	printf("Le fichier n'existe pas");
	 }
}
	
int main(void){
	creer_fichier();
	afficher_fichier();
	return 0;
}	