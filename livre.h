#ifndef LIVRE_H
#define LIVRE_H

class livre
{
          char livre_num[30];
          char livre_nom[50];
          char auteur_nom[20];
  public:
          void cree_livre();
          void affiche_livre();
          void modifie_livre();
          char* getlivrenum();
		  void report();
		  
		  
		  
		  void nv_livre();
		  void affiche_un_livre(char n[]);
		  void modifier_livre();
		  void supprimer_livre();
		  void affiche_tt_livres();
		  void emprunt_livre();
		  void retour_livre();
		  void livre_menu();
		  

};        

#endif





