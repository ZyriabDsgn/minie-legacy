/* Minie Is Not IE is a Free(dom), simple & lightweight Web browser <http://www.minie-project.org/>
* Copyright (C) 2013 - Arthur Wallendorff <http://www.core-unit.net/>
* Contact (for Minie) : flaco@minie-project.org
*
* Minie is the application's main class.
* It instantiates everything and is the only Minie-related class called by the main() function.
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

#ifndef MINIE_H
#define MINIE_H

#include <QtWidgets/QMainWindow>
#include <QtWebkitWidgets/QWebView>
#include <QtGui/QIcon>
#include <QtCore/QString>
#include <QtCore/QDebug>
#include <ctime>
#include "tools.h"
#include "const.h"

class Minie : public QMainWindow
{
  Q_OBJECT
 public:
  Minie(QWidget * parent = 0);

  QTabWidget* getTabManager() const {return m_tabManager;}

  friend QWebView* tools::currentPage() const;
  friend QIcon tools::getFavicon() const;

 private:
  /* INITIALIZATIONS */
  void initActions();

  void initTitleBar();
  void initMenuBar();

  void checkCache();

  QMenu *m_fileMenu;
  QMenu *m_navigationMenu;
  QMenu *m_helpMenu;
  QMenu *m_aboutMenu;

  QTextStream *m_homePageFile;

  /* MODULES */
  OptionsManager *m_optionsManager;
  TabManager *m_tabManager;

  private slots:
    void hideGUI();

    void openNewTab();
    void closeAllTabs();

    void previousPage();
    void nextPage();
    void stopLoad();
    void reloadPage();
    void goHomePage();
    void loadPage();
};

#endif //MINIE_H
