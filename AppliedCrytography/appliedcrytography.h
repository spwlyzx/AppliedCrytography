#ifndef APPLIEDCRYTOGRAPHY_H
#define APPLIEDCRYTOGRAPHY_H

#include <QtWidgets/QMainWindow>
#include "ui_appliedcrytography.h"
#include <QtWidgets/QFileDialog>

class AppliedCrytography : public QMainWindow
{
	Q_OBJECT

public:
	AppliedCrytography(QWidget *parent = 0);
	~AppliedCrytography();

private slots:
	void GenerateKey();
	void SavePublicKey();
	void SavePrivateKey();
	void LoadMessage();
	void EncryptMessage();
	void SaveMessage();
	void LoadPrivateKey();
	void LoadPublicKey();
	void LoadEncryptedText();
	void DecryptMessage();
	void SaveDecryptedText();

private:
	Ui::AppliedCrytographyClass ui;
};

#endif // APPLIEDCRYTOGRAPHY_H
