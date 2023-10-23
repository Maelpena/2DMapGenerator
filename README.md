# 2DMapGenerator

Générateur procédurale de map en 2d.
Le projet utilise la library sfml pour l'affichage.



![image](https://github.com/Maelpena/2DMapGenerator/assets/34342829/6da4f5d7-69cb-464e-a9fe-b7b32065d58d)

![image](https://github.com/Maelpena/2DMapGenerator/assets/34342829/d698e3a8-963b-4aa5-b139-ec3f3a5c8388)

![image](https://github.com/Maelpena/2DMapGenerator/assets/34342829/5180bf15-9adb-4802-aa48-032754a9a629)




# Classe Display :

La Classe Display possède une map qu'elle affiche à chaque frame. 
Elle permet la navigation dans la map (touche ZQSD), le zoom (Scroll) ainsi que le rafraichissement de la map (clique droit)


# Classe MapGenerator :

La Classe MapGenerator demande un unique paramètre lors de sa construction : sa taille (map carré, minimum 100*100).
Elle possède différente variables membre modifiable dans son constructeur qui permettent d'ajuster la carte notamment:

m_noiseRate : Correspond à la fréquence du bruit qu'utilise toute la génération

m_dungeonSize : Correspond à la taille des donjons, (conserver un nombre impair de façon à garder des donjons symétriques)
