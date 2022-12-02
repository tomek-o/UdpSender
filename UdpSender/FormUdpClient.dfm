object frmUdpClient: TfrmUdpClient
  Left = 0
  Top = 0
  Align = alClient
  BorderStyle = bsNone
  Caption = 'UDP client'
  ClientHeight = 253
  ClientWidth = 409
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    409
    253)
  PixelsPerInch = 96
  TextHeight = 13
  object lblAddress: TLabel
    Left = 8
    Top = 8
    Width = 39
    Height = 13
    Caption = 'Address'
  end
  object lblPort: TLabel
    Left = 200
    Top = 8
    Width = 20
    Height = 13
    Caption = 'Port'
  end
  object lblData: TLabel
    Left = 8
    Top = 45
    Width = 250
    Height = 13
    Caption = 'Data to send (hex string, e.g. ABCDEF0123456789)'
  end
  object pnlBottom: TPanel
    Left = 0
    Top = 212
    Width = 409
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      409
      41)
    object btnSend: TButton
      Left = 326
      Top = 8
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Send'
      TabOrder = 0
      OnClick = btnSendClick
    end
  end
  object edAddress: TEdit
    Left = 53
    Top = 5
    Width = 129
    Height = 21
    TabOrder = 1
    Text = '225.1.1.1'
  end
  object edPort: TEdit
    Left = 226
    Top = 5
    Width = 49
    Height = 21
    TabOrder = 2
    Text = '4242'
  end
  object memo: TMemo
    Left = 8
    Top = 64
    Width = 393
    Height = 142
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      '3AE284B1C598C68ED3ACC59ED0A9D087C5A6CF9AC4A600000'
      '0000000000000000000000000000000000000000000000000000'
      '0000000000000000000000000000000000000000000000000000'
      '0000000000000000000000000000000000000000000000000000'
      '0000000000000000000000000000000000000000000000000000'
      '0000000000000000000000000000000000000000000000000000'
      '0000000000000000000000000000000000000000000000000000'
      '0000000000000000000000000000000000000000000000000000'
      '0000000000000000000000000000000000000000000000000000'
      '0000000000000000000000000000000000000000000000000000'
      '000000000000000')
    ScrollBars = ssVertical
    TabOrder = 3
  end
end
