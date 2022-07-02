#include "etudiant.h"
#include "livre.h"
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<iostream>
#include<iomanip>
using namespace std ;
fstream fp;
etudiant st;

void gotoxye(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void etudiant::cree_etudiant()
          {
          			
                    cout<<"\nID de l'etudiant:  ";
                    cin>>ID_num;
                    cout<<"\n\nEntrer le nom de l'etudiant: ";
                    cin>>etudiant_nom;
                    token=0;
                    stbno[0]='/0';
                    cout<<"\t\t\n\nL'etudiant a ete ajoute au archive...\n\n";
          }
void etudiant::affiche_etudiant()
          {
          			
                    cout<<"\nID de l'etudiant: "<<ID_num;
                    cout<<"\nNom de l'etudiant:  ";
                    puts(etudiant_nom);
                    cout<<"\nN° du livre emprunte: "<<token;
                    if(token==1)
                               cout<<"\nBo "<<stbno;
          }
void etudiant::modifie_etudiant()
          {		
                    cout<<"\nID de l'etudiant "<<ID_num;
                    cout<<"\nModifier le nom de l'etudiant: ";
                    cin.ignore();
                    cin.getline(etudiant_nom,50);
          }
char* etudiant::get_ID_num()
          {
                    return ID_num;
          }
char* etudiant::retstbno()
          {
                    return stbno;
          }
int etudiant::rettoken()
          {
                    return token;
          }
void etudiant::addtoken()
          {token=1;}
void etudiant::resettoken()
          {token=0;}
void etudiant::getstbno(char t[])
          {
                    strcpy(stbno,t);
          }
void etudiant::report()
          {cout<<"\t"<<ID_num<<setw(20)<<etudiant_nom<<setw(10)<<token<<endl;}
void etudiant::nv_etudiant()
{
        system("cls");
          int more_or_main;
          fp.open("etudiant.dat",ios::out|ios::app);
          do
          {
                    st.cree_etudiant();
                    fp.write((char*)&st,sizeof(etudiant));
                    cout<<"\n[1]_Ajouter un etudiant.";
                    cout<<"\n[2]_Revenir au MENU principal.\n\n";
                    cout<<"Entrer: ";
                    cin>>more_or_main;
          }while(more_or_main == 1);
          fp.close();
}
void etudiant::affiche_un_etudiant(char n[])
{
          system("cls");
          cout<<"\nDETAILS de l'etudiant\n";
          int check=0;
          fp.open("etudiant.dat",ios::in);
          while(fp.read((char*)&st,sizeof(etudiant)))
          {
                    if((strcmpi(st.get_ID_num(),n)==0))
                    {
                               st.affiche_etudiant();
                               check=1;
                    }
          }
          fp.close();
          if(check==0)
                    cout<<"\n\nL'etudiant n'existe pas";
          getch();
}
void etudiant::modifier_etudiant()
{
          system("cls");
          char n[20];
          int found=0;
          cout<<"\n\n\tModifier l'etudiant... ";
          cout<<"\n\n\tEntrer l'ID de l'etudiant: ";
          cin>>n;
          fp.open("etudiant.dat",ios::in|ios::out);
          while(fp.read((char*)&st,sizeof(etudiant)) && found==0)
          {
                    if(strcmpi(st.get_ID_num(),n)==0)
                    {
                               st.affiche_etudiant();
                               cout<<"\nEntrer les nouveaux detials de l'etudiant"<<endl;
                               st.modifie_etudiant();
                               int pos=-1*sizeof(st);
                               fp.seekp(pos,ios::cur);
                               fp.write((char*)&st,sizeof(etudiant));
                               cout<<"\n\n\t Enregistre dans l'archive...\n\n";
                               found=1;
                    }
          }
          fp.close();
          if(found==0)
                    cout<<"\n\n Etudiant non trouve ";
          getch();
}
void etudiant::supprimer_etudiant()
{
          system("cls");
          char n[20];
          int flag=0;
          cout<<"\n\n\n\tSupprimer etudiant";
          cout<<"\n\nEntrer l'ID de l'etudiant que tu veux supprimer: ";
          cin>>n;
          fp.open("etudiant.dat",ios::in|ios::out);
          fstream fp2;
          fp2.open("Temp.dat",ios::out);
          fp.seekg(0,ios::beg);
          while(fp.read((char*)&st,sizeof(etudiant)))
          {
                    if(strcmpi(st.get_ID_num(),n)!=0)
                              fp2.write((char*)&st,sizeof(etudiant));
                    else
                              flag=1;
          }
          fp2.close();
          fp.close();
          remove("etudiant.dat");
          rename("Tmp.dat","etudiant.dat");
          if(flag==1)
                    cout<<"\n\n\tEtudiant supprime ..\n";
          else
                    cout<<"\n\nL'etudiant n'a pas ete trouve";
        getch();
}
void etudiant::affiche_tt_etudiants()
{
              system("cls");
          fp.open("etudiant.dat",ios::in);
          if(!fp)
          {
                    cout<<"ERREUR! le fichier n'a pas pu s'executer ";
                    getch();
                    return;
          }
          cout<<"\n\n\t\tLISTE DES ETUDIANTS\n\n";
          cout<<"==================================================================\n";
          cout<<"\tID "<<setw(10)<<"NOM"<<setw(20)<<"Livre emprunte\n";
          cout<<"==================================================================\n";
          while(fp.read((char*)&st,sizeof(etudiant)))
          {
                    st.report();
          }
          fp.close();
          getch();
}
void etudiant::etudiant_menu()
{
          int option;
               gotoxye(0,4);
        cout<<"===================================================================================================================="<<endl;
			gotoxye(40,5);
        cout<<"MENU GESTION DES ETUDIANTS"<<endl;
        cout<<"====================================================================================================================\n\n\n";
                cout<<"\n\t\t\t\t\t[1]_CREER UN ETUDIANT\n";
                cout<<"\n\t\t\t\t\t[2]_AFFICHER TOUS LES ETUDIANTS\n";
                cout<<"\n\t\t\t\t\t[3]_AFFICHER UN ETUDIANT PRECIS\n";
                cout<<"\n\t\t\t\t\t[4]_MODIFIER UN ETUDIANT\n";
                cout<<"\n\t\t\t\t\t[5]_SUPPRIMER UN ETUDIANT\n";
                cout<<"\n\t\t\t\t\t[6]_REVENIR AU MENU PRINCIPAL\n";
 cout<<"\n\t\tOption: ";
 cin>>option;
 switch(option)
          {
                    case 1:  system("cls");
                            nv_etudiant();
                             break;
                    case 2: system("cls");
 
                              affiche_tt_etudiants();
                            break;
                    case 3:
                              char num[20];
                               system("cls");
                        cout<<"\n\n\tVeuillez entrer votre ID: ";
                              cin>>num;
                         affiche_un_etudiant(num);
                              break;
                    case 4:system("cls");
                           modifier_etudiant();break;
                    case 5: system("cls");
                           supprimer_etudiant();break;
                    case 6: 
                               break;
                    default:cout<<"\a";
          }
}

