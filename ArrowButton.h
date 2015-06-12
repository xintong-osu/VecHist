#ifndef ARROW_SLIDER_H
#define ARROW_SLIDER_H

#include <QPushButton>

class ArrowButton : public QPushButton
{
	Q_OBJECT
public:
	ArrowButton(bool type);
	void paintEvent(QPaintEvent *);

private:
	bool type = false;
};

#endif //ARROW_SLIDER_H
