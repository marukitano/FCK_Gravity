module.exports = [
  {
    type: 'heading',
    defaultValue: 'FCK_Gravity'
  },
  {
    type: 'section',
    items: [
      {
        type: 'heading',
        defaultValue: 'Farben'
      },
      {
        type: 'color',
        messageKey: 'BackgroundColor',
        label: 'Hintergrundfarbe',
        defaultValue: '0x000000'
      },
      {
        type: 'color',
        messageKey: 'ForegroundColor',
        label: 'Schriftfarbe',
        defaultValue: '0xFFFFFF'
      }
    ]
  },
  {
    type: 'section',
    items: [
      {
        type: 'heading',
        defaultValue: 'Wappen'
      },
      {
        type: 'toggle',
        messageKey: 'ShowEmblem',
        label: 'Schweizer Wappen anzeigen',
        defaultValue: true
      }
    ]
  },
  {
    type: 'submit',
    defaultValue: 'Speichern'
  }
];
