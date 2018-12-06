#include <stdio.h>

void afficheTab(int tab[], int taille){
  int i;
  for(i = 0; i < taille; i++) {
      
    printf("%d\n",tab[i]);
    }

}

void changeTab(int tab[], int indice){
  tab[indice]+=2;/*ajoute 2*/
  printf("Les adresses de t et t[0] dans la fonction changeTab() sont : %p et %p\n",tab, &(tab[0]));
}

  

 int main(void){
    int tab[5] =  {1,2,3,4,5};
    afficheTab(tab, 5);
    changeTab(tab, 4);
    printf("Les adresses de t et t[0] dans le main sont : %p et %p\n",tab, &(tab[0]));
    afficheTab(tab, 5);
    return 0;
  }


