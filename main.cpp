#include<iomanip>
#include"livre.h"
#include<windows.h>
#include"etudiant.h"
using namespace std;

livre bk1;
etudiant st1;
int mdp=123;
int mdp1;
char e_aigu=0x82;


void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main()
{
cout<<"\n\t\t\tLe mot de passe est 123 ( modifiable dans le main.cpp)\n\n ";
do{
cout<<"\t\t\tEntrez le mot de passe :";
cin>>mdp1;
cout<<"\nMot de passe erron"<<e_aigu<<",veuillez r"<<e_aigu<<"essayer svp.\n\n ";}while(mdp1!=mdp);
          int option = 0;
          

          for(;;)
          {system("cls");
          gotoxy(0,4);
        cout<<"===================================================================================================================="<<endl;
			gotoxy(40,5);
        cout<<"GESTION DE BIBLIOTHEQUE"<<endl;
        cout<<"====================================================================================================================\n\n\n";
				
                cout<<"\n\t\t\t\t\t[1]_EMPRUNTER UN LIVRE\n";
                cout<<"\n\t\t\t\t\t[2]_RENDRE UN LIVRE\n";
   				cout<<"\n\t\t\t\t\t[3]_GESTION DES ETUDIANTS\n";
   				cout<<"\n\t\t\t\t\t[4]_GESTION DES LIVRES\n";
   				cout<<"\n\t\t\t\t\t[5]_ARRETER LE PROGRAMME\n\n";
 				cout<<"\n\t\t\t\t\tCHOIX: ";
 				
 				cout<<"\n\n====================================================================================================================";
 				cout<<endl<<endl<<"\n\t\t\t\t\t\t\tRealis"<<e_aigu<<" par: SAAI El Mehdi (IMS) "<<endl<<endl<<endl;

 				cin>>option;
 				
 				
 						switch(option)
                    {
                            case 1:system("cls");
                                          bk1.emprunt_livre();
                                          break;
                            case 2:system("cls");
                                         bk1.retour_livre(); 
                                          break;
                            case 3:system("cls");
                                         st1.etudiant_menu();
                                          break;
                       		case 4:system("cls");
                                  bk1.livre_menu();
                                  break;
                            case 5:exit(0);
                                         break;
                              default :cout<<"\a";
                                         exit(0);
                    }
          }
}
