#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED

struct date {
    int jour;
    int mois;
    int annee;
};
typedef struct date DATE ;

struct adress{
    char rue[50];
    char ville[50];
    char gouv[50];
    int cdpost;
};
typedef struct adress ADRESS;

struct reclamation {
  int numcin;
  int numroom ;
  DATE daterec;
  char contenu[50];
};
typedef struct reclamation RECLAMATION;


struct client {
   char nom[50];
   char prenom[50];
   int age;
   DATE datenaiss ;
   ADRESS ladresse;
   int numcin;
   int facture;
   int numroom;
   int nbrec;
   RECLAMATION *tabrec;

} ;
typedef struct client CLIENT;

struct room {
   int prix;
   int etage;
   char etat[20];
   int numroom;
   int nblit;
};
typedef struct room ROOM;





struct hotel{
  char nom[20];
  ADRESS adresshotel;
  int numtel;
  int nbroom;
  int nbroomposib;
  int nbclient;
  CLIENT *tabclient;
  ROOM *tabroom;
};
typedef struct hotel HOTEL;



int affichermenu(HOTEL);
void ajouterclient(HOTEL*);
int RechercherClient(int, CLIENT *, int );
int Rechercherchambre(int, CLIENT *, int );
void retirerclient(HOTEL*);
void modifierclient(HOTEL* );
void affichierclient(HOTEL);
void ajouterreclamation(HOTEL*  );
void afficherreclamation(HOTEL);
void afficherlesfacture (HOTEL   );
void afficherfacture (HOTEL   );





#endif // HOTEL_H_INCLUDED
