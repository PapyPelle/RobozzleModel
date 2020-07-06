# Robozzle solver

Un petit projet dans Microsoft Visual Studio sur 3 jours pour tenter de trouver la solution au problème "Tree" sur le site de puzzle *RoboZZle* ([ce problème](http://robozzle.com/js/play.aspx?puzzle=152)).

N'arrivant pas à trouver cette solution rapidement, j'ai décidé de tenter une méthode brute force. Pour pallier aux 16 milliards de possibilités, j'ai implémenté les suppositions que j'avais faites sur ce qui doit être présent ou non dans la solution, pour réduire les cas à tester à moins de 10 millions (et passer de 2 mois à 1 heure de test).

Le code n'est pas très propre pour le générateur de solutions, et il manque globalement de commentaires. Je vais revenir dessus car je pense peut être pouvoir expérimenter les techniques d'algorithmes génétiques sur ce problème, en trouvant une bonne heuristique et malgrès l'unicité de certaines solutions. Le code (avec un peu d'ajustement) modélisant le principe de *RoboZZle* permet de simuler n'importe quel problème à une fonction.