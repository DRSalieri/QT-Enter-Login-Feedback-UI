#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QWidget>
#include<QDesktopServices>
#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include<QLabel>
#include<QLineEdit>
#include "database.h"


class LoginForm: public QDialog{

Q_OBJECT 

public:
	explicit LoginForm(QDialog *parent = 0);  //explicit ��ֹ����
	~LoginForm();
	

public slots:
	void true_();//���ȷ�ϰ�ť��ִ�еĲۺ��� 


private:

	QLabel *infolable;         //������ʾ��ע����桱����
	QLabel *usrlable;         //"�û���"��ǩ
	QLabel *pwdLable;              //"����"��ǩ
	QLineEdit *usrLEd;      //�û����༭��
	QLineEdit *pwdLEd;           //����༭��
	QPushButton *TrueBtn;        //ȷ�ϰ�ť
	QPushButton *FalseBtn;       //ȡ����ť
	QMessageBox* messageBox;

	DataBase *Mydb;

};



#endif  
