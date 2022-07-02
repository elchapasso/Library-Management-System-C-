#include "livre.h"
#include"etudiant.h"
#include<fstream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<iostream>
#include<iomanip>
using namespace std;
fstream fpp,fp1;
livre bk;
etudiant stt;
void gotoxyl(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void livre::cree_livre()
          {
                    cout<<"\nEntrer le numero du livre: ";
                    cin>>livre_num;
                    cout<<"\nEntrer le nom du livre: ";
                     cin.ignore();
                    cin.getline(livre_nom,50);
                    cout<<"\nEntrer le nom d'auteur': ";
                    cin.ignore();
                    cin.getline(auteur_nom,50);
                    cout<<"\t\t\n\nLe livre a ete bien cree...\n\n";
          }
          
void livre::affiche_livre()
          {
                    cout<<"\nN° du livre: "<<livre_num;
                    cout<<"\nNom du livre: "<<livre_nom;
                    cout<<"\nNom d'auteur': "<<auteur_nom;
          }
          
void livre::modifie_livre()
          {
                    cout<<"\nN° du livre: "<<livre_num;
                    cout<<"\nModifier le nom du livre : ";
                    cin.ignore();
                    cin.getline(livre_nom,50);
                    cout<<"\nModifier le nom de l'auteur: ";
                    cin.ignore();
                    cin.getline(auteur_nom,50);
          }
char* livre::getlivrenum()
          {
                    return livre_num;
          }
void livre::report()
          {cout<<livre_num<<setw(30)<<livre_nom<<setw(30)<<auteur_nom<<endl;}
void livre::nv_livre()
{
          system("cls");
          int more_or_main;
          fpp.open("livre.dat",ios::out|ios::app);
          do
          {
                    bk.cree_livre();
                    fpp.write((char*)&bk,sizeof(livre));
                    cout<<"\n[1]_Ajouter un livre.";
                    cout<<"\n[2]_Revenir au MENU principal.\n\n";
                    cout<<"Enter: ";
                    cin>>more_or_main;
          }while(more_or_main == 1);
          fpp.close();
}
void livre::affiche_un_livre(char n[])
{
          system("cls");
          cout<<"\nDETAILS des livres\n";
          int check=0;
          fpp.open("livre.dat",ios::in);
          while(fpp.read((char*)&bk,sizeof(livre)))
          {
                    if(strcmpi(bk.getlivrenum(),n)==0)
                    {
                               bk.affiche_livre();
                              check=1;
                    }
          }
          fpp.close();
          if(check==0)
                    cout<<"\n\nLe livre n'existe pas";
        getch();
}
void livre::modifier_livre()
{
          system("cls");
          char n[20];
          int found=0;
          cout<<"\n\n\tModifier un livre";
          cout<<"\n\n\tEntrer le numero du livre: ";
          cin>>n;
          fpp.open("livre.dat",ios::in|ios::out);
          while(fpp.read((char*)&bk,sizeof(livre)) && found==0)
          {
                    if(strcmpi(bk.getlivrenum(),n)==0)
                    {
                               bk.affiche_livre();
                               cout<<"\nEntrer les nouveaux details du livre"<<endl;
                               bk.modifie_livre();
                               int pos=-1*sizeof(bk);
                              fpp.seekp(pos,ios::cur);
                              fpp.write((char*)&bk,sizeof(livre));
                              cout<<"\n\n\t Enregistte dans L'archive...\n\n";
                              found=1;
                    }
          }
          fpp.close();
          if(found==0)
                    cout<<"\n\n Le Livre n'a pas ete trouve \n";
          getch();
}
void livre::supprimer_livre()
{
          system("cls");
          char n[20];
          int flag=0;
          cout<<"\n\n\n\tSupprimer un livre";
          cout<<"\n\nEntrer le numero du livre que vous voulez supprimer: ";
          cin>>n;
          fpp.open("livre.dat",ios::in|ios::out);
          fstream fp2;
          fpp.open("Tmp.dat",ios::out);
          fpp.seekg(0,ios::beg);
          while(fpp.read((char*)&bk,sizeof(livre)))
          {
                    if(strcmpi(bk.getlivrenum(),n)!=0)  
                    {
                               fp2.write((char*)&bk,sizeof(livre));
                    }
                    else
                              flag=1;
          }
          fp2.close();
          fpp.close();
          remove("livre.dat");
          rename("Tmp.dat","livre.dat");
          if(flag==1)
                    cout<<"\n\n\tLe livre a ete supprimer ..\n";
          else
                    cout<<"\n\nLe livre n'a pas ete trouve";
          getch();
}
void livre::affiche_tt_livres()
{
          system("cls");
          fpp.open("livre.dat",ios::in);
          if(!fpp)
          {
                    cout<<"ERREUR! le fichier n'a pas pu s'executer ";
                    getch();
                    return;
          }
          cout<<"\n\n\t\tLISTE DES LIVRES\n\n";
         cout<<"=========================================================================\n";
          cout<<"Numero du livre"<<setw(20)<<"Nom du livre"<<setw(25)<<"Auteur\n";
          cout<<"=========================================================================\n";
          while(fpp.read((char*)&bk,sizeof(livre)))
          {
                    bk.report();
          }
          fpp.close();
          getch();
}
void livre::emprunt_livre()
{
          system("cls");
               gotoxyl(0,4);
        cout<<"===================================================================================================================="<<endl;
			gotoxyl(40,5);
        cout<<"EMPRUNTER DES LIVRES"<<endl;
        cout<<"====================================================================================================================\n\n\n";
          char sn[20],bn[20];
          int found=0,flag=0;
   
          cout<<"\n\n\tEntrer l'ID de l'etudiant: ";
          cin>>sn;
          fpp.open("etudiant.dat",ios::in|ios::out);
          fp1.open("livre.dat",ios::in|ios::out);
          while(fpp.read((char*)&stt,sizeof(etudiant)) && found==0)
          {
                    if(strcmpi(stt.get_ID_num(),sn)==0)
                    {
                               found=1;
                               if(stt.rettoken()==0)
                               {
                                        cout<<"\n\n\tEntrer le numero du livre: ";
                                         cin>>bn;
                                         while(fp1.read((char*)&bk,sizeof(livre))&& flag==0)
                                         {
                                                   if(strcmpi(bk.getlivrenum(),bn)==0)
                                                 {
                                                           bk.affiche_livre();
                                                             flag=1;
                                                             stt.addtoken();
                                                             stt.getstbno(bk.getlivrenum());
                                                             int pos=-1*sizeof(stt);
                                                             fpp.seekp(pos,ios::cur);
                                                             fpp.write((char*)&stt,sizeof(etudiant));
                                                             cout<<"\n\n\t Le livre a ete emprunte...";
                                                   }
                                        }
                                        if(flag==0)
                                                   cout<<"Le livre n'existe pas '";
                               }
                              else
                                        cout<<"Tu n'a pas encore rendu le livre emprunte ";
                    }
          }
          if(found==0)
                    cout<<"Cet enregisttrement n'existe pas...\n";
          getch();
          system("cls");
          fpp.close();
          fp1.close();
}
void livre::retour_livre()
{
    system("cls");
         gotoxyl(0,4);
        cout<<"===================================================================================================================="<<endl;
			gotoxyl(40,5);
        cout<<"RENDRE DES LIVRES"<<endl;
        cout<<"====================================================================================================================\n\n\n";
    char sn[20],bn[20];
    int found=0, flag=0, day, fine;
   
    cout<<"\n\n\tEntrer l'ID de l'etudiant: ";
    cin>>sn;
    fpp.open("etudiant.dat",ios::in|ios::out);
    fp1.open("livre.dat",ios::in|ios::out);
    while(fpp.read((char*)&stt,sizeof(etudiant)) && found==0)
       {
                       if(strcmpi(stt.get_ID_num(),sn)==0)
              {
                        found=1;
                        if(stt.rettoken()==1)
                        {
                               while(fp1.read((char*)&bk,sizeof(livre))&& flag==0)
                               {
                                         if(strcmpi(bk.getlivrenum(),stt.retstbno())==0)
                               {
                                         bk.affiche_livre();
                                         flag=1;
                                         cout<<"\n\nLe livre a ete rendu en : ";
                                         cin>>day;
                                        
                                                   stt.resettoken();
                                                   int pos=-1*sizeof(stt);
                                                   fpp.seekp(pos,ios::cur);
                                                   fpp.write((char*)&stt,sizeof(etudiant));
                                                  cout<<"\n\n\t LE LIVRE A ETE BIEN RENDU...";
                               }
                        }
                      if(flag==0)
                        cout<<"Ce numero de livre n'existe pas";
                          }
                     else
                               cout<<"Aucun livre emprunte.....Veuillez vérifier une autre fois!!";
                    }
             }
      if(found==0)
          cout<<"Enregisttrement de l'etudiant n'existe pas...";
          getch();
          system("cls");
  fpp.close();
  fp1.close();
  }
  void livre::livre_menu()
{
          int option;
            gotoxyl(0,4);
        cout<<"===================================================================================================================="<<endl;
			gotoxyl(40,5);
        cout<<"MENU GESTION DES LIVRES"<<endl;
        cout<<"====================================================================================================================\n\n\n";
                cout<<"\n\t\t\t\t\t[1]_CREATION DES LIVRES\n	";
                cout<<"\n\t\t\t\t\t[2]_AFFICHER TOUS LES LIVRES\n";
                cout<<"\n\t\t\t\t\t[3]_AFFICHER UN LIVRE PRECIS\n";
                cout<<"\n\t\t\t\t\t[4]_MODIFIER DES LIVRES\n";
                cout<<"\n\t\t\t\t\t[5]_SUPPRIMER DES LIVRES\n";
                cout<<"\n\t\t\t\t\t[6]_REVENIR AU MENU PRINCIPAL\n";
 cout<<"\n\t\tOption: ";
 cin>>option;
 switch(option)
          {
                    case 1:  system("cls");
                                         nv_livre();
                                                   break;
                               case 2: affiche_tt_livres();
                                 break;
                    case 3:
                              char num[20];
                               system("cls");
                              cout<<"\n\n\tVeuillez entrer le numero du livre: ";
                              cin>>num;
                              affiche_un_livre(num);
                              break;
                    case 4: modifier_livre();break;
                    case 5: supprimer_livre();break;
                    case 6: system("cls");
                               break;
                    default:cout<<"\a";
          }
}

  
