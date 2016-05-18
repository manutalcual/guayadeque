// -------------------------------------------------------------------------------- //
//	Copyright (C) 2008-2016 J.Rios anonbeat@gmail.com
//
//    This Program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 3, or (at your option)
//    any later version.
//
//    This Program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; see the file LICENSE.  If not, write to
//    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//    http://www.gnu.org/copyleft/gpl.html
//
// -------------------------------------------------------------------------------- //
#include "AuiManagedPanel.h"

#include "Utils.h"

// -------------------------------------------------------------------------------- //
guAuiManagedPanel::guAuiManagedPanel( wxWindow * parent, wxAuiManager * manager ) :
    wxPanel( parent, wxID_ANY, wxDefaultPosition, wxSize( -1, -1 ), wxTAB_TRAVERSAL|wxNO_BORDER )
{
    m_Manager = manager;

    Connect( wxEVT_SIZE, wxSizeEventHandler( guAuiManagedPanel::OnChangedSize ), NULL, this );
}

// -------------------------------------------------------------------------------- //
guAuiManagedPanel::~guAuiManagedPanel()
{
    Disconnect( wxEVT_SIZE, wxSizeEventHandler( guAuiManagedPanel::OnChangedSize ), NULL, this );
}

// -------------------------------------------------------------------------------- //
void guAuiManagedPanel::OnChangedSize( wxSizeEvent &event )
{
    wxSize Size = event.GetSize();

    wxAuiPaneInfo &PaneInfo = m_Manager->GetPane( this );
    if( PaneInfo.IsOk() )
    {
        if( ( PaneInfo.floating_size.x != Size.x ) || ( PaneInfo.floating_size.y != Size.y ) )
        {
            PaneInfo.floating_size.x = Size.x;
            PaneInfo.floating_size.y = Size.y;
        }
    }

    event.Skip();
}

// -------------------------------------------------------------------------------- //
