#include "include/calviz.h"
#include "ui_calviz.h"
#include "include/Processing.hpp"
#include "include/RSD.hpp"
#include "include/Utility.hpp"
#include<QtWidgets>
#include <QPushButton>
#include<QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

using namespace QtCharts;

Calviz::Calviz(QWidget *parent) :
    QWidget(parent)
{
    position = 0;
    create_Input_section();
    create_Derivative_input();
    create_RSD_input();

    visualizeLayout = new QGridLayout;

    visualizeWidget = new QWidget;
    visualizeWidget->setLayout(visualizeLayout);

    scrollArea = new QScrollArea;
    scrollArea->setWidget(visualizeWidget);
    scrollArea->setWidgetResizable(true);

    scrollBoxLayout = new QVBoxLayout;
    scrollBoxLayout->addWidget(scrollArea);

    visualizeGroupBox = new QGroupBox(tr("Your Visualization"));
    visualizeGroupBox->setLayout(scrollBoxLayout);
    visualizeGroupBox->setLayout(visualizeLayout);

    processingLayout = new QVBoxLayout;
    processingLayout->addWidget(inputGroupBox);
    processingLayout->addWidget(derivativeGroupBox);
    processingLayout->addWidget(RSDGroupBox);

    visualizeButtonBox = new QPushButton("Process", this);
    processingLayout->addWidget(visualizeButtonBox);

    processingGroupBox = new QGroupBox(tr("Your Processing"));
    processingGroupBox->setLayout(processingLayout);

    make_connection();

    mainLayout = new QGridLayout;
    mainLayout->addWidget(processingGroupBox, 0, 0);
    mainLayout->addWidget(visualizeGroupBox, 0, 1);
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(1, 6);
    setLayout(mainLayout);
    setWindowTitle(tr("Calviz"));
}

Calviz::~Calviz()
{
    delete inputLayout;
    delete processingLayout;
    delete scrollBoxLayout;
    delete derivativeLayout;
    delete RSDLayout;
    delete exprLineEdit;
    delete xLineEdit;
    delete RSDGroupBox;
    delete derivativeGroupBox;
    delete inputGroupBox;
    delete processingGroupBox;
    delete visualizeGroupBox;
    delete visualizeLayout;
    delete mainLayout;
    delete visualizeButtonBox;
    delete exprLabel;
    delete xLabel;
    delete scrollArea;
    delete dbuttonOnce;
    delete rsdbuttonOnce;
    delete dbuttonTwice;
    delete rsdbuttonTwice;
    delete dbuttonOther;
    delete rsdbuttonOther;
    delete derivativeSpinBox;
    delete RSDSpinBox;
    delete visualizeWidget;
}

void Calviz::create_Input_section(){
    inputGroupBox = new QGroupBox(tr("Input Section"));
    inputLayout = new QVBoxLayout;

    exprLabel = new QLabel(tr("Enter Your Expression = "));
    exprLineEdit = new QLineEdit;
    exprLineEdit->setPlaceholderText("Ex: 3x^3 + 5x^2 - 8x + 5");

    xLabel = new QLabel(tr("Enter Your X Value = "));
    xLineEdit = new QLineEdit;
    xLineEdit->setPlaceholderText("Ex: 1, 3, 5, 8");

    inputLayout->addWidget(exprLabel);
    inputLayout->addWidget(exprLineEdit);
    inputLayout->addWidget(xLabel);
    inputLayout->addWidget(xLineEdit);
    inputGroupBox->setLayout(inputLayout);
}

void Calviz::create_Derivative_input(){
    derivativeGroupBox = new QGroupBox(tr("Derivative"));
    derivativeGroupBox->setCheckable(true);
    derivativeLayout = new QHBoxLayout;

    dbuttonOnce = new QRadioButton("Once", this);
    dbuttonTwice = new QRadioButton("Twice", this);
    dbuttonOther = new QRadioButton("Other", this);
    derivativeSpinBox = new QSpinBox;
    derivativeSpinBox->setEnabled(false);
    derivativeSpinBox->setMinimum(1);
    derivativeSpinBox->setMaximum(10);

    derivativeLayout->addWidget(dbuttonOnce);
    derivativeLayout->addWidget(dbuttonTwice);
    derivativeLayout->addWidget(dbuttonOther);
    derivativeLayout->addWidget(derivativeSpinBox);
    derivativeGroupBox->setLayout(derivativeLayout);
}

