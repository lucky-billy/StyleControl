#include "bcombobox.h"

BComboBox::BComboBox(QWidget *parent) : QComboBox(parent)
{

}

BComboBox::~BComboBox()
{

}

void BComboBox::showPopup()
{
    QComboBox::showPopup();
    QWidget *popup = this->findChild<QFrame*>();
    popup->move(popup->x(), popup->y() + 2);
}
