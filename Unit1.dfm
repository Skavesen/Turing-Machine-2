object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 674
  ClientWidth = 1106
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1106
    Height = 674
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 1098
        Height = 646
        Align = alClient
        Caption = 'Panel1'
        Color = clWindow
        ParentBackground = False
        TabOrder = 0
        object Label3: TLabel
          Left = 0
          Top = 11
          Width = 261
          Height = 23
          Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1072#1103' '#1076#1083#1080#1085#1072' '#1089#1083#1086#1074#1072':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -20
          Font.Name = 'Boyarsky'
          Font.Style = []
          ParentFont = False
        end
        object Button6: TButton
          Left = 335
          Top = 17
          Width = 88
          Height = 88
          Caption = #9654
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -73
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = Button6Click
        end
        object Button7: TButton
          Left = 429
          Top = 17
          Width = 88
          Height = 88
          Caption = #9632
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -73
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = Button7Click
        end
        object Button8: TButton
          Left = 523
          Top = 17
          Width = 88
          Height = 88
          Caption = #9208#65039
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -73
          Font.Name = 'Segoe UI Symbol'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = Button8Click
        end
        object Chart1: TChart
          Left = -4
          Top = 111
          Width = 1109
          Height = 538
          Legend.Alignment = laBottom
          Legend.Brush.Color = 14680063
          Legend.CustomPosition = True
          Legend.DividingLines.Width = 8
          Legend.Font.Height = -16
          Legend.Font.Name = 'Boyarsky'
          Legend.Font.Style = [fsBold, fsItalic]
          Legend.Left = 316
          Legend.ResizeChart = False
          Legend.TextSymbolGap = 8
          Legend.Title.Brush.Gradient.Direction = gdLeftRight
          Legend.Title.Children = <
            item
            end>
          Legend.Title.ChildLayout = slLeftRight
          Legend.Title.Cursor = crArrow
          Legend.Title.Font.Height = -41
          Legend.Title.Margins.Left = 0
          Legend.Title.Margins.Top = 4
          Legend.Title.Visible = False
          Legend.Top = 490
          Legend.TopPos = 9
          Legend.VertSpacing = 23
          MarginBottom = 10
          SubTitle.Font.Color = clRed
          Title.Font.Color = clBlack
          Title.Font.Height = -40
          Title.Font.Name = 'Boyarsky'
          Title.Margins.Left = 8
          Title.Text.Strings = (
            #1043#1088#1072#1092#1080#1082' '#1074#1088#1077#1084#1077#1085#1085#1086#1081' '#1089#1083#1086#1078#1085#1086#1089#1090#1080)
          Title.VertMargin = 1
          BottomAxis.LabelsFormat.Font.Height = -16
          BottomAxis.Title.Caption = #1044#1083#1080#1085#1072' '#1089#1083#1086#1074#1072
          BottomAxis.Title.Font.Height = -19
          BottomAxis.Title.Font.Name = 'Boyarsky'
          LeftAxis.LabelsFormat.Font.Height = -16
          LeftAxis.Title.Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1096#1072#1075#1086#1074
          LeftAxis.Title.Font.Height = -16
          LeftAxis.Title.Font.Name = 'Boyarsky'
          LeftAxis.TitleSize = 1
          View3D = False
          TabOrder = 3
          DefaultCanvas = 'TGDIPlusCanvas'
          PrintMargins = (
            15
            33
            15
            33)
          ColorPaletteIndex = 13
          object Series1: TLineSeries
            SeriesColor = 327912
            Title = #1054#1076#1085#1086#1083#1077#1085#1090#1086#1095#1085#1072#1103' '#1052#1058
            Brush.BackColor = clDefault
            LinePen.Width = 2
            Pointer.InflateMargins = True
            Pointer.Style = psRectangle
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
            Data = {
              0019000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              00000000000000000000000000}
            Detail = {0000000000}
          end
          object Series2: TLineSeries
            SeriesColor = 14958107
            Title = #1044#1074#1091#1093#1083#1077#1085#1090#1086#1095#1085#1072#1103' '#1052#1058
            Brush.BackColor = clDefault
            LinePen.Width = 2
            Pointer.InflateMargins = True
            Pointer.Style = psRectangle
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
            Data = {
              0019000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              00000000000000000000000000}
            Detail = {0000000000}
          end
        end
        object Edit2: TEdit
          Left = 0
          Top = 41
          Width = 320
          Height = 64
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -40
          Font.Name = 'Verdana'
          Font.Orientation = 2
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          Text = '11'
          OnChange = Edit2Change
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1057#1083#1086#1074#1086
      ImageIndex = 1
      object Label1: TLabel
        Left = 16
        Top = 13
        Width = 247
        Height = 45
        Align = alCustom
        Alignment = taCenter
        BiDiMode = bdLeftToRight
        Caption = #1056#1072#1089#1095#1105#1090' '#1089#1083#1086#1074#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'Boyarsky'
        Font.Style = []
        ParentBiDiMode = False
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 378
        Top = 21
        Width = 695
        Height = 40
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Boyarsky'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = 'aabbbbbbbbcccc'
        OnChange = Edit1Change
      end
      object Button2: TButton
        Left = 16
        Top = 74
        Width = 521
        Height = 55
        Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1085#1072' '#1086#1076#1085#1086#1081' '#1083#1077#1085#1090#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Boyarsky'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = Button2Click
      end
      object Memo1: TMemo
        Left = 16
        Top = 144
        Width = 1057
        Height = 499
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 2
      end
      object Button5: TButton
        Left = 552
        Top = 74
        Width = 521
        Height = 55
        Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1085#1072' '#1076#1074#1091#1093' '#1083#1077#1085#1090#1072#1093
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Boyarsky'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = Button5Click
      end
    end
  end
end
