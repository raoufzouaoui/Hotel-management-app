
#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"
#include"hote.c"
int main()
{
   int choix;
   int numcin;
   HOTEL h;
    ;
   printf("saisie les info de l'hotel \n");
   printf("saisie le nom de l'hotel \n");
   scanf("%s",h.nom);
   printf("saisie l'adress:rue,ville,gouv,codepostal \n");
   scanf(" %s %s %s %d",h.adresshotel.rue,h.adresshotel.ville,h.adresshotel.gouv,&h.adresshotel.cdpost);
   printf("saisir le num de telephone \n");
   scanf("%d",&h.numtel);
   printf("saisir le nb de chambre totale \n");
   scanf("%d",&h.nbroom);
   printf(" saisie le nb de chambre dispo \n");
   scanf("%d", &h.nbroomposib);
   while(h.nbroomposib>h.nbroom)
   {
       printf(" Erreur saisie le nb de chambre dispo \n");
       scanf("%d", &h.nbroomposib);
   }
   h.tabclient=(CLIENT *) malloc ( h.nbclient*sizeof (CLIENT ));
   if (!(h.tabclient)) exit(-1);
   h.tabroom=(ROOM *) malloc ( h.nbroom*sizeof (ROOM ));
   if(!(h.tabroom)) exit(-1);
   //n=affichermenu(h);


   while(choix!=11){
        choix=affichermenu(h);
   switch (choix)
   {
      case 1: ajouterclient(&h);break;
      case 2: retirerclient(&h);break;
      case 3: modifierclient( &h);break;
      case 4:affichierclient(h);break;
      case 5:ajouterreclamation(&h);break;
      case 6:afficherlesfacture( h);break;
      case 7:{
          printf("donner le numcin client rechercher\n");
          scanf("%d",&numcin);
          printf("%d\n",RechercherClient(numcin, h.tabclient ,h.nbclient));
          };break;
      case 8:afficherreclamation( h);break;
      case 9:afficherfacture( h);break;
      case 10: break;

   }
   }


    return 0;
}
