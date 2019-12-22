///
/// @file src/wxwidgets/MainWindow.cpp
///
/// 
///
// Copyright (c) 2019, Jakub Korbel <i@jakubkorbel.cz>
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// The views and conclusions contained in the software and documentation are those
// of the authors and should not be interpreted as representing official policies,
// either expressed or implied, of the DrD project.

// -------------------------------------
// Includes
// -------------------------------------

// Environment
#include <drd/Environment.h>

// System includes
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/grid.h>

// Project includes
#include "DrdGuiFrame.hpp"

// -------------------------------------
// Constants
// -------------------------------------

// -------------------------------------
// Macros
// -------------------------------------

// -------------------------------------
// Local Data Types
// -------------------------------------

// -------------------------------------
// Forward Declarations
// -------------------------------------

// -------------------------------------
// Variable Definitions
// -------------------------------------

wxBEGIN_EVENT_TABLE(DrdFrame, wxFrame)
    EVT_MENU(ID_Hello,   DrdFrame::OnHello)
    EVT_MENU(wxID_EXIT,  DrdFrame::OnExit)
    EVT_MENU(wxID_ABOUT, DrdFrame::OnAbout)
wxEND_EVENT_TABLE()

// -------------------------------------
// Function Definitions
// -------------------------------------


DrdFrame::DrdFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
	m_rollBox = new wxTextCtrl(this, TEXT_Main, "Hi!", wxDefaultPosition, wxDefaultSize,
	0, wxDefaultValidator, wxTextCtrlNameStr);
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Loading finished!" );


/*
    wxGrid* grid = new wxGrid( this,
                        -1,
                        wxPoint( 0, 0 ),
                        wxSize( 400, 300 ) );
    // Then we call CreateGrid to set the dimensions of the grid
    // (100 rows and 10 columns in this example)
    grid->CreateGrid( 100, 10 );
    // We can set the sizes of individual rows and columns
    // in pixels
    grid->SetRowSize( 0, 60 );
    grid->SetColSize( 0, 120 );
    // And set grid cell contents as strings
    grid->SetCellValue( 0, 0, "wxGrid is good" );
    // We can specify that some cells are read->only
    grid->SetCellValue( 0, 3, "This is read->only" );
    grid->SetReadOnly( 0, 3 );
    // Colours can be specified for grid cell contents
    grid->SetCellValue(3, 3, "green on grey");
    grid->SetCellTextColour(3, 3, *wxGREEN);
    grid->SetCellBackgroundColour(3, 3, *wxLIGHT_GREY);
    // We can specify the some cells will store numeric
    // values rather than strings. Here we set grid column 5
    // to hold floating point values displayed with width of 6
    // and precision of 2
    grid->SetColFormatFloat(5, 6, 2);
    grid->SetCellValue(0, 6, "3.1415");*/

}
void DrdFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void DrdFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void DrdFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}


// Private Functions

// -------------------------------------
// An empty line follows.

