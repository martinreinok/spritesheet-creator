/********************************************************************************
** Form generated from reading UI file 'spritesheetcreator.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITESHEETCREATOR_H
#define UI_SPRITESHEETCREATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpritesheetCreator
{
public:
    QAction *actionClear_All;
    QAction *actionLoad_Files;
    QAction *actionSpritesheet_Preview;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QMenu *menuView;
    QStatusBar *statusbar;
    QDockWidget *LoadFilesDock;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *AddImagesButton;
    QLabel *label;
    QTableWidget *ImageTable;
    QDockWidget *PreviewDock;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QGraphicsView *SpritesheetPreview;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QComboBox *TilingConstant;
    QSpinBox *TilingNumber;
    QLineEdit *TilingOtherNumber;
    QGroupBox *PreviewCheckbox;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *ShowPreviewCheckbox;
    QCheckBox *AnimateCheckbox;
    QSpinBox *FPSSelector;
    QPushButton *SaveSpritesheetButton;

    void setupUi(QMainWindow *SpritesheetCreator)
    {
        if (SpritesheetCreator->objectName().isEmpty())
            SpritesheetCreator->setObjectName("SpritesheetCreator");
        SpritesheetCreator->resize(379, 509);
        QIcon icon;
        icon.addFile(QString::fromUtf8("9tiles.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SpritesheetCreator->setWindowIcon(icon);
        actionClear_All = new QAction(SpritesheetCreator);
        actionClear_All->setObjectName("actionClear_All");
        actionLoad_Files = new QAction(SpritesheetCreator);
        actionLoad_Files->setObjectName("actionLoad_Files");
        actionLoad_Files->setCheckable(true);
        actionLoad_Files->setChecked(true);
        actionSpritesheet_Preview = new QAction(SpritesheetCreator);
        actionSpritesheet_Preview->setObjectName("actionSpritesheet_Preview");
        actionSpritesheet_Preview->setCheckable(true);
        actionSpritesheet_Preview->setChecked(true);
        centralwidget = new QWidget(SpritesheetCreator);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        SpritesheetCreator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SpritesheetCreator);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 379, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        menuAbout->setTearOffEnabled(false);
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        SpritesheetCreator->setMenuBar(menubar);
        statusbar = new QStatusBar(SpritesheetCreator);
        statusbar->setObjectName("statusbar");
        SpritesheetCreator->setStatusBar(statusbar);
        LoadFilesDock = new QDockWidget(SpritesheetCreator);
        LoadFilesDock->setObjectName("LoadFilesDock");
        LoadFilesDock->setAutoFillBackground(true);
        LoadFilesDock->setStyleSheet(QString::fromUtf8(""));
        LoadFilesDock->setFloating(false);
        LoadFilesDock->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, 0, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        AddImagesButton = new QPushButton(dockWidgetContents);
        AddImagesButton->setObjectName("AddImagesButton");

        verticalLayout->addWidget(AddImagesButton);

        label = new QLabel(dockWidgetContents);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(6);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        ImageTable = new QTableWidget(dockWidgetContents);
        ImageTable->setObjectName("ImageTable");
        ImageTable->setContextMenuPolicy(Qt::CustomContextMenu);
        ImageTable->setAcceptDrops(true);
        ImageTable->setFrameShape(QFrame::Box);
        ImageTable->setFrameShadow(QFrame::Sunken);
        ImageTable->setAutoScrollMargin(2);
        ImageTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ImageTable->setDragDropOverwriteMode(false);
        ImageTable->setDragDropMode(QAbstractItemView::DropOnly);
        ImageTable->setAlternatingRowColors(true);

        verticalLayout->addWidget(ImageTable);


        verticalLayout_2->addLayout(verticalLayout);

        LoadFilesDock->setWidget(dockWidgetContents);
        SpritesheetCreator->addDockWidget(Qt::TopDockWidgetArea, LoadFilesDock);
        PreviewDock = new QDockWidget(SpritesheetCreator);
        PreviewDock->setObjectName("PreviewDock");
        PreviewDock->setAutoFillBackground(true);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName("dockWidgetContents_4");
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(-1, 1, -1, 1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        SpritesheetPreview = new QGraphicsView(dockWidgetContents_4);
        SpritesheetPreview->setObjectName("SpritesheetPreview");
        SpritesheetPreview->setAcceptDrops(false);
        SpritesheetPreview->setFrameShape(QFrame::Box);
        SpritesheetPreview->setFrameShadow(QFrame::Sunken);
        SpritesheetPreview->setRenderHints(QPainter::LosslessImageRendering|QPainter::TextAntialiasing);

        verticalLayout_4->addWidget(SpritesheetPreview);

        groupBox = new QGroupBox(dockWidgetContents_4);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(-1, -1, 0, -1);
        TilingConstant = new QComboBox(groupBox);
        TilingConstant->setObjectName("TilingConstant");

        verticalLayout_6->addWidget(TilingConstant);

        TilingNumber = new QSpinBox(groupBox);
        TilingNumber->setObjectName("TilingNumber");
        TilingNumber->setMinimum(1);
        TilingNumber->setMaximum(1000);

        verticalLayout_6->addWidget(TilingNumber);


        horizontalLayout->addLayout(verticalLayout_6);

        TilingOtherNumber = new QLineEdit(groupBox);
        TilingOtherNumber->setObjectName("TilingOtherNumber");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TilingOtherNumber->sizePolicy().hasHeightForWidth());
        TilingOtherNumber->setSizePolicy(sizePolicy);
        TilingOtherNumber->setMaximumSize(QSize(100, 16777215));
        TilingOtherNumber->setFocusPolicy(Qt::NoFocus);
        TilingOtherNumber->setAcceptDrops(false);
        TilingOtherNumber->setReadOnly(true);

        horizontalLayout->addWidget(TilingOtherNumber);


        verticalLayout_4->addWidget(groupBox);


        verticalLayout_5->addLayout(verticalLayout_4);

        PreviewCheckbox = new QGroupBox(dockWidgetContents_4);
        PreviewCheckbox->setObjectName("PreviewCheckbox");
        PreviewCheckbox->setCheckable(true);
        horizontalLayout_3 = new QHBoxLayout(PreviewCheckbox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        ShowPreviewCheckbox = new QCheckBox(PreviewCheckbox);
        ShowPreviewCheckbox->setObjectName("ShowPreviewCheckbox");
        ShowPreviewCheckbox->setChecked(true);

        horizontalLayout_2->addWidget(ShowPreviewCheckbox);

        AnimateCheckbox = new QCheckBox(PreviewCheckbox);
        AnimateCheckbox->setObjectName("AnimateCheckbox");
        AnimateCheckbox->setEnabled(false);

        horizontalLayout_2->addWidget(AnimateCheckbox);

        FPSSelector = new QSpinBox(PreviewCheckbox);
        FPSSelector->setObjectName("FPSSelector");
        FPSSelector->setEnabled(false);
        FPSSelector->setMaximum(1000);
        FPSSelector->setValue(10);

        horizontalLayout_2->addWidget(FPSSelector);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_5->addWidget(PreviewCheckbox);

        SaveSpritesheetButton = new QPushButton(dockWidgetContents_4);
        SaveSpritesheetButton->setObjectName("SaveSpritesheetButton");
        SaveSpritesheetButton->setMinimumSize(QSize(0, 30));

        verticalLayout_5->addWidget(SaveSpritesheetButton);

        PreviewDock->setWidget(dockWidgetContents_4);
        SpritesheetCreator->addDockWidget(Qt::BottomDockWidgetArea, PreviewDock);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuEdit->addAction(actionClear_All);
        menuView->addAction(actionLoad_Files);
        menuView->addAction(actionSpritesheet_Preview);

        retranslateUi(SpritesheetCreator);

        QMetaObject::connectSlotsByName(SpritesheetCreator);
    } // setupUi

    void retranslateUi(QMainWindow *SpritesheetCreator)
    {
        SpritesheetCreator->setWindowTitle(QCoreApplication::translate("SpritesheetCreator", "SpritesheetCreator", nullptr));
        actionClear_All->setText(QCoreApplication::translate("SpritesheetCreator", "Clear All", nullptr));
        actionLoad_Files->setText(QCoreApplication::translate("SpritesheetCreator", "Load Files", nullptr));
        actionSpritesheet_Preview->setText(QCoreApplication::translate("SpritesheetCreator", "Spritesheet Preview", nullptr));
        menuFile->setTitle(QCoreApplication::translate("SpritesheetCreator", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("SpritesheetCreator", "Edit", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("SpritesheetCreator", "About", nullptr));
        menuView->setTitle(QCoreApplication::translate("SpritesheetCreator", "View", nullptr));
        LoadFilesDock->setWindowTitle(QCoreApplication::translate("SpritesheetCreator", "Load Files", nullptr));
        AddImagesButton->setText(QCoreApplication::translate("SpritesheetCreator", "Add Images", nullptr));
        label->setText(QCoreApplication::translate("SpritesheetCreator", "(Or Drag and Drop)", nullptr));
        PreviewDock->setWindowTitle(QCoreApplication::translate("SpritesheetCreator", "Spritesheet Preview", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SpritesheetCreator", "Tiling", nullptr));
        PreviewCheckbox->setTitle(QCoreApplication::translate("SpritesheetCreator", "Preview", nullptr));
        ShowPreviewCheckbox->setText(QCoreApplication::translate("SpritesheetCreator", "Show", nullptr));
        AnimateCheckbox->setText(QCoreApplication::translate("SpritesheetCreator", "Animate", nullptr));
        FPSSelector->setSuffix(QCoreApplication::translate("SpritesheetCreator", " FPS", nullptr));
        SaveSpritesheetButton->setText(QCoreApplication::translate("SpritesheetCreator", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpritesheetCreator: public Ui_SpritesheetCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITESHEETCREATOR_H
