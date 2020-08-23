// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2018 The Circle Foundation & Conceal Devs
// Copyright (c) 2018-2019 Conceal Network & Conceal Devs
//  
// Copyright (c) 2018 The Circle Foundation & Conceal Devs
// Copyright (c) 2018-2019 Conceal Network & Conceal Devs
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <QByteArrayData>
#include <QSortFilterProxyModel>
#include <QString>

class QObject;

namespace WalletGui {

class SortedAddressListModel : public QSortFilterProxyModel {
  Q_OBJECT

public:
  static SortedAddressListModel& instance();

protected:

private:
  SortedAddressListModel();
  ~SortedAddressListModel();
};

}
