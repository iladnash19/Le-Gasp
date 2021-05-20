#include<iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
using namespace std;
const int nbmax=6;


/*            PREMIERE  CLASS             */

class carte {
public:
    int ord;
    int abs;
    int face;

public:
    carte(int x, int y, int z);
    bool voisin(carte y, int n);
    void inverser();

};
carte::carte(int x, int y,int z=0)
{
    this->ord=x;
    this->abs=y;
    this->face=z;

}

bool carte::voisin(carte y,int n) // DEterminer tout les voisins d'une carte donnée
{
    int i;
    int j;
    i=this->abs;
    j=this->ord;

    if (((j-1>=0)&&(y.abs==i)&&(y.ord==j-1))||((j<n)&&(y.abs==i)&&(y.ord==j+1))||((i-1>=0)&&(y.abs==i-1)&&(y.ord==j))||((i<n)&&(y.abs==i+1)&&(y.ord==j))||((i-1>=0)&&(j-1>=0)&&(y.abs==i-1)&&(y.ord==j-1))||((i<n)&&(y.abs==i+1)&&(y.ord==j))||((i-1>=0)&&(j<n)&&(y.abs==i-1)&&(y.ord==j+1))||((i<n)&&(y.abs==i+1)&&(y.ord==j))||((i<n)&&(j-1>=0)&&(y.abs==i+1)&&(y.ord==j-1))||((i<n)&&(y.abs==i+1)&&(y.ord==j))||((i<n)&&(j<n)&&(y.abs==i+1)&&(y.ord==j+1)))
        return true;
    else
        return false;
}

void carte::inverser()  // changer la face du carte
{
    if(this->face==0)
        this->face=1;
    else
        this->face=0;
}

/*               DEUXIEME CLASS            */

class plateau {
private:
    int matrice[nbmax][nbmax];
    int taille;
public:
    plateau(int);
    void update(int,carte);
    void afficher();
    int somme();
};

plateau::plateau(int n)   // initialiser la plateau avec des cartes inverser
{
    taille=n;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            matrice[i][j]=0;
        }
    }
}

void plateau::update(int n,carte c)  // actualiser le plateau
{

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            carte p(i,j,matrice[i][j]);

            if (c.voisin(p,n))
               {
                 p.inverser();
                 matrice[i][j]=p.face;
               }
        }

    }

}

void plateau::afficher()  //Affichage
{
    for (int i=0;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
            cout << this->matrice[i][j] <<" |" << "\t" ;
        }
        if (taille==6)
            {cout << endl<<"-------------------------------------------"<<endl;}
        if(taille==4)
            {cout << endl<<"---------------------------"<<endl;}
        if(taille==5)
            {cout << endl<<"-----------------------------------"<<endl;}

    }
}
int plateau::somme() // indiquer si tout les cartes sont inversés (leurs sommes = tailles au carré )
{   int n=this->taille;
    int s=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            s+=this->matrice[i][j];
        }
    }
    return s;
}

/*               TROISIEME CLASS              */

class joueur
{
private:
	string nom;
	int nbcoup;
public:
	joueur(string );
	void get_nom();
	void set_nbcoup();
	int niveau();

};
joueur::joueur(string x){
	    this->nom=x;
	    this->nbcoup=0;


	}
void joueur::get_nom(){
		cout<<"entrez votre prenom :";
		cin>>nom;
	}

int joueur::niveau(){ //choisir le niveau
    int x;
    do
        {   cout<<"Choisissez le niveau: ";
            cin>>x;
    }while ((x<1 || x>3));
    if (x==1)
            {cout << "Niveau facile,entrainer vous pour atteindre d'autres niveaux."<<endl;
            return 4;}
    if (x==2)
           {
            cout <<"Niveau moyen,Continuez votre progrés."<<endl;
            return 5;}
    if (x==3)
            {cout << "Niveau difficile,Montrez votre talent!"<<endl;
            return 6;}

	}

/* ************** 4eme class * *********/

class partie
{
private:
    int x,y;
    int n;
public:
    partie();
    int choisi_abs_carte(int);
    int choisi_ord_carte(int);
    void gagner(int , int);
    int menu(char );
};
partie::partie (){};

int  partie ::choisi_abs_carte(int n)
{
    int x;
    do{
    cout<<"Donner l'abscisse x : ";
    cin>>x;
   }while(x<0||x>n-1);
   return x;
}
int  partie ::choisi_ord_carte(int n)
{
    int y;
   do{
    cout<<"Donner l'ordonne y : ";
    cin>>y;

   }while(y<0||y>n-1);
   return y;
}

