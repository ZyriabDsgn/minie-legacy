/* Minie Is Not IE is a Free(dom), simple & lightweight Web browser <http://www.minie-project.org/>
* Copyleft 2013 2014 - Arthur Wallendorff <http://www.core-unit.net/>
* Contact (for Minie) : flaco@minie-project.org
*
* tools.h regroups useful functions, QActions, etc
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

#ifndef TOOLS_H
#define TOOLS_H

#include <QtWebkit/QWebSettings>
#include <QtCore/QUrl>
#include <QtWidgets/QAction>
#include <QtWebkitWidgets/QWebView>
#include <QtCore/QString>
#include <QtCore/QTextStream>
#include "const.h"


namespace Tools
{
  QWebView* currentPage() const
  {
    return qobject_cast<QWebView *>(m_tabManager->currentWidget());
  }

  QIcon getFavicon() const
  {
    return QWebSettings::iconForUrl(QUrl(currentPage()->url()) );
  }

  int countLines(QFile * file);
  {
    int line_count(0);
    file->open(QIODevice::ReadOnly);

    QString line[100];
    QTextStream in(file);

    while(!in.atEnd())
      {
	line[linecount] = in.readLine();
	++line_count;
      }
    
    return line_count;
  }

  bool isUrl(QString * s) const
  {
    QStringList oddsStringList;
    QFile oddsFile(ODDS_LIST);
    QTextStream in(&oddsFile);
    int i(0), c;

    if(!oddsFile.open(QIODevice::ReadOnly | QIODevice::Text))
      return;

    while(!in.atEnd())
      {
        oddsStringList << in.readLine();
      }

    for(c = 0; c < oddsStringList.size(); ++c)
      {
	if(s->contains(oddsStringList.at(c)) )
	  return true;

	else
	  return false;
      }
  }

  namespace Actions
  {
    QAction *openNewTab;
    QAction *closeTab;
    QAction *closeAllTabs;
    QAction *quitApp;
    QAction *previous;
    QAction *next;
    QAction *stopLoad;
    QAction *reload;
    QAction *goHomePage;
    QAction *loadPage;
    QAction *help;
    QAction *aboutMinie;
    QAction *aboutGPL;
    QAction *aboutQt;
  
    void initActions(QMainWindow * parent)
    {
      openNewTab = new QAction(tr("Open a new &tab"), parent);
      openNewTab->setShortcut(QKeySequence("Ctrl+T"));

      closeAllTabs = new QAction(tr("Close all tabs"), parent);
      closeAllTabs->setShortcut(QKeySequence("Ctrl+Shift+W"));
      
      quitApp = new QAction(tr("&Quit", "Close the application"), parent);
      quitApp->setShortcut(QKeySequence("Ctrl+Q"));

      previous = new QAction(tr("&Previous"), parent);
      previous->setToolTip(tr("Return to the previous page"));
      previous->setIcon(QIcon(PREVIOUS_ICON));
      previous->setShortcut(QKeySequence("Ctrl+Backspace"));

      next = new QAction(tr("&Next"), parent);
      next->setToolTip(tr("Go to the next page"));
      next->setIcon(QIcon(NEXT_ICON));
      next->setShortcut(QKeySequence("Ctrl+Alt+Backspace"));
    
      stopLoad = new QAction(tr("&Stop loading page"), parent);
      stopLoad->setToolTip(tr("Stop the page's loading"));
      stopLoad->setIcon(QIcon(STOP_ICON));
      stopLoad->setShortcut(QKeySequence("Esc"));

      reload = new QAction(tr("&Reload page"), parent);
      reload->setToolTip(tr("Reload the page"));
      reload->setIcon(QIcon(RELOAD_ICON));
      reload->setShortcut(QKeySequence("F5"));

      goHomePage = new QAction(tr("Jump to the &homepage(s)"), parent);
      goHomePage->setToolTip(tr("Open your home page(s)"));
      goHomePage->setIcon(QIcon(HOME_ICON));
      goHomePage->setShortcut(QKeySequence("Alt+Home"));

      loadPage = new QAction(tr("&Load page"), parent);
      loadPage->setToolTip(tr("Load the given url"));
      loadPage->setIcon(QIcon(LOAD_ICON));
      loadPage->setShortcut(Qt::Key_Enter);

      help = new QAction(tr("&Help"), parent);
      help->setIcon(QIcon(HELP_ICON));
      help->setShortcut(Qt::Key_F1);

      aboutMinie = new QAction(tr("About &Minie"), parent);
      aboutGPL = new QAction(tr("About the GNU &GPLv3"), parent);
      aboutQt = new QAction(tr("About &Qt"), parent);
    } //initActions()

  } //namespace Actions

} //namespace Tools

#endif //TOOLS_H
