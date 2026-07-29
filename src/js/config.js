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
    type: 'section',
    items: [
      {
        type: 'heading',
        defaultValue: 'Bewegung im Ölbad'
      },
      {
        type: 'slider',
        messageKey: 'Inertia',
        label: 'Trägheit',
        description: 'Niedrig reagiert schnell, hoch reagiert schwer und langsam.',
        defaultValue: 5,
        min: 1,
        max: 10,
        step: 1
      },
      {
        type: 'slider',
        messageKey: 'Speed',
        label: 'Geschwindigkeit',
        description: 'Stellt das Gewicht und damit die antreibende Kraft ein.',
        defaultValue: 5,
        min: 1,
        max: 10,
        step: 1
      },
      {
        type: 'slider',
        messageKey: 'Friction',
        label: 'Reibung',
        description: 'Niedrig schwingt länger nach, hoch kommt schneller zur Ruhe.',
        defaultValue: 5,
        min: 1,
        max: 10,
        step: 1
      },
      {
        type: 'slider',
        messageKey: 'Deadzone',
        label: 'Deadzone',
        description: 'Winkel in Grad, bevor die Scheibe aus der Ruhe losfährt.',
        defaultValue: 5,
        min: 1,
        max: 10,
        step: 1
      }
    ]
  },
  {
    type: 'submit',
    defaultValue: 'Speichern'
  }
];
