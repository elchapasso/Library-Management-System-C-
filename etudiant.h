#ifndef ETUDIANT_H
#define ETUDIANT_H
#include<iostream>
#include<stdio.h>
#include<string.h>s
#include<iomanip>
using namespace std ;
class etudiant
{
          char ID_num[20];
          char etudiant_nom[20];
          char stbno[6];
          int token;
public:
          void cree_etudiant();
          void affiche_etudiant();
          void modifie_etudiant();
          char* get_ID_num();
          char* retstbno();
          int rettoken();
          void addtoken();
          void resettoken();
          void getstbno(char t[]);
          void report();
          
          
          
          void nv_etudiant();
          void affiche_un_etudiant(char n[]);
          void modifier_etudiant();
          void supprimer_etudiant();
          void affiche_tt_etudiants();
          void etudiant_menu();
};

#endif





