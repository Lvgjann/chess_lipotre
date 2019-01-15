SRC_CXX=Piece.cxx Joueur.cxx Echiquier.cxx JoueurBlanc.cxx JoueurNoir.cxx Roi.cxx Reine.cxx Fou.cxx Cavalier.cxx Tour.cxx Pion.cxx
CXXFLAGS+=-std=c++11
OBJ=${SRC_CXX:.cxx=.o}

all: echecs

echecs: $(OBJ) Jeu.o
	$(CXX) $(OBJ) Jeu.o -o Echecs

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(OBJ) Jeu.o Echecs *~

