#include <stdio.h>
#include <stdlib.h>

// Définition de la structure de la liste
typedef struct Noeud {
    int donnee;
    struct Noeud* suivant;
} Noeud;

// Fonction pour créer un nouveau noeud
Noeud* creerNoeud(int donnee) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->donnee = donnee;
    nouveau->suivant = NULL;
    return nouveau;
}

// Fonction pour insérer un élément en fin de liste
void insererEnFin(Noeud** tete, int donnee) {
    Noeud* nouveau = creerNoeud(donnee);
    if (*tete == NULL) {
        *tete = nouveau;
    } else {
        Noeud* temp = *tete;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }
}

// Fonction pour afficher la liste
void afficherListe(Noeud* tete) {
    Noeud* temp = tete;
    while (temp != NULL) {
        printf("%d ", temp->donnee);
        temp = temp->suivant;
    }
    printf("\n");
}

// Fonction pour supprimer toutes les occurrences d'un élément
void supprimerOccurrences(Noeud** tete, int valeur) {
    // Supprimer les occurrences en tête
    while (*tete != NULL && (*tete)->donnee == valeur) {
        Noeud* temp = *tete;
        *tete = (*tete)->suivant;
        free(temp);
    }

    // Supprimer les occurrences dans le reste de la liste
    Noeud* temp = *tete;
    while (temp != NULL && temp->suivant != NULL) {
        if (temp->suivant->donnee == valeur) {
            Noeud* noeudASupprimer = temp->suivant;
            temp->suivant = temp->suivant->suivant;
            free(noeudASupprimer);
        } else {
            temp = temp->suivant;
        }
    }
}

int main() {
    Noeud* tete = NULL;
    int n, valeur;

    // Créer une liste avec des éléments
    printf("Entrez le nombre d'éléments : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Entrez l'élément %d : ", i + 1);
        int donnee;
        scanf("%d", &donnee);
        insererEnFin(&tete, donnee);
    }

    // Afficher la liste
    printf("Liste : ");
    afficherListe(tete);

    // Lire l'élément à supprimer
    printf("Entrez la valeur à supprimer : ");
    scanf("%d", &valeur);

    // Supprimer les occurrences
    supprimerOccurrences(&tete, valeur);

    // Afficher la liste après suppression
    printf("Liste après suppression : ");
    afficherListe(tete);

    return 0;
}