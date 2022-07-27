/* Minie Is Not IE is a Free(dom), simple & lightweight Web browser <http://www.minie-project.org/>
* Copyleft 2013 2014 - Arthur Wallendorff <http://www.core-unit.net/>
* Contact (for Minie) : flaco@minie-project.org
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

#include "Minie.h"

Minie::Minie(QWidget * parent = 0)
  : QMainWindow(parent), m_optionManager(new OptionManager(this)),
    m_tabManager(new TabManager(this)), m_homePageManager(new HomePageManage(this))
{
  checkCache();

  initActions();
  m_optionManager->checkOptions();

  initTitleBar();
  m_tabManager->initGUI();
  initMenuBar();
  m_homePageManager->initHomePage();
}

/* INITIALIZATIONS */
void Minie::initActions()
{
  qDebug() << "Actions initialization" << endl;

  time_t start, end;
  double timeLaps;

  time(&start);

  connect(Tools::Actions::openNewTab, SIGNAL(triggered()), this, SLOT(openNewTab()) );
  connect(Tools::Actions::closeTab, SIGNAL(triggered()), this, SLOT(closeTab()) );
  connect(Tools::Actions::closeAllTabs, SIGNAL(triggered()), this, SLOT(closeTab()) );
  connect(Tools::Actions::quitApp, SIGNAL(triggered()), this, SLOT(quitApp()) );

  connect(Tools::Actions::previous, SIGNAL(triggered()), this, SLOT(previousPage()) );
  connect(Tools::Actions::next, SIGNAL(triggered()), this, SLOT(nextPage()) );
  connect(Tools::Actions::stopLoad, SIGNAL(triggered()), this, SLOT(stopLoad()) );
  connect(Tools::Actions::reload, SIGNAL(triggered()), this, SLOT(reloadPage()) );
  connect(Tools::Actions::goHomePage, SIGNAL(triggered()), this, SLOT(goHomePage()) );
  connect(Tools::Actions::loadPage, SIGNAL(triggered()), this, SLOT(loadPage()) );
  connect(Tools::Actions::aboutMinie, SIGNAL(triggered()), this, SLOT(aboutMinie()) );
  connect(Tools::Actions::aboutGPL, SIGNAL(triggered()), this, SLOT(aboutGPL()) );
  connect(Tools::Actions::aboutQt, SIGNAL(triggered()), this, SLOT(aboutQt()) );

  time(&end);
  timeLaps = difftime(end, start);
  qDebug() << "Execution in " << timeLaps << " seconds." << endl;
}

void Minie::initTitleBar()
{
  qDebug() << "Title bar initialization" << endl;

  time_t start, end;
  double timeLaps;

  time(&start);

  QString appTitle = ("Minie " + APP_VERSION);

  setWindowIcon(QIcon(APP_ICON));
  setWindowTitle(appTitle);

  time(&end);
  timeLaps = difftime(end, start);
  qDebug() << "Execution in " << timeLaps << " seconds." << endl;
}


void Minie::initMenuBar()
{
  qDebug() << "Menu bar initialization" << endl;

  time_t start, end;
  double timeLaps;

  time(&start);

  m_fileMenu = menuBar()->addMenu(tr("&File"));
  m_fileMenu->addAction(Tools::Actions::openNewTab);
  m_fileMenu->addAction(Tools::Actions::closeTab);
  m_fileMenu->addAction(Tools::Actions::closeAllTabs);
  m_fileMenu->addAction(Tools::Actions::quitApp);

  m_navigationMenu = menuBar()->addMenu(tr("&Navigation"));
  m_navigationMenu->addAction(Tools::Actions::previous);
  m_navigationMenu->addAction(Tools::Actions::next);
  m_navigationMenu->addAction(Tools::Actions::stopLoad);
  m_navigationMenu->addAction(Tools::Actions::reload);
  m_navigationMenu->addAction(Tools::Actions::goHomePage);
  m_navigationMenu->addAction(Tools::Actions::loadPage);
  
  m_helpMenu = menuBar()->addMenu(tr("&Help"));
  m_helpMenu->addAction(Tools::Actions::help);

  m_aboutMenu = menuBar()->addMenu(tr("&About"));
  m_aboutMenu->addAction(Tools::Actions::aboutMinie);
  m_aboutMenu->addAction(Tools::Actions::aboutGPL);
  m_aboutMenu->addAction(Tools::Actions::aboutQt);

  time(&end);
  timeLaps = difftime(end, start);
  qDebug << "Execution in " << timeLaps << " seconds." << endl;
}

void Minie::checkCache()
{
  if(!QDir(qApp->applicationDirPath() + CACHE_PATH).exists())
    {
      QDir(qApp->applicationDirPath()).mkdir(CACHE_PATH);
    }

  QWebSettings::setIconDatabasePath(qApp->applicationDirPath() + CACHE_PATH);
}
