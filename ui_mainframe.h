/********************************************************************************
** Form generated from reading UI file 'mainframe.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainFrame
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *buttonOpen;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *buttonDeleteContents;
    QSpacerItem *horizontalSpacer;
    QToolButton *buttonShowList;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QPushButton *pushRGB2Gray;
    QPushButton *pushGaussianNoise;
    QLabel *label_4;
    QLineEdit *editSigmaNoise;
    QPushButton *pushSaltPepper;
    QLabel *label_5;
    QLineEdit *editTau;
    QPushButton *pushHistogramEQ;
    QPushButton *pushEdgeFDG;
    QLabel *label_6;
    QLineEdit *editSigmaFDG;
    QWidget *tab_4;
    QPushButton *pushSephiaTone;
    QLabel *label;
    QSpinBox *spinHue;
    QLabel *label_2;
    QDoubleSpinBox *spinSat;
    QPushButton *pushHarrisCorner;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *editSigmaCorner;
    QLineEdit *editThreshCorner;
    QLineEdit *editSizeBlock;
    QWidget *tab_5;
    QPushButton *pushHistogram;
    QPushButton *pushOstu;
    QLabel *label_3;
    QSpinBox *spinOstu;
    QPushButton *pushThresholding;
    QPushButton *pushDilation;
    QPushButton *pushBoundary;
    QWidget *tab_2;
    QPushButton *pushCircleLocalization;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QSpinBox *editMinR;
    QSpinBox *editMaxR;
    QSpinBox *editResolution;
    QSpinBox *editThreshVote;
    QPushButton *pushCanny;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QDoubleSpinBox *editSigmaCanny;
    QDoubleSpinBox *editLow;
    QDoubleSpinBox *editHigh;
    QListWidget *listWidget;

    void setupUi(QDialog *MainFrame)
    {
        if (MainFrame->objectName().isEmpty())
            MainFrame->setObjectName("MainFrame");
        MainFrame->resize(622, 461);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainFrame->sizePolicy().hasHeightForWidth());
        MainFrame->setSizePolicy(sizePolicy);
        MainFrame->setMinimumSize(QSize(0, 461));
        MainFrame->setModal(false);
        verticalLayout = new QVBoxLayout(MainFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(MainFrame);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 41));
        frame->setMaximumSize(QSize(16777215, 41));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        buttonOpen = new QToolButton(frame);
        buttonOpen->setObjectName("buttonOpen");
        buttonOpen->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonOpen->sizePolicy().hasHeightForWidth());
        buttonOpen->setSizePolicy(sizePolicy2);
        buttonOpen->setMinimumSize(QSize(41, 41));
        buttonOpen->setMaximumSize(QSize(41, 41));
        buttonOpen->setLayoutDirection(Qt::LeftToRight);
        buttonOpen->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOpen->setIcon(icon);
        buttonOpen->setIconSize(QSize(41, 41));
        buttonOpen->setCheckable(false);
        buttonOpen->setAutoRepeat(false);
        buttonOpen->setAutoExclusive(false);
        buttonOpen->setPopupMode(QToolButton::DelayedPopup);
        buttonOpen->setToolButtonStyle(Qt::ToolButtonIconOnly);
        buttonOpen->setAutoRaise(false);

        horizontalLayout_3->addWidget(buttonOpen);

        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName("toolButton_2");
        sizePolicy2.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy2);
        toolButton_2->setMinimumSize(QSize(41, 41));
        toolButton_2->setMaximumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName("toolButton_3");
        sizePolicy2.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy2);
        toolButton_3->setMinimumSize(QSize(41, 41));
        toolButton_3->setMaximumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(toolButton_3);

        buttonDeleteContents = new QToolButton(frame);
        buttonDeleteContents->setObjectName("buttonDeleteContents");
        sizePolicy2.setHeightForWidth(buttonDeleteContents->sizePolicy().hasHeightForWidth());
        buttonDeleteContents->setSizePolicy(sizePolicy2);
        buttonDeleteContents->setMinimumSize(QSize(41, 41));
        buttonDeleteContents->setMaximumSize(QSize(41, 41));
        buttonDeleteContents->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/1-21.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDeleteContents->setIcon(icon1);
        buttonDeleteContents->setIconSize(QSize(41, 41));

        horizontalLayout_3->addWidget(buttonDeleteContents);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonShowList = new QToolButton(frame);
        buttonShowList->setObjectName("buttonShowList");
        sizePolicy2.setHeightForWidth(buttonShowList->sizePolicy().hasHeightForWidth());
        buttonShowList->setSizePolicy(sizePolicy2);
        buttonShowList->setMinimumSize(QSize(41, 41));
        buttonShowList->setMaximumSize(QSize(41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/2-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonShowList->setIcon(icon2);
        buttonShowList->setIconSize(QSize(82, 41));

        horizontalLayout_3->addWidget(buttonShowList);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(2, -1, -1, -1);
        tabWidget = new QTabWidget(MainFrame);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setMinimumSize(QSize(299, 394));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(255, 85, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush1);
        tabWidget->setPalette(palette);
        tabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(31, 31));
        tabWidget->setElideMode(Qt::ElideMiddle);
        tab_1 = new QWidget();
        tab_1->setObjectName("tab_1");
        pushRGB2Gray = new QPushButton(tab_1);
        pushRGB2Gray->setObjectName("pushRGB2Gray");
        pushRGB2Gray->setGeometry(QRect(0, 10, 75, 24));
        pushGaussianNoise = new QPushButton(tab_1);
        pushGaussianNoise->setObjectName("pushGaussianNoise");
        pushGaussianNoise->setGeometry(QRect(60, 80, 151, 31));
        label_4 = new QLabel(tab_1);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 120, 48, 16));
        editSigmaNoise = new QLineEdit(tab_1);
        editSigmaNoise->setObjectName("editSigmaNoise");
        editSigmaNoise->setGeometry(QRect(100, 120, 113, 22));
        pushSaltPepper = new QPushButton(tab_1);
        pushSaltPepper->setObjectName("pushSaltPepper");
        pushSaltPepper->setGeometry(QRect(60, 150, 151, 31));
        label_5 = new QLabel(tab_1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 190, 48, 16));
        editTau = new QLineEdit(tab_1);
        editTau->setObjectName("editTau");
        editTau->setGeometry(QRect(100, 190, 113, 22));
        pushHistogramEQ = new QPushButton(tab_1);
        pushHistogramEQ->setObjectName("pushHistogramEQ");
        pushHistogramEQ->setGeometry(QRect(60, 220, 151, 41));
        pushEdgeFDG = new QPushButton(tab_1);
        pushEdgeFDG->setObjectName("pushEdgeFDG");
        pushEdgeFDG->setGeometry(QRect(60, 270, 151, 41));
        label_6 = new QLabel(tab_1);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 320, 41, 16));
        editSigmaFDG = new QLineEdit(tab_1);
        editSigmaFDG->setObjectName("editSigmaFDG");
        editSigmaFDG->setGeometry(QRect(100, 320, 113, 22));
        tabWidget->addTab(tab_1, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        pushSephiaTone = new QPushButton(tab_4);
        pushSephiaTone->setObjectName("pushSephiaTone");
        pushSephiaTone->setGeometry(QRect(40, 40, 111, 51));
        label = new QLabel(tab_4);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 110, 51, 21));
        spinHue = new QSpinBox(tab_4);
        spinHue->setObjectName("spinHue");
        spinHue->setGeometry(QRect(80, 110, 42, 22));
        spinHue->setMaximum(360);
        spinHue->setSingleStep(10);
        spinHue->setValue(30);
        label_2 = new QLabel(tab_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 140, 51, 21));
        spinSat = new QDoubleSpinBox(tab_4);
        spinSat->setObjectName("spinSat");
        spinSat->setGeometry(QRect(80, 140, 62, 22));
        spinSat->setMaximum(1.000000000000000);
        spinSat->setSingleStep(0.100000000000000);
        spinSat->setValue(0.300000000000000);
        pushHarrisCorner = new QPushButton(tab_4);
        pushHarrisCorner->setObjectName("pushHarrisCorner");
        pushHarrisCorner->setGeometry(QRect(50, 210, 121, 51));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 270, 48, 16));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(110, 270, 48, 16));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(160, 270, 48, 16));
        editSigmaCorner = new QLineEdit(tab_4);
        editSigmaCorner->setObjectName("editSigmaCorner");
        editSigmaCorner->setGeometry(QRect(50, 290, 41, 21));
        editThreshCorner = new QLineEdit(tab_4);
        editThreshCorner->setObjectName("editThreshCorner");
        editThreshCorner->setGeometry(QRect(100, 290, 41, 21));
        editSizeBlock = new QLineEdit(tab_4);
        editSizeBlock->setObjectName("editSizeBlock");
        editSizeBlock->setGeometry(QRect(150, 290, 41, 21));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        pushHistogram = new QPushButton(tab_5);
        pushHistogram->setObjectName("pushHistogram");
        pushHistogram->setGeometry(QRect(80, 60, 81, 41));
        pushOstu = new QPushButton(tab_5);
        pushOstu->setObjectName("pushOstu");
        pushOstu->setGeometry(QRect(80, 160, 141, 31));
        label_3 = new QLabel(tab_5);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 200, 51, 16));
        spinOstu = new QSpinBox(tab_5);
        spinOstu->setObjectName("spinOstu");
        spinOstu->setGeometry(QRect(140, 200, 42, 22));
        spinOstu->setMaximum(254);
        spinOstu->setValue(100);
        pushThresholding = new QPushButton(tab_5);
        pushThresholding->setObjectName("pushThresholding");
        pushThresholding->setGeometry(QRect(190, 200, 31, 21));
        pushDilation = new QPushButton(tab_5);
        pushDilation->setObjectName("pushDilation");
        pushDilation->setGeometry(QRect(90, 250, 111, 31));
        pushBoundary = new QPushButton(tab_5);
        pushBoundary->setObjectName("pushBoundary");
        pushBoundary->setGeometry(QRect(90, 290, 111, 31));
        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        pushCircleLocalization = new QPushButton(tab_2);
        pushCircleLocalization->setObjectName("pushCircleLocalization");
        pushCircleLocalization->setGeometry(QRect(30, 10, 151, 51));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 70, 48, 16));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 100, 48, 16));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 130, 48, 16));
        editMinR = new QSpinBox(tab_2);
        editMinR->setObjectName("editMinR");
        editMinR->setGeometry(QRect(90, 70, 42, 22));
        editMinR->setValue(50);
        editMaxR = new QSpinBox(tab_2);
        editMaxR->setObjectName("editMaxR");
        editMaxR->setGeometry(QRect(140, 70, 42, 22));
        editMaxR->setValue(70);
        editResolution = new QSpinBox(tab_2);
        editResolution->setObjectName("editResolution");
        editResolution->setGeometry(QRect(90, 100, 42, 22));
        editResolution->setValue(1);
        editThreshVote = new QSpinBox(tab_2);
        editThreshVote->setObjectName("editThreshVote");
        editThreshVote->setGeometry(QRect(90, 130, 42, 22));
        pushCanny = new QPushButton(tab_2);
        pushCanny->setObjectName("pushCanny");
        pushCanny->setGeometry(QRect(40, 190, 131, 41));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(50, 240, 48, 16));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(110, 240, 48, 16));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(160, 240, 48, 16));
        editSigmaCanny = new QDoubleSpinBox(tab_2);
        editSigmaCanny->setObjectName("editSigmaCanny");
        editSigmaCanny->setGeometry(QRect(40, 260, 62, 22));
        editSigmaCanny->setValue(1.000000000000000);
        editLow = new QDoubleSpinBox(tab_2);
        editLow->setObjectName("editLow");
        editLow->setGeometry(QRect(100, 260, 62, 22));
        editLow->setValue(10.000000000000000);
        editHigh = new QDoubleSpinBox(tab_2);
        editHigh->setObjectName("editHigh");
        editHigh->setGeometry(QRect(160, 260, 62, 22));
        editHigh->setValue(30.000000000000000);
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        listWidget = new QListWidget(MainFrame);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy4);
        listWidget->setMinimumSize(QSize(0, 394));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush3(QColor(0, 0, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        QBrush brush6(QColor(120, 120, 120, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        QBrush brush7(QColor(240, 240, 240, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        listWidget->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(10);
        listWidget->setFont(font);

        horizontalLayout->addWidget(listWidget);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MainFrame);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainFrame);
    } // setupUi

    void retranslateUi(QDialog *MainFrame)
    {
        MainFrame->setWindowTitle(QCoreApplication::translate("MainFrame", "Practice CV", nullptr));
#if QT_CONFIG(tooltip)
        buttonOpen->setToolTip(QCoreApplication::translate("MainFrame", "open an image file", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonOpen->setText(QString());
        toolButton_2->setText(QCoreApplication::translate("MainFrame", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainFrame", "...", nullptr));
#if QT_CONFIG(tooltip)
        buttonDeleteContents->setToolTip(QCoreApplication::translate("MainFrame", "close all forms", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonDeleteContents->setText(QString());
#if QT_CONFIG(tooltip)
        buttonShowList->setToolTip(QCoreApplication::translate("MainFrame", "show the list view", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonShowList->setText(QString());
        pushRGB2Gray->setText(QCoreApplication::translate("MainFrame", "RGB->Gray", nullptr));
        pushGaussianNoise->setText(QCoreApplication::translate("MainFrame", "Gaussian Noise", nullptr));
        label_4->setText(QCoreApplication::translate("MainFrame", "sigma", nullptr));
        editSigmaNoise->setText(QCoreApplication::translate("MainFrame", "0.7", nullptr));
        pushSaltPepper->setText(QCoreApplication::translate("MainFrame", "Salt & Pepper Noise", nullptr));
        label_5->setText(QCoreApplication::translate("MainFrame", "ratio", nullptr));
        editTau->setText(QCoreApplication::translate("MainFrame", "0.01", nullptr));
        pushHistogramEQ->setText(QCoreApplication::translate("MainFrame", "Histogram Equalization", nullptr));
        pushEdgeFDG->setText(QCoreApplication::translate("MainFrame", "Edge with FDG", nullptr));
        label_6->setText(QCoreApplication::translate("MainFrame", "sigma", nullptr));
        editSigmaFDG->setText(QCoreApplication::translate("MainFrame", "1.0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("MainFrame", "1 ", nullptr));
        pushSephiaTone->setText(QCoreApplication::translate("MainFrame", "Sephia Tone", nullptr));
        label->setText(QCoreApplication::translate("MainFrame", "Hue", nullptr));
        label_2->setText(QCoreApplication::translate("MainFrame", "Sat", nullptr));
        pushHarrisCorner->setText(QCoreApplication::translate("MainFrame", "Harris Corner", nullptr));
        label_7->setText(QCoreApplication::translate("MainFrame", "sigma", nullptr));
        label_8->setText(QCoreApplication::translate("MainFrame", "thresh", nullptr));
        label_9->setText(QCoreApplication::translate("MainFrame", "block", nullptr));
        editSigmaCorner->setText(QCoreApplication::translate("MainFrame", "0.7", nullptr));
        editThreshCorner->setText(QCoreApplication::translate("MainFrame", "100000", nullptr));
        editSizeBlock->setText(QCoreApplication::translate("MainFrame", "7", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainFrame", "2", nullptr));
        pushHistogram->setText(QCoreApplication::translate("MainFrame", "Histogram", nullptr));
        pushOstu->setText(QCoreApplication::translate("MainFrame", "Ostu Thresholding", nullptr));
        label_3->setText(QCoreApplication::translate("MainFrame", "Threshold", nullptr));
        pushThresholding->setText(QCoreApplication::translate("MainFrame", ">>", nullptr));
        pushDilation->setText(QCoreApplication::translate("MainFrame", "Dilation", nullptr));
        pushBoundary->setText(QCoreApplication::translate("MainFrame", "Boundary", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainFrame", "3", nullptr));
        pushCircleLocalization->setText(QCoreApplication::translate("MainFrame", "Circle Localization", nullptr));
        label_10->setText(QCoreApplication::translate("MainFrame", "Radius", nullptr));
        label_11->setText(QCoreApplication::translate("MainFrame", "Resolution", nullptr));
        label_12->setText(QCoreApplication::translate("MainFrame", "Threshold", nullptr));
        pushCanny->setText(QCoreApplication::translate("MainFrame", "Canny Edge Detection", nullptr));
        label_13->setText(QCoreApplication::translate("MainFrame", "sigma", nullptr));
        label_14->setText(QCoreApplication::translate("MainFrame", "low", nullptr));
        label_15->setText(QCoreApplication::translate("MainFrame", "high", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainFrame", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainFrame: public Ui_MainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
