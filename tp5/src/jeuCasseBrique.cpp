#include <unistd.h>
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>

#include "EcranASCII.h"



void enable_raw_mode()
{
    termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Disable echo as well
    tcsetattr(0, TCSANOW, &term);
}

void disable_raw_mode()
{
    termios term;
    tcgetattr(0, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(0, TCSANOW, &term);
}

bool kbhit()
{
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    return byteswaiting > 0;
}



void
jeuBouclePrincipale()
{
   while (true) {
    enable_raw_mode();
    if(kbhit()){
      unsigned char a = getchar();
      if(a == 'a')
      {
        std:: cout << "touche tapé: a" << std::endl;
      }
      if(a == 'z')
      {
        std::cout << "touche tapé: z" << std::endl;
      }
      disable_raw_mode();
      tcflush(0, TCIFLUSH);
    }
    usleep(200000);
    // A compléter
  }
}




int main(int argc, char * argv[]) {

  

  return EXIT_SUCCESS;
}





