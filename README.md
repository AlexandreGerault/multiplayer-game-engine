# Multiplayer-Game-Engine
Moteur pour créer des jeux en ligne en C++

## But du projet

Le but de ce projet est de me simplifier le développement de jeux multijoueurs basés sur le principe de rôles cachés, fonctionnant sur des actions simples au tour par tour. L'intérêt d'écrire un *petit* moteur est de rendre plus simple l'écriture des échanges sur le réseau, la gestion des salles de jeux etc. En effet, le projet est composé de deux parties distinctes : un moteur de jeu et une partie logicielle qui permet de créer des salles de jeux textuelles, à la manière d'un salon vocal sur Discord.

## Objectifs (en cours de complétion)

Ce projet, que je peux appelé plus rapidement MGE, a pour moi plusieurs objectifs. Certains sont plus techniques, et d'autres plutôt personnels.

### Objectifs techniques

- [ ] Charger un script de jeu (langage interprété non choisi) par salle de jeu (le script utilise la partie moteur pour communiquer sur le réseau, pour effectuer des actions comme mute des joueurs etc)
- [ ] Créer des salles de jeux
- [X] Accepter une connexion client
- [ ] Fermer une connexion
- [ ] Fonctionner sous les plateformes Windows, Linux et macOS
- [ ] Établir un protocol de communication (pour le réseau)
- [X] Communiquer sur le réseau via des sockets/websockets

### Objectifs personnels

- [ ] Choisir des design pattern appropriés et apprendre à mieux les comprendre par la pratique
- [ ] S'entrainer à respecter les principes SOLID
- [ ] S'entrainer à établir l'architecture d'un logiciel, sans être appuyé par un framework

## Avancement

Le projet à son stade actuel permet de gérer les échanges sur le réseau grâce à l'utilisation de sockets. Il supporte également la communication par websocket ce qui rend possible la création de client sur des technologies web, plus accessibles et plus flexibles. J'expérimente encore beaucoup sur des branches que je ne fusionne pas tout de suite, notamment pour la gestion des évènements.

## Pourquoi C++ ?

Alors pourquoi C++ ? Mais aussi pourquoi Boost et pas Qt ? Pour le choix du langage, je cherchais quelque chose de multi-plateforme, qui se compile et puisse être simple à utiliser. S'il s'agit d'un moteur de jeu, je code également la partie serveur au sens "serveur de jeu" dans le même projet. Ainsi je souhaite qu'il soit simple d'utilisation et consomme aussi peu de ressources que nécessaire.

Je souhaite également fournir un projet gratuitement et aussi libre que possible au niveau des licences ce qui explique en partie le choix de Boost qui est plus permissif que Qt à ce niveau. De plus, la façon d'approcher la partie réseau de Boost semble être plus proche de ce que le standard est sur le point de mettre en place pour les futures version de C++.

## Mon schéma de classe

J'essai de clarifier mes idées avant de coder sur des schémas mais très peu sont fait sur ordinateur. En effet, je fais souvent des schémas pour ma phase de réflexion et n'ont pas d'utilité une fois ma réfléxion terminée. En revanche, j'ai fait un diagramme de classe qui me permet, après une assez longue pause, de voir assez rapidement comment j'ai conçu l'architecture du projet. C'est un aide-mémoire assez pratique pour le moment, même si sa taille commence à justifier de le séparer en plusieurs schéma : un schéma maitre qui représente les différents modules et des sous-schémas par module. [Version actuelle du schéma](https://drive.google.com/file/d/1L65RontLWFYtbnkZinolVIkQ1Ivs5OyP/view?usp=sharing)


