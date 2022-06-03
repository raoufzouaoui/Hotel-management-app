
#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"

int affichermenu(HOTEL h) {
 int n;
 printf("**********************gestion de l'hotel******************************* \n ");
 printf("notre hotel %s\n", h.nom);// se trouve %s %s %s %s %d \n, pour plus d'information contacter %d\n",h.nom,h.adresshotel.rue,h.adresshotel.ville,h.adresshotel.gouv,h.adresshotel.cdpost,h.numtel);
 printf(" choisir l'une des instruction suivantes : \n");
 printf(" **1- ajouter un client \n");
 printf(" **2- retirer un client \n");
 printf(" **3- modifier un client \n");
 printf(" **4- afficher les details des clients \n ");
 printf(" **5- ajouter une reclamation \n");
 printf(" **6- afficher les factures des clients \n");
 printf(" **7- recherche d'un client \n");
 printf(" **8- afficher les reclamations des clients \n");
 printf(" **9- afficher le factures d'un client \n");
 printf(" **10- quitter \n");
 do{
    scanf("%d",&n);
    }
 while ((n>10)||(n<1));


 return n;
}


void afficherfacture(HOTEL h){

    printf("choisir le numcin de client \n");
        int numcin;
        scanf("%d",&numcin);
    int pos=RechercherClient(numcin,(h.tabclient),h.nbclient);
    if(pos==-1)
    {
        printf("client introuvable! Svp verifier les informations\n");
    }
    else{
     printf("le client : %d\n",h.tabclient[pos].numcin);
     printf("le numroom est: %d\n",h.tabclient[pos].numroom);
     printf("la facture est: %d\n",h.tabclient[pos].facture);
     printf("\n");
     }
}


void afficherlesfacture(HOTEL h){

 for(int i=0;i<h.nbclient;i++)
     {printf("le client est: %d\n",h.tabclient[i].numcin);
     printf("le numroom est: %d\n",h.tabclient[i].numroom);
     printf("la facture est: %d\n",h.tabclient[i].facture);
     printf("\n");
     }
}

void afficherreclamation(HOTEL h)
{
    for(int j=0;j<h.nbclient;j++)
    {
    printf("%d",h.tabclient[j].nbrec);
    for(int i=0;i<h.tabclient[j].nbrec;i++)
    {
       printf(" numcin de client: %d\n ", h.tabclient[j].tabrec[i].numcin );
       printf(" numroom est : %d\n ", h.tabclient[j].tabrec[i].numroom );
       printf(" date de reclamation est: %d  %d  %d \n" , h.tabclient[j].tabrec[i].daterec.jour ,h.tabclient[j].tabrec[i].daterec.mois ,h.tabclient[j].tabrec[i].daterec.annee);
       printf(" contenu : %s \n", h.tabclient[j].tabrec[i].contenu);

       printf("\n");
    }
    printf("\n");
    }
}


void ajouterreclamation(HOTEL *h){
    RECLAMATION r;
    printf("donner le numcin du client :\n");
    scanf("%d", &(r.numcin));

    while(RechercherClient(r.numcin,(h->tabclient),h->nbclient)==-1)
    {
        printf("le client n'existe pas\n");
        printf("saisir numcin\n");
        scanf("%d",&(r.numcin));
    }
    printf("donner la date : \n");
    scanf("%d%d%d",&(r.daterec.jour),&(r.daterec.mois),&(r.daterec.annee));
    printf("ecrire votre reclamation :\n");
    scanf("%s",r.contenu);

    int s=RechercherClient(r.numcin,(h->tabclient),h->nbclient);
    /*
    printf("%d", (h->tabclient[s].nbrec+1));
    Sh->tabclient[s].tabrec = (RECLAMATION *) realloc ( h->tabclient[s].tabrec, (h->tabclient[s].nbrec+1) * sizeof (RECLAMATION) );
    printf("3xxxxxxxxxx\n");
    h->tabclient[s].nbrec++;
    h->tabclient[s].tabrec[h->tabclient[s].nbrec-1]=r;  */
}








