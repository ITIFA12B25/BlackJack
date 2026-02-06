/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *pages;
    QWidget *pageCreateRoom;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *CreateRoomBox;
    QLabel *balanceEdit;
    QLabel *label_2;
    QSpinBox *spinPlayers;
    QPushButton *btnCreateRoom;
    QPushButton *btnBackFromCreate;
    QLineEdit *editBalance;
    QWidget *pageGameSimple;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QPushButton *btnSwitchToTable;
    QPushButton *btnHit;
    QPushButton *btnLeaveGame1;
    QGroupBox *lblDealerCardsSimple_2;
    QLabel *lblDealerCardsSimple;
    QLabel *lblDealerTotalSimple;
    QGroupBox *lblDealerCardsSimple_3;
    QLabel *lblPlayerCardsSimple;
    QLabel *lblPlayerTotalSimple;
    QPushButton *btnStand;
    QPushButton *btnSplit;
    QLabel *lblGameIdSimple;
    QWidget *pageGameTable;
    QGridLayout *gridLayout_4;
    QPushButton *btnSplit2;
    QPushButton *btnHit2;
    QPushButton *btnStand2;
    QGroupBox *grpFinance;
    QLabel *lblBalanceValue;
    QLabel *lblTotalBetValue;
    QLabel *lblTotalWinValue;
    QGroupBox *grpSeat1;
    QLabel *lblSeat1Cards;
    QLabel *lblSeat1Total;
    QPushButton *btnLeaveGame2;
    QPushButton *btnSwitchToSimple;
    QGroupBox *grpDealer;
    QGridLayout *gridLayout_2;
    QLabel *lblDealerCardsTable;
    QLabel *lblDealerTotalTable;
    QWidget *pageJoinRoom;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTableWidget *tblRooms;
    QPushButton *btnJoinSelected;
    QPushButton *btnBackFromJoin;
    QPushButton *btnRefreshRooms;
    QWidget *pageLobby;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *btnGoCreate;
    QPushButton *btnGoJoin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QFont font;
        font.setPointSize(8);
        MainWindow->setFont(font);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        pages = new QStackedWidget(centralwidget);
        pages->setObjectName("pages");
        pageCreateRoom = new QWidget();
        pageCreateRoom->setObjectName("pageCreateRoom");
        verticalLayout_2 = new QVBoxLayout(pageCreateRoom);
        verticalLayout_2->setObjectName("verticalLayout_2");
        CreateRoomBox = new QGroupBox(pageCreateRoom);
        CreateRoomBox->setObjectName("CreateRoomBox");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font1.setPointSize(24);
        font1.setBold(true);
        CreateRoomBox->setFont(font1);
        CreateRoomBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        CreateRoomBox->setCheckable(false);
        balanceEdit = new QLabel(CreateRoomBox);
        balanceEdit->setObjectName("balanceEdit");
        balanceEdit->setGeometry(QRect(14, 91, 186, 32));
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(balanceEdit->sizePolicy().hasHeightForWidth());
        balanceEdit->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font2.setPointSize(17);
        font2.setBold(true);
        balanceEdit->setFont(font2);
        balanceEdit->setScaledContents(false);
        label_2 = new QLabel(CreateRoomBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(14, 221, 210, 32));
        label_2->setFont(font2);
        spinPlayers = new QSpinBox(CreateRoomBox);
        spinPlayers->setObjectName("spinPlayers");
        spinPlayers->setGeometry(QRect(14, 271, 728, 37));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinPlayers->sizePolicy().hasHeightForWidth());
        spinPlayers->setSizePolicy(sizePolicy1);
        spinPlayers->setFont(font2);
        spinPlayers->setMinimum(1);
        spinPlayers->setMaximum(4);
        btnCreateRoom = new QPushButton(CreateRoomBox);
        btnCreateRoom->setObjectName("btnCreateRoom");
        btnCreateRoom->setGeometry(QRect(14, 379, 728, 37));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font3.setPointSize(18);
        font3.setBold(true);
        btnCreateRoom->setFont(font3);
        btnCreateRoom->setIconSize(QSize(30, 30));
        btnBackFromCreate = new QPushButton(CreateRoomBox);
        btnBackFromCreate->setObjectName("btnBackFromCreate");
        btnBackFromCreate->setGeometry(QRect(14, 434, 728, 37));
        btnBackFromCreate->setFont(font2);
        editBalance = new QLineEdit(CreateRoomBox);
        editBalance->setObjectName("editBalance");
        editBalance->setEnabled(true);
        editBalance->setGeometry(QRect(14, 141, 728, 37));
        editBalance->setFont(font2);

        verticalLayout_2->addWidget(CreateRoomBox);

        pages->addWidget(pageCreateRoom);
        pageGameSimple = new QWidget();
        pageGameSimple->setObjectName("pageGameSimple");
        horizontalLayout = new QHBoxLayout(pageGameSimple);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(pageGameSimple);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(741, 200));
        groupBox->setAutoFillBackground(true);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        gridLayout_3->setHorizontalSpacing(7);
        gridLayout_3->setContentsMargins(11, 7, 11, 18);
        btnSwitchToTable = new QPushButton(groupBox);
        btnSwitchToTable->setObjectName("btnSwitchToTable");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnSwitchToTable->sizePolicy().hasHeightForWidth());
        btnSwitchToTable->setSizePolicy(sizePolicy2);
        btnSwitchToTable->setMinimumSize(QSize(0, 40));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font4.setPointSize(14);
        btnSwitchToTable->setFont(font4);

        gridLayout_3->addWidget(btnSwitchToTable, 5, 0, 1, 1);

        btnHit = new QPushButton(groupBox);
        btnHit->setObjectName("btnHit");
        sizePolicy2.setHeightForWidth(btnHit->sizePolicy().hasHeightForWidth());
        btnHit->setSizePolicy(sizePolicy2);
        btnHit->setMinimumSize(QSize(0, 45));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font5.setPointSize(17);
        btnHit->setFont(font5);

        gridLayout_3->addWidget(btnHit, 4, 0, 1, 1);

        btnLeaveGame1 = new QPushButton(groupBox);
        btnLeaveGame1->setObjectName("btnLeaveGame1");
        sizePolicy2.setHeightForWidth(btnLeaveGame1->sizePolicy().hasHeightForWidth());
        btnLeaveGame1->setSizePolicy(sizePolicy2);
        btnLeaveGame1->setMinimumSize(QSize(0, 40));
        btnLeaveGame1->setFont(font4);

        gridLayout_3->addWidget(btnLeaveGame1, 5, 2, 1, 1);

        lblDealerCardsSimple_2 = new QGroupBox(groupBox);
        lblDealerCardsSimple_2->setObjectName("lblDealerCardsSimple_2");
        lblDealerCardsSimple_2->setMinimumSize(QSize(0, 100));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font6.setPointSize(10);
        font6.setBold(true);
        lblDealerCardsSimple_2->setFont(font6);
        lblDealerCardsSimple = new QLabel(lblDealerCardsSimple_2);
        lblDealerCardsSimple->setObjectName("lblDealerCardsSimple");
        lblDealerCardsSimple->setGeometry(QRect(10, 30, 38, 27));
        lblDealerCardsSimple->setFont(font6);
        lblDealerCardsSimple->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblDealerTotalSimple = new QLabel(lblDealerCardsSimple_2);
        lblDealerTotalSimple->setObjectName("lblDealerTotalSimple");
        lblDealerTotalSimple->setGeometry(QRect(10, 70, 105, 27));
        lblDealerTotalSimple->setFont(font6);

        gridLayout_3->addWidget(lblDealerCardsSimple_2, 1, 0, 1, 1);

        lblDealerCardsSimple_3 = new QGroupBox(groupBox);
        lblDealerCardsSimple_3->setObjectName("lblDealerCardsSimple_3");
        lblDealerCardsSimple_3->setMinimumSize(QSize(0, 100));
        lblDealerCardsSimple_3->setFont(font6);
        lblPlayerCardsSimple = new QLabel(lblDealerCardsSimple_3);
        lblPlayerCardsSimple->setObjectName("lblPlayerCardsSimple");
        lblPlayerCardsSimple->setGeometry(QRect(10, 30, 38, 27));
        lblPlayerCardsSimple->setFont(font6);
        lblPlayerCardsSimple->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblPlayerTotalSimple = new QLabel(lblDealerCardsSimple_3);
        lblPlayerTotalSimple->setObjectName("lblPlayerTotalSimple");
        lblPlayerTotalSimple->setGeometry(QRect(10, 70, 111, 27));
        lblPlayerTotalSimple->setFont(font6);

        gridLayout_3->addWidget(lblDealerCardsSimple_3, 1, 2, 1, 1);

        btnStand = new QPushButton(groupBox);
        btnStand->setObjectName("btnStand");
        sizePolicy2.setHeightForWidth(btnStand->sizePolicy().hasHeightForWidth());
        btnStand->setSizePolicy(sizePolicy2);
        btnStand->setMinimumSize(QSize(0, 45));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font7.setPointSize(18);
        btnStand->setFont(font7);

        gridLayout_3->addWidget(btnStand, 4, 1, 1, 1);

        btnSplit = new QPushButton(groupBox);
        btnSplit->setObjectName("btnSplit");
        sizePolicy2.setHeightForWidth(btnSplit->sizePolicy().hasHeightForWidth());
        btnSplit->setSizePolicy(sizePolicy2);
        btnSplit->setMinimumSize(QSize(0, 45));
        btnSplit->setFont(font5);
        btnSplit->setIconSize(QSize(20, 50));

        gridLayout_3->addWidget(btnSplit, 4, 2, 1, 1);

        lblGameIdSimple = new QLabel(groupBox);
        lblGameIdSimple->setObjectName("lblGameIdSimple");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblGameIdSimple->sizePolicy().hasHeightForWidth());
        lblGameIdSimple->setSizePolicy(sizePolicy3);
        lblGameIdSimple->setMinimumSize(QSize(713, 15));
        lblGameIdSimple->setMaximumSize(QSize(16777215, 500));
        lblGameIdSimple->setFont(font4);
        lblGameIdSimple->setTextFormat(Qt::TextFormat::AutoText);
        lblGameIdSimple->setScaledContents(true);
        lblGameIdSimple->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblGameIdSimple, 0, 0, 1, 3);


        horizontalLayout->addWidget(groupBox);

        pages->addWidget(pageGameSimple);
        pageGameTable = new QWidget();
        pageGameTable->setObjectName("pageGameTable");
        gridLayout_4 = new QGridLayout(pageGameTable);
        gridLayout_4->setObjectName("gridLayout_4");
        btnSplit2 = new QPushButton(pageGameTable);
        btnSplit2->setObjectName("btnSplit2");
        btnSplit2->setFont(font5);
        btnSplit2->setIconSize(QSize(20, 50));

        gridLayout_4->addWidget(btnSplit2, 2, 3, 1, 1);

        btnHit2 = new QPushButton(pageGameTable);
        btnHit2->setObjectName("btnHit2");
        btnHit2->setFont(font5);

        gridLayout_4->addWidget(btnHit2, 2, 0, 1, 1);

        btnStand2 = new QPushButton(pageGameTable);
        btnStand2->setObjectName("btnStand2");
        btnStand2->setFont(font5);

        gridLayout_4->addWidget(btnStand2, 2, 1, 1, 2);

        grpFinance = new QGroupBox(pageGameTable);
        grpFinance->setObjectName("grpFinance");
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font8.setPointSize(10);
        font8.setWeight(QFont::Black);
        grpFinance->setFont(font8);
        grpFinance->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblBalanceValue = new QLabel(grpFinance);
        lblBalanceValue->setObjectName("lblBalanceValue");
        lblBalanceValue->setGeometry(QRect(30, 30, 63, 20));
        lblTotalBetValue = new QLabel(grpFinance);
        lblTotalBetValue->setObjectName("lblTotalBetValue");
        lblTotalBetValue->setGeometry(QRect(30, 50, 63, 20));
        lblTotalWinValue = new QLabel(grpFinance);
        lblTotalWinValue->setObjectName("lblTotalWinValue");
        lblTotalWinValue->setGeometry(QRect(30, 70, 63, 20));

        gridLayout_4->addWidget(grpFinance, 0, 0, 1, 1);

        grpSeat1 = new QGroupBox(pageGameTable);
        grpSeat1->setObjectName("grpSeat1");
        grpSeat1->setFont(font8);
        grpSeat1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblSeat1Cards = new QLabel(grpSeat1);
        lblSeat1Cards->setObjectName("lblSeat1Cards");
        lblSeat1Cards->setGeometry(QRect(30, 30, 63, 20));
        lblSeat1Total = new QLabel(grpSeat1);
        lblSeat1Total->setObjectName("lblSeat1Total");
        lblSeat1Total->setGeometry(QRect(30, 50, 63, 20));

        gridLayout_4->addWidget(grpSeat1, 1, 1, 1, 2);

        btnLeaveGame2 = new QPushButton(pageGameTable);
        btnLeaveGame2->setObjectName("btnLeaveGame2");
        btnLeaveGame2->setFont(font5);

        gridLayout_4->addWidget(btnLeaveGame2, 3, 0, 1, 2);

        btnSwitchToSimple = new QPushButton(pageGameTable);
        btnSwitchToSimple->setObjectName("btnSwitchToSimple");
        btnSwitchToSimple->setFont(font5);

        gridLayout_4->addWidget(btnSwitchToSimple, 3, 2, 1, 2);

        grpDealer = new QGroupBox(pageGameTable);
        grpDealer->setObjectName("grpDealer");
        grpDealer->setFont(font8);
        grpDealer->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_2 = new QGridLayout(grpDealer);
        gridLayout_2->setObjectName("gridLayout_2");
        lblDealerCardsTable = new QLabel(grpDealer);
        lblDealerCardsTable->setObjectName("lblDealerCardsTable");

        gridLayout_2->addWidget(lblDealerCardsTable, 0, 0, 1, 1);

        lblDealerTotalTable = new QLabel(grpDealer);
        lblDealerTotalTable->setObjectName("lblDealerTotalTable");

        gridLayout_2->addWidget(lblDealerTotalTable, 1, 0, 1, 1);


        gridLayout_4->addWidget(grpDealer, 0, 3, 1, 1);

        pages->addWidget(pageGameTable);
        pageJoinRoom = new QWidget();
        pageJoinRoom->setObjectName("pageJoinRoom");
        widget = new QWidget(pageJoinRoom);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 781, 531));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 1, 0, 1);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font9.setPointSize(26);
        font9.setWeight(QFont::ExtraBold);
        label_3->setFont(font9);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        tblRooms = new QTableWidget(widget);
        if (tblRooms->columnCount() < 3)
            tblRooms->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font4);
        tblRooms->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font4);
        tblRooms->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font4);
        tblRooms->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tblRooms->rowCount() < 3)
            tblRooms->setRowCount(3);
        tblRooms->setObjectName("tblRooms");
        tblRooms->setMaximumSize(QSize(16777215, 16777177));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font10.setPointSize(12);
        tblRooms->setFont(font10);
        tblRooms->setFrameShape(QFrame::Shape::NoFrame);
        tblRooms->setFrameShadow(QFrame::Shadow::Plain);
        tblRooms->setLineWidth(9);
        tblRooms->setMidLineWidth(5);
        tblRooms->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        tblRooms->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        tblRooms->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        tblRooms->setAlternatingRowColors(false);
        tblRooms->setShowGrid(true);
        tblRooms->setGridStyle(Qt::PenStyle::SolidLine);
        tblRooms->setSortingEnabled(true);
        tblRooms->setWordWrap(true);
        tblRooms->setCornerButtonEnabled(true);
        tblRooms->setRowCount(3);
        tblRooms->setColumnCount(3);
        tblRooms->horizontalHeader()->setVisible(true);
        tblRooms->horizontalHeader()->setCascadingSectionResizes(true);
        tblRooms->horizontalHeader()->setMinimumSectionSize(60);
        tblRooms->horizontalHeader()->setDefaultSectionSize(142);
        tblRooms->horizontalHeader()->setHighlightSections(true);
        tblRooms->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tblRooms->horizontalHeader()->setStretchLastSection(true);
        tblRooms->verticalHeader()->setCascadingSectionResizes(true);
        tblRooms->verticalHeader()->setMinimumSectionSize(28);
        tblRooms->verticalHeader()->setDefaultSectionSize(79);
        tblRooms->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tblRooms->verticalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tblRooms);

        btnJoinSelected = new QPushButton(widget);
        btnJoinSelected->setObjectName("btnJoinSelected");
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font11.setPointSize(19);
        font11.setBold(false);
        btnJoinSelected->setFont(font11);

        verticalLayout_3->addWidget(btnJoinSelected);

        btnBackFromJoin = new QPushButton(widget);
        btnBackFromJoin->setObjectName("btnBackFromJoin");
        btnBackFromJoin->setFont(font5);

        verticalLayout_3->addWidget(btnBackFromJoin);

        btnRefreshRooms = new QPushButton(widget);
        btnRefreshRooms->setObjectName("btnRefreshRooms");
        btnRefreshRooms->setFont(font5);

        verticalLayout_3->addWidget(btnRefreshRooms);

        pages->addWidget(pageJoinRoom);
        pageLobby = new QWidget();
        pageLobby->setObjectName("pageLobby");
        verticalLayout = new QVBoxLayout(pageLobby);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(pageLobby);
        label->setObjectName("label");
        QFont font12;
        font12.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font12.setPointSize(44);
        font12.setWeight(QFont::ExtraBold);
        label->setFont(font12);
        label->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        label->setTextFormat(Qt::TextFormat::PlainText);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        btnGoCreate = new QPushButton(pageLobby);
        btnGoCreate->setObjectName("btnGoCreate");
        btnGoCreate->setMinimumSize(QSize(0, 50));
        QFont font13;
        font13.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font13.setPointSize(19);
        btnGoCreate->setFont(font13);

        verticalLayout->addWidget(btnGoCreate);

        btnGoJoin = new QPushButton(pageLobby);
        btnGoJoin->setObjectName("btnGoJoin");
        btnGoJoin->setMinimumSize(QSize(0, 50));
        btnGoJoin->setFont(font13);

        verticalLayout->addWidget(btnGoJoin);

        pages->addWidget(pageLobby);

        gridLayout->addWidget(pages, 0, 0, 1, 1, Qt::AlignmentFlag::AlignVCenter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        lblGameIdSimple->setBuddy(lblGameIdSimple);
#endif // QT_CONFIG(shortcut)

        retranslateUi(MainWindow);

        pages->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        CreateRoomBox->setTitle(QCoreApplication::translate("MainWindow", "CREATE ROOM", nullptr));
        balanceEdit->setText(QCoreApplication::translate("MainWindow", "Starting Balance", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Number of Players", nullptr));
        btnCreateRoom->setText(QCoreApplication::translate("MainWindow", "CREAT", nullptr));
        btnBackFromCreate->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        editBalance->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        groupBox->setTitle(QString());
        btnSwitchToTable->setText(QCoreApplication::translate("MainWindow", "TABLE VIEW", nullptr));
        btnHit->setText(QCoreApplication::translate("MainWindow", "HIT", nullptr));
        btnLeaveGame1->setText(QCoreApplication::translate("MainWindow", "LEAVE/BACK", nullptr));
        lblDealerCardsSimple_2->setTitle(QCoreApplication::translate("MainWindow", "Dealer", nullptr));
        lblDealerCardsSimple->setText(QCoreApplication::translate("MainWindow", "?,?", nullptr));
        lblDealerTotalSimple->setText(QCoreApplication::translate("MainWindow", "DealerTotal : 0", nullptr));
        lblDealerCardsSimple_3->setTitle(QCoreApplication::translate("MainWindow", "Player", nullptr));
        lblPlayerCardsSimple->setText(QCoreApplication::translate("MainWindow", "?,?", nullptr));
        lblPlayerTotalSimple->setText(QCoreApplication::translate("MainWindow", "PlayerTotal : 0", nullptr));
        btnStand->setText(QCoreApplication::translate("MainWindow", "STAND", nullptr));
        btnSplit->setText(QCoreApplication::translate("MainWindow", "SPLIT", nullptr));
        lblGameIdSimple->setText(QCoreApplication::translate("MainWindow", "GameId:", nullptr));
        btnSplit2->setText(QCoreApplication::translate("MainWindow", "SPLIT", nullptr));
        btnHit2->setText(QCoreApplication::translate("MainWindow", "HIT", nullptr));
        btnStand2->setText(QCoreApplication::translate("MainWindow", "STAND", nullptr));
        grpFinance->setTitle(QCoreApplication::translate("MainWindow", "Finance", nullptr));
        lblBalanceValue->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblTotalBetValue->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblTotalWinValue->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        grpSeat1->setTitle(QCoreApplication::translate("MainWindow", "YOU", nullptr));
        lblSeat1Cards->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblSeat1Total->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnLeaveGame2->setText(QCoreApplication::translate("MainWindow", "LEAVE/BACK", nullptr));
        btnSwitchToSimple->setText(QCoreApplication::translate("MainWindow", "SIMPLE VIEW", nullptr));
        grpDealer->setTitle(QCoreApplication::translate("MainWindow", "Dealer", nullptr));
        lblDealerCardsTable->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblDealerTotalTable->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "JOIN ROOM", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblRooms->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "SERVER ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblRooms->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "NAME", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblRooms->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "PLAYERS", nullptr));
        btnJoinSelected->setText(QCoreApplication::translate("MainWindow", "Join", nullptr));
        btnBackFromJoin->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        btnRefreshRooms->setText(QCoreApplication::translate("MainWindow", "Refresh Rooms", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "BLACK JACK", nullptr));
        btnGoCreate->setText(QCoreApplication::translate("MainWindow", "CREAT GAME", nullptr));
        btnGoJoin->setText(QCoreApplication::translate("MainWindow", "JOIN GAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
