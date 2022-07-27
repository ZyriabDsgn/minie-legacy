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

#include "TabManager.h"

TabManager::TabManager()
{
  setStyleSheet("QTabBar::tab {width: 110px;}");
  setTabShape(QTabWidget::Triangular);
  setTabsClosable(true);
  setMovable(true);
  setElideMode(Qt::ElideRight);
}

void TabManager::initGUI()
{
  qDebug() << "GUI initialization" << endl;

  time_t start, end;
  double timeLaps;

  time(&start);

  QVector<QUrl *> homePageList = HomePageManager::getHomePageList(); 

  for(int i(0); i < HomePageManager::getHomePageNumber(); ++i)
    {
      addTab(homePageList->at(i));
    }

  time(&end);

  qDebug() << "Execution in " << timeLaps << " seconds." << endl;
}

int addTab(QWidget * page)
{
  
  
