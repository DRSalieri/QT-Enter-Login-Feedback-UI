#ifndef DATABASE_H
#define DATABASE_H


#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include<QString>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>

class DataBase
{
//public:
//	bool createConnection();  //����һ������
//	bool createTable();       //�������ݿ��
//	bool insert();            //��������
//	bool queryAll();          //��ѯ������Ϣ
//	bool updateById(int id);  //����
//	bool deleteById(int id);  //ɾ��
//	bool sortById();          //����

public:
	DataBase();
	~DataBase();
	void initsql();                
	void createtable(); 
	void insert(QString Usr,QString Pwd);
	bool Search(QString s1,QString s2);

private:
	//QSqlQuery *query;
	//QSqlQuery sql_query;
	QSqlDatabase db;
};





#endif // DATABASE_H