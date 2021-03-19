#ifndef BCOMBOBOX_H
#define BCOMBOBOX_H

#include <QComboBox>

class BComboBox : public QComboBox
{
public:
    BComboBox(QWidget *parent = nullptr);
    ~BComboBox();

    void showPopup()override;
};

#endif // BCOMBOBOX_H
