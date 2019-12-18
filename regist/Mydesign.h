#ifndef  MYDESIGN_H
#define  MYDESIGN_H

#include <QMainWindow>
#include <QWidget>
#include<QDesktopServices>
#include <QPushButton>
#include<QUrl>
#include<windows.h>
#include "enter.h"
#include "feedback.h"

class MainWindow : public QMainWindow{

	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();


private:
	//layout
	QPushButton *enterBtn;        //��¼��ť
	QPushButton *loginBtn;        //ע�ᰴť
	QPushButton *feedbackBtn;     //������ť
	EnterForm *en;
	FeedbackForm *fe; 

private slots:
	void enter();
	//void login();
	void feedback();

	


};


#endif