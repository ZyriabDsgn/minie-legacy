#ifndef HISTORY_H
#define HISTORY_H

#include <QtWidget/QPushButton>
#include <QtWidget/QTreeView>
#include <QtWidget/QHBoxLayout>
#include <QtWidget/QDialog>

namespace ui
{
  class History;
}

class History : QDialog
{
  Q_OBJECT

    public:
  explicit History(QWidget *parent = 0);
  ~History();

