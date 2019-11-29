/********************************************************************************
** Form generated from reading UI file 'NavarQT.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVARQT_H
#define UI_NAVARQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NavarQTClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QWidget *steps;
    QVBoxLayout *verticalLayout;
    QWidget *steps_top;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_step_1;
    QLabel *label_divider_12;
    QPushButton *pushButton_step_2;
    QLabel *label_divider_23;
    QPushButton *pushButton_step_3;
    QLabel *label_divider_34;
    QPushButton *pushButton_step_4;
    QSpacerItem *horizontalSpacer_12;
    QWidget *steps_bottom;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_16;
    QWidget *header;
    QGridLayout *gridLayout_11;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_close;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_icon;
    QSpacerItem *horizontalSpacer_14;
    QStackedWidget *body;
    QWidget *setup_page;
    QGridLayout *gridLayout_2;
    QWidget *controls;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer_8;
    QWidget *instructions;
    QGridLayout *gridLayout_12;
    QSpacerItem *verticalSpacer_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QWidget *cameras;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_camera_left;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_camera_right;
    QWidget *login_page;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLabel *label_login_image;
    QLineEdit *lineEdit_user;
    QPushButton *pushButton_1;
    QLineEdit *lineEdit_password;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *surgery_page;
    QGridLayout *gridLayout_9;
    QScrollArea *scrollArea_cases;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_7;
    QWidget *widget_2;
    QGridLayout *gridLayout_6;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_case_11;
    QPushButton *pushButton_case_12;
    QPushButton *pushButton_case_13;
    QLabel *label_case_title;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_cases_view;
    QGridLayout *gridLayout_8;
    QLabel *label;
    QLabel *label_4;
    QTabWidget *tabWidget_cases_view;
    QWidget *tab_1;
    QWidget *tab_2;
    QWidget *tab_3;
    QPushButton *pushButton_2;
    QWidget *choice_page;
    QGridLayout *gridLayout_10;
    QLabel *label_5;
    QPushButton *pushButton_tibia;
    QPushButton *pushButton_femur;
    QPushButton *pushButton_9;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_instructions;

    void setupUi(QWidget *NavarQTClass)
    {
        if (NavarQTClass->objectName().isEmpty())
            NavarQTClass->setObjectName(QStringLiteral("NavarQTClass"));
        NavarQTClass->resize(2665, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NavarQTClass->sizePolicy().hasHeightForWidth());
        NavarQTClass->setSizePolicy(sizePolicy);
        NavarQTClass->setMinimumSize(QSize(1920, 1080));
        NavarQTClass->setMaximumSize(QSize(2665, 1080));
        NavarQTClass->setStyleSheet(QLatin1String("@font-face{\n"
"font-family: HelveticaLC;\n"
"src: url(\":/fonts/HelveticaLC\");\n"
"}\n"
"\n"
"QWidget{\n"
"background-color: white;\n"
"}\n"
"\n"
"QPushButton{\n"
"Text-align:left;\n"
"white-space: normal;\n"
"font-family: HelveticaLC;\n"
"font-style: normal;\n"
"color: #2BAAE1;\n"
"font-size: 12px;\n"
"text-shadow: 1px;\n"
"}\n"
"\n"
"QLabel{\n"
"font-family: HelveticaLCl;\n"
"font-style: normal;\n"
"color: #2BAAE1;\n"
"font-size: 18px;\n"
"text-shadow: 1px;\n"
"}"));
        gridLayout = new QGridLayout(NavarQTClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 3, 0, 1, 1);

        steps = new QWidget(NavarQTClass);
        steps->setObjectName(QStringLiteral("steps"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(steps->sizePolicy().hasHeightForWidth());
        steps->setSizePolicy(sizePolicy1);
        steps->setMinimumSize(QSize(1920, 186));
        steps->setMaximumSize(QSize(1920, 186));
        verticalLayout = new QVBoxLayout(steps);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        steps_top = new QWidget(steps);
        steps_top->setObjectName(QStringLiteral("steps_top"));
        sizePolicy1.setHeightForWidth(steps_top->sizePolicy().hasHeightForWidth());
        steps_top->setSizePolicy(sizePolicy1);
        steps_top->setMinimumSize(QSize(1920, 0));
        steps_top->setMaximumSize(QSize(1920, 16777215));
        horizontalLayout_3 = new QHBoxLayout(steps_top);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_11 = new QSpacerItem(325, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        pushButton_step_1 = new QPushButton(steps_top);
        pushButton_step_1->setObjectName(QStringLiteral("pushButton_step_1"));
        sizePolicy1.setHeightForWidth(pushButton_step_1->sizePolicy().hasHeightForWidth());
        pushButton_step_1->setSizePolicy(sizePolicy1);
        pushButton_step_1->setMaximumSize(QSize(114, 124));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/steps1"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_step_1->setIcon(icon);
        pushButton_step_1->setIconSize(QSize(114, 124));
        pushButton_step_1->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_step_1);

        label_divider_12 = new QLabel(steps_top);
        label_divider_12->setObjectName(QStringLiteral("label_divider_12"));
        sizePolicy1.setHeightForWidth(label_divider_12->sizePolicy().hasHeightForWidth());
        label_divider_12->setSizePolicy(sizePolicy1);
        label_divider_12->setMinimumSize(QSize(271, 0));
        label_divider_12->setMaximumSize(QSize(272, 16777215));
        label_divider_12->setPixmap(QPixmap(QString::fromUtf8(":/icons/divider")));
        label_divider_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_divider_12);

        pushButton_step_2 = new QPushButton(steps_top);
        pushButton_step_2->setObjectName(QStringLiteral("pushButton_step_2"));
        sizePolicy1.setHeightForWidth(pushButton_step_2->sizePolicy().hasHeightForWidth());
        pushButton_step_2->setSizePolicy(sizePolicy1);
        pushButton_step_2->setMaximumSize(QSize(114, 124));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/steps2"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_step_2->setIcon(icon1);
        pushButton_step_2->setIconSize(QSize(114, 124));
        pushButton_step_2->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_step_2);

        label_divider_23 = new QLabel(steps_top);
        label_divider_23->setObjectName(QStringLiteral("label_divider_23"));
        sizePolicy1.setHeightForWidth(label_divider_23->sizePolicy().hasHeightForWidth());
        label_divider_23->setSizePolicy(sizePolicy1);
        label_divider_23->setMinimumSize(QSize(271, 0));
        label_divider_23->setMaximumSize(QSize(272, 16777215));
        label_divider_23->setPixmap(QPixmap(QString::fromUtf8(":/icons/divider")));
        label_divider_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_divider_23);

        pushButton_step_3 = new QPushButton(steps_top);
        pushButton_step_3->setObjectName(QStringLiteral("pushButton_step_3"));
        sizePolicy1.setHeightForWidth(pushButton_step_3->sizePolicy().hasHeightForWidth());
        pushButton_step_3->setSizePolicy(sizePolicy1);
        pushButton_step_3->setMaximumSize(QSize(114, 124));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/steps3"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_step_3->setIcon(icon2);
        pushButton_step_3->setIconSize(QSize(114, 124));
        pushButton_step_3->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_step_3);

        label_divider_34 = new QLabel(steps_top);
        label_divider_34->setObjectName(QStringLiteral("label_divider_34"));
        sizePolicy1.setHeightForWidth(label_divider_34->sizePolicy().hasHeightForWidth());
        label_divider_34->setSizePolicy(sizePolicy1);
        label_divider_34->setMinimumSize(QSize(271, 0));
        label_divider_34->setMaximumSize(QSize(272, 16777215));
        label_divider_34->setPixmap(QPixmap(QString::fromUtf8(":/icons/divider")));
        label_divider_34->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_divider_34);

        pushButton_step_4 = new QPushButton(steps_top);
        pushButton_step_4->setObjectName(QStringLiteral("pushButton_step_4"));
        sizePolicy1.setHeightForWidth(pushButton_step_4->sizePolicy().hasHeightForWidth());
        pushButton_step_4->setSizePolicy(sizePolicy1);
        pushButton_step_4->setMaximumSize(QSize(114, 124));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/steps4"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_step_4->setIcon(icon3);
        pushButton_step_4->setIconSize(QSize(114, 124));
        pushButton_step_4->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_step_4);

        horizontalSpacer_12 = new QSpacerItem(325, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);


        verticalLayout->addWidget(steps_top);

        steps_bottom = new QWidget(steps);
        steps_bottom->setObjectName(QStringLiteral("steps_bottom"));
        sizePolicy1.setHeightForWidth(steps_bottom->sizePolicy().hasHeightForWidth());
        steps_bottom->setSizePolicy(sizePolicy1);
        steps_bottom->setMinimumSize(QSize(1920, 25));
        steps_bottom->setMaximumSize(QSize(1920, 25));
        horizontalLayout_4 = new QHBoxLayout(steps_bottom);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_15 = new QSpacerItem(238, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_15);

        label_7 = new QLabel(steps_bottom);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(291, 20));
        label_7->setMaximumSize(QSize(291, 20));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_7);

        horizontalSpacer_17 = new QSpacerItem(92, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_17);

        label_8 = new QLabel(steps_bottom);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(291, 20));
        label_8->setMaximumSize(QSize(291, 20));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_8);

        horizontalSpacer_18 = new QSpacerItem(92, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_18);

        label_9 = new QLabel(steps_bottom);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(291, 20));
        label_9->setMaximumSize(QSize(291, 20));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_9);

        horizontalSpacer_19 = new QSpacerItem(92, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_19);

        label_10 = new QLabel(steps_bottom);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(291, 20));
        label_10->setMaximumSize(QSize(291, 20));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_10);

        horizontalSpacer_16 = new QSpacerItem(238, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_16);


        verticalLayout->addWidget(steps_bottom);


        gridLayout->addWidget(steps, 2, 0, 1, 1);

        header = new QWidget(NavarQTClass);
        header->setObjectName(QStringLiteral("header"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(header->sizePolicy().hasHeightForWidth());
        header->setSizePolicy(sizePolicy2);
        header->setMinimumSize(QSize(0, 80));
        header->setMaximumSize(QSize(1920, 80));
        header->setSizeIncrement(QSize(0, 80));
        header->setStyleSheet(QStringLiteral("background-color: #2BAAE1;"));
        gridLayout_11 = new QGridLayout(header);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        pushButton_close = new QPushButton(header);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        sizePolicy1.setHeightForWidth(pushButton_close->sizePolicy().hasHeightForWidth());
        pushButton_close->setSizePolicy(sizePolicy1);
        pushButton_close->setMinimumSize(QSize(55, 50));
        pushButton_close->setMaximumSize(QSize(55, 50));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/close"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_close->setIcon(icon4);
        pushButton_close->setIconSize(QSize(50, 50));
        pushButton_close->setFlat(true);

        gridLayout_11->addWidget(pushButton_close, 0, 3, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(46, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_13, 0, 4, 1, 1);

        label_icon = new QLabel(header);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        sizePolicy1.setHeightForWidth(label_icon->sizePolicy().hasHeightForWidth());
        label_icon->setSizePolicy(sizePolicy1);
        label_icon->setMinimumSize(QSize(147, 55));
        label_icon->setMaximumSize(QSize(147, 55));
        label_icon->setPixmap(QPixmap(QString::fromUtf8(":/icons/logo")));

        gridLayout_11->addWidget(label_icon, 0, 1, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_14, 0, 0, 1, 1);


        gridLayout->addWidget(header, 0, 0, 1, 1);

        body = new QStackedWidget(NavarQTClass);
        body->setObjectName(QStringLiteral("body"));
        body->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(body->sizePolicy().hasHeightForWidth());
        body->setSizePolicy(sizePolicy3);
        setup_page = new QWidget();
        setup_page->setObjectName(QStringLiteral("setup_page"));
        gridLayout_2 = new QGridLayout(setup_page);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        controls = new QWidget(setup_page);
        controls->setObjectName(QStringLiteral("controls"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(controls->sizePolicy().hasHeightForWidth());
        controls->setSizePolicy(sizePolicy4);
        controls->setMinimumSize(QSize(224, 0));
        controls->setMaximumSize(QSize(224, 16777215));
        verticalLayout_2 = new QVBoxLayout(controls);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(controls);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        label_6 = new QLabel(controls);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy5);
        label_6->setStyleSheet(QStringLiteral("font-size: 12px"));
        label_6->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(label_6);

        pushButton_3 = new QPushButton(controls);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(226, 45));
        pushButton_3->setMaximumSize(QSize(226, 45));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/start"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon5);
        pushButton_3->setIconSize(QSize(221, 45));
        pushButton_3->setFlat(true);

        verticalLayout_2->addWidget(pushButton_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_9 = new QSpacerItem(44, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        pushButton_10 = new QPushButton(controls);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);
        pushButton_10->setMinimumSize(QSize(135, 40));
        pushButton_10->setMaximumSize(QSize(135, 40));
        QFont font;
        font.setFamily(QStringLiteral("HelveticaLC"));
        font.setItalic(false);
        pushButton_10->setFont(font);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/skip"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon6);
        pushButton_10->setIconSize(QSize(129, 40));
        pushButton_10->setFlat(true);

        horizontalLayout->addWidget(pushButton_10);

        horizontalSpacer_8 = new QSpacerItem(44, 44, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout_2->addWidget(controls, 0, 5, 1, 1);

        instructions = new QWidget(setup_page);
        instructions->setObjectName(QStringLiteral("instructions"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(instructions->sizePolicy().hasHeightForWidth());
        instructions->setSizePolicy(sizePolicy6);
        instructions->setMinimumSize(QSize(200, 0));
        instructions->setMaximumSize(QSize(489, 16777215));
        gridLayout_12 = new QGridLayout(instructions);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 102, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_12->addItem(verticalSpacer_6, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(instructions);
        buttonGroup_instructions = new QButtonGroup(NavarQTClass);
        buttonGroup_instructions->setObjectName(QStringLiteral("buttonGroup_instructions"));
        buttonGroup_instructions->addButton(pushButton_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy7);
        pushButton_4->setStyleSheet(QStringLiteral(""));
        pushButton_4->setFlat(true);

        gridLayout_12->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(instructions);
        buttonGroup_instructions->addButton(pushButton_6);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy7.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy7);
        pushButton_6->setStyleSheet(QStringLiteral(""));
        pushButton_6->setFlat(true);

        gridLayout_12->addWidget(pushButton_6, 3, 1, 1, 1);

        pushButton_7 = new QPushButton(instructions);
        buttonGroup_instructions->addButton(pushButton_7);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy7.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy7);
        pushButton_7->setStyleSheet(QStringLiteral(""));
        pushButton_7->setFlat(true);

        gridLayout_12->addWidget(pushButton_7, 4, 1, 1, 1);

        pushButton_8 = new QPushButton(instructions);
        buttonGroup_instructions->addButton(pushButton_8);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy7.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy7);
        pushButton_8->setStyleSheet(QStringLiteral(""));
        pushButton_8->setFlat(true);

        gridLayout_12->addWidget(pushButton_8, 5, 1, 1, 1);

        pushButton_5 = new QPushButton(instructions);
        buttonGroup_instructions->addButton(pushButton_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy7.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy7);
        pushButton_5->setStyleSheet(QStringLiteral(""));
        pushButton_5->setFlat(true);

        gridLayout_12->addWidget(pushButton_5, 2, 1, 1, 1);

        label_11 = new QLabel(instructions);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(25, 27));
        label_11->setMaximumSize(QSize(25, 27));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/icons/bullet")));

        gridLayout_12->addWidget(label_11, 1, 0, 1, 1);

        label_12 = new QLabel(instructions);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMinimumSize(QSize(25, 27));
        label_12->setMaximumSize(QSize(25, 27));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/icons/bullet")));

        gridLayout_12->addWidget(label_12, 2, 0, 1, 1);

        label_13 = new QLabel(instructions);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_13->setMinimumSize(QSize(25, 27));
        label_13->setMaximumSize(QSize(25, 27));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/icons/bullet")));

        gridLayout_12->addWidget(label_13, 3, 0, 1, 1);

        label_14 = new QLabel(instructions);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(25, 27));
        label_14->setMaximumSize(QSize(25, 27));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/icons/bullet")));

        gridLayout_12->addWidget(label_14, 4, 0, 1, 1);

        label_15 = new QLabel(instructions);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMinimumSize(QSize(25, 27));
        label_15->setMaximumSize(QSize(25, 27));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/icons/bullet")));

        gridLayout_12->addWidget(label_15, 5, 0, 1, 1);


        gridLayout_2->addWidget(instructions, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(141, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 6, 1, 1);

        cameras = new QWidget(setup_page);
        cameras->setObjectName(QStringLiteral("cameras"));
        sizePolicy1.setHeightForWidth(cameras->sizePolicy().hasHeightForWidth());
        cameras->setSizePolicy(sizePolicy1);
        cameras->setMinimumSize(QSize(1165, 656));
        cameras->setMaximumSize(QSize(1566, 656));
        cameras->setStyleSheet(QLatin1String(".QWidget{\n"
"border-color: rgb(43, 170, 225);\n"
"border-style:outset;\n"
"border-width: 5px;\n"
"padding: 6 px;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(cameras);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_camera_left = new QLabel(cameras);
        label_camera_left->setObjectName(QStringLiteral("label_camera_left"));
        sizePolicy1.setHeightForWidth(label_camera_left->sizePolicy().hasHeightForWidth());
        label_camera_left->setSizePolicy(sizePolicy1);
        label_camera_left->setMinimumSize(QSize(750, 600));
        label_camera_left->setMaximumSize(QSize(750, 600));
        label_camera_left->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_camera_left);

        horizontalSpacer_10 = new QSpacerItem(50, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        label_camera_right = new QLabel(cameras);
        label_camera_right->setObjectName(QStringLiteral("label_camera_right"));
        sizePolicy1.setHeightForWidth(label_camera_right->sizePolicy().hasHeightForWidth());
        label_camera_right->setSizePolicy(sizePolicy1);
        label_camera_right->setMinimumSize(QSize(750, 600));
        label_camera_right->setMaximumSize(QSize(750, 600));
        label_camera_right->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_camera_right);


        gridLayout_2->addWidget(cameras, 0, 3, 1, 1);

        body->addWidget(setup_page);
        cameras->raise();
        controls->raise();
        instructions->raise();
        login_page = new QWidget();
        login_page->setObjectName(QStringLiteral("login_page"));
        sizePolicy3.setHeightForWidth(login_page->sizePolicy().hasHeightForWidth());
        login_page->setSizePolicy(sizePolicy3);
        gridLayout_5 = new QGridLayout(login_page);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(login_page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_login_image = new QLabel(groupBox);
        label_login_image->setObjectName(QStringLiteral("label_login_image"));
        label_login_image->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_login_image, 1, 1, 1, 1);

        lineEdit_user = new QLineEdit(groupBox);
        lineEdit_user->setObjectName(QStringLiteral("lineEdit_user"));
        lineEdit_user->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_user, 2, 1, 1, 1);

        pushButton_1 = new QPushButton(groupBox);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_1, 4, 1, 1, 1);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_password->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_password, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 5, 1, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        body->addWidget(login_page);
        surgery_page = new QWidget();
        surgery_page->setObjectName(QStringLiteral("surgery_page"));
        gridLayout_9 = new QGridLayout(surgery_page);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        scrollArea_cases = new QScrollArea(surgery_page);
        scrollArea_cases->setObjectName(QStringLiteral("scrollArea_cases"));
        scrollArea_cases->setWidgetResizable(true);
        scrollArea_cases->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 120, 113));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        gridLayout_6 = new QGridLayout(widget_2);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_6->addWidget(label_2, 0, 0, 1, 2);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_6->addWidget(label_3, 1, 0, 3, 1);

        pushButton_case_11 = new QPushButton(widget_2);
        buttonGroup = new QButtonGroup(NavarQTClass);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(pushButton_case_11);
        pushButton_case_11->setObjectName(QStringLiteral("pushButton_case_11"));

        gridLayout_6->addWidget(pushButton_case_11, 1, 1, 1, 1);

        pushButton_case_12 = new QPushButton(widget_2);
        buttonGroup->addButton(pushButton_case_12);
        pushButton_case_12->setObjectName(QStringLiteral("pushButton_case_12"));

        gridLayout_6->addWidget(pushButton_case_12, 2, 1, 1, 1);

        pushButton_case_13 = new QPushButton(widget_2);
        buttonGroup->addButton(pushButton_case_13);
        pushButton_case_13->setObjectName(QStringLiteral("pushButton_case_13"));

        gridLayout_6->addWidget(pushButton_case_13, 3, 1, 1, 1);


        gridLayout_7->addWidget(widget_2, 2, 0, 1, 1);

        label_case_title = new QLabel(scrollAreaWidgetContents);
        label_case_title->setObjectName(QStringLiteral("label_case_title"));
        sizePolicy2.setHeightForWidth(label_case_title->sizePolicy().hasHeightForWidth());
        label_case_title->setSizePolicy(sizePolicy2);

        gridLayout_7->addWidget(label_case_title, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_3, 3, 0, 1, 1);

        scrollArea_cases->setWidget(scrollAreaWidgetContents);

        gridLayout_9->addWidget(scrollArea_cases, 0, 0, 1, 1);

        widget_cases_view = new QWidget(surgery_page);
        widget_cases_view->setObjectName(QStringLiteral("widget_cases_view"));
        gridLayout_8 = new QGridLayout(widget_cases_view);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_cases_view);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_8->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(widget_cases_view);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_8->addWidget(label_4, 1, 0, 1, 1);

        tabWidget_cases_view = new QTabWidget(widget_cases_view);
        tabWidget_cases_view->setObjectName(QStringLiteral("tabWidget_cases_view"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        tabWidget_cases_view->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_cases_view->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget_cases_view->addTab(tab_3, QString());

        gridLayout_8->addWidget(tabWidget_cases_view, 2, 0, 1, 1);


        gridLayout_9->addWidget(widget_cases_view, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(surgery_page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy6.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy6);
        pushButton_2->setAutoDefault(true);

        gridLayout_9->addWidget(pushButton_2, 0, 2, 1, 1);

        body->addWidget(surgery_page);
        choice_page = new QWidget();
        choice_page->setObjectName(QStringLiteral("choice_page"));
        gridLayout_10 = new QGridLayout(choice_page);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(choice_page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setTextFormat(Qt::RichText);
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignJustify|Qt::AlignTop);

        gridLayout_10->addWidget(label_5, 0, 0, 1, 1);

        pushButton_tibia = new QPushButton(choice_page);
        pushButton_tibia->setObjectName(QStringLiteral("pushButton_tibia"));
        sizePolicy1.setHeightForWidth(pushButton_tibia->sizePolicy().hasHeightForWidth());
        pushButton_tibia->setSizePolicy(sizePolicy1);
        pushButton_tibia->setMinimumSize(QSize(400, 400));
        pushButton_tibia->setMaximumSize(QSize(400, 400));
        pushButton_tibia->setFlat(true);

        gridLayout_10->addWidget(pushButton_tibia, 0, 1, 1, 1);

        pushButton_femur = new QPushButton(choice_page);
        pushButton_femur->setObjectName(QStringLiteral("pushButton_femur"));
        sizePolicy1.setHeightForWidth(pushButton_femur->sizePolicy().hasHeightForWidth());
        pushButton_femur->setSizePolicy(sizePolicy1);
        pushButton_femur->setMinimumSize(QSize(400, 400));
        pushButton_femur->setMaximumSize(QSize(400, 400));
        pushButton_femur->setFlat(true);

        gridLayout_10->addWidget(pushButton_femur, 0, 2, 1, 1);

        pushButton_9 = new QPushButton(choice_page);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setEnabled(true);
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy8);

        gridLayout_10->addWidget(pushButton_9, 0, 3, 1, 1);

        body->addWidget(choice_page);

        gridLayout->addWidget(body, 5, 0, 1, 1);

        QWidget::setTabOrder(lineEdit_user, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, pushButton_1);
        QWidget::setTabOrder(pushButton_1, pushButton_7);
        QWidget::setTabOrder(pushButton_7, pushButton_8);
        QWidget::setTabOrder(pushButton_8, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_4);
        QWidget::setTabOrder(pushButton_4, scrollArea_cases);
        QWidget::setTabOrder(scrollArea_cases, pushButton_case_11);
        QWidget::setTabOrder(pushButton_case_11, pushButton_case_12);
        QWidget::setTabOrder(pushButton_case_12, pushButton_case_13);

        retranslateUi(NavarQTClass);

        body->setCurrentIndex(0);
        tabWidget_cases_view->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(NavarQTClass);
    } // setupUi

    void retranslateUi(QWidget *NavarQTClass)
    {
        NavarQTClass->setWindowTitle(QApplication::translate("NavarQTClass", "NavarQT", Q_NULLPTR));
        pushButton_step_1->setText(QString());
        label_divider_12->setText(QString());
        pushButton_step_2->setText(QString());
        label_divider_23->setText(QString());
        pushButton_step_3->setText(QString());
        label_divider_34->setText(QString());
        pushButton_step_4->setText(QString());
        label_7->setText(QApplication::translate("NavarQTClass", "Estaci\303\263n de Trabajo", Q_NULLPTR));
        label_8->setText(QApplication::translate("NavarQTClass", "Calibraci\303\263n del Sistema", Q_NULLPTR));
        label_9->setText(QApplication::translate("NavarQTClass", "Verificaci\303\263n Instrumental", Q_NULLPTR));
        label_10->setText(QApplication::translate("NavarQTClass", "Cirug\303\255a", Q_NULLPTR));
        pushButton_close->setText(QString());
        label_icon->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("NavarQTClass", "1", Q_NULLPTR)
         << QApplication::translate("NavarQTClass", "2", Q_NULLPTR)
         << QApplication::translate("NavarQTClass", "3", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("NavarQTClass", "<html><head/><body><p><br><span style=\" font-size:9pt;\">Frecuencia de captura (segundos)</span></p></body></html>", Q_NULLPTR));
        pushButton_3->setText(QString());
        pushButton_10->setText(QString());
        pushButton_4->setText(QApplication::translate("NavarQTClass", "Ubique el soporte de las c\303\241maras al extremo contrario de la rodilla a operar.", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("NavarQTClass", "Verifique la altura del soporte de las c\303\241maras con respecto a la altura del cirujano.", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("NavarQTClass", "Despliegue el brazo del soporte con un \303\241ngulo de m\303\241s o menos 45\302\260.", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("NavarQTClass", "Ubique las c\303\241maras de tal forma que en la visualizaci\303\263n se aprecie claramente en el recuadro la zona de trabajo (la zona que se va a operar).", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("NavarQTClass", "Encienda las c\303\241maras.", Q_NULLPTR));
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_camera_left->setText(QApplication::translate("NavarQTClass", "Camera 1", Q_NULLPTR));
        label_camera_right->setText(QApplication::translate("NavarQTClass", "camera 2", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("NavarQTClass", "Autenticaci\303\263n de usuarios", Q_NULLPTR));
        label_login_image->setText(QApplication::translate("NavarQTClass", "TextLabel", Q_NULLPTR));
        lineEdit_user->setPlaceholderText(QApplication::translate("NavarQTClass", "Usuario", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("NavarQTClass", "Ingresar", Q_NULLPTR));
        lineEdit_password->setPlaceholderText(QApplication::translate("NavarQTClass", "Contrase\303\261a", Q_NULLPTR));
        label_2->setText(QApplication::translate("NavarQTClass", "Caso 1", Q_NULLPTR));
        label_3->setText(QApplication::translate("NavarQTClass", "Datos", Q_NULLPTR));
        pushButton_case_11->setText(QApplication::translate("NavarQTClass", "PushButton", Q_NULLPTR));
        pushButton_case_12->setText(QApplication::translate("NavarQTClass", "PushButton", Q_NULLPTR));
        pushButton_case_13->setText(QApplication::translate("NavarQTClass", "PushButton", Q_NULLPTR));
        label_case_title->setText(QApplication::translate("NavarQTClass", "Casos cl\303\255nicos", Q_NULLPTR));
        label->setText(QApplication::translate("NavarQTClass", "Caso: ", Q_NULLPTR));
        label_4->setText(QApplication::translate("NavarQTClass", "Datos", Q_NULLPTR));
        tabWidget_cases_view->setTabText(tabWidget_cases_view->indexOf(tab_1), QApplication::translate("NavarQTClass", "Radiograf\303\255as", Q_NULLPTR));
        tabWidget_cases_view->setTabText(tabWidget_cases_view->indexOf(tab_2), QApplication::translate("NavarQTClass", "Tomograf\303\255as", Q_NULLPTR));
        tabWidget_cases_view->setTabText(tabWidget_cases_view->indexOf(tab_3), QApplication::translate("NavarQTClass", "Modelo 3D", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("NavarQTClass", "Iniciar registro", Q_NULLPTR));
        label_5->setText(QApplication::translate("NavarQTClass", "<html><head/><body><p><span style=\" font-weight:600;\">Registro</span></p><p>Seleccione tibia o f\303\251mur para iniciar el proceso de registro.</p></body></html>", Q_NULLPTR));
        pushButton_tibia->setText(QApplication::translate("NavarQTClass", "Tibia", Q_NULLPTR));
        pushButton_femur->setText(QApplication::translate("NavarQTClass", "Femur", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("NavarQTClass", "Iniciar femur", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NavarQTClass: public Ui_NavarQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVARQT_H
