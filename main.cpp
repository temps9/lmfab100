#include <QApplication>
#include "clavier.h"
#ifdef WIN32 // WIN32 is defined by all Windows 32 compilers, but not by others.
#include <windows.h>
#else
#include <unistd.h>
#endif
/* Imaginer et creer par Abadie joris*/
/* en utilisant un concept de Andre pierre jocelyn*/
/*Cette oeuvre est protégée et n'est divulguée et réservé que pour utilisation sous linux dans les conditions Creative common ci-dessous*/
/* Cette oeuvre est mise à disposition selon les termes de la Licence Creative Commons Paternité - Pas d'Utilisation Commerciale - Partage des Conditions Initiales à l'Identique 2.0 France. */
/*Aucune garantie n'est donner sur les effets de cet executable*/
/*depend de sudo apt-get install qtmultimedia5-dev
sudo apt-get install libqt5multimedia5-plugins*/

#ifdef QT_STATIC
#include <QtCore/QtPlugin>
Q_IMPORT_PLUGIN(DSServicePlugin)
#endif

int main(int argc, char *argv[])
{
  char nomfichierwav[32];
  char nomfichierwavacte[40];
  char lettresclaviers[] = {97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123};
  char c;
        for(int i=0; i<26; i++)
         {
    c = lettresclaviers[i];
    for(int n=1; n<6; n++)
     {
  snprintf(nomfichierwav, 32, "%c%d.wav", c, n);
  FILE * fichierwav;
  if (!(fichierwav=fopen(nomfichierwav, "r")))
  // sinon, on le génère
   {
if (n==1)
  {
    genereFichierJo(c);
    conversionJoWav(c,n);
  }
else
  {    
  snprintf(nomfichierwavacte, 40, "sox %c1.wav %c%d.wav", c, c, n);
system(nomfichierwavacte);
  }
   }
  else
   fclose(fichierwav);
}
}

    QApplication app(argc, argv);
    clavier fenetre;
    fenetre.show();
    return app.exec();
}

