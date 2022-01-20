unit exp5;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Grids, DBGrids, DB, DBTables, StdCtrls;

type
  TForm1 = class(TForm)
    testdatabase: TDatabase;
    testdatasource: TDataSource;
    DBGrid1: TDBGrid;
    Button1: TButton;
    testquery: TQuery;
    Label1: TLabel;
    Label2: TLabel;
    input_author: TMemo;
    Label3: TLabel;
    input_bookserial: TMemo;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    input_bookname: TMemo;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  Input: ansistring;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
begin
  Input:='select * from PB18061383_exp5 where true ';
  if(length(input_bookname.Text)>0)
  then Input:=Input+'and bookname like '''+input_bookname.Text+''' ';
  if(length(input_author.Text)>0)
  then Input:=Input+'and author like '''+input_author.Text+''' ';
  if(length(input_bookserial.Text)>0)
  then Input:=Input+'and bookserial like '''+input_bookserial.Text+''' ';
  testquery.Close;
  testquery.SQL.Text:=Input;
  testquery.Open;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Input:='insert into PB18061383_exp5 values( '+''''+input_bookserial.Text+''', NULL, NULL);';
  testquery.Close;
  testquery.SQL.Text:=Input;
  testquery.ExecSQL;
  if(length(input_bookname.Text)>0)
  then Input:='update PB18061383_exp5 set bookname='''+input_bookname.Text+''' '+'where bookserial like '+''''+input_bookserial.Text+''';';
  testquery.Close;
  testquery.SQL.Text:=Input;
  testquery.ExecSQL;
  if(length(input_author.Text)>0)
  then Input:='update PB18061383_exp5 set author='''+input_author.Text+''' '+'where bookserial like '+''''+input_bookserial.Text+''';';
  testquery.Close;
  testquery.SQL.Text:=Input;
  testquery.ExecSQL;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  Input:='delete from PB18061383_exp5 where false ';
  if(length(input_bookname.Text)>0)
  then Input:=Input+'or bookname like '''+input_bookname.Text+''' ';
  if(length(input_author.Text)>0)
  then Input:=Input+'or author like '''+input_author.Text+''' ';
  if(length(input_bookserial.Text)>0)
  then Input:=Input+'or bookserial like '''+input_bookserial.Text+''' ';
  testquery.Close;
  testquery.SQL.Text:=Input;
  testquery.ExecSQL;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  if(length(input_bookname.Text)>0)
  then Input:='update PB18061383_exp5 set bookname='''+input_bookname.Text+''' '+'where bookserial like '+''''+input_bookserial.Text+''';';
  testquery.Close;
  testquery.SQL.Text:=Input;
  testquery.ExecSQL;
  if(length(input_author.Text)>0)
  then Input:='update PB18061383_exp5 set author='''+input_author.Text+''' '+'where bookserial like '+''''+input_bookserial.Text+''';';
  testquery.Close;
  testquery.SQL.Text:=Input;
  testquery.ExecSQL;
end;

end.
