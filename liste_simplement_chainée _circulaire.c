#include <stdio.h>
#include <stdlib.h>
typedef struct cellule{
int val;
struct cellule *suiv;
}cellule;
int main()
{
cellule *l= NULL,*q,*p;
int v,i,n,choix;
printf("Combien d'element voulait vous inserer?: ");
scanf("%d",&n);
printf("Insertion en tete (1) ou en queue (2)?: ");
scanf("%d",&choix);
for(i=0;i<n;i++){
printf("Entrez l'element a inserer: ");
scanf("%d",&v);
p=(cellule*)malloc(sizeof(cellule));
p->val=v;
if(l==NULL){
    p->suiv=p;
    l=p;
}else{
q=l;
while(q->suiv!=l){
      q=q->suiv;
}
if(choix==1){
    q->suiv=p;
    p->suiv=l;
    l=p;
} else{
    q->suiv=p;
    p->suiv=l;
}
}
}
printf("\nLa liste circulaire contient: ");
if(l!=NULL){
    p=l;
    do{
    printf("%d",p->val);
    p=p->suiv;
    }while(p!=l);
}
printf("\n");
return 0;
}
