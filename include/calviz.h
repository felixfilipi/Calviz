#ifndef CALVIZ_H
#define CALVIZ_H

#include <QWidget>
#include<iostream>
#include<vector>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QAction;
class QGroupBox;
class QLabel;
class QLineEdit;
class QRadioBox;
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QWidget;
class QRadioButton;
class QSpinBox;
class QScrollArea;
class QGridLayout;
QT_END_NAMESPACE

class Calviz : public QWidget
{
    Q_OBJECT

public:
    explicit Calviz(QWidget *parent = 0);
    ~Calviz();

private slots:
    void create_Input_section();
    void create_Derivative_input();
    void create_RSD_input();
    void on_visualizeButton_clicked();
    void make_connection();
    void on_derivativeSpinBox_Enabled();
    void on_RSDSpinBox_Enabled();
    void get_All_Value();
    void get_currState();
    void do_Processing();
    void add_Chart(QString, std::vector<double>, std::string);
    void add_Chart(QString, std::vector<std::string>, std::vector<std::vector<double>>, int, QString);
    void clean_visualization();

private:
    QVBoxLayout *inputLayout;
    QVBoxLayout *processingLayout;
    QVBoxLayout *scrollBoxLayout;
    QHBoxLayout *derivativeLayout;
    QHBoxLayout *RSDLayout;
    QLineEdit *exprLineEdit;
    QLineEdit *xLineEdit;
    QString in_expr, in_xval;
    QGroupBox *RSDGroupBox;
    QGroupBox *derivativeGroupBox;
    QGroupBox *inputGroupBox;
    QGroupBox *processingGroupBox;
    QGroupBox *visualizeGroupBox;
    QGridLayout *visualizeLayout;
    QGridLayout *mainLayout;
    QPushButton *visualizeButtonBox;
    QLabel *exprLabel;
    QLabel *xLabel;
    QScrollArea *scrollArea;
    QRadioButton *dbuttonOnce, *rsdbuttonOnce;
    QRadioButton *dbuttonTwice, *rsdbuttonTwice;
    QRadioButton *dbuttonOther, *rsdbuttonOther;
    QSpinBox *derivativeSpinBox;
    QSpinBox *RSDSpinBox;
    QWidget *visualizeWidget;
    int in_deriv, in_rsd, state, position;

};

#endif // CALVIZ_H
