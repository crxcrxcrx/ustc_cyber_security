program Project1;

uses
  Forms,
  exp5 in '.\exp5.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
