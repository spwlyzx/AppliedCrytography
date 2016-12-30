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

