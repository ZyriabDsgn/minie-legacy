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

#include "UrlField.h"

UrlField::UrlField(QWidget *parent)
  : QWidget(parent), ui(new Ui::UrlField), autofill(new QCompleter(URL_LIST, this))
								  
{
  ui->setupUi(this);

  maxCount(10);
  setEditable(true);

  autofill->setCaseSensitivity(Qt::CaseInsensitive);
  autofill->setCompletionMode(QCompleter::InlineCompletion | QCompleter::UnfilteredPopupCompletion);

  setCompleter(autofill);
}



UrlField::~UrlField()
{
  delete ui;
}
