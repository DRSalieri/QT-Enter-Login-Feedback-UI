

#include"login.h"



LoginForm::LoginForm(QDialog *parent):	
					 QDialog(parent)

{
	//���ô������
	this->setWindowTitle(tr("Login UI"));


	infolable=new QLabel(this);
	infolable->move(70,40);
	infolable->setText("Welcome to Login UI ");

	
	//userNameLbl->setMargin(20);
	usrlable = new QLabel(this);   //newһ����ǩ����
	
	usrlable->setMargin(20);
	usrlable->move(70,80);         //�ƶ���(70,80)λ��(Label���Ͻ����꣬����ڸ�����)
	usrlable->setText("UserName:");  //���ñ�ǩ�ı�

	//�û��������
	usrLEd = new QLineEdit(this);
	usrLEd->move(120,80);
	usrLEd->setPlaceholderText(tr("Please input UserName!"));//ռλ��

	//����Label
	pwdLable = new QLabel(this);
	pwdLable->move(80,130);
	pwdLable->setMargin(20);
	pwdLable->setText("PassWord:");

	//���������
	pwdLEd = new QLineEdit(this);
	pwdLEd->move(120,130);
	pwdLEd->setPlaceholderText("Please input PassWord!");
	pwdLEd->setEchoMode(QLineEdit::Password);//�����������Բ����ʾ

	//ȷ�ϰ�ť
	TrueBtn = new QPushButton(this);
	TrueBtn->move(80,200);
	TrueBtn->setText("YES");

	//�˳���ť
	FalseBtn = new QPushButton(this);
	FalseBtn->move(170,200);
	FalseBtn->setText("NO");

	//������¼��ťʱ ִ�� LoginForm::login �ۺ���(�Զ���)�������˳���ťʱ ִ�� LoginForm::close �ۺ���(����Ĺرպ����������Լ�д)
	connect(TrueBtn,SIGNAL(clicked()),this,SLOT(true_()));
	connect(FalseBtn,SIGNAL(clicked()),this,SLOT(close()));



	Mydb=new DataBase();
	Mydb->initsql();  

	this->show();

}

void LoginForm::true_(){   //��ע����Ϣ���뵽�������ݿ�
    
	     

    //����û��ڱ༭�������������
	QString s1=usrLEd->text();
	QString s2=pwdLEd->text();
	Mydb->insert(s1,s2);   //����δ���룿����
	


	//������ʾע��ɹ�				 	
	messageBox = new QMessageBox(this);
	messageBox->setIcon(QMessageBox::Information);
	messageBox->setWindowTitle(" Login Success !! ");
	messageBox->setText("congratulation ! !");
	messageBox->show();
	

}

LoginForm::~LoginForm(){

	delete Mydb;
	delete infolable;       
	delete usrlable;        
	delete pwdLable;        
	delete usrLEd;      
	delete pwdLEd;       
	delete TrueBtn;    
	delete FalseBtn;   
	delete messageBox;

}