void Calviz::create_RSD_input(){
    RSDGroupBox = new QGroupBox(tr("Root Squared"));
    RSDGroupBox->setCheckable(true);
    RSDLayout = new QHBoxLayout;

    rsdbuttonOnce = new QRadioButton("Once", this);
    rsdbuttonTwice = new QRadioButton("Twice", this);
    rsdbuttonOther = new QRadioButton("Other", this);
    RSDSpinBox = new QSpinBox;
    RSDSpinBox->setEnabled(false);
    RSDSpinBox->setMinimum(1);
    RSDSpinBox->setMaximum(10);

    RSDLayout->addWidget(rsdbuttonOnce);
    RSDLayout->addWidget(rsdbuttonTwice);
    RSDLayout->addWidget(rsdbuttonOther);
    RSDLayout->addWidget(RSDSpinBox);
    RSDGroupBox->setLayout(RSDLayout);
}

void Calviz::add_Chart(QString x_in, std::vector<double> y, std::string title){

    QLineSeries *series = new QLineSeries();
    QChart *chart;
    QChartView *chartView;

    QString ttl = QString::fromUtf8(title.c_str());
    std::vector<double> x = util::parse_to_number(x_in.toStdString());
    for( int i = 0 ; i <= x.size() - 1; i++){
        series->append(x[i], y[i]);
    };

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(ttl);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    if(position < 1){
        visualizeLayout->addWidget(chartView, position+1,0);
        position++;
    }
}

void Calviz::add_Chart(QString x_val, std::vector<std::string> x_in, std::vector<std::vector<double>> y, int row, QString label){

    QChartView *chartView;
    QLineSeries *series;
    QGridLayout *rowLayout;
    QChart *chart;
    QLabel *chartLabel;
    QString ttl;
    std::vector<double> x = util::parse_to_number(x_val.toStdString());
    rowLayout = new QGridLayout;

    chartLabel = new QLabel(tr(label.toStdString().c_str()));
    rowLayout->addWidget(chartLabel, 0, 0);
    rowLayout->setColumnStretch(0, 1);

    for(int i = 0; i <= x_in.size() - 1; i++){
        series = new QLineSeries();
        for( int j = 0 ; j <= x.size() - 1; j++){
            series->append(x[j], y[i][j]);
        };

        chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        ttl = QString::fromUtf8(x_in[i].c_str());
        chart->setTitle(ttl);

        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        rowLayout->addWidget(chartView, 0, i + 1);
        rowLayout->setColumnStretch(i + 1, 2);
        rowLayout->setRowStretch(i + 1, 1);
    }

    visualizeLayout->addLayout(rowLayout, row, 0);
    if(in_deriv <= 3){
        visualizeWidget->setMinimumWidth(500);
    }else if(in_deriv > 3 && in_deriv <= 6){
        visualizeWidget->setMinimumWidth(2000);
    }else{
        visualizeWidget->setMinimumWidth(3000);
    }

}

void Calviz::on_derivativeSpinBox_Enabled(){
    if(dbuttonOther->isChecked()){
        derivativeSpinBox->setEnabled(true);
    }else{
        derivativeSpinBox->setEnabled(false);
    }
}

void Calviz::on_RSDSpinBox_Enabled(){
    if(rsdbuttonOther->isChecked()){
        RSDSpinBox->setEnabled(true);
    }else{
        RSDSpinBox->setEnabled(false);
    }
}

void Calviz::make_connection(){
    connect(visualizeButtonBox, &QPushButton::released, this, &Calviz::on_visualizeButton_clicked);
    connect(dbuttonOther, &QRadioButton::toggled, this, &Calviz::on_derivativeSpinBox_Enabled);
    connect(rsdbuttonOther, &QRadioButton::toggled, this, &Calviz::on_RSDSpinBox_Enabled);
}

