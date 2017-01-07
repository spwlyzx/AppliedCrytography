#include "appliedcrytography.h"
#include <QtWidgets/QApplication>
#include "BigInteger.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AppliedCrytography w;
	w.show();
	return a.exec();
}
