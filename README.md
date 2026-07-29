# FCK_Gravity

FCK_Gravity is a gravity-driven vector watchface for the Pebble Time 2.

---

## Deutsch

**FCK Gravity** ist eine modernisierte Version des Pebble-Ziffernblatts
**Upright**, das ursprünglich von **Jnm** entwickelt wurde.

Die Uhrzeit wird mit vier Ziffernblöcken dargestellt. Der
Beschleunigungssensor erkennt die Ausrichtung der Uhr und dreht die gesamte
Anzeige entsprechend der Schwerkraft, sodass die Uhrzeit beim Bewegen des
Handgelenks aufrecht bleibt.

### Funktionen

- Entwickelt für die Pebble Time 2 (`emery`, 200 × 228 Pixel)
- Vektorbasiert gezeichnete Ziffern
- Gemeinsame Rotation aller vier Ziffernblöcke
- Unterstützung für das 12- und 24-Stunden-Format
- Natürliches Ölbad-Bewegungsmodell
- Gedämpftes Anfahren und Abbremsen
- Einstellbares Losbrechverhalten und einstellbare Deadzone
- Einstellbare Trägheit, Geschwindigkeit und Reibung
- Einstellbare Schrift- und Hintergrundfarbe
- Optional ausblendbares Schweizer Wappen im Drehpunkt
- Sensorabtastung mit 10 Hz
- Darstellung mit ungefähr 18 Bildern pro Sekunde

### Bewegungsmodell

Die Anzeige verhält sich wie eine frei gelagerte, gewichtete Scheibe in einem
Behälter mit zähflüssigem Öl. Das Gewicht erzeugt abhängig von der Lage der Uhr
ein tangentiales Drehmoment. Gleichzeitig bremst der viskose Widerstand die
Scheibe proportional zu ihrer Bewegungsgeschwindigkeit.

Dadurch fährt die Anzeige gedämpft an und kommt ohne künstliche Einfangphase
wieder zur Ruhe. Eine einstellbare Deadzone und ein Losbrechmoment verhindern,
dass kleine unbeabsichtigte Handbewegungen die Scheibe ständig in Bewegung
setzen.

Über vier Regler lassen sich Trägheit, Geschwindigkeit beziehungsweise Gewicht,
Reibung und Deadzone anpassen. Die Mittelstellung `5 / 5 / 5 / 5` entspricht
der sorgfältig abgestimmten Standardbewegung.

### Ursprung

FCK_Gravity wird von einem Schweizer Entwickler gepflegt und ist bewusst als
Schweizer Ziffernblatt gestaltet. Das kleine Schweizer Wappen im Drehpunkt ist
als augenzwinkerndes Detail gedacht und kann in den Einstellungen jederzeit
ausgeblendet werden.

Gravity basiert auf dem ursprünglichen Pebble-Watchface **Upright** von
**Jnm**. Die ursprünglichen Zifferngrafiken wurden in Vektorpfade umgewandelt
und das Watchface für die Pebble Time 2 sowie das aktuelle Pebble-SDK
modernisiert.

### Lizenz

Neue Gravity-Quelltexte und Änderungen von Maru werden unter der
[MIT-Lizenz](LICENSE) veröffentlicht.

Der ursprüngliche Upright-Quellcode und die ursprünglichen Grafiken bleiben
von der BSD-Lizenzfreigabe des ursprünglichen Entwicklers abgedeckt.

Weitere Informationen befinden sich in
[THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

---

## English

**FCK Gravity** is a modernized version of the Pebble watchface **Upright**,
originally created by **Jnm**.

The time is displayed using four separate digit blocks. The accelerometer
detects the orientation of the watch and rotates the entire display according
to gravity, keeping the time upright as the wrist moves.

### Features

- Designed for the Pebble Time 2 (`emery`, 200 × 228 pixels)
- Vector-rendered digits
- Unified rotation of all four digit blocks
- Support for both 12-hour and 24-hour time formats
- Natural oil-bath motion model
- Damped acceleration and deceleration
- Adjustable breakaway behavior and deadzone
- Adjustable inertia, speed, and friction
- Configurable foreground and background colors
- Optional Swiss emblem at the rotation pivot
- 10 Hz accelerometer sampling
- Rendering at approximately 18 frames per second

### Motion model

The display behaves like a freely suspended weighted disc inside a container
filled with viscous oil. Depending on the orientation of the watch, the weight
creates tangential torque while viscous resistance slows the disc in proportion
to its angular velocity.

This makes the display accelerate and decelerate smoothly without a separate
artificial settling phase. An adjustable deadzone and breakaway threshold keep
small unintended wrist movements from constantly starting the disc.

Four sliders control inertia, speed or effective weight, friction, and deadzone.
The centered setting `5 / 5 / 5 / 5` is the carefully tuned default motion.

### Origin

FCK_Gravity is maintained by a Swiss developer and is intentionally presented
as a Swiss watchface. The small Swiss emblem at the rotation pivot is meant as
a playful detail and can be hidden at any time in the settings.

Gravity is based on the original Pebble watchface **Upright** by **Jnm**. The
original digit graphics were converted into vector paths, and the watchface
was modernized for the Pebble Time 2 and the current Pebble SDK.

### License

New Gravity source code and modifications by Maru are released under the
[MIT License](LICENSE).

The original Upright source code and graphics remain subject to the BSD
license grant made by the original developer.

See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) for details.
