#include <QVBoxLayout>
#include "ArrowWidget.h"
#include "qpushbutton.h"


ArrowWidget::ArrowWidget()
{
	//QPushButton * button1 = new QPushButton();
	//QPushButton * button2 = new QPushButton();

	arrowButton1 = new ArrowButton(false);
	placeHolder = new QWidget();
	arrowButton2 = new ArrowButton(true);

	arrowButton1->resize(100, 100);
	arrowButton2->resize(100, 100);

	QSizePolicy arrow1Policy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	arrow1Policy.setHorizontalStretch(5);
	arrowButton1->setSizePolicy(arrow1Policy);

	QSizePolicy placeHolderPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	placeHolderPolicy.setHorizontalStretch(5);
	placeHolder->setSizePolicy(placeHolderPolicy);


	QSizePolicy arrow2Policy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	arrow2Policy.setHorizontalStretch(5);
	arrowButton2->setSizePolicy(arrow2Policy);



	QVBoxLayout layout;
	layout.addWidget(arrowButton1);
	layout.addWidget(placeHolder);
	layout.addWidget(arrowButton2);

	layout.setSpacing(0);
	layout.setContentsMargins(0, 0, 0, 0);


	//layout.addWidget(button1);
	//layout.addWidget(button2);
	this->setLayout(&layout);
}