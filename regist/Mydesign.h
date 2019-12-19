#ifndef  MYDESIGN_H
#define  MYDESIGN_H
#pragma execution_character_set("utf-8") 



#include <QMainWindow>
#include <QWidget>
#include<QDesktopServices>
#include <QPushButton>
#include<QUrl>
#include<windows.h>
#include "enter.h"
#include <QPalette>
#include "feedback.h"
#include "login.h"

class MainWindow : public QMainWindow{

	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();


private:
	//layout
	QLabel *infolable; 
	QPushButton *enterBtn;        //��¼��ť
	QPushButton *loginBtn;        //ע�ᰴť
	QPushButton *feedbackBtn;     //������ť
	EnterForm *en;
	FeedbackForm *fe; 
	LoginForm *lo;

private slots:
	void enter();
	void login();
	void feedback();

	


};


#endif