/* Minie Is Not IE is a Free(dom), simple & lightweight Web browser <http://www.minie-project.org/>
* Copyleft 2013 2014 - Arthur Wallendorff <http://www.core-unit.net/>
* Contact (for Minie) : flaco@minie-project.org
*
* UrlField.h represents the URL field's model part.
* For the URLs list take a look in const.h and content/
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

#ifndef URLFIELD_H
#define URLFIELD_H

#include <QtWidget/QComboBox>
#include <QtWidget/QCompleter>
#include <QtCore/QStringList>
#include "const.h"

namespace Ui
{
  class UrlField;
}

class UrlField : public QComboBox
{

 public:
  explicit UrlField(QWidget *parent = 0);
  ~UrlField();
  
 private:
  Ui::UrlField *ui;
  QCompleter *autofill;  
};

#endif // URLFIELD_H
