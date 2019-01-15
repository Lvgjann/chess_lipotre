
#include <iostream>
#include <string>
#include "Piece.h"
#include "Echiquier.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

/**
 * Boucle de jeu
 */
void run()
{
  bool jeuFini = false;
  bool whiteTurn = true;
  string commande;
  JoueurBlanc jBlanc;
  JoueurNoir jNoir;
  Echiquier echiquier;

  jBlanc.initEchiquier(echiquier);
  jNoir.initEchiquier(echiquier);
  while (!jeuFini)
  {
    cout << "Main au joueur" << (whiteTurn ? "blanc" : "noir") << endl;
    echiquier.affiche();
    cout << "Entrez une commande (\"help\" pour une liste)> ";
    cin >> commande;
    if (commande == "stop")
    {
      jeuFini = true;
    }
    else if (commande == "help")
    {
      cout << " stop : arrete la partie et termine le programme" << endl;
      cout << " help : affiche la liste de commandes avec descriptions" << endl;
      cout << " move : permet de deplacer une piece" << endl;
    }
    else if (commande == "move")
    {
      int x, y;
      cout << "Entrez les coordonnées de la pièce à bouger" << endl;
      cin >> x >> y;
      std::shared_ptr<Piece> p = echiquier.getPiece(x, y);
      if (p != nullptr)
      {
        p->affiche();
        std::cout<<std::endl;
        cout<<"Entrer les coodonnes de la destination"<<endl;
        cin>>x>>y;
        if(echiquier.deplacer(p,x,y))
        {
          cout<<"déplacement réussi"<<endl;
        }
        else{
          cout<<"déplacement  échoué"<<endl;
        }
      }
    }
  }
}

/**
 * Programme principal
 */
int main(int argc, char **argv)
{
  run();
  return 0;
}