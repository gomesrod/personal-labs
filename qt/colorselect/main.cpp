#include "ColorSelect.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  ColorSelect cs;
  
  cs.show();
  return app.exec();
}