void partie::gagner(int s ,int n)
{
   if (s==n*n)
    cout<<"vous avez gagner ! congratulation! "<<endl;
  else
    cout<<"vous avez perdu ! "<<endl;
}
int partie::menu(char on )
{

    do{
    cout<<"Voulez-vous continuer ou quitter le jeu? :(o/n) ";
    cin>>on;
   }while(on!='o' && on!='n');
    if(on=='o')
       {
           return 1;
       }
    else
       {
         return 0;
       }

}

/* ******************* 5ème class ************ */
class joueur_vs_computer
{
public:
    friend class plateau;
    friend class carte;
    friend class partie;
    friend class joueur;
    void jouer(int ,plateau,plateau , partie ,int , int ,int );

};
void joueur_vs_computer ::jouer(int t , plateau p1,plateau p2,partie p,int s1=0 , int s2= 0, int q=0)
{
    cout << "Voila ton plateau.Commencez! :"<<endl<<endl;
    p1.afficher();
    cout<<endl<<endl;
    cout<<"Le plateau de machine : "<<endl<<endl;;
    p2.afficher();
    do{
            q++;
            cout<< "********************************************************************************************************************" <<endl;
            cout << "                                  Le tour numero : " << q  <<endl;
            cout<< "********************************************************************************************************************" <<endl<<endl;;
            cout<<"choississez une carte : "<<endl;
            int  x=p.choisi_abs_carte(t);
            int  y=p.choisi_ord_carte(t);
            carte c1( x,  y);
            p1.update(t,c1);
            s1=p1.somme();
            cout<<"Ta somme est : "<<s1<<endl;
            p1.afficher();
            cout<<endl<<endl;
            cout<<"Tour de machine"<<endl;
            int   a= rand()%4;
            cout<<"L'abscisse est : "<< a <<endl;
            int  b= rand()%4;
            cout<<"l'ordonnee est : "<< b <<endl;
            carte c2( a,  b);
            p2.update(t,c2);
            int  s2=p2.somme();
            cout<<"La somme du machine  est : "<<s2<<endl;
            p2.afficher();
            cout<<endl<<endl;
           // cout<< "*********************************************************************************************************" <<endl;
        }while((s1!=t*t) && (s2!=t*t));
        if (s1==t*t)
            cout<<"vous avez gagner ! congratulation! "<<endl;
        else
            cout<<"vous avez perdu ! "<<endl;

}


int main()
{
    int x,y,r;
    char on='o';
    int t;//taille
    int ab;
    string nom;
    cout<<endl;
    cout<< "                                          BIENVENUE AU JEU DU GASP"<<endl;
    cout<<endl;
    cout<<endl;
    cout << "COMMENCER VOTRE PARTIE " <<endl;
    cout<<endl;
    joueur j(nom);
    j.get_nom();
    partie partie;
    do{
        cout<<"voulez vous un jeu  : "<<endl;
        cout << "        1-Individuel "<<endl;
        cout << "        2-Contre la machine "<<endl;
        cin>>r;
        if(r==1)
            {
                cout << "Choisissez le degre de difficulte,tapez :"<<endl;
                cout << "        1-pour niveau facile "<<endl;
                cout << "        2-pour niveau moyen "<<endl;
                cout << "        3-pour niveau difficile "<<endl;
                t= j.niveau();
                cout<<"Jouer dans un plateau de "<<t*t<< " cartes" <<endl<<endl;;
                int k=0; // nombre de coups
                int q=0; // la somme des faces du cartes
                plateau p(t);
                p.afficher();
                cout<<endl;
                do
                {
                    x=partie.choisi_abs_carte(t);
                    y=partie.choisi_ord_carte(t);
                    carte c( x,  y);
                    k++;
                    cout<<"La tentation numéro : "<<k<<endl;
                    p.update(t,c);
                    q=p.somme();
                    cout<<"La somme est : "<<q<<endl<<endl;;
                    p.afficher();
                    cout<<endl;
                }while(q<t*t && k<t*t); //jouer jusqu'a la somme egale au taille au carré (tout les cartes sont inverseés) et nbdecoup superieur au nbdecoup limité
                partie.gagner(q,t);
            }

            else
                {
                    joueur_vs_computer game;
                    cout << "Choisissez le degre de difficulte,tapez :"<<endl;
                    cout << "        1-pour niveau facile "<<endl;
                    cout << "        2-pour niveau moyen "<<endl;
                    cout << "        3-pour niveau difficile "<<endl;
                    t= j.niveau();
                    cout<<"Jouer dans un plateau de "<<t*t<< " cartes" <<endl<<endl;;

                    int s1,s2;
                    int q=0;
                    plateau p1(t);
                    cout<<endl;
                    plateau p2(t);
                    int z;
                    game.jouer(t,p1,p2,partie,s1,s2,z);
                }
                ab=partie.menu(on);
    }while(ab==1);

}

