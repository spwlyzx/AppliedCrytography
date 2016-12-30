/********************************************************************************
** Form generated from reading UI file 'appliedcrytography.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLIEDCRYTOGRAPHY_H
#define UI_APPLIEDCRYTOGRAPHY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppliedCrytographyClass
{
public:
    QWidget *centralWidget;
    QTabWidget *MainTabs;
    QWidget *Encryption;
    QGroupBox *Encryption_Public_Key_Group;
    QLabel *E_Value_N;
    QTextEdit *Encryption_N;
    QLabel *E_Value_B;
    QTextEdit *Encryption_B;
    QPushButton *Save_Public_Key;
    QLabel *Encryption_Level;
    QComboBox *RSA_Level;
    QPushButton *Generate_Key;
    QGroupBox *Encryption_Private_Key_Group;
    QLabel *E_Value_A;
    QLabel *E_Value_P;
    QLabel *E_Value_Q;
    QTextEdit *Encryption_P;
    QTextEdit *Encryption_A;
    QTextEdit *Encryption_Q;
    QPushButton *Save_Private_Key;
    QGroupBox *Encryption_Message_Group;
    QTextEdit *Encrption_Message;
    QPushButton *Load_Message;
    QGroupBox *Encryption_Encrypted_Message_Group;
    QPushButton *Encrypt_Message;
    QPushButton *Save_Message;
    QTextEdit *Encryption_Encrypted_Message;
    QWidget *Decryption;
    QGroupBox *Decryption_Key_Group;
    QPushButton *Load_Private_Key;
    QPushButton *Load_Public_Key;
    QLabel *D_Value_A;
    QTextEdit *Decryption_A;
    QLabel *D_Value_N;
    QTextEdit *Decryption_N;
    QGroupBox *Decryption_Encrypted_Text_Group;
    QPushButton *Load_Encrypted_Text;
    QTextEdit *Decryption_Encrypted_Text;
    QGroupBox *Decryption_Decrypted_Text_Group;
    QPushButton *Decrypt_Message;
    QPushButton *Save_Decrypted_Text;
    QTextEdit *Decryption_Decrypted_Text;

    void setupUi(QMainWindow *AppliedCrytographyClass)
    {
        if (AppliedCrytographyClass->objectName().isEmpty())
            AppliedCrytographyClass->setObjectName(QStringLiteral("AppliedCrytographyClass"));
        AppliedCrytographyClass->resize(840, 540);
        AppliedCrytographyClass->setMinimumSize(QSize(840, 540));
        AppliedCrytographyClass->setMaximumSize(QSize(840, 540));
        centralWidget = new QWidget(AppliedCrytographyClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainTabs = new QTabWidget(centralWidget);
        MainTabs->setObjectName(QStringLiteral("MainTabs"));
        MainTabs->setGeometry(QRect(0, 0, 840, 540));
        Encryption = new QWidget();
        Encryption->setObjectName(QStringLiteral("Encryption"));
        Encryption_Public_Key_Group = new QGroupBox(Encryption);
        Encryption_Public_Key_Group->setObjectName(QStringLiteral("Encryption_Public_Key_Group"));
        Encryption_Public_Key_Group->setGeometry(QRect(10, 40, 371, 191));
        E_Value_N = new QLabel(Encryption_Public_Key_Group);
        E_Value_N->setObjectName(QStringLiteral("E_Value_N"));
        E_Value_N->setGeometry(QRect(20, 20, 54, 12));
        Encryption_N = new QTextEdit(Encryption_Public_Key_Group);
        Encryption_N->setObjectName(QStringLiteral("Encryption_N"));
        Encryption_N->setGeometry(QRect(20, 40, 331, 40));
        E_Value_B = new QLabel(Encryption_Public_Key_Group);
        E_Value_B->setObjectName(QStringLiteral("E_Value_B"));
        E_Value_B->setGeometry(QRect(20, 90, 54, 12));
        Encryption_B = new QTextEdit(Encryption_Public_Key_Group);
        Encryption_B->setObjectName(QStringLiteral("Encryption_B"));
        Encryption_B->setGeometry(QRect(20, 110, 331, 40));
        Save_Public_Key = new QPushButton(Encryption_Public_Key_Group);
        Save_Public_Key->setObjectName(QStringLiteral("Save_Public_Key"));
        Save_Public_Key->setGeometry(QRect(260, 158, 101, 23));
        Encryption_Level = new QLabel(Encryption);
        Encryption_Level->setObjectName(QStringLiteral("Encryption_Level"));
        Encryption_Level->setGeometry(QRect(18, 12, 101, 16));
        RSA_Level = new QComboBox(Encryption);
        RSA_Level->setObjectName(QStringLiteral("RSA_Level"));
        RSA_Level->setGeometry(QRect(130, 10, 131, 22));
        Generate_Key = new QPushButton(Encryption);
        Generate_Key->setObjectName(QStringLiteral("Generate_Key"));
        Generate_Key->setGeometry(QRect(280, 9, 91, 23));
        Encryption_Private_Key_Group = new QGroupBox(Encryption);
        Encryption_Private_Key_Group->setObjectName(QStringLiteral("Encryption_Private_Key_Group"));
        Encryption_Private_Key_Group->setGeometry(QRect(10, 240, 371, 261));
        E_Value_A = new QLabel(Encryption_Private_Key_Group);
        E_Value_A->setObjectName(QStringLiteral("E_Value_A"));
        E_Value_A->setGeometry(QRect(20, 20, 54, 12));
        E_Value_P = new QLabel(Encryption_Private_Key_Group);
        E_Value_P->setObjectName(QStringLiteral("E_Value_P"));
        E_Value_P->setGeometry(QRect(20, 90, 54, 12));
        E_Value_Q = new QLabel(Encryption_Private_Key_Group);
        E_Value_Q->setObjectName(QStringLiteral("E_Value_Q"));
        E_Value_Q->setGeometry(QRect(20, 160, 54, 12));
        Encryption_P = new QTextEdit(Encryption_Private_Key_Group);
        Encryption_P->setObjectName(QStringLiteral("Encryption_P"));
        Encryption_P->setGeometry(QRect(20, 110, 331, 40));
        Encryption_A = new QTextEdit(Encryption_Private_Key_Group);
        Encryption_A->setObjectName(QStringLiteral("Encryption_A"));
        Encryption_A->setGeometry(QRect(20, 40, 331, 40));
        Encryption_Q = new QTextEdit(Encryption_Private_Key_Group);
        Encryption_Q->setObjectName(QStringLiteral("Encryption_Q"));
        Encryption_Q->setGeometry(QRect(20, 180, 331, 40));
        Save_Private_Key = new QPushButton(Encryption_Private_Key_Group);
        Save_Private_Key->setObjectName(QStringLiteral("Save_Private_Key"));
        Save_Private_Key->setGeometry(QRect(250, 228, 111, 23));
        Encryption_Message_Group = new QGroupBox(Encryption);
        Encryption_Message_Group->setObjectName(QStringLiteral("Encryption_Message_Group"));
        Encryption_Message_Group->setGeometry(QRect(390, 10, 431, 221));
        Encrption_Message = new QTextEdit(Encryption_Message_Group);
        Encrption_Message->setObjectName(QStringLiteral("Encrption_Message"));
        Encrption_Message->setGeometry(QRect(20, 20, 391, 161));
        Load_Message = new QPushButton(Encryption_Message_Group);
        Load_Message->setObjectName(QStringLiteral("Load_Message"));
        Load_Message->setGeometry(QRect(311, 190, 101, 23));
        Encryption_Encrypted_Message_Group = new QGroupBox(Encryption);
        Encryption_Encrypted_Message_Group->setObjectName(QStringLiteral("Encryption_Encrypted_Message_Group"));
        Encryption_Encrypted_Message_Group->setGeometry(QRect(390, 240, 431, 261));
        Encrypt_Message = new QPushButton(Encryption_Encrypted_Message_Group);
        Encrypt_Message->setObjectName(QStringLiteral("Encrypt_Message"));
        Encrypt_Message->setGeometry(QRect(20, 20, 111, 23));
        Save_Message = new QPushButton(Encryption_Encrypted_Message_Group);
        Save_Message->setObjectName(QStringLiteral("Save_Message"));
        Save_Message->setGeometry(QRect(311, 20, 101, 23));
        Encryption_Encrypted_Message = new QTextEdit(Encryption_Encrypted_Message_Group);
        Encryption_Encrypted_Message->setObjectName(QStringLiteral("Encryption_Encrypted_Message"));
        Encryption_Encrypted_Message->setGeometry(QRect(20, 53, 391, 191));
        MainTabs->addTab(Encryption, QString());
        Decryption = new QWidget();
        Decryption->setObjectName(QStringLiteral("Decryption"));
        Decryption_Key_Group = new QGroupBox(Decryption);
        Decryption_Key_Group->setObjectName(QStringLiteral("Decryption_Key_Group"));
        Decryption_Key_Group->setGeometry(QRect(10, 10, 811, 191));
        Load_Private_Key = new QPushButton(Decryption_Key_Group);
        Load_Private_Key->setObjectName(QStringLiteral("Load_Private_Key"));
        Load_Private_Key->setGeometry(QRect(670, 20, 121, 23));
        Load_Public_Key = new QPushButton(Decryption_Key_Group);
        Load_Public_Key->setObjectName(QStringLiteral("Load_Public_Key"));
        Load_Public_Key->setGeometry(QRect(670, 100, 121, 23));
        D_Value_A = new QLabel(Decryption_Key_Group);
        D_Value_A->setObjectName(QStringLiteral("D_Value_A"));
        D_Value_A->setGeometry(QRect(22, 28, 54, 12));
        Decryption_A = new QTextEdit(Decryption_Key_Group);
        Decryption_A->setObjectName(QStringLiteral("Decryption_A"));
        Decryption_A->setGeometry(QRect(20, 50, 771, 41));
        D_Value_N = new QLabel(Decryption_Key_Group);
        D_Value_N->setObjectName(QStringLiteral("D_Value_N"));
        D_Value_N->setGeometry(QRect(22, 108, 54, 12));
        Decryption_N = new QTextEdit(Decryption_Key_Group);
        Decryption_N->setObjectName(QStringLiteral("Decryption_N"));
        Decryption_N->setGeometry(QRect(20, 130, 771, 41));
        Decryption_Encrypted_Text_Group = new QGroupBox(Decryption);
        Decryption_Encrypted_Text_Group->setObjectName(QStringLiteral("Decryption_Encrypted_Text_Group"));
        Decryption_Encrypted_Text_Group->setGeometry(QRect(10, 210, 401, 291));
        Load_Encrypted_Text = new QPushButton(Decryption_Encrypted_Text_Group);
        Load_Encrypted_Text->setObjectName(QStringLiteral("Load_Encrypted_Text"));
        Load_Encrypted_Text->setGeometry(QRect(20, 25, 131, 23));
        Decryption_Encrypted_Text = new QTextEdit(Decryption_Encrypted_Text_Group);
        Decryption_Encrypted_Text->setObjectName(QStringLiteral("Decryption_Encrypted_Text"));
        Decryption_Encrypted_Text->setGeometry(QRect(20, 60, 361, 221));
        Decryption_Decrypted_Text_Group = new QGroupBox(Decryption);
        Decryption_Decrypted_Text_Group->setObjectName(QStringLiteral("Decryption_Decrypted_Text_Group"));
        Decryption_Decrypted_Text_Group->setGeometry(QRect(420, 210, 401, 291));
        Decrypt_Message = new QPushButton(Decryption_Decrypted_Text_Group);
        Decrypt_Message->setObjectName(QStringLiteral("Decrypt_Message"));
        Decrypt_Message->setGeometry(QRect(30, 25, 131, 23));
        Save_Decrypted_Text = new QPushButton(Decryption_Decrypted_Text_Group);
        Save_Decrypted_Text->setObjectName(QStringLiteral("Save_Decrypted_Text"));
        Save_Decrypted_Text->setGeometry(QRect(250, 25, 131, 23));
        Decryption_Decrypted_Text = new QTextEdit(Decryption_Decrypted_Text_Group);
        Decryption_Decrypted_Text->setObjectName(QStringLiteral("Decryption_Decrypted_Text"));
        Decryption_Decrypted_Text->setGeometry(QRect(20, 60, 361, 221));
        MainTabs->addTab(Decryption, QString());
        AppliedCrytographyClass->setCentralWidget(centralWidget);

        retranslateUi(AppliedCrytographyClass);

        MainTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AppliedCrytographyClass);
    } // setupUi

    void retranslateUi(QMainWindow *AppliedCrytographyClass)
    {
        AppliedCrytographyClass->setWindowTitle(QApplication::translate("AppliedCrytographyClass", "Applied Cryptography", 0));
        Encryption_Public_Key_Group->setTitle(QApplication::translate("AppliedCrytographyClass", "Public Key", 0));
        E_Value_N->setText(QApplication::translate("AppliedCrytographyClass", "Value N:", 0));
        E_Value_B->setText(QApplication::translate("AppliedCrytographyClass", "Value B:", 0));
        Save_Public_Key->setText(QApplication::translate("AppliedCrytographyClass", "Save Public Key", 0));
        Encryption_Level->setText(QApplication::translate("AppliedCrytographyClass", "Encryption Level:", 0));
        RSA_Level->clear();
        RSA_Level->insertItems(0, QStringList()
         << QApplication::translate("AppliedCrytographyClass", "RSA-512(not safe)", 0)
         << QApplication::translate("AppliedCrytographyClass", "RSA-768(not safe)", 0)
         << QApplication::translate("AppliedCrytographyClass", "RSA-1024(safe)", 0)
         << QApplication::translate("AppliedCrytographyClass", "RSA-2048(safe)", 0)
        );
        Generate_Key->setText(QApplication::translate("AppliedCrytographyClass", "Generate Key", 0));
        Encryption_Private_Key_Group->setTitle(QApplication::translate("AppliedCrytographyClass", "Private Key", 0));
        E_Value_A->setText(QApplication::translate("AppliedCrytographyClass", "Value A:", 0));
        E_Value_P->setText(QApplication::translate("AppliedCrytographyClass", "Value P:", 0));
        E_Value_Q->setText(QApplication::translate("AppliedCrytographyClass", "Value Q:", 0));
        Save_Private_Key->setText(QApplication::translate("AppliedCrytographyClass", "Save Private Key", 0));
        Encryption_Message_Group->setTitle(QApplication::translate("AppliedCrytographyClass", "Message", 0));
        Load_Message->setText(QApplication::translate("AppliedCrytographyClass", "Load Message", 0));
        Encryption_Encrypted_Message_Group->setTitle(QApplication::translate("AppliedCrytographyClass", "Encrypted Message", 0));
        Encrypt_Message->setText(QApplication::translate("AppliedCrytographyClass", "Encrypt Message", 0));
        Save_Message->setText(QApplication::translate("AppliedCrytographyClass", "Save Message", 0));
        MainTabs->setTabText(MainTabs->indexOf(Encryption), QApplication::translate("AppliedCrytographyClass", "Encryption", 0));
        Decryption_Key_Group->setTitle(QApplication::translate("AppliedCrytographyClass", "Keys", 0));
        Load_Private_Key->setText(QApplication::translate("AppliedCrytographyClass", "Load Private Key", 0));
        Load_Public_Key->setText(QApplication::translate("AppliedCrytographyClass", "Load Public Key", 0));
        D_Value_A->setText(QApplication::translate("AppliedCrytographyClass", "Value A:", 0));
        D_Value_N->setText(QApplication::translate("AppliedCrytographyClass", "Value N:", 0));
        Decryption_Encrypted_Text_Group->setTitle(QApplication::translate("AppliedCrytographyClass", "Encrypted Text", 0));
        Load_Encrypted_Text->setText(QApplication::translate("AppliedCrytographyClass", "Load Encrypted Text", 0));
        Decryption_Decrypted_Text_Group->setTitle(QApplication::translate("AppliedCrytographyClass", "Decrypted Text", 0));
        Decrypt_Message->setText(QApplication::translate("AppliedCrytographyClass", "Decrypt Message", 0));
        Save_Decrypted_Text->setText(QApplication::translate("AppliedCrytographyClass", "Save Decrypted Text", 0));
        MainTabs->setTabText(MainTabs->indexOf(Decryption), QApplication::translate("AppliedCrytographyClass", "Decryption", 0));
    } // retranslateUi

};

namespace Ui {
    class AppliedCrytographyClass: public Ui_AppliedCrytographyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLIEDCRYTOGRAPHY_H
