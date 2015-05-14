#include "CheckConnect.h"



CheckConnect::CheckConnect(void)
{
}


CheckConnect::~CheckConnect(void)
{
}


Mat    CheckConnect::getImg(VideoCapture xp)
{
   Mat tmp;
      if(!xp.read(tmp)) { // permet de vérifier si le flux de la camera ip à bien été ouvert
              cout << "Pas de frame" << endl; 
            waitKey();
        }

    return tmp;
}