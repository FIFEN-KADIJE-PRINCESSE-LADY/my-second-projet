#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du nœud
typedef struct Noeud {
    int donnee;
    struct Noeud* suivant;
    struct Noeud* precedent;
} Noeud;

// Fonction pour créer un nouveau nœud
Noeud* creerNoeud(int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire!\n");
        exit(1);
    }
    nouveau->donnee = valeur;
    nouveau->suivant = nouveau;
    nouveau->precedent = nouveau;
    return nouveau;
}

// Fonction pour insérer en tête
Noeud* insererEnTete(Noeud* tete, int valeur) {
    Noeud* nouveau = creerNoeud(valeur);

    // Si la liste est vide
    if (tete == NULL) {
        return nouveau;
    }

    // Trouver le dernier nœud
    Noeud* dernier = tete->precedent;

    // Insertion en tête
    nouveau->suivant = tete;
    nouveau->precedent = dernier;
    dernier->suivant = nouveau;
    tete->precedent = nouveau;

    return nouveau; // La nouvelle tête
}

// Fonction pour insérer en queue
Noeud* insererEnQueue(Noeud* tete, int valeur) {
    Noeud* nouveau = creerNoeud(valeur);

    // Si la liste est vide
    if (tete == NULL) {
        return nouveau;
    }

    // Trouver le dernier nœud
    Noeud* dernier = tete->precedent;

    // Insertion en queue
    nouveau->suivant = tete;
    nouveau->precedent = dernier;
    dernier->suivant = nouveau;
    tete->precedent = nouveau;

    return tete; // La tête reste inchangée
}

// Fonction pour afficher la liste dans le sens direct
void afficherListe(Noeud* tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }

    Noeud* temp = tete;
    printf("Liste (sens direct): ");
    do {
        printf("%d ", temp->donnee);
        temp = temp->suivant;
    } while (temp != tete);
    printf("\n");
}

// Fonction principale
int main() {
    Noeud* tete = NULL;
    int choix, valeur;

    printf("=== Liste Doublement Chainee Circulaire ===\n\n");

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Inserer en tete\n");
        printf("2. Inserer en queue\n");
        printf("3. Afficher la liste\n");
        printf("4. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur a inserer en tete: ");
                scanf("%d", &valeur);
                tete = insererEnTete(tete, valeur);
                printf("Valeur %d inseree en tete avec succes!\n", valeur);
                break;

            case 2:
                printf("Entrez la valeur a inserer en queue: ");
                scanf("%d", &valeur);
                tete = insererEnQueue(tete, valeur);
                printf("Valeur %d inseree en queue avec succes!\n", valeur);
                break;

            case 3:
                afficherListe(tete);
                break;


            default:
                printf("Choix invalide! Veuillez reessayer.\n");
        }
    }

    return 0;
}
