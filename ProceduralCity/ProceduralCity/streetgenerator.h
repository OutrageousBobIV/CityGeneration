#ifndef STREETGENERATOR_H
#define STREETGENERATOR_H

#include <QtWidgets/QMainWindow>
#include "ui_streetgenerator.h"

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "StreetGen.h"

class StreetGenerator : public QMainWindow
{
	Q_OBJECT

public:
	StreetGenerator(QWidget *parent = 0);
	~StreetGenerator();

private slots:
	void onClickGenerate();

	void on_comboBox_activated(const QString &arg1);

	void on_pushButton_clicked();
	void on_buttonHMap_clicked();
	void on_buttonPMap_clicked();
	void on_buttonGMap_clicked();

private:
	Ui::StreetGenerator ui;
	StreetGen generator;
	QFileDialog fd;
	QString getFileChoice();
};

#endif // STREETGENERATOR_H
