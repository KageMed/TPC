#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxi 999

void ajout (FILE *fic , char ch[]) ///  ***** ADD *****
{
    FILE *fic2=NULL;
      int trouve=1;
     char ch2[maxi],ch3[maxi];
     fic2=fopen("fic7","w+");
printf("introduire le nom du fichier: ");

    gets(ch3);
   fic=fopen(ch3,"r+");
   if (fic==NULL)
  {
      printf("fichier introuvable\n");
      return 0;
  }

    while (fgets(ch2,maxi,fic)!=NULL)
       {
           if (strcmp(ch,ch2)>0)
           {

               fputs(ch2,fic2);

           }
          if (strcmp(ch,ch2)<0)
          {
              fputs(ch,fic2); trouve=0; break ;
          }
       }

       if (trouve=1)
       {
           fputs(ch,fic2);
       }
       while (fgets(ch2,maxi,fic)!=NULL)
       {
           fputs(ch2,fic2);
       }
       fclose(fic);
      fic=fopen(ch3,"w+");
       rewind(fic2);
       while (fgets(ch2,maxi,fic2)!=NULL)
       {
           fputs(ch2,fic);
       }

printf("le mot a %ct%c ajout%c avec success\n",130,130,130);

}

void triefic (FILE *fic) /// ******* TRIE *******
{
    FILE *fic1=NULL,*fic2=NULL;
    char ch[maxi],mini[maxi],ch3[maxi];
    printf("introduire le nom du fichier: ");
    gets(&ch3);
    gets(ch3);
   fic=fopen(ch3,"r+");
   if (fic==NULL)
  {
      printf("fichier introuvable\n");
      return 0;
  }

    fic1=fopen("fic4","w+");
    fic2=fopen("fic5","w+");

    while ( fgets(mini,maxi,fic)!=NULL)
    {


       while (fgets(ch,maxi,fic)!=NULL)
       {

        if (strcmp(ch,mini)<0)
        {


            fputs(mini,fic1);

            strcpy(mini,"");
            strcpy(mini,ch);

        }else
        {
            if (strcmp(ch,mini)>0)
            fputs(ch,fic1);

        }
      }
        printf("%s",mini);
        fputs(mini,fic2);
        rewind(fic1);
        fclose(fic);
        fic=fopen(ch3,"w+");
         while (fgets(ch,maxi,fic1)!=NULL)
         {
             fputs(ch,fic);
         }
         fclose(fic1);
         fic1=fopen("fic1","w+");
         rewind(fic);

    }
    rewind(fic2);
    fclose(fic);
    fic=fopen(ch3,"w+");
    while (fgets(ch,maxi,fic2)!=NULL)
         {
             fputs(ch,fic);
         }




}



 long half (FILE *dico , long begin ,long end) /// ***** HALF ******
{
    char x;
    long i=0;
    rewind(dico);

    do
        {
             x=fgetc(dico);
             if(x=='\n'){i++;}
             i++;
        }
    while ( x!= EOF && i< ((begin+end)/2) );

    if (x!=EOF)
    {
       do
        {
             x=fgetc(dico);
             i++;
             if (x=='\n')
             {

                 return i+1;
             }
        }
    while ( x!= EOF  );



    }

        return -1;


}

long existe (char ch[], FILE *dico) /// ***** EXISTE ******
{
  int i,j;
  long begin,end,a=0,b;
  char chaine [maxi],ch2[maxi],x;



    rewind(dico);
    fgets(chaine,maxi,dico);
     j=0;
       while (chaine[j]!=',')
       {
           ch2[j]=chaine[j];j++;
       }
       ch2[j]='\0';
        if(strcmp(ch,ch2)==0)
           {
               return 0;
           }
           rewind(dico);
       b=half(dico,0,3);
       rewind(dico);
     begin=ftell(dico);
     fseek(dico,0,SEEK_END);
     end=ftell(dico);
     rewind(dico);
     a=half(dico,begin,end);
     rewind(dico);
     fseek(dico,a,SEEK_SET);
   while (a!=-1  && (end-begin)>1 )
   {
       fgets(chaine,maxi,dico);
       j=0;
       while (chaine[j]!=',')
       {
           ch2[j]=chaine[j];j++;
       }
       ch2[j]='\0';


           if(strcmp(ch,ch2)==0)
           {
               // printf("begin:%d end:%d a:%d b:%d ch:%s ch2:%s equal \n",begin,end,a,b,ch,ch2);
               return a;

           }


               if(strcmp(ch,ch2)<0)
               {
                  end=(end+begin)/2;
                  rewind(dico);
                  a=half(dico,begin,end);


                  rewind(dico);
                  fseek(dico,a,SEEK_SET);
             //   printf("begin:%d end:%d a:%d b:%d ch:%s ch2:%s inf \n",begin,end,a,b,ch,ch2);


               }
                if(strcmp(ch,ch2)>0)
               {

                   begin=(end+begin)/2;

                  rewind(dico);

                  a=half(dico,begin,end);
               //  printf("begin:%d end:%d a:%d b:%d ch:%s ch2:%s sup \n",begin,end,a,b,ch,ch2);
                  rewind(dico);
                  fseek(dico,a,SEEK_SET);
               }




   }
   if (a==b)
   {
        fgets(chaine,maxi,dico);
       j=0;
       while (chaine[j]!=',')
       {
           ch2[j]=chaine[j];j++;
       }
       ch2[j]='\0';
        if(strcmp(ch,ch2)==0)
           {
               return a;
           }

   }


   return -1;

}


