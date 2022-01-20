object Form1: TForm1
  Left = 547
  Top = 163
  Width = 514
  Height = 664
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 32
    Width = 33
    Height = 13
    Caption = #20070#21517
  end
  object Label2: TLabel
    Left = 200
    Top = 32
    Width = 33
    Height = 13
    Caption = #20316#32773
  end
  object Label3: TLabel
    Left = 48
    Top = 88
    Width = 33
    Height = 13
    Caption = #20070#21495
  end
  object DBGrid1: TDBGrid
    Left = 40
    Top = 152
    Width = 417
    Height = 425
    DataSource = testdatasource
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object Button1: TButton
    Left = 376
    Top = 48
    Width = 73
    Height = 25
    Caption = #26597#35810
    TabOrder = 1
    OnClick = Button1Click
  end
  object input_bookname: TMemo
    Left = 48
    Top = 48
    Width = 129
    Height = 25
    TabOrder = 2
  end
  object input_author: TMemo
    Left = 200
    Top = 48
    Width = 129
    Height = 25
    TabOrder = 3
  end
  object input_bookserial: TMemo
    Left = 48
    Top = 104
    Width = 129
    Height = 25
    TabOrder = 4
  end
  object Button2: TButton
    Left = 200
    Top = 104
    Width = 75
    Height = 25
    Caption = #25554#20837
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 288
    Top = 104
    Width = 75
    Height = 25
    Caption = #21024#38500
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 376
    Top = 104
    Width = 75
    Height = 25
    Caption = #26356#26032
    TabOrder = 7
    OnClick = Button4Click
  end
  object testdatabase: TDatabase
    AliasName = 'user-MySQL-PB18061383'
    Connected = True
    DatabaseName = 'test'
    LoginPrompt = False
    Params.Strings = (
      'DATABASE NAME=test'
      'USER NAME=root'
      'ODBC DSN=user-MySQL-PB18061383'
      'OPEN MODE=READ/WRITE'
      'SCHEMA CACHE SIZE=8'
      'SQLQRYMODE='
      'LANGDRIVER='
      'SQLPASSTHRU MODE=SHARED AUTOCOMMIT'
      'SCHEMA CACHE TIME=-1'
      'MAX ROWS=-1'
      'BATCH COUNT=200'
      'ENABLE SCHEMA CACHE=FALSE'
      'SCHEMA CACHE DIR='
      'ENABLE BCD=FALSE'
      'ROWSET SIZE=20'
      'BLOBS TO CACHE=64'
      'PASSWORD=')
    SessionName = 'Default'
  end
  object testdatasource: TDataSource
    AutoEdit = False
    DataSet = testquery
    Top = 64
  end
  object testquery: TQuery
    DatabaseName = 'user-MySQL-PB18061383'
    Top = 32
  end
end
