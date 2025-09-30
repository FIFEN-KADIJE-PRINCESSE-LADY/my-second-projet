# A propos D'INF 231 : Structures de Données Dynamiques - Implémentation en C

## Statut et Description du Projet

> Le présent dépôt est la soumission du Travail Pratique d'INF 231, axé sur l'implémentation des algorithmes d'insertion pour différentes topologies de listes chaînées en langage C. 
>*Objectif Principal :* Démontrer une maîtrise complète de la gestion dynamique de la mémoire et des pointeurs pour concevoir des structures de données robustes et performantes.

##  Membres de l'Équipe

Notre projet a été développé en collaboration. 
| Nom du Membre | Matricule | Contribution / Responsabilité |
| *FIFEN-KADUE-PRINCESSE-LADY* | [24G2107] | *Coordination*, Tests Unitaires, Documentation Avancée du README.md. |
| *[KAMGA NGOKA HENRYKE LUDOVIK]* | [24F2750] | Développement et validation des Listes Chaînées *Triées* (Doubles). |
| *[TCHATCHOUA DAMI CLAUDIA]* | [24G2407] | Développement et validation des Listes *Circulaires* (Insertions Tête/Queue Doublement Chaînée). |
| *[BANDE FOTGNA ALEXIE ROSTELLE]* | [24G2750] | Développement et validation des Listes *Circulaires* (Insertions Tête/Queue Simplement Chaînée). |
| *[NGUELEFACK PRINCESSE]* | [24G2575] | Développement et validation des Listes Chaînées *Triées* (Simples). |
| *[TAPA FOTSO PASQUIN]* | [24G2868] |Développement et validation des Listes *Circulaires* (Insertions Tête/Queue Simplement Chaînée). |


## Répertoire des Fichiers Source

Chaque fichier C contient une *fonction main()* pour des tests d'exécution individuels et illustre une méthode d'insertion spécifique.

| Fichier C | Type de Structure | Rôle de l'Opération |
| *insertion_trie_simple.c* | Liste Simplement Chaînée | Assure que la liste reste *triée* après l'insertion (O(n)). |
| *insertion_trie_double.c* | Liste Doublement Chaînée | Assure que la liste reste *triée* ; mise à jour de *deux* pointeurs adjacents (suiv et prec). |
| *insertion_tete_queue_circulaire_simplement_chainée* | Liste Simplement Chaînée Circulaire | Insertion en *Tête* (Opération O(n) pour trouver la queue, ou O(1) si un pointeur sur la queue est maintenu). |
| *insertion_tete_queue_circulaire_double.chainée* | Liste Doublement Chaînée Circulaire | Insertion en *Tête* (Opération O(1)). |

##  Instructions de Compilation

Les fichiers peuvent être compilés à l'aide de l'outil standard gcc (GNU Compiler Collection) en ligne de commande.

### *Exemple d'Utilisation*

```bash
# 1. Compilation du programme :
# Le drapeau -o permet de nommer le fichier exécutable.
gcc insertion_trie_double.c -o trie_double_exec

# 2. Exécution du programme :
./trie_double_exec