void ajouterclient( HOTEL *h)
   {    CLIENT c;
        printf("saisir numcin\n");
        scanf("%d",&c.numcin);
        while(RechercherClient(c.numcin,(h->tabclient),h->nbclient)!=-1)
        {
            printf("le client est deja existe\n");
            printf("saisir numcin\n");
            scanf("%d",&c.numcin);
        }
        printf("saisir  nom client\n");
        scanf("%s",c.nom);
        printf("saisir  prenom client\n");
        scanf("%s",c.prenom);
        printf("saisir age client\n");
        scanf("%d",&c.age);
        printf("saisir datenaissence\n");
        scanf("%d%d%d",&c.datenaiss.jour,&c.datenaiss.mois,&c.datenaiss.annee);
        printf("saisir ladresse\n");
        scanf("%s%s%s%d",c.ladresse.rue,c.ladresse.ville,c.ladresse.gouv,&c.ladresse.cdpost);
        printf("saisir facture\n");
        scanf("%d",&c.facture);
        printf("saisir le num de room\n");
        scanf("%d",&c.numroom);
        while(Rechercherchambre(c.numroom,(h->tabclient),h->nbclient)!=-1)
        {
            printf("le numroom est deja existe\n");
            printf("saisir numroom\n");
            scanf("%d",&c.numroom);
        }
        h->tabclient = (CLIENT *)realloc (h->tabclient, (h->nbclient+1) * sizeof(CLIENT));
        h->nbclient++;
        h->tabclient[h->nbclient-1]=c;

   }


   int Rechercherchambre(int numroom, CLIENT *tab, int n){
       int i=0,pos=-1;
    while(numroom!=(*(tab+i)).numroom && (i<n))
    {
        i++;
    }
    if(i<n)
        pos=i;
    return pos;


}


int RechercherClient(int numcin, CLIENT *tab, int n){
       int i=0,pos=-1;
    while(numcin!=(*(tab+i)).numcin && i<n)
    {
        i++;
    }
    if(i<n)
        pos=i;
    return pos;
}



void retirerclient(HOTEL*h){
    printf("choisir le numcin de client a retire\n");
        int numcin;
        scanf("%d",&numcin);
        int i;
        if(RechercherClient(numcin,(h->tabclient),h->nbclient)==-1)
            printf("client introuvable! svp verifier les information entrees\n");
        else{
            if(h->nbclient ==1)
            {
                h->tabclient = (CLIENT*)malloc(1*sizeof(CLIENT));
            }
            else{
                for(i=RechercherClient(numcin,h->tabclient,h->nbclient );i<h->nbclient ;i++)
                {
                    h->tabclient[i]=h->tabclient[i+1];
                }
            }
            h->nbclient--;
            printf("client supprimee!\n");
        }
}

void modifierclient(HOTEL*h){

     printf("choisir le numcin de client a modifier\n");
        int numcin;
        scanf("%d",&numcin);
    int pos=RechercherClient(numcin,(h->tabclient),h->nbclient);
    if(pos==-1)
    {
        printf("client introuvable! Svp verifier les informations\n");
    }
    else{
            printf("Modification de client : %d \n", numcin);
            printf("modifier le num de room\n");
            scanf("%d",&(((h->tabclient)[pos]).numroom));
            printf("modifier l'age\n");
            scanf("%d",&(((h->tabclient)[pos]).age));
            printf("modifier l'adresse\n");
            scanf("%d%d%d",&(((h->tabclient)[pos]).datenaiss.jour),&(((h->tabclient)[pos]).datenaiss.mois),&(((h->tabclient)[pos]).datenaiss.annee));

    }
}

void affichierclient(HOTEL h)
{ printf("%d",h.nbclient);
    for(int i=0;i<h.nbclient;i++)
      {

       printf(" numcin de client: %d\n ", h.tabclient[i].numcin );
       printf(" son nom est : %s\n ", h.tabclient[i].nom );
       printf(" son prenom est :  %s \n", h.tabclient[i].prenom);
       printf(" son age est : %d \n", h.tabclient[i].age  );
       printf(" son date de naissance est: %d  %d  %d \n" , h.tabclient[i].datenaiss.jour ,h.tabclient[i].datenaiss.mois ,h.tabclient[i].datenaiss.annee);
       printf(" son adress est : %s  %s  %s  %d\n",h.tabclient[i].ladresse.rue ,h.tabclient[i].ladresse.ville, h.tabclient[i].ladresse.gouv ,h.tabclient[i].ladresse.cdpost);
       printf ("son num de numroom est : %d \n", h.tabclient[i].numroom );
       printf(" facture : %d \n", h.tabclient[i].facture);

       printf("\n");
      }

}
