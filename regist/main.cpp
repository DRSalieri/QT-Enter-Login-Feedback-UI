
#include "Mydesign.h"
#include "database.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//MainWindow w;
	//w.show();


	DataBase d;
	d.createConnection();  //��������
	d.createTable();
	d.insert();
	d.queryAll();          //�Ѿ���ɹ�createTable(), insert(), ���ڽ��в�ѯ
	
	return a.exec();
}
