


#include "database.h"
#include <QVariant>


//
////����һ�����ݿ�����
//bool DataBase::createConnection()
//{
//	//�Ժ�Ϳ�����"sqlite1"�����ݿ����������
//	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "sqlite1");
//	db.setDatabaseName(".//qtDBtest.db");
//	if( !db.open())
//	{
//		qDebug() << "�޷��������ݿ�����";
//		return false;
//	}
//	return true;
//}
//
////�������ݿ��
//	bool DataBase::createTable()
//{
//	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
//	QSqlQuery query(db);
//	bool success = query.exec("create table stu(id int primary key,age int)");
//	if(success)
//	{
//		qDebug() << QObject::tr("sucessed create��\n");
//		return true;
//	}
//	else
//	{
//		qDebug() << QObject::tr("error create��\n");
//		return false;
//	}
//}
//
//	//�����ݿ��в����¼
//	bool DataBase::insert()
//	{
//		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
//		QSqlQuery query(db);
//		query.prepare("insert into stu values(:a, :b)");
//
//
//		/*query.prepare("INSERT INTO person (id, forename, surname) "
//		"VALUES (:id, :forename, :surname)");
//		query.bindValue(":id", 1001);
//		query.bindValue(":forename", "Bart");
//		query.bindValue(":surname", "Simpson");
//		query.exec();*/
//
//			query.bindValue(":a",16060102113);
//			query.bindValue(":b", 20);
//		
//
//			bool success=query.exec();
//			if(!success)
//			{
//				QSqlError lastError = query.lastError();
//				qDebug() << lastError.driverText() << QString(QObject::tr("insert error"));
//				return false;
//			}
//		return true;
//	}
//
//	//��ѯ������Ϣ
//	bool DataBase::queryAll()
//	{
//		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
//		QSqlQuery query(db);
//		query.exec("select * from stu");
//		QSqlRecord rec = query.record();
//		qDebug() << QObject::tr("stu count ��" ) << rec.count();
//
//		while(query.next())
//		{
//			for(int index = 0; index < 10; index++)
//				qDebug() << query.value(index) << " ";
//			qDebug() << "\n";
//		}
//		return true;
//	}
//
//	//����IDɾ����¼
//	bool DataBase::deleteById(int id)
//	{
//		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
//		QSqlQuery query(db);
//		query.prepare(QString("delete from stu where id = %1").arg(id));
//		if(!query.exec())
//		{
//			qDebug() << "ɾ����¼ʧ�ܣ�";
//			return false;
//		}
//		return true;
//	}
//
//	//����ID���¼�¼
//	bool DataBase::updateById(int id)
//	{
//		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
//		QSqlQuery query(db);
//		query.prepare(QString("update stu set attribute=?,type=?,"
//			"kind=?, nation=?,"
//			"carnumber=?, elevaltor=?,"
//			"distance=?, oil=?,"
//			"temperature=? where id=%1").arg(id));
//
//		query.bindValue(0,"����");
//		query.bindValue(1,"�γ�");
//		query.bindValue(2,"����");
//		query.bindValue(3,rand()%100);
//		query.bindValue(4,rand()%10000);
//		query.bindValue(5,rand()%300);
//		query.bindValue(6,rand()%200000);
//		query.bindValue(7,rand()%52);
//		query.bindValue(8,rand()%100);
//
//		bool success=query.exec();
//		if(!success)
//		{
//			QSqlError lastError = query.lastError();
//			qDebug() << lastError.driverText() << QString(QObject::tr("����ʧ��"));
//		}
//		return true;
//	}
//
//	//����
//	bool DataBase::sortById()
//	{
//		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
//		QSqlQuery query(db);
//		bool success=query.exec("select * from automobil order by id desc");
//		if(success)
//		{
//			qDebug() << QObject::tr("����ɹ�");
//			return true;
//		}
//		else
//		{
//			qDebug() << QObject::tr("����ʧ�ܣ�");
//			return false;
//		}
//	}
//


DataBase::DataBase(){

}





void DataBase::initsql(){

	
	if (QSqlDatabase::contains("first"))
	{
		db = QSqlDatabase::database("first");
	}
	else
	{
		db = QSqlDatabase::addDatabase("QSQLITE","First");
		db.setDatabaseName("MyDataBase1.db");
		//db.setUserName("tonglin");
		//db.setPassword("123456");
	}



	if(db.open())
	{
		qDebug()<<"Database connected successfully!";
		return;
	}
	else
	{
		qDebug()<<"Database connected failed!";
		return;
	}


	


}



bool DataBase::Search(QString s1,QString s2){

	//�����ݿ��м���s1��Ӧ�Ľ������Ȼ����s2���бȶ�

	//select pwd from UserInfo where usr=s1;
	
	QSqlQuery sql_query(db);
	QString search_sql="select password from UserInfo where username=(?)";
	sql_query.prepare(search_sql);
	sql_query.addBindValue(s1);

	if(!sql_query.exec())
	{
		qDebug() << "Error: Fail to Search." << sql_query.lastError();
	}
	else
	{
		qDebug() << "Search Success !";
	}



	//���� QSqlQuery::value: not positioned on a valid record
	QString pass;

     if(sql_query.next()){
	 pass = sql_query.value(0).toString();
	 }


	 /*QSqlRecord rec = sql_query.record();
	 int snamecol = rec.indexOf(s1);
	 QString value = sql_query.value(snamecol).toString();*/
	
	
	if(s2==pass)
	{
		return true;
	}
	else
	{
		return false;


	}
}


void DataBase::createtable(){
	
	QSqlQuery sql_query(db);

	QString create_sql = "create table UserInfo( username varchar(20),password varchar(20))";
	sql_query.prepare(create_sql);
	if(!sql_query.exec())
	{
		qDebug() << "Error: Fail to create table." << sql_query.lastError();
	}
	else
	{
		qDebug() << "Table created!";
	}

	
	//query->exec("create table UserInfo(username int(20),password int(20)");
	//db.close();
}


//Driver not loadԭ�� ����ΪQSQLQuery����û�к�db����

void DataBase::insert(QString Usr,QString Pwd){

	QSqlQuery sql_query(db);
	QString insert_sql = "insert into UserInfo values (?, ?)";
	sql_query.prepare(insert_sql);
	sql_query.addBindValue(Usr);
	sql_query.addBindValue(Pwd);
	if(!sql_query.exec())
	{
		qDebug() << sql_query.lastError();
	}
	else
	{
		qDebug() << "inserted Wang!";
	}
	if(!sql_query.exec("INSERT INTO student VALUES(3, \"Li\", 23)"))
	{
		qDebug() << sql_query.lastError();
	}
	else
	{
		qDebug() << "inserted Li!";
	}

	

}




DataBase::~DataBase(){

	db.close();
}

