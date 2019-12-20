
#ifndef ENTER_H
#define ENTER_H


#include <QMainWindow>
#include <QWidget>
#include<QDesktopServices>
#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include<QLabel>
#include<QLineEdit>
#include "database.h"


class EnterForm : public QDialog
{
	Q_OBJECT 
public:
	explicit EnterForm(QDialog *parent = 0);  //explicit ��ֹ����
	~EnterForm();

public slots:
		void enter_();//�����¼��ť��ִ�еĲۺ���
	
private:
	QLabel *userNameLbl;         //"�û���"��ǩ
	QLabel *pwdLbl;              //"����"��ǩ
	QLineEdit *userNameLEd;      //�û����༭��
	QLineEdit *pwdLEd;           //����༭��
	QPushButton *loginBtn;       //��¼��ť
	QPushButton *exitBtn;        //�˳���ť
	QMessageBox *messageBox;

	DataBase *Mydb;


};








//class Enter{
//
//public:
//	Enter();
//	~Enter();
//	void run();
//
//
//private:
//
//
//
//};
//
//
//
//
//
#endif