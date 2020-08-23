// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2018 The Circle Foundation & Conceal Devs
// Copyright (c) 2018-2019 Conceal Network & Conceal Devs
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php

#include "ImportGUIKeyDialog.h"

#include <QDir>
#include <QFileDialog>
#include <QLineEdit>

#include "ui_importguikeydialog.h"

class QWidget;

namespace WalletGui 
{

ImportGUIKeyDialog::ImportGUIKeyDialog(QWidget* _parent) : QDialog(_parent), m_ui(new Ui::ImportGUIKeyDialog) {
  m_ui->setupUi(this);
}

ImportGUIKeyDialog::~ImportGUIKeyDialog() {
}

QString ImportGUIKeyDialog::getKeyString() const {
  return m_ui->m_keyEdit->text().trimmed();
}

QString ImportGUIKeyDialog::getFilePath() const {
  return m_ui->m_pathEdit->text().trimmed();
}

void ImportGUIKeyDialog::selectPathClicked() {
  QString filePath = QFileDialog::getSaveFileName(this, tr("Wallet file"),
#ifdef Q_OS_WIN
    QApplication::applicationDirPath(),
#else
    QDir::homePath(),
#endif
    tr("Wallets (*.wallet)")
    );

  if (!filePath.isEmpty() && !filePath.endsWith(".wallet")) {
    filePath.append(".wallet");
  }

  m_ui->m_pathEdit->setText(filePath);
}

}
