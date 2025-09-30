#include <stdio.h>
#include <stdlib.h>

// Structure du nœud
typedef struct Noeud {
    int donnee;
    struct Noeud* suiv;
} Noeud;

// Fonction pour créer un nouveau nœud
/*Noeud* creerNoeud(int donnee) {
    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    nouveauNoeud->donnee = donnee;
    nouveauNoeud->suiv = NULL;
    return nouveauNoeud;
}*/

// Fonction pour insérer un élément dans une liste triée
void insererDansListeTrie(Noeud** tete, int donnee) {
    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    nouveauNoeud->donnee = donnee;
    nouveauNoeud->suiv = NULL;
  /*  Noeud* nouveauNoeud = creerNoeud(donnee);*/

    // Cas où la liste est vide ou le nouveau nœud doit être inséré en tête
    if (*tete == NULL || (*tete)->donnee >= donnee) {
        nouveauNoeud->suiv = *tete;
        *tete = nouveauNoeud;
    } else {
        Noeud* temp = *tete;
        while (temp->suiv != NULL && temp->suiv->donnee < donnee) {
            temp = temp->suiv;
        }
        nouveauNoeud->suiv = temp->suiv;
        temp->suiv = nouveauNoeud;
    }
}

// Fonction pour afficher la liste
void afficherListe(Noeud* tete) {
    while (tete != NULL) {
        printf("%d ", tete->donnee);
        tete = tete->suiv;
    }
    printf("\n");
}

int main() {
    Noeud* tete = NULL;
    int i=0,n, valeur;

    printf("Entrer le nombre d'éléments à insérer : ");
    scanf("%d", &n);
    while(i<n){
   // for (int i = 0; i < n; i++) {
        printf("Entrer l'élément %d : ", i + 1);
        scanf("%d", &valeur);
        insererDansListeTrie(&tete, valeur);
  //  }
    i=i+1;
    }

    printf("Liste triée : ");
    afficherListe(tete);

    // Insérer un nouvel élément
    printf("Entrer un nouvel élément à insérer : ");
    scanf("%d", &valeur);
    insererDansListeTrie(&tete, valeur);

    printf("Liste triée après insertion : ");
    afficherListe(tete);

    return 0;
}
