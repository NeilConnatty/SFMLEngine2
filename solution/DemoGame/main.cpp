#include <iostream>
#include <application.h>

int main()
{
   try 
   {
      application app;
      app.run();
   }
   catch (std::exception& e)
   {
      std::cout << "\nException: " << e.what() << std::endl;
   }
}
