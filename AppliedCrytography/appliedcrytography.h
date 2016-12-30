#ifndef APPLIEDCRYTOGRAPHY_H
#define APPLIEDCRYTOGRAPHY_H

#include <QtWidgets/QMainWindow>
#include "ui_appliedcrytography.h"

class AppliedCrytography : public QMainWindow
{
	Q_OBJECT

public:
	AppliedCrytography(QWidget *parent = 0);
	~AppliedCrytography();

private:
	Ui::AppliedCrytographyClass ui;
};

#endif // APPLIEDCRYTOGRAPHY_H
