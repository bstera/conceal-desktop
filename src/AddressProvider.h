// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2015-2016 XDN developers
// Copyright (c) 2016 Karbowanec developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <QByteArrayData>
#include <QNetworkAccessManager>
#include <QObject>
#include <QString>

namespace WalletGui {

class AddressProvider : public QObject {
  Q_OBJECT

public:
  explicit AddressProvider(QObject *parent);
  ~AddressProvider();

  void getAddress();

private:
  QNetworkAccessManager m_networkManager;
  void readyRead();

Q_SIGNALS:
  void addressFoundSignal(const QString& _address);
};

}
