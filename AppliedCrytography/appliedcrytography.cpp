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
	b = produceBigInteger(bits/2);
	while (gcd(b, phi_n) != 1)
		b = b + 1;
	a = inverseMod(b, phi_n);
	ui.Encryption_A->setText(QString(a.toString16().c_str()));
	ui.Encryption_B->setText(QString(b.toString16().c_str()));
	ui.Encryption_N->setText(QString(n.toString16().c_str()));
	ui.Encryption_P->setText(QString(p.toString16().c_str()));
	ui.Encryption_Q->setText(QString(q.toString16().c_str()));
}

void AppliedCrytography::SavePublicKey()
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Public Key"),
		".", tr("Key Files (*.txt)"));
	ofstream f(filename.toStdString());
	if (!filename.isEmpty() && !f)
	{
		QMessageBox::warning(this,"Warning","The path should not contain chinese.");
		return;
	}
	else if(!filename.isEmpty() && n.bitNum==0)
	{
		QMessageBox::warning(this, "Warning", "You should generate a group of keys");
		return;
	}
	else if (filename.isEmpty())
		return;
	f << n.toString16() << endl;
	f << b.toString16() << endl;
}

void AppliedCrytography::SavePrivateKey()
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Private Key"),
		".", tr("Key Files (*.txt)"));
	ofstream f(filename.toStdString());
	if (!filename.isEmpty() && !f)
	{
		QMessageBox::warning(this, "Warning", "The path should not contain chinese.");
		return;
	}
	else if (!filename.isEmpty() && n.bitNum == 0)
	{
		QMessageBox::warning(this, "Warning", "You should generate a group of keys");
		return;
	}
	else if (filename.isEmpty())
		return;
	f << a.toString16() << endl;
	f << p.toString16() << endl;
	f << q.toString16() << endl;
}

void AppliedCrytography::LoadMessage()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Load Message"),
		".", tr("Key Files (*.txt)"));
	fstream f(filename.toStdString());
	if (!filename.isEmpty() && !f)
	{
		QMessageBox::warning(this, "Warning", "The path should not contain chinese.");
		return;
	}
	else if (filename.isEmpty())
	{
		return;
	}
	string line;
	message = "";
	while (!f.eof())
	{
		getline(f,line);
		message = message + line;
	}
	ui.Encrption_Message->setText(QString(message.c_str()));
}

void AppliedCrytography::EncryptMessage()
{
	message = ui.Encrption_Message->toPlainText().toStdString();
	if (n.bitNum == 0 || a.bitNum == 0 || b.bitNum == 0 || p.bitNum == 0 || q.bitNum == 0)
	{
		QMessageBox::warning(this, "Warning", "Please generate the keys!");
		return;
	}
	int bits = 512;
	if (n.bitNum > 1024)
		bits = 2048;
	else if (n.bitNum > 768)
		bits = 1024;
	else if (n.bitNum > 512)
		bits = 768;
	vector<BigInteger> origin;
	vector<BigInteger> after;
	transferToBigIntegers(origin, message, bits);
	for (int i = 0; i < origin.size(); i++)
	{
		after.push_back(modularExp(origin[i], b, n));
	}
	transferToString16(after, encrypt_message, bits);
	ui.Encryption_Encrypted_Message->setText(encrypt_message.c_str());
}

void AppliedCrytography::SaveMessage()
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Encrypted Message"),
		".", tr("Message Files (*.txt)"));
	ofstream f(filename.toStdString());
	if (!filename.isEmpty() && !f)
	{
		QMessageBox::warning(this, "Warning", "The path should not contain chinese.");
		return;
	}
	else if (filename.isEmpty())
		return;
	f << encrypt_message << endl;
}

void AppliedCrytography::LoadPrivateKey()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Load Private Key"),
		".", tr("Key Files (*.txt)"));
	fstream f(filename.toStdString());
	if (!filename.isEmpty() && !f)
	{
		QMessageBox::warning(this, "Warning", "The path should not contain chinese.");
		return;
	}
	else if (filename.isEmpty())
		return;
	string temp;
	f >> temp;
	a = BigInteger(temp);
	ui.Decryption_A->setText(QString(temp.c_str()));
	f >> temp;
	p = BigInteger(temp); 
	f >> temp;
	q = BigInteger(temp);
}

void AppliedCrytography::LoadPublicKey()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Load Public Key"),
		".", tr("Key Files (*.txt)"));
	fstream f(filename.toStdString());
	if (!filename.isEmpty() && !f)
	{
		QMessageBox::warning(this, "Warning", "The path should not contain chinese.");
		return;
	}
	else if (filename.isEmpty())
		return;
	string temp;
	f >> temp;
	n = BigInteger(temp);
	ui.Decryption_N->setText(QString(temp.c_str()));
	f >> temp;
	b = BigInteger(temp);
}

void AppliedCrytography::LoadEncryptedText()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Load Encrypted Message"),
		".", tr("Message Files (*.txt)"));
	fstream f(filename.toStdString());
	if (!filename.isEmpty() && !f)
	{
		QMessageBox::warning(this, "Warning", "The path should not contain chinese.");
		return;
	}
	else if (filename.isEmpty())
		return;
	string line;
	encrypt_message = "";
	while (!f.eof())
	{
		getline(f, line);
		encrypt_message = encrypt_message + line;
	}
	ui.Decryption_Encrypted_Text->setText(QString(encrypt_message.c_str()));
}

void AppliedCrytography::DecryptMessage()
{
	encrypt_message = ui.Decryption_Encrypted_Text->toPlainText().toStdString();
	if (n.bitNum == 0 || a.bitNum == 0 || b.bitNum == 0 || p.bitNum == 0 || q.bitNum == 0)
	{
		QMessageBox::warning(this, "Warning", "Please load the keys!");
		return;
	}
	int bits = 512;
	if (n.bitNum > 1024)
		bits = 2048;
	else if (n.bitNum > 768)
		bits = 1024;
	else if (n.bitNum > 512)
		bits = 768;
	vector<BigInteger> origin;
	vector<BigInteger> after;
	transferToBigIntegers16(origin, encrypt_message, bits);
	for (int i = 0; i < origin.size(); i++)
	{
		after.push_back(modularExp(origin[i], a, n));
	}
	transferToString(after, message, bits);
	ui.Decryption_Decrypted_Text->setText(message.c_str());
}

void AppliedCrytography::SaveDecryptedText()
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Decrypted Message"),
		".", tr("Message Files (*.txt)"));
	ofstream f(filename.toStdString());
	if (!filename.isEmpty() && !f )
	{
		QMessageBox::warning(this, "Warning", "The path should not contain chinese.");
		return;
	}
	else if (filename.isEmpty())
		return;
	f << message << endl;
}

