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
      if(!xp.read(tmp)) { // permet de v�rifier si le flux de la camera ip � bien �t� ouvert
              cout << "Pas de frame" << endl; 
            waitKey();
        }

    return tmp;
}