void Calviz::get_All_Value(){

    in_expr = exprLineEdit->text();
    in_xval = xLineEdit->text();

    if(dbuttonOnce->isChecked()){
        in_deriv = 1;
    }else if(dbuttonTwice -> isChecked()){
        in_deriv = 2;
    }else if(dbuttonOther -> isChecked()){
        in_deriv = derivativeSpinBox->value();
    };

    if(rsdbuttonOnce->isChecked()){
        in_rsd = 1;
    }else if(rsdbuttonTwice->isChecked()){
        in_rsd = 2;
    }else if(rsdbuttonOther->isChecked()){
        in_rsd = RSDSpinBox->value();
    };
}

void Calviz::get_currState(){
    if(in_expr.isEmpty() == false && in_xval.isEmpty() == false && in_deriv == 0 && in_rsd == 0){
        state = 1;
    }else if(in_expr.isEmpty() == false && in_xval.isEmpty() == false && in_deriv != 0 && in_rsd == 0){
        state = 2;
    }else if(in_expr.isEmpty() == false && in_xval.isEmpty() == false && in_deriv == 0 && in_rsd != 0){
        state = 3;
    }else if(in_expr.isEmpty() == false && in_xval.isEmpty() == false && in_deriv != 0 && in_rsd !=0){
        state = 4;
    }else if(in_expr.isEmpty() == true || in_xval.isEmpty() == true){
        state = 5;
    };
}

void Calviz::do_Processing(){
    std::string cleanExpr;
    std::vector<double> interval, result;
    std::vector<std::vector<double>> all_interval, all_derivative_result, RSD_result;
    std::vector<std::vector<std::vector<double>>> all_RSD_result;
    std::vector<std::string> all_derivative_expr;

    switch(state){
    case 1:
    {
        Processing *p = new Processing();
        p->No_Diff_No_RSD(in_expr.toStdString(), in_xval.toStdString());
        cleanExpr = p->getCleanExpr();
        interval = p->getInterval();
        result = p->get_result_props();
        add_Chart(in_xval, result, cleanExpr);
        delete p;
        break;
    }

    case 2:
    {
        Processing *p = new Processing();
        p->Diff_no_RSD(in_deriv, in_expr.toStdString(), in_xval.toStdString());
        all_derivative_expr = p->get_All_Derivative_Expr();
        all_derivative_result = p->get_All_Derivative_Result();
        all_interval = p->get_All_Interval();
        add_Chart(in_xval, all_derivative_expr, all_derivative_result, 0, "Derivative Result");
        add_Chart(in_xval, all_derivative_expr, all_interval, 1, "Interval Result");
        delete p;
        break;
    }

    case 3:
    {
        RSD *rsd = new RSD();
        rsd->No_Diff_with_RSD(in_rsd, in_expr.toStdString(), in_xval.toStdString());
        cleanExpr = rsd->getCleanExpr();
        result = rsd->get_result_props();
        interval = rsd->getInterval();
        RSD_result = rsd->get_RSD_result();
        all_interval = rsd->get_All_Interval();

        delete rsd;
        break;
    }

    case 4:
    {
        RSD *rsd = new RSD();
        rsd->Diff_and_RSD(in_deriv, in_rsd, in_expr.toStdString(), in_xval.toStdString());
        all_derivative_expr = rsd->get_All_Derivative_Expr();
        all_RSD_result = rsd->get_all_RSD_result();

        delete rsd;
        break;
    }
    case 5:
    {
        QMessageBox::information(this, "Title", "Please fill the empty field");
        break;
    }
    }
}

void Calviz::clean_visualization(){
    visualizeLayout = new QGridLayout;

    visualizeWidget = new QWidget;
    visualizeWidget->setLayout(visualizeLayout);
}

void Calviz::on_visualizeButton_clicked()
{
//    clean_visualization();
    get_All_Value();
    get_currState();
    do_Processing();
}

