#ifndef APPLIEDCRYTOGRAPHY_H
#define APPLIEDCRYTOGRAPHY_H

#include <QtWidgets/QMainWindow>
#include "ui_appliedcrytography.h"
#include <QtWidgets/QFileDialog>
#include "BigInteger.h"
#include <iostream>
#include <fstream>
#include "QtWidgets/qmessagebox.h"

class AppliedCrytography : public QMainWindow
{
	Q_OBJECT

public:
	AppliedCrytography(QWidget *parent = 0);
	~AppliedCrytography();

private:
	BigInteger a, b, p, q, n, phi_n;
	int bits;
	string message, encrypt_message;

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
