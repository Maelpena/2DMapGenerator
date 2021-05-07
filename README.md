# 2DMapGenerator

Ceci est un generateur procedurale de map en 2d.
Le projet utilise la library sfml pour l'affichage.

# Classe Display :
La Classe Display possede un map qu'elle affiche a chaque frame. 
Elle permet la navigation dans la map (touche ZQSD), le zoom(Scroll) ainsi que le rafraichissement de la map (clique droit)

# Classe MapGenerator :
La Classe MapGenerator demande un unique parametre lors de sa construction : sa taille (map carré).
Elle possede differente variable instancié dans son constructeur qui permettent d'ajuster la carte :
m_noiseRate : Correspond à la frequence du bruit qu'utilise toute la génération
m_dungeonSize : Correspond a la taille des dongeon, (conservé un nombre impair de facon a garder des dongeons symetrique)
