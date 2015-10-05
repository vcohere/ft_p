# ft_p

Un projet de client/serveur ftp simple. Le protocol de transfert de fichier est "fait maison". Le serveur utilise fork() pour gerer les plusieurs clients au lieu de select(), par choix de simplicite. 
<br />
Lancer le serveur : ./serveur [port]<br />
Lancer le client : ./client [ipadress] [port]

Commandes disponibles :
* get
* put
* ls ( toutes les options sont utilisables )
* pwd
* exit
