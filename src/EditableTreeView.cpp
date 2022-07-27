/* Minie Is Not IE is a Free(dom), simple & lightweight Web browser <http://www.minie-project.org/>
 * Copyleft 2013 2014 - Arthur Wallendorff <http://www.core-unit.net/>
 * Contact (for Minie) : flaco@minie-project.org
 *
 * 
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

#include "EditableTreeView.h"

EditableTreeView::EditableTreeView(QWidget * parent)
  : QTreeView(parent)
{
}

void EditableTreeView::keyPressEvent(QKeyEvent * event)
{
  if(model() && event->key() == Qt::Key_Delete)
    {
      removeSelection();
      event->setAccepted(true);
    }
  else
    QAbstraceItemView::KeyPressEvent(event);
}

/* SLOTS */
void EditableTreeView::removeSelection()
{
  if(!model() || !selectionModel() || !selectionModel()->hasSelection())
    return;

  QModelIndexList selectedRow = selectionModel()->selectedRows();
  
  for(int i = selectedRow.count() - 1; i >= 0; --i)
    {
      QModelIndex index = selectedRows.at(i);
      model()->removeRow(index.row(), index.parent());
    }
}

void EditableTreeView::removeAll()
{
  if(!model())
    return;

  model()->removeRows(0, model()->rowCount(rootIndex()), rootIndex());
}
