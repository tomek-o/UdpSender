object frmUdpClient: TfrmUdpClient
  Left = 0
  Top = 0
  Align = alClient
  BorderStyle = bsNone
  Caption = 'UDP client'
  ClientHeight = 371
  ClientWidth = 470
  Color = clBtnFace
  Constraints.MinHeight = 300
  Constraints.MinWidth = 409
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  DesignSize = (
    470
    371)
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
  object lblBytes: TLabel
    Left = 370
    Top = 45
    Width = 3
    Height = 13
  end
  object pnlBottom: TPanel
    Left = 0
    Top = 255
    Width = 470
    Height = 116
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitWidth = 409
    DesignSize = (
      470
      116)
    object lblInterval: TLabel
      Left = 8
      Top = 55
      Width = 110
      Height = 13
      Caption = 'Interval (random) from'
    end
    object lblTo: TLabel
      Left = 175
      Top = 55
      Width = 10
      Height = 13
      Caption = 'to'
    end
    object lblMs: TLabel
      Left = 244
      Top = 55
      Width = 13
      Height = 13
      Caption = 'ms'
    end
    object lblDatagramsPerTick: TLabel
      Left = 8
      Top = 80
      Width = 139
      Height = 13
      Caption = 'Datagrams sent per tick from'
    end
    object lblTo2: TLabel
      Left = 201
      Top = 80
      Width = 10
      Height = 13
      Caption = 'to'
    end
    object lblDataToSend: TLabel
      Left = 8
      Top = 6
      Width = 24
      Height = 13
      Caption = 'Send'
    end
    object btnSend: TButton
      Left = 341
      Top = 36
      Width = 121
      Height = 53
      Anchors = [akTop, akRight]
      Caption = 'Send single message'
      TabOrder = 0
      OnClick = btnSendClick
      ExplicitLeft = 280
    end
    object chbSendAutomatically: TCheckBox
      Left = 8
      Top = 32
      Width = 212
      Height = 17
      Caption = 'Send automatically at specified interval'
      TabOrder = 1
      OnClick = chbSendAutomaticallyClick
      OnKeyDown = chbSendAutomaticallyKeyDown
      OnKeyPress = chbSendAutomaticallyKeyPress
    end
    object edIntervalMin: TEdit
      Left = 124
      Top = 52
      Width = 45
      Height = 21
      TabOrder = 2
      Text = '1000'
      OnChange = edIntervalMinChange
    end
    object edIntervalMax: TEdit
      Left = 193
      Top = 52
      Width = 45
      Height = 21
      TabOrder = 3
      Text = '1000'
      OnChange = edIntervalMaxChange
    end
    object cbDatagramsPerTickMin: TComboBox
      Left = 153
      Top = 77
      Width = 42
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 4
      OnChange = cbDatagramsPerTickMinChange
    end
    object cbDatagramsPerTickMax: TComboBox
      Left = 217
      Top = 77
      Width = 42
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 5
      OnChange = cbDatagramsPerTickMaxChange
    end
    object cbSendType: TComboBox
      Left = 50
      Top = 3
      Width = 239
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 6
      OnChange = cbSendTypeChange
    end
  end
  object edAddress: TEdit
    Left = 53
    Top = 5
    Width = 129
    Height = 21
    TabOrder = 1
    Text = '225.1.1.1'
    OnChange = edAddressChange
  end
  object edPort: TEdit
    Left = 226
    Top = 5
    Width = 49
    Height = 21
    TabOrder = 2
    Text = '4242'
    OnChange = edPortChange
  end
  object memo: TMemo
    Left = 8
    Top = 64
    Width = 454
    Height = 185
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = []
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
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 3
    OnChange = memoChange
    ExplicitWidth = 393
  end
  object tmrAutoSend: TTimer
    Enabled = False
    OnTimer = tmrAutoSendTimer
    Left = 304
    Top = 8
  end
end
