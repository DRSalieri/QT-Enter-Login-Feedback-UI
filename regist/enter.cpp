#include "enter.h"

EnterForm::EnterForm(QDialog *parent) :
QDialog(parent)
{
	//���ô������
	this->setWindowTitle(tr("Enter UI"));

	//�û���Label
	//userNameLbl->setMargin(20);
	userNameLbl = new QLabel(this);   //newһ����ǩ����
	userNameLbl->setMargin(20);
	userNameLbl->move(70,80);         //�ƶ���(70,80)λ��(Label���Ͻ����꣬����ڸ�����)
	userNameLbl->setText("UserName:");  //���ñ�ǩ�ı�

	//�û��������
	userNameLEd = new QLineEdit(this);
	userNameLEd->move(120,80);
	userNameLEd->setPlaceholderText(tr("Please input UserName!"));//ռλ��

	//����Label
	pwdLbl = new QLabel(this);
	pwdLbl->move(80,130);
	pwdLbl->setMargin(20);
	pwdLbl->setText("PassWord:");

	//���������
	pwdLEd = new QLineEdit(this);
	pwdLEd->move(120,130);
	pwdLEd->setPlaceholderText("Please input PassWord!");
	pwdLEd->setEchoMode(QLineEdit::Password);//�����������Բ����ʾ

	//��¼��ť
	loginBtn = new QPushButton(this);
	loginBtn->move(80,200);
	loginBtn->setText("Enter");

	//�˳���ť
	exitBtn = new QPushButton(this);
	exitBtn->move(170,200);
	exitBtn->setText("Quit");

	//������¼��ťʱ ִ�� LoginForm::login �ۺ���(�Զ���)�������˳���ťʱ ִ�� LoginForm::close �ۺ���(����Ĺرպ����������Լ�д)
	connect(loginBtn,SIGNAL(clicked()),this,SLOT(enter_()));
	connect(exitBtn,SIGNAL(clicked()),this,SLOT(close()));

	Mydb=new DataBase();
	Mydb->initsql();  

	this->show();
}




void EnterForm::enter_()
{
	//���userNameLEd�������ı���userNameLEd->text()��
	//trimmed()ȥ��ǰ��ո�
	//tr()��������ֹ��������ʱ����

	//userNameLEd->text().trimmed() == tr("tonglin") && pwdLEd->text() == tr("123456")
	QString s1=userNameLEd->text().trimmed();
	QString s2=pwdLEd->text();

	if(Mydb->Search(s1,s2))             //������ݿ�֮�������Ҫ��һ��Searchȥ�ж��Ƿ������ݿ���
	{
		
		//�ڴ�й©
		messageBox = new QMessageBox(this);
		messageBox->setIcon(QMessageBox::Information);
		messageBox->setWindowTitle(" Hello !! ");
		messageBox->setText("Welcome to coming ...");
		messageBox->show();
		
		
		
		//accept();//�رմ��壬�����÷���ֵΪAccepted
	} 
	else 
	{                              //����              ����                OK��ť  
		QMessageBox::warning(this, tr("Warning��"),tr("Input Error��"),QMessageBox::Yes);

		// ������������
		userNameLEd->clear();
		pwdLEd->clear();

		//��궨λ
		userNameLEd->setFocus();
	}
}



EnterForm::~EnterForm(){

	delete messageBox;
	delete Mydb;
	delete userNameLbl;        
	delete pwdLbl;             
	delete userNameLEd;     
	delete pwdLEd;          
	delete loginBtn;      
	delete exitBtn;       
}	