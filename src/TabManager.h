/* Minie Is Not IE is a Free(dom), simple & lightweight Web browser <http://www.minie-project.org/>
* Copyleft 2013 2014 - Arthur Wallendorff <http://www.core-unit.net/>
* Contact (for Minie) : flaco@minie-project.org
*
* The tab manager manages the tabs system and its content (thread for each webview, etc)
*
*****************
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************
*/

#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <QtWidgets/QTabWidget>
#include <QtCore/QDebug>
#include <QtCore/QVector>
#include <QtCore/QThread>
#include <ctime>
#include "HomePageManager.h"

class TabManager : public QTabWidget
{
  Q_OBJECT
 public:
  TabManager(QWidget * parent = 0);
  
  int addTab(QWidget * page);

 private:
  void initGUI();

  QVector<QThread> m_threadList;

  private slots:
    void setTabTitle(bool ok);
};

#endif //TABMANAGER_H
