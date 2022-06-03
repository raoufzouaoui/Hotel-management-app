# Rapport Mini Projet Gestion d’un Hotel

Mon mini projet est un système de gestion d’un Hotel, il va aider la receptionniste à bien gérer son travail,
en organisant les clients, leurs informations, leur état, etc... Notre programme contient 
plusieurs structures et fonctions dans le but de simplifier la tache et pour que notre programme soit bien exécutable et lisible.


## Les structures :

#### • DATE elle est constituée de : 

Jour (entier)
Mois (entier)
Année (entier)

#### • ADRESSE , elle est constituée de :

Rue (chaine de caractères )
Ville (chaine de caractères )
Gouv  (chaine de caractères )
Codepostale (entier)

#### • ROOM, elle est constituée de :
 
prix (entier)
etage (entier)
etat (chaine de caractères)
numroom (entier)
nblit (entier)


#### • CLIENT, elle est constituée de :

nom (chaine de caractères)
prenom (chaine de caractères)
numcin (entier)
age (entier)			
datenaiss (DATE)
Num_tel (entier)
ladresse (ADRESSE)
facture (entier)
entier (entier)
reclam (RECLAMATION)


#### • RECLAMATION, elle est constituée de :

nom (chaine de caractères)
numroom (entier)
daterec (DATE)
contenu (chaine de caractères)


#### • HOTEL, elle est constituée de :

nom
adresshotel
numtel
nbroom;
nbroomposib
nbclient
CLIENT *tabclient (tableau dynamique de CLIENT)
ROOM *tabroom (tableau dynamique de ROOM)

## Les fonctions : 
• affichermenu • ajouterclient • RechercherClient • modifierclient 
• retirerclient • affichierclient  • affichierlesclient
• afficherfacture • afficherlesfacture
• ajouterreclamation • affichierreclamation 


#### Fonction affichermenu :
Cette fonction est appelée au début de programme, elle affiche un sommaire avec lequel l’utilisateur va savoir les opérations possibles avec notre système.
Enfin la fonction permet à l’utilisateur de choisir la commande qu’il veut faire en entrant le numéro de choix voulu au clavier .

#### Fonction ajouterclient :
Cette fonction a pour but d’ajouter un client dans le tableau dynamique « hotel.tabclient ».Elle prend comme paramètre le tableau dynamique.
Elle fait appel à la fonction RechercherClient pour vérifier si le client existe ou non.
Si oui le client est ajouté, sinon le message « Le client est deja existe » s’affiche.

#### Fonction RechercherClient :
Cette fonction a pour but de vérifier si un client donner existe ou non,Elle prend en paramètre le numcin de client, le tableau dynamique de client et le nombres des clients.
Et elle donne la position de client dans le tableau s’il existe, sinon elle return -1.
Cette fonction sera utile dans plusieurs fonctions dans la suite.

#### Fonction modifierclient :
Le rôle de cette fonction est de mettre à jour les détails d’un client à partir d'un numcin entré au clavier.En fait, elle prend comme paramètres le numcin de client, un tableau dynamique des clients et sa longueur.
On vérifie d'abord si le client avec le numcin donné existe déjà et ce avec l'appel de la fonction RechercherClient .
Si le client existe, on modifie numroom de client, son datenaiss et son age . Sinon,
la fonction affiche le message « client introuvable ! Svp vérifier les informations »

#### Fonction retirerclient :
Cette fonction a pour but de supprimer un client à partir d'un numcin entré au clavier.Elle prend comme paramètres le HOTEL* .
On vérifie d'abord si le client avec le numcin entré au clavier et ce avec l'appel de la fonction RechercherClient.
Si le client existe, on supprime le client en utilisant un variable aux et la fonction realloc . Sinon,
la fonction affiche le message « client introuvable ! Svp vérifier les informations »

#### Fonction affichierclient :
Le rôle de cette fonction est d’afficher les détails d’un seul client :les informations personnelles. 
On fait entrer le numcin du client et la fonction va faire appel à la fonction RechercherClient qui utilise se numcin pour tester si ce Client existe (enregistré) ou non avant l’affichage

#### Fonction affichierlesclient : 
Dans cette fonction Tous les détails de tous les clients seront affichés en utilisant une boucle For.

#### Fonction afficherfacture :
Le rôle de cette fonction est d’afficher la facture d’un seul client .
On fait entrer le numcin du client et la fonction va faire appel à la fonction RechercherClient qui utilise se numcin pour tester si ce Client existe (enregistré) ou non avant l’affichage

#### Fonction afficherlesfacture :
Dans cette fonction Tous les factures de tous les clients seront affichés en utilisant une boucle For.


#### Fonction ajouterreclamation :
Cette fonction a pour but d’ajouter une reclamation dans le tableau dynamique « hotel.tabclient.tabrec », Elle prend comme paramètre le tableau dynamique.
Elle fait appel à la fonction RechercherClient pour vérifier si le client existe ou non.
Si oui le client est ajouté, sinon le message « Le client est deja existe » s’affiche.

#### Fonction affichierreclamation :
Le rôle de cette fonction est d’afficher les détails d’une reclamation d'un seul client , On fait entrer le numcin du client et la fonction va faire appel à la fonction RechercherClient qui utilise se numcin pour tester si ce Client existe (enregistré) ou non avant l’affichage 
et la fonction Rechercherchambre qui utilise se numroom pour tester si ce le room reservé ou non .