char *findw(char ch[], FILE *dico) /// ****** FINDW *******
{
    long a;
    char chain[maxi];
    a=existe(ch,dico);
     rewind(dico);
     if (a!=-1)

     {
         fseek(dico,a,SEEK_SET);
         fgets(chain,maxi,dico);
         return chain;
     }else
     {
         printf("Le Mot introduit n'existe pas\n");
         return NULL;
     }


}

void f_pell (FILE *fic , FILE *dico)  /// ****** TELL ******
{
    int j,trouve;
    char ch[maxi],ch2[maxi],chaine[maxi],ch3[maxi],ch4[maxi];

     printf("introduire le nom du fichier: ");
    gets(&ch3);
    gets(ch3);
    fic=fopen(ch3,"r+");
  if (fic==NULL)
  {
      printf("fichier introuvable\n");
      return 0;
  }
   rewind(fic);

     while ( fgets(ch,maxi,fic)!=NULL)
    {

         trouve=0;

         rewind(dico);
       while (fgets(chaine,maxi,dico)!=NULL && trouve ==0)
       {

             strcpy(ch4,ch);
          j=0;
       while (chaine[j]!=',')
       {
           ch2[j]=chaine[j];j++;
       }
       ch2[j]='\n';
       ch2[j+1]='\0';
      //printf("ch %s, ch2 %s",ch,ch2);
        if(strcmp(ch,ch2)==0)
           {
               trouve=1;
           }

       }
      if (trouve==0)
      {

          printf("%s\n",ch);
      }


    }
}

int main()
{
    FILE *fic=NULL,*dico=NULL,*fic2=NULL,*introuvable;
    char ch[maxi],x,ch3[maxi],re,ch1[maxi],ch2[maxi];
    char *chaine;
    long a,b,c;
    int i=0,j=0;

     do{

    printf("********************************************************************************");
    printf("********************* Bienvenue Au Dictionnaire-Francais ***********************\n\n");
     printf(" Introduire Le chiffre Correspondant %c l'operation de Votre Choix :\n\n",133);
     printf("1-d%cfinition d'un mot\n\n",130);
     printf("2-Trier un fichier de mots %c l'ordre alphabetique\n\n",133);
     printf("3-Affichage des mot qui n'existe pas dans le dictionnaire\n\n");
     printf("4-Ajouter un mot et %ca d%cfinition dans un fichier\n\n",135,130);
     printf("5-Quitter\n\n\n");


     fic=fopen("fic2","r+");
     introuvable=fopen("introuv","a");

    do ///******* LIRE LE CHOIX + CTRL *******
    {
         printf("                                                   Votre Choix :");
         scanf("%s",&ch3);
    if (strlen(ch3)==1)
          {x=ch3[0]-48; }
    else  {x=0;}


    }
    while ( x<=0 || x>=6 );



 switch (x)
 {

           /// ***** case one DEFINITION *****
 case 1: {
     gets(&re);
      printf("Vous avez choisis : 1-deffinition d'un mot\n");
            printf("Introduire Le mot\n");

    gets(ch);
    chaine=findw(ch,fic);
    if (chaine!=NULL)
    puts(chaine);
    else
    {
        fprintf(introuvable,"%s\n",ch);
    }

   break;}

 case 2:  /// *********** Case Two TRIE FIC *********
        {
            fclose(fic);
            triefic(fic);
            break;
        }

 case 3:  /// ******** Case three AFFICHAGE NON-TROUVE ********
        {
        fclose(fic2);
        f_pell(fic2,fic);
      break;
        }
 case 4:  ///  ******** Case four ADD_WORD ********
    {
        printf("intoduire le mot que vous voulez ajouter dans le dictionnaire :\n");
        gets(&re);
        gets(ch1);
        printf("introduire la deffinition de %s en fran%cais\n",ch1,135);
        gets(ch2);
        for(i=0;i<strlen(ch1);i++)
        {
            ch[i]=ch1[i];
        }
        ch[i]=',';i++; ch[i]='"';i++;
         for(j=0;j<strlen(ch2);j++)
         {
             ch[i]=ch2[j];i++;
         }
        ch[i]='"';ch[i+1]='\n';ch[i+2]='\0';

        fclose(fic);
        ajout(fic,ch);
        break;
    }
 case 5: /// ********* EXIT ******
       {
           return 0;break;

       }
 }
fclose(fic);
fclose(introuvable);
    printf("\n \n Veulliez Vous Continuer ? (Y : Oui / N: Non)\n");

do ///************ LIRE + CTRL************
{

 scanf("%s",&ch3);
    if (strlen(ch3)!=1)
          {re=0;}
          else
          {
              re=ch3[0];
          }

}
while (re != 'y' && re!= 'Y' && re!= 'n' && re!= 'N');
       printf("\n\n");
       system("cls");
    }while (re=='y' || re=='Y');

}
