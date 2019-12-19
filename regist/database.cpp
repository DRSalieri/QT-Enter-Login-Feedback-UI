


#include "database.h"
#include <QVariant>
//����һ�����ݿ�����
bool DataBase::createConnection()
{
	//�Ժ�Ϳ�����"sqlite1"�����ݿ����������
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "sqlite1");
	db.setDatabaseName(".//qtDBtest.db");
	if( !db.open())
	{
		qDebug() << "�޷��������ݿ�����";
		return false;
	}
	return true;
}

//�������ݿ��
	bool DataBase::createTable()
{
	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
	QSqlQuery query(db);
	bool success = query.exec("create table stu(id int primary key,age int)");
	if(success)
	{
		qDebug() << QObject::tr("sucessed create��\n");
		return true;
	}
	else
	{
		qDebug() << QObject::tr("error create��\n");
		return false;
	}
}

	//�����ݿ��в����¼
	bool DataBase::insert()
	{
		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
		QSqlQuery query(db);
		query.prepare("insert into stu values(:a, :b)");


		/*query.prepare("INSERT INTO person (id, forename, surname) "
		"VALUES (:id, :forename, :surname)");
		query.bindValue(":id", 1001);
		query.bindValue(":forename", "Bart");
		query.bindValue(":surname", "Simpson");
		query.exec();*/

			query.bindValue(":a",16060102113);
			query.bindValue(":b", 20);
		

			bool success=query.exec();
			if(!success)
			{
				QSqlError lastError = query.lastError();
				qDebug() << lastError.driverText() << QString(QObject::tr("insert error"));
				return false;
			}
		return true;
	}

	//��ѯ������Ϣ
	bool DataBase::queryAll()
	{
		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
		QSqlQuery query(db);
		query.exec("select * from stu");
		QSqlRecord rec = query.record();
		qDebug() << QObject::tr("stu count ��" ) << rec.count();

		while(query.next())
		{
			for(int index = 0; index < 10; index++)
				qDebug() << query.value(index) << " ";
			qDebug() << "\n";
		}
		return true;
	}

	////����IDɾ����¼
	//bool DataBase::deleteById(int id)
	//{
	//	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
	//	QSqlQuery query(db);
	//	query.prepare(QString("delete from stu where id = %1").arg(id));
	//	if(!query.exec())
	//	{
	//		qDebug() << "ɾ����¼ʧ�ܣ�";
	//		return false;
	//	}
	//	return true;
	//}

	////����ID���¼�¼
	//bool DataBase::updateById(int id)
	//{
	//	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
	//	QSqlQuery query(db);
	//	query.prepare(QString("update stu set attribute=?,type=?,"
	//		"kind=?, nation=?,"
	//		"carnumber=?, elevaltor=?,"
	//		"distance=?, oil=?,"
	//		"temperature=? where id=%1").arg(id));

	//	query.bindValue(0,"����");
	//	query.bindValue(1,"�γ�");
	//	query.bindValue(2,"����");
	//	query.bindValue(3,rand()%100);
	//	query.bindValue(4,rand()%10000);
	//	query.bindValue(5,rand()%300);
	//	query.bindValue(6,rand()%200000);
	//	query.bindValue(7,rand()%52);
	//	query.bindValue(8,rand()%100);

	//	bool success=query.exec();
	//	if(!success)
	//	{
	//		QSqlError lastError = query.lastError();
	//		qDebug() << lastError.driverText() << QString(QObject::tr("����ʧ��"));
	//	}
	//	return true;
	//}

	////����
	//bool DataBase::sortById()
	//{
	//	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //�������ݿ�����
	//	QSqlQuery query(db);
	//	bool success=query.exec("select * from automobil order by id desc");
	//	if(success)
	//	{
	//		qDebug() << QObject::tr("����ɹ�");
	//		return true;
	//	}
	//	else
	//	{
	//		qDebug() << QObject::tr("����ʧ�ܣ�");
	//		return false;
	//	}
	//}