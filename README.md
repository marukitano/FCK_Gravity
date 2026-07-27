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
- Frei gelagerte, gewichtete Scheibenbewegung
- Kein Zittern bei annähernd waagerechter Haltung
- Gleichmäßige Winkeldeadzone
- Einmaliges natürliches Überschwingen mit weicher Endlage
- Sensorabtastung mit 10 Hz
- Darstellung mit ungefähr 18 Bildern pro Sekunde
- Einstellbare Schrift- und Hintergrundfarbe
- Optional ausblendbares Schweizer Wappen im Drehpunkt

### Bewegungsmodell

Die Anzeige verhält sich wie eine frei gelagerte, gewichtete Scheibe. Der
Beschleunigungssensor erzeugt ein tangentiales Drehmoment, wodurch sich das
gesamte Ziffernblatt flüssig nach der Schwerkraft ausrichtet.

Eine Winkeldeadzone verhindert Zittern bei kleinen Bewegungen. Beim Abbremsen
darf die Anzeige einmal natürlich überschwingen und wird anschließend weich in
die Endlage geführt.

### Ursprung

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
- Freely suspended weighted-disc motion
- No jitter when the watch is held nearly flat
- Consistent angular deadzone
- One natural overshoot followed by soft final settling
- 10 Hz accelerometer sampling
- Rendering at approximately 18 frames per second
- Configurable foreground and background colors
- Optional Swiss emblem at the rotation pivot

### Motion model

The display behaves like a freely suspended weighted disc. Accelerometer input
creates tangential torque, allowing the complete watchface to align smoothly
with gravity.

An angular deadzone prevents jitter during small movements. As the display
slows down, it is allowed one natural overshoot before softly settling into its
final position.

### Origin

Gravity is based on the original Pebble watchface **Upright** by **Jnm**. The
original digit graphics were converted into vector paths, and the watchface
was modernized for the Pebble Time 2 and the current Pebble SDK.

### License

New Gravity source code and modifications by Maru are released under the
[MIT License](LICENSE).

The original Upright source code and graphics remain subject to the BSD
license grant made by the original developer.

See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) for details.
