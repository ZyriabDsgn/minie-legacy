/* Minie Is Not IE is a Free(dom), simple & lightweight Web browser <http://www.minie-project.org/>
* Copyleft 2013 2014 - Arthur Wallendorff <http://www.core-unit.net/>
* Contact (for Minie) : flaco@minie-project.org
*
* The home page manager will simply manage the user defined home pages via the minie/content/options/homepage (const = HOMEPAGE_LIST) text file
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

#ifndef HOMEPAGEMANAGER_H
#define HOMEPAGEMANAGER_H

#include <QtCore/QString>
#include <QtCore/QUrl>
#include <QtCore/QVector>
#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <ctime>
#include "tools.h"
#include "const.h"

class HomePageManager
{
 public:
  HomePageManager(QWidget * parent = 0);

  void initHomePage();
  static QVector<QUrl *>* getHomePageList() const {return m_homePageList;}
  static int getHomePageNumber() const {return m_homePageList->size();}

 private:
  QVector<QUrl *> *m_homePageList;
  QFile *m_homePageFile;
};

#endif //HOMEPAGEMANAGER_H
