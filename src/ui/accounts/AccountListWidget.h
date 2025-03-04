#ifndef ACCOUNTLISTWIDGET_H
#define ACCOUNTLISTWIDGET_H

#include "AddAccountWidget.h"
#include <QWidget>

class QGridLayout;
class QListWidget;
class QPushButton;
class QListWidgetItem;
class QString;
class QAction;

class AccountListWidget : public QWidget {
    Q_OBJECT
  public:
    explicit AccountListWidget(QWidget *parent = nullptr);

  signals:
    void signal_accountUpdate();

  private slots:
    void menuTrigger(QAction *action);
    void onAccountAdded();
    void onAccountClicked(QListWidgetItem *item);

  private:
    bool eventFilter(QObject *source, QEvent *event);
    QGridLayout *_layout;
    QListWidget *_accountList;
    QPushButton *_addAccountButton;
    AddAccountWidget *_addAccountWidget;
    QString _selectedAccount;
    QAction *_actRemove;
    void populateList();
};

#endif
