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

#include "HomePageManager.h"

HomePageManager::HomePageManager(QWidget * parent = 0)
  : m_homePageFile(new QFile(HOMEPAGE_LIST))
{
  m_homePageList->push_back(nullptr);
}

void HomePageManager::initHomePage()
{
  qDebug << "Home page initialization" << endl;

  time_t start, end;
  double timeLaps;

  time(&start);

  int i(0);
  QTextStream in(&m_homePageFile);
  QVector<QString> urlList;

  m_homePageList->pop_back();

  while(!in.atEnd())
    {
      urlList.push_back(new QString(in.readLine()) );
      m_homePageList->push_back(new QUrl(urlList[i]));
      ++i;
    }

  homePageFile->seek(0);

  time(&end);
  timeLaps = difftime(end, start);
  qDebug() << "Execution in " << timeLaps << " seconds." << endl;
}
