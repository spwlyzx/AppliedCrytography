#include "appliedcrytography.h"

AppliedCrytography::AppliedCrytography(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.Generate_Key, SIGNAL(clicked()), this, SLOT(GenerateKey()));
	connect(ui.Save_Public_Key, SIGNAL(clicked()), this, SLOT(SavePublicKey()));
	connect(ui.Save_Private_Key, SIGNAL(clicked()), this, SLOT(SavePrivateKey()));
	connect(ui.Load_Message, SIGNAL(clicked()), this, SLOT(LoadMessage()));
	connect(ui.Encrypt_Message, SIGNAL(clicked()), this, SLOT(EncryptMessage()));
	connect(ui.Save_Message, SIGNAL(clicked()), this, SLOT(SaveMessage()));
	connect(ui.Load_Private_Key, SIGNAL(clicked()), this, SLOT(LoadPrivateKey()));
	connect(ui.Load_Public_Key, SIGNAL(clicked()), this, SLOT(LoadPublicKey()));
	connect(ui.Load_Encrypted_Text, SIGNAL(clicked()), this, SLOT(LoadEncryptedText()));
	connect(ui.Decrypt_Message, SIGNAL(clicked()), this, SLOT(DecryptMessage()));
	connect(ui.Save_Decrypted_Text, SIGNAL(clicked()), this, SLOT(SaveDecryptedText()));
}

AppliedCrytography::~AppliedCrytography()
{

}

void AppliedCrytography::GenerateKey()
{
	int i = ui.RSA_Level->currentIndex();
	switch (i) {
		case 0: bits = 512; break;
		case 1: bits = 768; break;
		case 2: bits = 1024; break;
		case 3: bits = 2048; break;
	}
	p = producePrime(bits / 2);
	q = producePrime(bits / 2);
	n = q*p;
	phi_n = (q - 1)*(p - 1);
	b = produceBigInteger(bits);
	while(gcd(b,phi_n)!=1)
		b = produceBigInteger(phi_n);
	a = inverseMod(b, phi_n);
	ui.Encryption_A->setText(QString(a.toString16().c_str()));
	ui.Encryption_B->setText(QString(b.toString16().c_str()));
	ui.Encryption_N->setText(QString(n.toString16().c_str()));
	ui.Encryption_P->setText(QString(p.toString16().c_str()));
	ui.Encryption_Q->setText(QString(q.toString16().c_str()));
}

void AppliedCrytography::SavePublicKey()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Save Public Key"),
		".", tr("Key Files (*.txt)"));
}

void AppliedCrytography::SavePrivateKey()
{

}

void AppliedCrytography::LoadMessage()
{

}

void AppliedCrytography::EncryptMessage()
{

}

void AppliedCrytography::SaveMessage()
{

}

void AppliedCrytography::LoadPrivateKey()
{

}

void AppliedCrytography::LoadPublicKey()
{

}

void AppliedCrytography::LoadEncryptedText()
{

}

void AppliedCrytography::DecryptMessage()
{

}

void AppliedCrytography::SaveDecryptedText()
{

}

